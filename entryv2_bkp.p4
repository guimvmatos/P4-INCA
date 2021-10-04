/* -*- P4_16 -*- */
#include <core.p4>
#include <v1model.p4>
const bit<16> TYPE_IPV6 = 0x86dd;
const bit<16> TYPE_GTP = 2152;
const bit<8> TYPE_UDP = 17;
const bit<8> TYPE_TCP = 6;
const bit<8> TYPE_SRV6 = 43;
const bit<8> pdu_container = 133;
const bit<8> num_segments2 = 2;
const bit<8> num_segments3 = 3;
const bit<8> TYPE_SR = 4;
const bit<8> SL = 2;
const bit<8> LE = 2;
const bit<8> LEN = 6;

#define max_hops 4
/*************************************************************************
*********************** H E A D E R S  ***********************************
*************************************************************************/
typedef bit<16> egressSpec_t;
typedef bit<48> macAddr_t;
typedef bit<128> ip6Addr_t;
header ethernet_t {
    macAddr_t dstAddr;
    macAddr_t srcAddr;
    bit<16> etherType;
}
header ipv6_t {
    bit<4> version;
    bit<8> traffic_class;
    bit<20> flow_label;
    bit<16> payload_len;
    bit<8> next_hdr;
    bit<8> hop_limit;
    bit<128> src_addr;
    bit<128> dst_addr;
}

header srv6_t3 {
    bit<8> next_hdr;
    bit<8> hdr_ext_len;
    bit<8> routing_type;
    bit<8> segment_left;
    bit<8> last_entry;
    bit<8> flags;
    bit<16> tag;
    bit<128> segment_id1;
    bit<128> segment_id2;
    bit<128> segment_id3;
}

header udp_t {
    bit<16> sport;
    bit<16> dport;
    bit<16> len;
    bit<16> checksum;
}
header tcp_t {
    bit<16> srcPort;
    bit<16> dstPort;
    bit<32> seqNo;
    bit<32> ackNo;
    bit<4>  dataOffset;
    bit<3>  res;
    bit<3>  ecn;
    bit<6>  ctrl;
    bit<16> window;
    bit<16> checksum;
    bit<16> urgentPtr;
}
header gtp_t {
    bit<3>  version_field_id;
    bit<1>  proto_type_id;
    bit<1>  spare;
    bit<1>  extension_header_flag_id;
    bit<1>  sequence_number_flag_id;
    bit<1>  npdu_number_flag_id;
    bit<8>  msgtype;
    bit<16> msglen;
    bit<32> teid;
}
header gtp_ext_t {
	bit<8> next_extension;
}
header pdu_container_t {
	bit<4> pdu_type;
	bit<5> spare;
	bit<1> rqi;
	bit<6> qosid;
	bit<8> padding; 
}
struct metadata {
    bit<1> anything;
}
struct headers {
    ethernet_t              ethernet;
    ipv6_t                  ipv6_outer;
    srv6_t3                 srv63;
    udp_t                   udp;
    tcp_t                   tcp;
    gtp_t                   gtp;
    gtp_ext_t               gtp_ext;
    pdu_container_t         pdu_container;
    ipv6_t                  ipv6_inner;
    udp_t                   udp_inner;
    tcp_t                   tcp_inner;                   
}
/*************************************************************************
*********************** P A R S E R  ***********************************
*************************************************************************/
parser MyParser(packet_in packet,
                out headers hdr,
                inout metadata meta,
                inout standard_metadata_t standard_metadata) {
    state start {
        transition parse_ethernet;
    }
    state parse_ethernet {
        packet.extract(hdr.ethernet);
        transition select(hdr.ethernet.etherType) {
            TYPE_IPV6: parse_ipv6_outer;
        }
    }
    state parse_ipv6_outer {
        packet.extract(hdr.ipv6_outer);
        transition select(hdr.ipv6_outer.next_hdr){
            TYPE_UDP: parse_udp_outer;
            TYPE_TCP: parse_tcp_outer;
            TYPE_SRV6: parse_srv63;
            default: accept; 
        }
    }
    
    state parse_srv63 {
        packet.extract(hdr.srv63);
        transition parse_udp_outer;
    }

    state parse_udp_outer {
        packet.extract(hdr.udp);
        transition select (hdr.udp.dport){
            TYPE_GTP: parse_gtp;
            default: accept;
        }
    }
    state parse_tcp_outer {
        packet.extract(hdr.tcp);
        transition accept;
    }
    
    state parse_gtp {
        packet.extract(hdr.gtp);
        transition select(hdr.gtp.extension_header_flag_id){
            1: parse_gtp_ext;
            0: parse_ipv6_inner;
        }
    }
    state parse_gtp_ext{
        packet.extract(hdr.gtp_ext);
        transition select(hdr.gtp_ext.next_extension){
            pdu_container: parse_pdu_container;
            } 
        }
    state parse_pdu_container{
        packet.extract(hdr.pdu_container);
        transition parse_ipv6_inner;
    }
    state parse_ipv6_inner{
        packet.extract(hdr.ipv6_inner);
        transition select(hdr.ipv6_inner.next_hdr){
            TYPE_UDP: parse_udp_inner;
            TYPE_TCP: parse_tcp_inner;
            default: accept;
        }
    }
    state parse_udp_inner{
        packet.extract(hdr.udp_inner);
        transition accept;
    }
    state parse_tcp_inner{
        packet.extract(hdr.tcp_inner);
        transition accept;
    }
}
/*************************************************************************
************   C H E C K S U M    V E R I F I C A T I O N   *************
*************************************************************************/
control MyVerifyChecksum(inout headers hdr, 
                         inout metadata meta) {   
    apply {  }
}
/*************************************************************************
**************  I N G R E S S   P R O C E S S I N G   *******************
*************************************************************************/
control MyIngress (inout headers hdr,
                   inout metadata meta,
                   inout standard_metadata_t standard_metadata) {
    action drop() {
        mark_to_drop();
    }
    action ipv6_forward (macAddr_t dstAddr, egressSpec_t port) {
        standard_metadata.egress_spec = port;
        hdr.ethernet.dstAddr = dstAddr;
    }

    action srv6_pop (bit<8> hop) {
        hdr.ipv6_outer.next_hdr = hdr.srv63.next_hdr;
        hdr.ipv6_outer.payload_len = hdr.ipv6_outer.payload_len - 56; /*cada sid tem 16bytes. são 3 sids + 8 bytes do header*/
        hdr.srv63.setInvalid();
        hdr.ipv6_outer.hop_limit = hop;
        hdr.gtp.spare = 1;
    }

    action build_srv63(ip6Addr_t s2, ip6Addr_t s3) {
        hdr.srv63.setValid(); 
        hdr.srv63.next_hdr = hdr.ipv6_outer.next_hdr; 
        hdr.srv63.hdr_ext_len =  LEN; 
        hdr.srv63.routing_type = TYPE_SR;
        hdr.srv63.segment_left = SL;
        hdr.srv63.last_entry = 2;
        hdr.srv63.flags = 0;
        hdr.srv63.tag = 1;
        hdr.srv63.segment_id1 = hdr.ipv6_outer.dst_addr;
        hdr.srv63.segment_id2 = s2;
        hdr.srv63.segment_id3 = s3;
        hdr.ipv6_outer.next_hdr = TYPE_SRV6;
        hdr.ipv6_outer.dst_addr = s3;
        hdr.ipv6_outer.payload_len = hdr.ipv6_outer.payload_len + 56;
    }

    table ipv6_outer_lpm {
        key = {
            hdr.ipv6_outer.dst_addr:exact;
        }
        actions = {
            ipv6_forward;
            drop;
            NoAction;
        }
        size = 1024;
        default_action = drop();
    }

    table main {
        key = {
            hdr.gtp.teid: ternary;
            hdr.pdu_container.qosid: ternary;
            hdr.ipv6_inner.dst_addr: ternary;
            hdr.ipv6_inner.src_addr: ternary;
            hdr.ipv6_inner.next_hdr: ternary;
            hdr.tcp_inner.dstPort: ternary;
            hdr.tcp_inner.srcPort: ternary;
            hdr.udp_inner.dport: ternary;
            hdr.udp_inner.sport: ternary;
        }
        actions = {
            build_srv63;
            srv6_pop;
        }
        default_action = srv6_pop(64);
        /*size = 1024;*/
    }

    table pop {
        key = {
            hdr.ipv6_outer.dst_addr:exact;
        }
        actions = {
            srv6_pop;
            drop;
        }
        size = 1024;
        default_action = drop();
    }
    
    apply {
        if (hdr.srv63.isValid() && hdr.srv63.segment_left == 2 && hdr.srv63.tag == 0){
            teid_exact.apply();
        } else if (hdr.srv63.isValid() && hdr.srv63.segment_left == 0){
            pop.apply();
        }
        ipv6_outer_lpm.apply();
    }
}
/************************************************************************
****************  E G R E S S   P R O C E S S I N G   *******************
*************************************************************************/
control MyEgress(inout headers hdr,
                 inout metadata meta,
                 inout standard_metadata_t standard_metadata) {
    apply {  }
}
/*************************************************************************
*************   C H E C K S U M    C O M P U T A T I O N   **************
*************************************************************************/
control MyComputeChecksum (inout headers hdr, 
                           inout metadata meta) {
     apply { }
}
/*************************************************************************
***********************  D E P A R S E R  *******************************
*************************************************************************/
control MyDeparser (packet_out packet,
                    in headers hdr) {
    apply {
        packet.emit(hdr.ethernet);
        packet.emit(hdr.ipv6_outer);
        packet.emit(hdr.srv63);
        packet.emit(hdr.udp);
        packet.emit(hdr.tcp);
        packet.emit(hdr.gtp);
        packet.emit(hdr.gtp_ext);
        packet.emit(hdr.pdu_container);
        packet.emit(hdr.ipv6_inner);
        packet.emit(hdr.udp_inner);
        packet.emit(hdr.tcp_inner);
    }
}
/*************************************************************************
***********************  S W I T C H  *******************************
*************************************************************************/
V1Switch(
MyParser(),
MyVerifyChecksum(),
MyIngress(),
MyEgress(),
MyComputeChecksum(),
MyDeparser()
) main;

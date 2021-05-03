/* -*- P4_16 -*- */
#include <core.p4>
#include <v1model.p4>
/* will be in udp header */
const bit<16> TYPE_IPV6 = 0x86dd;
const bit<16> TYPE_GTP = 2152;
/* will be in ipv6 header*/
const bit<8> TYPE_UDP = 17;
const bit<8> TYPE_TCP = 6;
const bit<8> TYPE_SRV6 = 43;
const bit<8> pdu_container = 133;
const bit<8> num_segments2 = 2;
const bit<8> num_segments3 = 3;
/* will be in srv6 header*/
const bit<8> TYPE_SR = 4;
const bit<4> TYPE_IP6 = 6;
const bit<8> SL = 2;
const bit<8> LE = 2;
const bit<8> LEN = 6;

#define max_hops 4
/*************************************************************************
*********************** H E A D E R S  ***********************************
*************************************************************************/
typedef bit<9> egressSpec_t; /*todo mudar para 9 na netronome*/
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
            TYPE_IPV6: check_ipv6_inner_or_outer;
        }
    }

    state check_ipv6_inner_or_outer{
        transition select (packet.lookahead<ipv6_t>().traffic_class){
            123: parse_ipv6_outer;
            default: parse_ipv6_inner;
        }
    }
    state parse_ipv6_outer {
        packet.extract(hdr.ipv6_outer);
        transition select(hdr.ipv6_outer.next_hdr){
            TYPE_UDP: parse_udp_outer;
            /*TYPE_TCP: parse_tcp_outer;*/
            /*TYPE_SRV6: parse_srv63;*/
            /*só preciso saber se é udp para verifiar se é 5g, qualquer outro eu aceito*/
            default: accept; 
        }
    }

    state parse_udp_outer {
        packet.extract(hdr.udp);
        transition select (hdr.udp.dport){
            TYPE_GTP: parse_gtp; /*seria o downlink*/
            default: accept; /*se não 5g, é uplink*/
        }
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
            TYPE_UDP: parse_udp_inner; /*preciso pois posso filtrar as portas no inca*/
            TYPE_TCP: parse_tcp_inner; /*preciso pois posso filtrar as portas no inca*/
            default: accept; /*se for um icmp por exemplo, passa tb*/
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

    action ipv6_forward (macAddr_t srcAddr, macAddr_t dstAddr, egressSpec_t port) {
        standard_metadata.egress_spec = port;
        hdr.ethernet.srcAddr = srcAddr;
        hdr.ethernet.dstAddr = dstAddr;
    }


    action core5g_pop (bit<8> hop) {
        hdr.ipv6_outer.hop_limit = hop;
        hdr.ipv6_outer.setInvalid();
        hdr.udp.setInvalid();
        hdr.gtp.setInvalid();
        hdr.gtp_ext.setInvalid();
        hdr.pdu_container.setInvalid();
        hdr.ipv6_outer.hop_limit = hop;
    }


    action core5g_build (ip6Addr_t s1, ip6Addr_t s2, ip6Addr_t s3, ip6Addr_t src) {
        hdr.ipv6_outer.setValid();
        hdr.srv63.setValid();
        hdr.udp.setValid();
        hdr.gtp.setValid();
        hdr.gtp_ext.setValid();
        hdr.pdu_container.setValid();
  
        hdr.ipv6_outer.version = TYPE_IP6;
        hdr.ipv6_outer.traffic_class =  123;
        hdr.ipv6_outer.flow_label = 0;
        hdr.ipv6_outer.payload_len = 80 + hdr.ipv6_inner.payload_len; /*180 -> valor com ping*/
        hdr.ipv6_outer.next_hdr = TYPE_SRV6;
        hdr.ipv6_outer.hop_limit = 64;
        hdr.ipv6_outer.dst_addr = s1;
        hdr.ipv6_outer.src_addr = src;
        

        hdr.srv63.next_hdr = TYPE_UDP;
        hdr.srv63.hdr_ext_len =  LEN;
        hdr.srv63.routing_type = TYPE_SR;
        hdr.srv63.segment_left = SL;
        hdr.srv63.last_entry = 2;
        hdr.srv63.flags = 0;
        hdr.srv63.tag = 1;
        hdr.srv63.segment_id1 = s1; /*(match fc00::1 -> fc00::1 e vice versa)*/
        hdr.srv63.segment_id2 = s2; /*fc00::101*/
        hdr.srv63.segment_id3 = s3; /*fc00::100*/

        hdr.udp.sport = 64515;
    	hdr.udp.dport = TYPE_GTP;
    	hdr.udp.len = 12 + hdr.ipv6_inner.payload_len;
    	hdr.udp.checksum = 0;

	    hdr.gtp.version_field_id = 1;
	    hdr.gtp.proto_type_id = 1;
	    hdr.gtp.spare = 0;
	    hdr.gtp.extension_header_flag_id = 1;
	    hdr.gtp.sequence_number_flag_id = 0;
	    hdr.gtp.npdu_number_flag_id = 0;
	    hdr.gtp.msgtype = 255 ;
	    hdr.gtp.msglen = 0;
	    hdr.gtp.teid = 32;

		hdr.gtp_ext.next_extension = 133;

		hdr.pdu_container.pdu_type = 1;
		hdr.pdu_container.spare = 0;
		hdr.pdu_container.rqi = 0;
		hdr.pdu_container.qosid = 14;
		hdr.pdu_container.padding = 0;

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


    table ipv6_inner_lpm { /*encaminha fc10::2 ou fc20::2 para final*/
        key = {
            hdr.ipv6_inner.dst_addr:exact;
        }
        actions = {
            ipv6_forward;
            drop;
            NoAction;
        }
        size = 1024;
        default_action = drop();
    }

    table uplink {
        key = {
            hdr.ipv6_inner.src_addr:exact; /*endereço na ran: fc10::2  upf: fc20::2*/
        }
        actions = {
            core5g_build;
            drop;
        }
        default_action = drop();
        /*size = 1024;*/
    }

    
    table downlink {
        key = {
            hdr.ipv6_outer.dst_addr:exact; /*endereço na ran: fc00::1/upf: fc00::5*/
        }
        actions = {
            core5g_pop;
            drop;
        }
        size = 1024;
        default_action = drop();
    }
    
    apply {
        if (!hdr.gtp.isValid()){
            uplink.apply();
            ipv6_outer_lpm.apply();
        } else if (hdr.gtp.isValid() && !hdr.srv63.isValid()){
            downlink.apply();
            ipv6_inner_lpm.apply();
        }
        
        
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
    apply { 
        update_checksum(
            hdr.udp.isValid(),
                                           { hdr.ipv6_outer.src_addr,
                                             hdr.ipv6_outer.dst_addr,
                                             8w0,
                                             hdr.ipv6_outer.next_hdr,
                                             hdr.udp.sport,
                                             hdr.udp.dport,
                                             hdr.udp.len
                                           },
                                           hdr.udp.checksum,
                                           HashAlgorithm.csum16);
                                    }
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

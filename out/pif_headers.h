/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_HEADERS_H__
#define __PIF_HEADERS_H__

/* Generated C source defining PIF headers, metadata and registers */
/* Warning: your edits to this file may be lost */

/*
 * Packet headers
 */

/* tcp_inner (20B) */
struct pif_header_tcp_inner {
    unsigned int srcPort:16;
    unsigned int dstPort:16;
    unsigned int seqNo:32;
    unsigned int ackNo:32;
    unsigned int dataOffset:4;
    unsigned int res:3;
    unsigned int ecn:3;
    unsigned int ctrl:6;
    unsigned int window:16;
    unsigned int checksum:16;
    unsigned int urgentPtr:16;
};

/* tcp_inner field accessor macros */
#define PIF_HEADER_GET_tcp_inner___srcPort(_hdr_p) (((_hdr_p)->srcPort)) /* tcp_inner.srcPort [16;0] */

#define PIF_HEADER_SET_tcp_inner___srcPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcPort = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.srcPort[16;0] */

#define PIF_HEADER_GET_tcp_inner___dstPort(_hdr_p) (((_hdr_p)->dstPort)) /* tcp_inner.dstPort [16;0] */

#define PIF_HEADER_SET_tcp_inner___dstPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstPort = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.dstPort[16;0] */

#define PIF_HEADER_GET_tcp_inner___seqNo(_hdr_p) (((_hdr_p)->seqNo)) /* tcp_inner.seqNo [32;0] */

#define PIF_HEADER_SET_tcp_inner___seqNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->seqNo = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.seqNo[32;0] */

#define PIF_HEADER_GET_tcp_inner___ackNo(_hdr_p) (((_hdr_p)->ackNo)) /* tcp_inner.ackNo [32;0] */

#define PIF_HEADER_SET_tcp_inner___ackNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->ackNo = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.ackNo[32;0] */

#define PIF_HEADER_GET_tcp_inner___dataOffset(_hdr_p) (((_hdr_p)->dataOffset)) /* tcp_inner.dataOffset [4;0] */

#define PIF_HEADER_SET_tcp_inner___dataOffset(_hdr_p, _val) \
    do { \
        (_hdr_p)->dataOffset = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.dataOffset[4;0] */

#define PIF_HEADER_GET_tcp_inner___res(_hdr_p) (((_hdr_p)->res)) /* tcp_inner.res [3;0] */

#define PIF_HEADER_SET_tcp_inner___res(_hdr_p, _val) \
    do { \
        (_hdr_p)->res = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.res[3;0] */

#define PIF_HEADER_GET_tcp_inner___ecn(_hdr_p) (((_hdr_p)->ecn)) /* tcp_inner.ecn [3;0] */

#define PIF_HEADER_SET_tcp_inner___ecn(_hdr_p, _val) \
    do { \
        (_hdr_p)->ecn = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.ecn[3;0] */

#define PIF_HEADER_GET_tcp_inner___ctrl(_hdr_p) (((_hdr_p)->ctrl)) /* tcp_inner.ctrl [6;0] */

#define PIF_HEADER_SET_tcp_inner___ctrl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ctrl = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.ctrl[6;0] */

#define PIF_HEADER_GET_tcp_inner___window(_hdr_p) (((_hdr_p)->window)) /* tcp_inner.window [16;0] */

#define PIF_HEADER_SET_tcp_inner___window(_hdr_p, _val) \
    do { \
        (_hdr_p)->window = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.window[16;0] */

#define PIF_HEADER_GET_tcp_inner___checksum(_hdr_p) (((_hdr_p)->checksum)) /* tcp_inner.checksum [16;0] */

#define PIF_HEADER_SET_tcp_inner___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.checksum[16;0] */

#define PIF_HEADER_GET_tcp_inner___urgentPtr(_hdr_p) (((_hdr_p)->urgentPtr)) /* tcp_inner.urgentPtr [16;0] */

#define PIF_HEADER_SET_tcp_inner___urgentPtr(_hdr_p, _val) \
    do { \
        (_hdr_p)->urgentPtr = (unsigned)(((_val))); \
    } while (0) /* tcp_inner.urgentPtr[16;0] */


/* udp (8B) */
struct pif_header_udp {
    unsigned int sport:16;
    unsigned int dport:16;
    unsigned int len:16;
    unsigned int checksum:16;
};

/* udp field accessor macros */
#define PIF_HEADER_GET_udp___sport(_hdr_p) (((_hdr_p)->sport)) /* udp.sport [16;0] */

#define PIF_HEADER_SET_udp___sport(_hdr_p, _val) \
    do { \
        (_hdr_p)->sport = (unsigned)(((_val))); \
    } while (0) /* udp.sport[16;0] */

#define PIF_HEADER_GET_udp___dport(_hdr_p) (((_hdr_p)->dport)) /* udp.dport [16;0] */

#define PIF_HEADER_SET_udp___dport(_hdr_p, _val) \
    do { \
        (_hdr_p)->dport = (unsigned)(((_val))); \
    } while (0) /* udp.dport[16;0] */

#define PIF_HEADER_GET_udp___len(_hdr_p) (((_hdr_p)->len)) /* udp.len [16;0] */

#define PIF_HEADER_SET_udp___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* udp.len[16;0] */

#define PIF_HEADER_GET_udp___checksum(_hdr_p) (((_hdr_p)->checksum)) /* udp.checksum [16;0] */

#define PIF_HEADER_SET_udp___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* udp.checksum[16;0] */


/* srv6_list (16B) */
struct pif_header_srv6_list {
    /* segment_id [32;96] */
    unsigned int segment_id:32;
    /* segment_id [32;64] */
    unsigned int __segment_id_1:32;
    /* segment_id [32;32] */
    unsigned int __segment_id_2:32;
    /* segment_id [32;0] */
    unsigned int __segment_id_3:32;
};

/* srv6_list field accessor macros */
#define PIF_HEADER_GET_srv6_list___segment_id___0(_hdr_p) (((_hdr_p)->__segment_id_3)) /* srv6_list.segment_id [32;0] */

#define PIF_HEADER_SET_srv6_list___segment_id___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__segment_id_3 = (unsigned)(((_val))); \
    } while (0) /* srv6_list.segment_id[32;0] */

#define PIF_HEADER_GET_srv6_list___segment_id___1(_hdr_p) (((_hdr_p)->__segment_id_2)) /* srv6_list.segment_id [32;32] */

#define PIF_HEADER_SET_srv6_list___segment_id___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__segment_id_2 = (unsigned)(((_val))); \
    } while (0) /* srv6_list.segment_id[32;32] */

#define PIF_HEADER_GET_srv6_list___segment_id___2(_hdr_p) (((_hdr_p)->__segment_id_1)) /* srv6_list.segment_id [32;64] */

#define PIF_HEADER_SET_srv6_list___segment_id___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__segment_id_1 = (unsigned)(((_val))); \
    } while (0) /* srv6_list.segment_id[32;64] */

#define PIF_HEADER_GET_srv6_list___segment_id___3(_hdr_p) (((_hdr_p)->segment_id)) /* srv6_list.segment_id [32;96] */

#define PIF_HEADER_SET_srv6_list___segment_id___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->segment_id = (unsigned)(((_val))); \
    } while (0) /* srv6_list.segment_id[32;96] */


/* gtp_ext (1B) */
struct pif_header_gtp_ext {
    unsigned int next_extension:8;
};

/* gtp_ext field accessor macros */
#define PIF_HEADER_GET_gtp_ext___next_extension(_hdr_p) (((_hdr_p)->next_extension)) /* gtp_ext.next_extension [8;0] */

#define PIF_HEADER_SET_gtp_ext___next_extension(_hdr_p, _val) \
    do { \
        (_hdr_p)->next_extension = (unsigned)(((_val))); \
    } while (0) /* gtp_ext.next_extension[8;0] */


/* udp_inner (8B) */
struct pif_header_udp_inner {
    unsigned int sport:16;
    unsigned int dport:16;
    unsigned int len:16;
    unsigned int checksum:16;
};

/* udp_inner field accessor macros */
#define PIF_HEADER_GET_udp_inner___sport(_hdr_p) (((_hdr_p)->sport)) /* udp_inner.sport [16;0] */

#define PIF_HEADER_SET_udp_inner___sport(_hdr_p, _val) \
    do { \
        (_hdr_p)->sport = (unsigned)(((_val))); \
    } while (0) /* udp_inner.sport[16;0] */

#define PIF_HEADER_GET_udp_inner___dport(_hdr_p) (((_hdr_p)->dport)) /* udp_inner.dport [16;0] */

#define PIF_HEADER_SET_udp_inner___dport(_hdr_p, _val) \
    do { \
        (_hdr_p)->dport = (unsigned)(((_val))); \
    } while (0) /* udp_inner.dport[16;0] */

#define PIF_HEADER_GET_udp_inner___len(_hdr_p) (((_hdr_p)->len)) /* udp_inner.len [16;0] */

#define PIF_HEADER_SET_udp_inner___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* udp_inner.len[16;0] */

#define PIF_HEADER_GET_udp_inner___checksum(_hdr_p) (((_hdr_p)->checksum)) /* udp_inner.checksum [16;0] */

#define PIF_HEADER_SET_udp_inner___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* udp_inner.checksum[16;0] */


/* ipv6_outer (40B) */
struct pif_header_ipv6_outer {
    unsigned int version:4;
    unsigned int traffic_class:8;
    unsigned int flow_label:20;
    unsigned int payload_len:16;
    unsigned int next_hdr:8;
    unsigned int hop_limit:8;
    /* src_addr [32;96] */
    unsigned int src_addr:32;
    /* src_addr [32;64] */
    unsigned int __src_addr_1:32;
    /* src_addr [32;32] */
    unsigned int __src_addr_2:32;
    /* src_addr [32;0] */
    unsigned int __src_addr_3:32;
    /* dst_addr [32;96] */
    unsigned int dst_addr:32;
    /* dst_addr [32;64] */
    unsigned int __dst_addr_1:32;
    /* dst_addr [32;32] */
    unsigned int __dst_addr_2:32;
    /* dst_addr [32;0] */
    unsigned int __dst_addr_3:32;
};

/* ipv6_outer field accessor macros */
#define PIF_HEADER_GET_ipv6_outer___version(_hdr_p) (((_hdr_p)->version)) /* ipv6_outer.version [4;0] */

#define PIF_HEADER_SET_ipv6_outer___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.version[4;0] */

#define PIF_HEADER_GET_ipv6_outer___traffic_class(_hdr_p) (((_hdr_p)->traffic_class)) /* ipv6_outer.traffic_class [8;0] */

#define PIF_HEADER_SET_ipv6_outer___traffic_class(_hdr_p, _val) \
    do { \
        (_hdr_p)->traffic_class = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.traffic_class[8;0] */

#define PIF_HEADER_GET_ipv6_outer___flow_label(_hdr_p) (((_hdr_p)->flow_label)) /* ipv6_outer.flow_label [20;0] */

#define PIF_HEADER_SET_ipv6_outer___flow_label(_hdr_p, _val) \
    do { \
        (_hdr_p)->flow_label = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.flow_label[20;0] */

#define PIF_HEADER_GET_ipv6_outer___payload_len(_hdr_p) (((_hdr_p)->payload_len)) /* ipv6_outer.payload_len [16;0] */

#define PIF_HEADER_SET_ipv6_outer___payload_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->payload_len = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.payload_len[16;0] */

#define PIF_HEADER_GET_ipv6_outer___next_hdr(_hdr_p) (((_hdr_p)->next_hdr)) /* ipv6_outer.next_hdr [8;0] */

#define PIF_HEADER_SET_ipv6_outer___next_hdr(_hdr_p, _val) \
    do { \
        (_hdr_p)->next_hdr = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.next_hdr[8;0] */

#define PIF_HEADER_GET_ipv6_outer___hop_limit(_hdr_p) (((_hdr_p)->hop_limit)) /* ipv6_outer.hop_limit [8;0] */

#define PIF_HEADER_SET_ipv6_outer___hop_limit(_hdr_p, _val) \
    do { \
        (_hdr_p)->hop_limit = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.hop_limit[8;0] */

#define PIF_HEADER_GET_ipv6_outer___src_addr___0(_hdr_p) (((_hdr_p)->__src_addr_3)) /* ipv6_outer.src_addr [32;0] */

#define PIF_HEADER_SET_ipv6_outer___src_addr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_addr_3 = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.src_addr[32;0] */

#define PIF_HEADER_GET_ipv6_outer___src_addr___1(_hdr_p) (((_hdr_p)->__src_addr_2)) /* ipv6_outer.src_addr [32;32] */

#define PIF_HEADER_SET_ipv6_outer___src_addr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_addr_2 = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.src_addr[32;32] */

#define PIF_HEADER_GET_ipv6_outer___src_addr___2(_hdr_p) (((_hdr_p)->__src_addr_1)) /* ipv6_outer.src_addr [32;64] */

#define PIF_HEADER_SET_ipv6_outer___src_addr___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_addr_1 = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.src_addr[32;64] */

#define PIF_HEADER_GET_ipv6_outer___src_addr___3(_hdr_p) (((_hdr_p)->src_addr)) /* ipv6_outer.src_addr [32;96] */

#define PIF_HEADER_SET_ipv6_outer___src_addr___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_addr = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.src_addr[32;96] */

#define PIF_HEADER_GET_ipv6_outer___dst_addr___0(_hdr_p) (((_hdr_p)->__dst_addr_3)) /* ipv6_outer.dst_addr [32;0] */

#define PIF_HEADER_SET_ipv6_outer___dst_addr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dst_addr_3 = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.dst_addr[32;0] */

#define PIF_HEADER_GET_ipv6_outer___dst_addr___1(_hdr_p) (((_hdr_p)->__dst_addr_2)) /* ipv6_outer.dst_addr [32;32] */

#define PIF_HEADER_SET_ipv6_outer___dst_addr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dst_addr_2 = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.dst_addr[32;32] */

#define PIF_HEADER_GET_ipv6_outer___dst_addr___2(_hdr_p) (((_hdr_p)->__dst_addr_1)) /* ipv6_outer.dst_addr [32;64] */

#define PIF_HEADER_SET_ipv6_outer___dst_addr___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dst_addr_1 = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.dst_addr[32;64] */

#define PIF_HEADER_GET_ipv6_outer___dst_addr___3(_hdr_p) (((_hdr_p)->dst_addr)) /* ipv6_outer.dst_addr [32;96] */

#define PIF_HEADER_SET_ipv6_outer___dst_addr___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_addr = (unsigned)(((_val))); \
    } while (0) /* ipv6_outer.dst_addr[32;96] */


/* ipv6_inner (40B) */
struct pif_header_ipv6_inner {
    unsigned int version:4;
    unsigned int traffic_class:8;
    unsigned int flow_label:20;
    unsigned int payload_len:16;
    unsigned int next_hdr:8;
    unsigned int hop_limit:8;
    /* src_addr [32;96] */
    unsigned int src_addr:32;
    /* src_addr [32;64] */
    unsigned int __src_addr_1:32;
    /* src_addr [32;32] */
    unsigned int __src_addr_2:32;
    /* src_addr [32;0] */
    unsigned int __src_addr_3:32;
    /* dst_addr [32;96] */
    unsigned int dst_addr:32;
    /* dst_addr [32;64] */
    unsigned int __dst_addr_1:32;
    /* dst_addr [32;32] */
    unsigned int __dst_addr_2:32;
    /* dst_addr [32;0] */
    unsigned int __dst_addr_3:32;
};

/* ipv6_inner field accessor macros */
#define PIF_HEADER_GET_ipv6_inner___version(_hdr_p) (((_hdr_p)->version)) /* ipv6_inner.version [4;0] */

#define PIF_HEADER_SET_ipv6_inner___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.version[4;0] */

#define PIF_HEADER_GET_ipv6_inner___traffic_class(_hdr_p) (((_hdr_p)->traffic_class)) /* ipv6_inner.traffic_class [8;0] */

#define PIF_HEADER_SET_ipv6_inner___traffic_class(_hdr_p, _val) \
    do { \
        (_hdr_p)->traffic_class = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.traffic_class[8;0] */

#define PIF_HEADER_GET_ipv6_inner___flow_label(_hdr_p) (((_hdr_p)->flow_label)) /* ipv6_inner.flow_label [20;0] */

#define PIF_HEADER_SET_ipv6_inner___flow_label(_hdr_p, _val) \
    do { \
        (_hdr_p)->flow_label = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.flow_label[20;0] */

#define PIF_HEADER_GET_ipv6_inner___payload_len(_hdr_p) (((_hdr_p)->payload_len)) /* ipv6_inner.payload_len [16;0] */

#define PIF_HEADER_SET_ipv6_inner___payload_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->payload_len = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.payload_len[16;0] */

#define PIF_HEADER_GET_ipv6_inner___next_hdr(_hdr_p) (((_hdr_p)->next_hdr)) /* ipv6_inner.next_hdr [8;0] */

#define PIF_HEADER_SET_ipv6_inner___next_hdr(_hdr_p, _val) \
    do { \
        (_hdr_p)->next_hdr = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.next_hdr[8;0] */

#define PIF_HEADER_GET_ipv6_inner___hop_limit(_hdr_p) (((_hdr_p)->hop_limit)) /* ipv6_inner.hop_limit [8;0] */

#define PIF_HEADER_SET_ipv6_inner___hop_limit(_hdr_p, _val) \
    do { \
        (_hdr_p)->hop_limit = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.hop_limit[8;0] */

#define PIF_HEADER_GET_ipv6_inner___src_addr___0(_hdr_p) (((_hdr_p)->__src_addr_3)) /* ipv6_inner.src_addr [32;0] */

#define PIF_HEADER_SET_ipv6_inner___src_addr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_addr_3 = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.src_addr[32;0] */

#define PIF_HEADER_GET_ipv6_inner___src_addr___1(_hdr_p) (((_hdr_p)->__src_addr_2)) /* ipv6_inner.src_addr [32;32] */

#define PIF_HEADER_SET_ipv6_inner___src_addr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_addr_2 = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.src_addr[32;32] */

#define PIF_HEADER_GET_ipv6_inner___src_addr___2(_hdr_p) (((_hdr_p)->__src_addr_1)) /* ipv6_inner.src_addr [32;64] */

#define PIF_HEADER_SET_ipv6_inner___src_addr___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_addr_1 = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.src_addr[32;64] */

#define PIF_HEADER_GET_ipv6_inner___src_addr___3(_hdr_p) (((_hdr_p)->src_addr)) /* ipv6_inner.src_addr [32;96] */

#define PIF_HEADER_SET_ipv6_inner___src_addr___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_addr = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.src_addr[32;96] */

#define PIF_HEADER_GET_ipv6_inner___dst_addr___0(_hdr_p) (((_hdr_p)->__dst_addr_3)) /* ipv6_inner.dst_addr [32;0] */

#define PIF_HEADER_SET_ipv6_inner___dst_addr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dst_addr_3 = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.dst_addr[32;0] */

#define PIF_HEADER_GET_ipv6_inner___dst_addr___1(_hdr_p) (((_hdr_p)->__dst_addr_2)) /* ipv6_inner.dst_addr [32;32] */

#define PIF_HEADER_SET_ipv6_inner___dst_addr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dst_addr_2 = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.dst_addr[32;32] */

#define PIF_HEADER_GET_ipv6_inner___dst_addr___2(_hdr_p) (((_hdr_p)->__dst_addr_1)) /* ipv6_inner.dst_addr [32;64] */

#define PIF_HEADER_SET_ipv6_inner___dst_addr___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dst_addr_1 = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.dst_addr[32;64] */

#define PIF_HEADER_GET_ipv6_inner___dst_addr___3(_hdr_p) (((_hdr_p)->dst_addr)) /* ipv6_inner.dst_addr [32;96] */

#define PIF_HEADER_SET_ipv6_inner___dst_addr___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_addr = (unsigned)(((_val))); \
    } while (0) /* ipv6_inner.dst_addr[32;96] */


/* pdu_container (3B) */
struct pif_header_pdu_container {
    unsigned int pdu_type:4;
    unsigned int spare:5;
    unsigned int rqi:1;
    unsigned int qosid:6;
    unsigned int padding:8;
};

/* pdu_container field accessor macros */
#define PIF_HEADER_GET_pdu_container___pdu_type(_hdr_p) (((_hdr_p)->pdu_type)) /* pdu_container.pdu_type [4;0] */

#define PIF_HEADER_SET_pdu_container___pdu_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->pdu_type = (unsigned)(((_val))); \
    } while (0) /* pdu_container.pdu_type[4;0] */

#define PIF_HEADER_GET_pdu_container___spare(_hdr_p) (((_hdr_p)->spare)) /* pdu_container.spare [5;0] */

#define PIF_HEADER_SET_pdu_container___spare(_hdr_p, _val) \
    do { \
        (_hdr_p)->spare = (unsigned)(((_val))); \
    } while (0) /* pdu_container.spare[5;0] */

#define PIF_HEADER_GET_pdu_container___rqi(_hdr_p) (((_hdr_p)->rqi)) /* pdu_container.rqi [1;0] */

#define PIF_HEADER_SET_pdu_container___rqi(_hdr_p, _val) \
    do { \
        (_hdr_p)->rqi = (unsigned)(((_val))); \
    } while (0) /* pdu_container.rqi[1;0] */

#define PIF_HEADER_GET_pdu_container___qosid(_hdr_p) (((_hdr_p)->qosid)) /* pdu_container.qosid [6;0] */

#define PIF_HEADER_SET_pdu_container___qosid(_hdr_p, _val) \
    do { \
        (_hdr_p)->qosid = (unsigned)(((_val))); \
    } while (0) /* pdu_container.qosid[6;0] */

#define PIF_HEADER_GET_pdu_container___padding(_hdr_p) (((_hdr_p)->padding)) /* pdu_container.padding [8;0] */

#define PIF_HEADER_SET_pdu_container___padding(_hdr_p, _val) \
    do { \
        (_hdr_p)->padding = (unsigned)(((_val))); \
    } while (0) /* pdu_container.padding[8;0] */


/* gtp (8B) */
struct pif_header_gtp {
    unsigned int version_field_id:3;
    unsigned int proto_type_id:1;
    unsigned int spare:1;
    unsigned int extension_header_flag_id:1;
    unsigned int sequence_number_flag_id:1;
    unsigned int npdu_number_flag_id:1;
    unsigned int msgtype:8;
    unsigned int msglen:16;
    unsigned int teid:32;
};

/* gtp field accessor macros */
#define PIF_HEADER_GET_gtp___version_field_id(_hdr_p) (((_hdr_p)->version_field_id)) /* gtp.version_field_id [3;0] */

#define PIF_HEADER_SET_gtp___version_field_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->version_field_id = (unsigned)(((_val))); \
    } while (0) /* gtp.version_field_id[3;0] */

#define PIF_HEADER_GET_gtp___proto_type_id(_hdr_p) (((_hdr_p)->proto_type_id)) /* gtp.proto_type_id [1;0] */

#define PIF_HEADER_SET_gtp___proto_type_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->proto_type_id = (unsigned)(((_val))); \
    } while (0) /* gtp.proto_type_id[1;0] */

#define PIF_HEADER_GET_gtp___spare(_hdr_p) (((_hdr_p)->spare)) /* gtp.spare [1;0] */

#define PIF_HEADER_SET_gtp___spare(_hdr_p, _val) \
    do { \
        (_hdr_p)->spare = (unsigned)(((_val))); \
    } while (0) /* gtp.spare[1;0] */

#define PIF_HEADER_GET_gtp___extension_header_flag_id(_hdr_p) (((_hdr_p)->extension_header_flag_id)) /* gtp.extension_header_flag_id [1;0] */

#define PIF_HEADER_SET_gtp___extension_header_flag_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->extension_header_flag_id = (unsigned)(((_val))); \
    } while (0) /* gtp.extension_header_flag_id[1;0] */

#define PIF_HEADER_GET_gtp___sequence_number_flag_id(_hdr_p) (((_hdr_p)->sequence_number_flag_id)) /* gtp.sequence_number_flag_id [1;0] */

#define PIF_HEADER_SET_gtp___sequence_number_flag_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->sequence_number_flag_id = (unsigned)(((_val))); \
    } while (0) /* gtp.sequence_number_flag_id[1;0] */

#define PIF_HEADER_GET_gtp___npdu_number_flag_id(_hdr_p) (((_hdr_p)->npdu_number_flag_id)) /* gtp.npdu_number_flag_id [1;0] */

#define PIF_HEADER_SET_gtp___npdu_number_flag_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->npdu_number_flag_id = (unsigned)(((_val))); \
    } while (0) /* gtp.npdu_number_flag_id[1;0] */

#define PIF_HEADER_GET_gtp___msgtype(_hdr_p) (((_hdr_p)->msgtype)) /* gtp.msgtype [8;0] */

#define PIF_HEADER_SET_gtp___msgtype(_hdr_p, _val) \
    do { \
        (_hdr_p)->msgtype = (unsigned)(((_val))); \
    } while (0) /* gtp.msgtype[8;0] */

#define PIF_HEADER_GET_gtp___msglen(_hdr_p) (((_hdr_p)->msglen)) /* gtp.msglen [16;0] */

#define PIF_HEADER_SET_gtp___msglen(_hdr_p, _val) \
    do { \
        (_hdr_p)->msglen = (unsigned)(((_val))); \
    } while (0) /* gtp.msglen[16;0] */

#define PIF_HEADER_GET_gtp___teid(_hdr_p) (((_hdr_p)->teid)) /* gtp.teid [32;0] */

#define PIF_HEADER_SET_gtp___teid(_hdr_p, _val) \
    do { \
        (_hdr_p)->teid = (unsigned)(((_val))); \
    } while (0) /* gtp.teid[32;0] */


/* srv6 (8B) */
struct pif_header_srv6 {
    unsigned int next_hdr:8;
    unsigned int hdr_ext_len:8;
    unsigned int routing_type:8;
    unsigned int segment_left:8;
    unsigned int last_entry:8;
    unsigned int flags:8;
    unsigned int tag:16;
};

/* srv6 field accessor macros */
#define PIF_HEADER_GET_srv6___next_hdr(_hdr_p) (((_hdr_p)->next_hdr)) /* srv6.next_hdr [8;0] */

#define PIF_HEADER_SET_srv6___next_hdr(_hdr_p, _val) \
    do { \
        (_hdr_p)->next_hdr = (unsigned)(((_val))); \
    } while (0) /* srv6.next_hdr[8;0] */

#define PIF_HEADER_GET_srv6___hdr_ext_len(_hdr_p) (((_hdr_p)->hdr_ext_len)) /* srv6.hdr_ext_len [8;0] */

#define PIF_HEADER_SET_srv6___hdr_ext_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->hdr_ext_len = (unsigned)(((_val))); \
    } while (0) /* srv6.hdr_ext_len[8;0] */

#define PIF_HEADER_GET_srv6___routing_type(_hdr_p) (((_hdr_p)->routing_type)) /* srv6.routing_type [8;0] */

#define PIF_HEADER_SET_srv6___routing_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->routing_type = (unsigned)(((_val))); \
    } while (0) /* srv6.routing_type[8;0] */

#define PIF_HEADER_GET_srv6___segment_left(_hdr_p) (((_hdr_p)->segment_left)) /* srv6.segment_left [8;0] */

#define PIF_HEADER_SET_srv6___segment_left(_hdr_p, _val) \
    do { \
        (_hdr_p)->segment_left = (unsigned)(((_val))); \
    } while (0) /* srv6.segment_left[8;0] */

#define PIF_HEADER_GET_srv6___last_entry(_hdr_p) (((_hdr_p)->last_entry)) /* srv6.last_entry [8;0] */

#define PIF_HEADER_SET_srv6___last_entry(_hdr_p, _val) \
    do { \
        (_hdr_p)->last_entry = (unsigned)(((_val))); \
    } while (0) /* srv6.last_entry[8;0] */

#define PIF_HEADER_GET_srv6___flags(_hdr_p) (((_hdr_p)->flags)) /* srv6.flags [8;0] */

#define PIF_HEADER_SET_srv6___flags(_hdr_p, _val) \
    do { \
        (_hdr_p)->flags = (unsigned)(((_val))); \
    } while (0) /* srv6.flags[8;0] */

#define PIF_HEADER_GET_srv6___tag(_hdr_p) (((_hdr_p)->tag)) /* srv6.tag [16;0] */

#define PIF_HEADER_SET_srv6___tag(_hdr_p, _val) \
    do { \
        (_hdr_p)->tag = (unsigned)(((_val))); \
    } while (0) /* srv6.tag[16;0] */


/* ethernet (14B) */
struct pif_header_ethernet {
    /* dstAddr [32;16] */
    unsigned int dstAddr:32;
    /* dstAddr [16;0] */
    unsigned int __dstAddr_1:16;
    /* srcAddr [16;32] */
    unsigned int srcAddr:16;
    /* srcAddr [32;0] */
    unsigned int __srcAddr_1:32;
    unsigned int etherType:16;
};

/* ethernet field accessor macros */
#define PIF_HEADER_GET_ethernet___dstAddr___0(_hdr_p) ((((_hdr_p)->dstAddr & 0xffff) << 16) | ((_hdr_p)->__dstAddr_1)) /* ethernet.dstAddr [32;0] */

#define PIF_HEADER_SET_ethernet___dstAddr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstAddr &= (unsigned)(0xffff0000); \
        (_hdr_p)->dstAddr |= (unsigned)((((_val) >> 16) & 0xffff)); \
        (_hdr_p)->__dstAddr_1 = (unsigned)(((_val))); \
    } while (0) /* ethernet.dstAddr[32;0] */

#define PIF_HEADER_GET_ethernet___dstAddr___1(_hdr_p) ((((_hdr_p)->dstAddr >> 16) & 0xffff)) /* ethernet.dstAddr [16;32] */

#define PIF_HEADER_SET_ethernet___dstAddr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstAddr &= (unsigned)(0xffff); \
        (_hdr_p)->dstAddr |= (unsigned)((((_val) & 0xffff) << 16)); \
    } while (0) /* ethernet.dstAddr[16;32] */

#define PIF_HEADER_GET_ethernet___srcAddr___0(_hdr_p) (((_hdr_p)->__srcAddr_1)) /* ethernet.srcAddr [32;0] */

#define PIF_HEADER_SET_ethernet___srcAddr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__srcAddr_1 = (unsigned)(((_val))); \
    } while (0) /* ethernet.srcAddr[32;0] */

#define PIF_HEADER_GET_ethernet___srcAddr___1(_hdr_p) (((_hdr_p)->srcAddr)) /* ethernet.srcAddr [16;32] */

#define PIF_HEADER_SET_ethernet___srcAddr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcAddr = (unsigned)(((_val))); \
    } while (0) /* ethernet.srcAddr[16;32] */

#define PIF_HEADER_GET_ethernet___etherType(_hdr_p) (((_hdr_p)->etherType)) /* ethernet.etherType [16;0] */

#define PIF_HEADER_SET_ethernet___etherType(_hdr_p, _val) \
    do { \
        (_hdr_p)->etherType = (unsigned)(((_val))); \
    } while (0) /* ethernet.etherType[16;0] */


/*
 * Metadata
 */

/* standard_metadata (16B) */
struct pif_header_standard_metadata {
    unsigned int clone_spec:32;
    unsigned int egress_spec:16;
    unsigned int egress_port:16;
    unsigned int ingress_port:16;
    unsigned int packet_length:14;
    unsigned int checksum_error:1;
    unsigned int _padding_0:1;
    unsigned int egress_instance:10;
    unsigned int parser_error_location:8;
    unsigned int instance_type:4;
    unsigned int parser_status:3;
    unsigned int _padding_1:7;
};

/* standard_metadata field accessor macros */
#define PIF_HEADER_GET_standard_metadata___clone_spec(_hdr_p) (((_hdr_p)->clone_spec)) /* standard_metadata.clone_spec [32;0] */

#define PIF_HEADER_SET_standard_metadata___clone_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->clone_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.clone_spec[32;0] */

#define PIF_HEADER_GET_standard_metadata___egress_spec(_hdr_p) (((_hdr_p)->egress_spec)) /* standard_metadata.egress_spec [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_spec[16;0] */

#define PIF_HEADER_GET_standard_metadata___egress_port(_hdr_p) (((_hdr_p)->egress_port)) /* standard_metadata.egress_port [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_port[16;0] */

#define PIF_HEADER_GET_standard_metadata___ingress_port(_hdr_p) (((_hdr_p)->ingress_port)) /* standard_metadata.ingress_port [16;0] */

#define PIF_HEADER_SET_standard_metadata___ingress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->ingress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.ingress_port[16;0] */

#define PIF_HEADER_GET_standard_metadata___packet_length(_hdr_p) (((_hdr_p)->packet_length)) /* standard_metadata.packet_length [14;0] */

#define PIF_HEADER_SET_standard_metadata___packet_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->packet_length = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.packet_length[14;0] */

#define PIF_HEADER_GET_standard_metadata___checksum_error(_hdr_p) (((_hdr_p)->checksum_error)) /* standard_metadata.checksum_error [1;0] */

#define PIF_HEADER_SET_standard_metadata___checksum_error(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum_error = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.checksum_error[1;0] */

#define PIF_HEADER_GET_standard_metadata____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* standard_metadata._padding_0 [1;0] */

#define PIF_HEADER_SET_standard_metadata____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* standard_metadata._padding_0[1;0] */

#define PIF_HEADER_GET_standard_metadata___egress_instance(_hdr_p) (((_hdr_p)->egress_instance)) /* standard_metadata.egress_instance [10;0] */

#define PIF_HEADER_SET_standard_metadata___egress_instance(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_instance = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_instance[10;0] */

#define PIF_HEADER_GET_standard_metadata___parser_error_location(_hdr_p) (((_hdr_p)->parser_error_location)) /* standard_metadata.parser_error_location [8;0] */

#define PIF_HEADER_SET_standard_metadata___parser_error_location(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_error_location = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_error_location[8;0] */

#define PIF_HEADER_GET_standard_metadata___instance_type(_hdr_p) (((_hdr_p)->instance_type)) /* standard_metadata.instance_type [4;0] */

#define PIF_HEADER_SET_standard_metadata___instance_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->instance_type = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.instance_type[4;0] */

#define PIF_HEADER_GET_standard_metadata___parser_status(_hdr_p) (((_hdr_p)->parser_status)) /* standard_metadata.parser_status [3;0] */

#define PIF_HEADER_SET_standard_metadata___parser_status(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_status = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_status[3;0] */

#define PIF_HEADER_GET_standard_metadata____padding_1(_hdr_p) (((_hdr_p)->_padding_1)) /* standard_metadata._padding_1 [7;0] */

#define PIF_HEADER_SET_standard_metadata____padding_1(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_1 = (unsigned)(((_val))); \
    } while (0) /* standard_metadata._padding_1[7;0] */


/* scalars (16B) */
struct pif_header_scalars {
    /* metadata@next_srv6_sid [32;96] */
    unsigned int metadata__next_srv6_sid:32;
    /* metadata@next_srv6_sid [32;64] */
    unsigned int __metadata__next_srv6_sid_1:32;
    /* metadata@next_srv6_sid [32;32] */
    unsigned int __metadata__next_srv6_sid_2:32;
    /* metadata@next_srv6_sid [32;0] */
    unsigned int __metadata__next_srv6_sid_3:32;
};

/* scalars field accessor macros */
#define PIF_HEADER_GET_scalars___metadata__next_srv6_sid___0(_hdr_p) (((_hdr_p)->__metadata__next_srv6_sid_3)) /* scalars.metadata__next_srv6_sid [32;0] */

#define PIF_HEADER_SET_scalars___metadata__next_srv6_sid___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__metadata__next_srv6_sid_3 = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata__next_srv6_sid[32;0] */

#define PIF_HEADER_GET_scalars___metadata__next_srv6_sid___1(_hdr_p) (((_hdr_p)->__metadata__next_srv6_sid_2)) /* scalars.metadata__next_srv6_sid [32;32] */

#define PIF_HEADER_SET_scalars___metadata__next_srv6_sid___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__metadata__next_srv6_sid_2 = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata__next_srv6_sid[32;32] */

#define PIF_HEADER_GET_scalars___metadata__next_srv6_sid___2(_hdr_p) (((_hdr_p)->__metadata__next_srv6_sid_1)) /* scalars.metadata__next_srv6_sid [32;64] */

#define PIF_HEADER_SET_scalars___metadata__next_srv6_sid___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__metadata__next_srv6_sid_1 = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata__next_srv6_sid[32;64] */

#define PIF_HEADER_GET_scalars___metadata__next_srv6_sid___3(_hdr_p) (((_hdr_p)->metadata__next_srv6_sid)) /* scalars.metadata__next_srv6_sid [32;96] */

#define PIF_HEADER_SET_scalars___metadata__next_srv6_sid___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata__next_srv6_sid = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata__next_srv6_sid[32;96] */



/*
 * Registers
 */

#endif /* __PIF_HEADERS_H__ */

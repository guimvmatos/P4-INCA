/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_IPV6_INNER_H__
#define __PIF_PLUGIN_IPV6_INNER_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* ipv6_inner (40B) */
struct pif_plugin_ipv6_inner {
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



#define PIF_PLUGIN_ipv6_inner_T __lmem struct pif_plugin_ipv6_inner

/*
 * Access function prototypes
 */

int pif_plugin_hdr_ipv6_inner_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_ipv6_inner_T *pif_plugin_hdr_get_ipv6_inner(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_ipv6_inner_T *pif_plugin_hdr_readonly_get_ipv6_inner(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_ipv6_inner_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_ipv6_inner_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_ipv6_inner_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_ipv6_inner_VALID(_ctl);
}

__forceinline PIF_PLUGIN_ipv6_inner_T *pif_plugin_hdr_get_ipv6_inner(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_ipv6_inner_DIRTY(_ctl);
    return (PIF_PLUGIN_ipv6_inner_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_ipv6_inner_OFF_LW);
}

__forceinline PIF_PLUGIN_ipv6_inner_T *pif_plugin_hdr_readonly_get_ipv6_inner(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_ipv6_inner_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_ipv6_inner_OFF_LW);
}

__forceinline int pif_plugin_hdr_ipv6_inner_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_ipv6_inner_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_IPV6_INNER_H__ */

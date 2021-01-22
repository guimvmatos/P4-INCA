/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_TCP_INNER_H__
#define __PIF_PLUGIN_TCP_INNER_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* tcp_inner (20B) */
struct pif_plugin_tcp_inner {
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



#define PIF_PLUGIN_tcp_inner_T __lmem struct pif_plugin_tcp_inner

/*
 * Access function prototypes
 */

int pif_plugin_hdr_tcp_inner_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_tcp_inner_T *pif_plugin_hdr_get_tcp_inner(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_tcp_inner_T *pif_plugin_hdr_readonly_get_tcp_inner(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_tcp_inner_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_tcp_inner_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_tcp_inner_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_tcp_inner_VALID(_ctl);
}

__forceinline PIF_PLUGIN_tcp_inner_T *pif_plugin_hdr_get_tcp_inner(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_tcp_inner_DIRTY(_ctl);
    return (PIF_PLUGIN_tcp_inner_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_tcp_inner_OFF_LW);
}

__forceinline PIF_PLUGIN_tcp_inner_T *pif_plugin_hdr_readonly_get_tcp_inner(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_tcp_inner_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_tcp_inner_OFF_LW);
}

__forceinline int pif_plugin_hdr_tcp_inner_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_tcp_inner_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_TCP_INNER_H__ */

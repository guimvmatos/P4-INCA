/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_UDP_INNER_H__
#define __PIF_PLUGIN_UDP_INNER_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* udp_inner (8B) */
struct pif_plugin_udp_inner {
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



#define PIF_PLUGIN_udp_inner_T __lmem struct pif_plugin_udp_inner

/*
 * Access function prototypes
 */

int pif_plugin_hdr_udp_inner_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_udp_inner_T *pif_plugin_hdr_get_udp_inner(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_udp_inner_T *pif_plugin_hdr_readonly_get_udp_inner(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_udp_inner_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_udp_inner_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_udp_inner_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_udp_inner_VALID(_ctl);
}

__forceinline PIF_PLUGIN_udp_inner_T *pif_plugin_hdr_get_udp_inner(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_udp_inner_DIRTY(_ctl);
    return (PIF_PLUGIN_udp_inner_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_udp_inner_OFF_LW);
}

__forceinline PIF_PLUGIN_udp_inner_T *pif_plugin_hdr_readonly_get_udp_inner(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_udp_inner_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_udp_inner_OFF_LW);
}

__forceinline int pif_plugin_hdr_udp_inner_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_udp_inner_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_UDP_INNER_H__ */

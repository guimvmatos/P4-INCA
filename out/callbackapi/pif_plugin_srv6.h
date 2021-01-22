/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_SRV6_H__
#define __PIF_PLUGIN_SRV6_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* srv6 (8B) */
struct pif_plugin_srv6 {
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



#define PIF_PLUGIN_srv6_T __lmem struct pif_plugin_srv6

/*
 * Access function prototypes
 */

int pif_plugin_hdr_srv6_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_srv6_T *pif_plugin_hdr_get_srv6(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_srv6_T *pif_plugin_hdr_readonly_get_srv6(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_srv6_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_srv6_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_srv6_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_srv6_VALID(_ctl);
}

__forceinline PIF_PLUGIN_srv6_T *pif_plugin_hdr_get_srv6(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_srv6_DIRTY(_ctl);
    return (PIF_PLUGIN_srv6_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_srv6_OFF_LW);
}

__forceinline PIF_PLUGIN_srv6_T *pif_plugin_hdr_readonly_get_srv6(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_srv6_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_srv6_OFF_LW);
}

__forceinline int pif_plugin_hdr_srv6_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T7_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_srv6_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_srv6_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_SRV6_H__ */

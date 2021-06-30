/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_SRV6_LIST_H__
#define __PIF_PLUGIN_SRV6_LIST_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* srv6_list (16B) */
struct pif_plugin_srv6_list {
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



#define PIF_PLUGIN_srv6_list_T __lmem struct pif_plugin_srv6_list

/*
 * Access function prototypes
 */

int pif_plugin_hdr_srv6_list_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_srv6_list_T *pif_plugin_hdr_get_srv6_list(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_srv6_list_T *pif_plugin_hdr_readonly_get_srv6_list(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_srv6_list_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_srv6_list_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_srv6_list_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_srv6_list_VALID(_ctl);
}

__forceinline PIF_PLUGIN_srv6_list_T *pif_plugin_hdr_get_srv6_list(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_srv6_list_DIRTY(_ctl);
    return (PIF_PLUGIN_srv6_list_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_srv6_list_OFF_LW);
}

__forceinline PIF_PLUGIN_srv6_list_T *pif_plugin_hdr_readonly_get_srv6_list(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_srv6_list_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_srv6_list_OFF_LW);
}

__forceinline int pif_plugin_hdr_srv6_list_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T8_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_srv6_list_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_srv6_list_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_SRV6_LIST_H__ */

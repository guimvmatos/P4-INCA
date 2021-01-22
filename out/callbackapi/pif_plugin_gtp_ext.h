/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_GTP_EXT_H__
#define __PIF_PLUGIN_GTP_EXT_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* gtp_ext (1B) */
struct pif_plugin_gtp_ext {
    unsigned int next_extension:8;
};

/* gtp_ext field accessor macros */
#define PIF_HEADER_GET_gtp_ext___next_extension(_hdr_p) (((_hdr_p)->next_extension)) /* gtp_ext.next_extension [8;0] */

#define PIF_HEADER_SET_gtp_ext___next_extension(_hdr_p, _val) \
    do { \
        (_hdr_p)->next_extension = (unsigned)(((_val))); \
    } while (0) /* gtp_ext.next_extension[8;0] */



#define PIF_PLUGIN_gtp_ext_T __lmem struct pif_plugin_gtp_ext

/*
 * Access function prototypes
 */

int pif_plugin_hdr_gtp_ext_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtp_ext_T *pif_plugin_hdr_get_gtp_ext(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtp_ext_T *pif_plugin_hdr_readonly_get_gtp_ext(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtp_ext_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtp_ext_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_gtp_ext_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_gtp_ext_VALID(_ctl);
}

__forceinline PIF_PLUGIN_gtp_ext_T *pif_plugin_hdr_get_gtp_ext(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_gtp_ext_DIRTY(_ctl);
    return (PIF_PLUGIN_gtp_ext_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtp_ext_OFF_LW);
}

__forceinline PIF_PLUGIN_gtp_ext_T *pif_plugin_hdr_readonly_get_gtp_ext(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_gtp_ext_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtp_ext_OFF_LW);
}

__forceinline int pif_plugin_hdr_gtp_ext_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_gtp_ext_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_GTP_EXT_H__ */

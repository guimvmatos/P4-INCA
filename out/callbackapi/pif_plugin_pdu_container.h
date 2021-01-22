/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_PDU_CONTAINER_H__
#define __PIF_PLUGIN_PDU_CONTAINER_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* pdu_container (3B) */
struct pif_plugin_pdu_container {
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



#define PIF_PLUGIN_pdu_container_T __lmem struct pif_plugin_pdu_container

/*
 * Access function prototypes
 */

int pif_plugin_hdr_pdu_container_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_pdu_container_T *pif_plugin_hdr_get_pdu_container(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_pdu_container_T *pif_plugin_hdr_readonly_get_pdu_container(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_pdu_container_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_pdu_container_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_pdu_container_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_pdu_container_VALID(_ctl);
}

__forceinline PIF_PLUGIN_pdu_container_T *pif_plugin_hdr_get_pdu_container(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_pdu_container_DIRTY(_ctl);
    return (PIF_PLUGIN_pdu_container_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_pdu_container_OFF_LW);
}

__forceinline PIF_PLUGIN_pdu_container_T *pif_plugin_hdr_readonly_get_pdu_container(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_pdu_container_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_pdu_container_OFF_LW);
}

__forceinline int pif_plugin_hdr_pdu_container_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_pdu_container_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_PDU_CONTAINER_H__ */

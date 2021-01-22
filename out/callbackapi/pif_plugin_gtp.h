/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_GTP_H__
#define __PIF_PLUGIN_GTP_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* gtp (8B) */
struct pif_plugin_gtp {
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



#define PIF_PLUGIN_gtp_T __lmem struct pif_plugin_gtp

/*
 * Access function prototypes
 */

int pif_plugin_hdr_gtp_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtp_T *pif_plugin_hdr_get_gtp(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtp_T *pif_plugin_hdr_readonly_get_gtp(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtp_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtp_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_gtp_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_gtp_VALID(_ctl);
}

__forceinline PIF_PLUGIN_gtp_T *pif_plugin_hdr_get_gtp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_gtp_DIRTY(_ctl);
    return (PIF_PLUGIN_gtp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtp_OFF_LW);
}

__forceinline PIF_PLUGIN_gtp_T *pif_plugin_hdr_readonly_get_gtp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_gtp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtp_OFF_LW);
}

__forceinline int pif_plugin_hdr_gtp_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_gtp_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_GTP_H__ */

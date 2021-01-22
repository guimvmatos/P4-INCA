/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/me.h>
#include <hashmap.h>
#include "pif_common.h"

extern __forceinline
pif_parrep_extract(__lmem uint32_t *_pif_parrep, __mem __addr40 uint8_t *_pif_parrep_pktdata, unsigned int _pif_parrep_pktlen, __lmem uint32_t *_pif_parrep_fk_ptr, __gpr uint32_t *_pif_parrep_fk_len)
{
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    PIF_PKT_INFO_TYPE struct pif_pkt_info *pkt_info = &pif_pkt_info_global;
    __xread uint32_t _pif_read_xbuf[24];
    unsigned int _pif_read_xbuf_off = 2;
    __gpr unsigned int _pif_parrep_pktoff = -2;
    unsigned int _pif_t_index;
    __gpr int _pif_parrep_state = 0;
    __gpr int _pif_parrep_error = 0;
    int i;

    /* First zero the parsed representation control data fields */
    for (i = 0; i < PIF_PARREP_CTLDATA_LEN_LW; i++)
        _pif_parrep[PIF_PARREP_CTLDATA_OFF_LW + i] = 0;

    _pif_parrep_pktdata -= _pif_read_xbuf_off;
    mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
    _pif_t_index = ((__ctx() << 5) | __xfer_reg_number(_pif_read_xbuf)) << 2;
__label_start:
    { /* implementation of parse node start */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_ethernet *ethernet;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_start");
#endif

        ethernet = (__lmem struct pif_header_ethernet *) (_pif_parrep + PIF_PARREP_ethernet_OFF_LW);
        {
            /* extract(ethernet) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_ethernet_LEN_LW;
                    sizeB = PIF_PARREP_ethernet_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_ethernet_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_ethernet_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_start;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_ethernet_VALID(_pif_ctldata);
                PIF_PARREP_SET_ethernet_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        if (((ethernet->etherType) == (0x86dd))) {
            __critical_path(); /* prioritize the fall through */
        } else {
            _pif_parrep_error = PIF_PARSE_ERROR_UNHANDLED_SELECT;
            goto _pif_parrep_label_error;
        }
    } /* end of implementation of parse node start */
__label_parse_ipv6_outer:
    { /* implementation of parse node parse_ipv6_outer */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_ipv6_outer *ipv6_outer;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_ipv6_outer");
#endif

        ipv6_outer = (__lmem struct pif_header_ipv6_outer *) (_pif_parrep + PIF_PARREP_ipv6_outer_OFF_LW);
        {
            /* extract(ipv6_outer) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_ipv6_outer_LEN_LW;
                    sizeB = PIF_PARREP_ipv6_outer_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_ipv6_outer_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 4 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 5 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 6 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 7 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 8 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 9 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_ipv6_outer_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_ipv6_outer;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_ipv6_outer_VALID(_pif_ctldata);
                PIF_PARREP_SET_ipv6_outer_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_ipv6_outer *_pif_fk = (__lmem struct pif_global_flowkey_ipv6_outer *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->ipv6_outer__dst_addr = ipv6_outer->dst_addr;
            _pif_fk->ipv6_outer____dst_addr_1 = ipv6_outer->__dst_addr_1;
            _pif_fk->ipv6_outer____dst_addr_2 = ipv6_outer->__dst_addr_2;
            _pif_fk->ipv6_outer____dst_addr_3 = ipv6_outer->__dst_addr_3;
            (*_pif_parrep_fk_len) += 4;
        }
#endif
        if (((ipv6_outer->next_hdr) == (0x11))) {
            __critical_path(); /* prioritize the fall through */
        } else if (((ipv6_outer->next_hdr) == (0x2b))) {
            goto __label_parse_srv6;
        } else {
            goto _pif_parrep_label_exit;
        }
    } /* end of implementation of parse node parse_ipv6_outer */
__label_parse_udp:
    { /* implementation of parse node parse_udp */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_udp *udp;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_udp");
#endif

        udp = (__lmem struct pif_header_udp *) (_pif_parrep + PIF_PARREP_udp_OFF_LW);
        {
            /* extract(udp) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_udp_LEN_LW;
                    sizeB = PIF_PARREP_udp_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_udp_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_udp_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_udp;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_udp_VALID(_pif_ctldata);
                PIF_PARREP_SET_udp_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        if (((udp->dport) == (0x868))) {
            __critical_path(); /* prioritize the fall through */
        } else {
            _pif_parrep_error = PIF_PARSE_ERROR_UNHANDLED_SELECT;
            goto _pif_parrep_label_error;
        }
    } /* end of implementation of parse node parse_udp */
__label_parse_gtp:
    { /* implementation of parse node parse_gtp */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_gtp *gtp;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_gtp");
#endif

        gtp = (__lmem struct pif_header_gtp *) (_pif_parrep + PIF_PARREP_gtp_OFF_LW);
        {
            /* extract(gtp) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_gtp_LEN_LW;
                    sizeB = PIF_PARREP_gtp_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_gtp_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_gtp_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_gtp;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_gtp_VALID(_pif_ctldata);
                PIF_PARREP_SET_gtp_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_gtp *_pif_fk = (__lmem struct pif_global_flowkey_gtp *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->gtp__spare = gtp->spare;
            _pif_fk->gtp__teid = gtp->teid;
            _pif_fk->__padding = 0;
            (*_pif_parrep_fk_len) += 2;
        }
#endif
        if (((gtp->extension_header_flag_id) == (0x1))) {
            __critical_path(); /* prioritize the fall through */
        } else if (((gtp->extension_header_flag_id) == (0x0))) {
            goto __label_parse_ipv6_inner;
        } else {
            _pif_parrep_error = PIF_PARSE_ERROR_UNHANDLED_SELECT;
            goto _pif_parrep_label_error;
        }
    } /* end of implementation of parse node parse_gtp */
__label_parse_gtp_ext:
    { /* implementation of parse node parse_gtp_ext */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_gtp_ext *gtp_ext;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_gtp_ext");
#endif

        gtp_ext = (__lmem struct pif_header_gtp_ext *) (_pif_parrep + PIF_PARREP_gtp_ext_OFF_LW);
        {
            /* extract(gtp_ext) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_gtp_ext_LEN_LW;
                    sizeB = PIF_PARREP_gtp_ext_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_gtp_ext_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 1 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_gtp_ext_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_gtp_ext;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_gtp_ext_VALID(_pif_ctldata);
                PIF_PARREP_SET_gtp_ext_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        if (((gtp_ext->next_extension) == (0x85))) {
            __critical_path(); /* prioritize the fall through */
        } else {
            _pif_parrep_error = PIF_PARSE_ERROR_UNHANDLED_SELECT;
            goto _pif_parrep_label_error;
        }
    } /* end of implementation of parse node parse_gtp_ext */
__label_parse_pdu_container:
    { /* implementation of parse node parse_pdu_container */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_pdu_container *pdu_container;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_pdu_container");
#endif

        pdu_container = (__lmem struct pif_header_pdu_container *) (_pif_parrep + PIF_PARREP_pdu_container_OFF_LW);
        {
            /* extract(pdu_container) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_pdu_container_LEN_LW;
                    sizeB = PIF_PARREP_pdu_container_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_pdu_container_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 1 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_pdu_container_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_pdu_container;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_pdu_container_VALID(_pif_ctldata);
                PIF_PARREP_SET_pdu_container_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_pdu_container *_pif_fk = (__lmem struct pif_global_flowkey_pdu_container *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->pdu_container__qosid = pdu_container->qosid;
            _pif_fk->__padding = 0;
            (*_pif_parrep_fk_len) += 1;
        }
#endif
        __critical_path(); /* prioritize the fall through */
    } /* end of implementation of parse node parse_pdu_container */
__label_parse_ipv6_inner:
    { /* implementation of parse node parse_ipv6_inner */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_ipv6_inner *ipv6_inner;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_ipv6_inner");
#endif

        ipv6_inner = (__lmem struct pif_header_ipv6_inner *) (_pif_parrep + PIF_PARREP_ipv6_inner_OFF_LW);
        {
            /* extract(ipv6_inner) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_ipv6_inner_LEN_LW;
                    sizeB = PIF_PARREP_ipv6_inner_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_ipv6_inner_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 4 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 5 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 6 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 7 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 8 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 9 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_ipv6_inner_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_ipv6_inner;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_ipv6_inner_VALID(_pif_ctldata);
                PIF_PARREP_SET_ipv6_inner_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_ipv6_inner *_pif_fk = (__lmem struct pif_global_flowkey_ipv6_inner *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->ipv6_inner__next_hdr = ipv6_inner->next_hdr;
            _pif_fk->ipv6_inner__src_addr = ipv6_inner->src_addr;
            _pif_fk->ipv6_inner____src_addr_1 = ipv6_inner->__src_addr_1;
            _pif_fk->ipv6_inner____src_addr_2 = ipv6_inner->__src_addr_2;
            _pif_fk->ipv6_inner____src_addr_3 = ipv6_inner->__src_addr_3;
            _pif_fk->ipv6_inner__dst_addr = ipv6_inner->dst_addr;
            _pif_fk->ipv6_inner____dst_addr_1 = ipv6_inner->__dst_addr_1;
            _pif_fk->ipv6_inner____dst_addr_2 = ipv6_inner->__dst_addr_2;
            _pif_fk->ipv6_inner____dst_addr_3 = ipv6_inner->__dst_addr_3;
            _pif_fk->__padding = 0;
            (*_pif_parrep_fk_len) += 9;
        }
#endif
        if (((ipv6_inner->next_hdr) == (0x11))) {
            __critical_path(); /* prioritize the fall through */
        } else if (((ipv6_inner->next_hdr) == (0x6))) {
            goto __label_parse_tcp_inner;
        } else {
            goto _pif_parrep_label_exit;
        }
    } /* end of implementation of parse node parse_ipv6_inner */
__label_parse_udp_inner:
    { /* implementation of parse node parse_udp_inner */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_udp_inner *udp_inner;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_udp_inner");
#endif

        udp_inner = (__lmem struct pif_header_udp_inner *) (_pif_parrep + PIF_PARREP_udp_inner_OFF_LW);
        {
            /* extract(udp_inner) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_udp_inner_LEN_LW;
                    sizeB = PIF_PARREP_udp_inner_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_udp_inner_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_udp_inner_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_udp_inner;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_udp_inner_VALID(_pif_ctldata);
                PIF_PARREP_SET_udp_inner_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_udp_inner *_pif_fk = (__lmem struct pif_global_flowkey_udp_inner *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->udp_inner__dport = udp_inner->dport;
            _pif_fk->udp_inner__sport = udp_inner->sport;
            (*_pif_parrep_fk_len) += 1;
        }
#endif
        goto _pif_parrep_label_exit;
    } /* end of implementation of parse node parse_udp_inner */
__label_parse_srv6:
    { /* implementation of parse node parse_srv6 */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_srv6 *srv6;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_srv6");
#endif

        srv6 = (__lmem struct pif_header_srv6 *) (_pif_parrep + PIF_PARREP_srv6_OFF_LW);
        {
            /* extract(srv6) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_srv6_LEN_LW;
                    sizeB = PIF_PARREP_srv6_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_srv6_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_srv6_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_srv6;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_srv6_VALID(_pif_ctldata);
                PIF_PARREP_SET_srv6_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        goto _pif_parrep_label_exit;
    } /* end of implementation of parse node parse_srv6 */
__label_parse_tcp_inner:
    { /* implementation of parse node parse_tcp_inner */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_tcp_inner *tcp_inner;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_tcp_inner");
#endif

        tcp_inner = (__lmem struct pif_header_tcp_inner *) (_pif_parrep + PIF_PARREP_tcp_inner_OFF_LW);
        {
            /* extract(tcp_inner) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_tcp_inner_LEN_LW;
                    sizeB = PIF_PARREP_tcp_inner_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_tcp_inner_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 4 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_tcp_inner_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_tcp_inner;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_tcp_inner_VALID(_pif_ctldata);
                PIF_PARREP_SET_tcp_inner_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_tcp_inner *_pif_fk = (__lmem struct pif_global_flowkey_tcp_inner *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->tcp_inner__dstPort = tcp_inner->dstPort;
            _pif_fk->tcp_inner__srcPort = tcp_inner->srcPort;
            (*_pif_parrep_fk_len) += 1;
        }
#endif
        goto _pif_parrep_label_exit;
    } /* end of implementation of parse node parse_tcp_inner */
_pif_parrep_label_exit:
    pif_pkt_info_spec.pkt_pl_off = _pif_parrep_pktoff + _pif_read_xbuf_off;
    PIF_PARREP_SET_VALID(_pif_ctldata);
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
    _pif_parrep_fk_ptr[(*_pif_parrep_fk_len) + 0] = _pif_parrep[PIF_PARREP_CTLDATA_OFF_LW + 0] & 0x88209380;
    _pif_parrep_fk_ptr[(*_pif_parrep_fk_len) + 1] = _pif_parrep[PIF_PARREP_CTLDATA_OFF_LW + 1] & 0x0;
    (*_pif_parrep_fk_len) += PIF_PARREP_CTLDATA_LEN_LW;
#endif /* !PIF_GLOBAL_FLOWCACHE_DISABLED */
    return 0;
_pif_parrep_label_error:
    pif_pkt_info_spec.pkt_pl_off = _pif_parrep_pktoff + _pif_read_xbuf_off;
    pif_global_set_stdmd_parser_error_location(_pif_parrep, _pif_parrep_state);
    return -_pif_parrep_error;
}

extern __forceinline int
pif_parrep_exceptions(__lmem uint32_t *_pif_parrep, int _pif_pe_error, __lmem uint32_t *_pif_parrep_fk_ptr, __gpr uint32_t *_pif_parrep_fk_len)
{
    return -1; /* no exceptions, always fail */
}

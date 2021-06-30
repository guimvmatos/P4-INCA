/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/mem_atomic.h>
#include <nfp/mem_ring.h>
#include <nfp/me.h>
#include <nfp/cls.h>
#include "pif_common.h"
#include "pkt_clone.h"

#ifdef PIF_DEBUG
    __export __emem_n(0) uint64_t pif_act_stats[PIF_ACTION_ID_MAX + 1];
#endif

extern __nnr uint32_t calc_fld_bmsk;

#define BITRANGE(var, width, offset) \
    (((var) >> (offset)) & ((1 << (width)) - 1))


static int pif_action_exec_ingress__ipv6_forward(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__ipv6_forward *_pif_act_data = (__xread struct pif_action_actiondata_ingress__ipv6_forward *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_ethernet *ethernet;
    __lmem struct pif_header_standard_metadata *standard_metadata;
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__ipv6_forward");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__ipv6_forward");
#endif

    ethernet = (__lmem struct pif_header_ethernet *) (_pif_parrep + PIF_PARREP_ethernet_OFF_LW);
    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_PARREP_SET_ethernet_DIRTY(_pif_ctldata);

    {
        /* modify_field(standard_metadata.egress_spec,port) */

        /* primitive body */
        standard_metadata->egress_spec = _pif_act_data->port;

    }
    {
        /* modify_field(ethernet.srcAddr,ethernet.dstAddr) */

        /* primitive body */
        ethernet->srcAddr = ((ethernet->dstAddr >> 16) & 0xffff);
        ethernet->__srcAddr_1 = ((ethernet->dstAddr & 0xffff) << 16) | ethernet->__dstAddr_1;

    }
    {
        /* modify_field(ethernet.dstAddr,dstAddr) */

        /* primitive body */
        ethernet->dstAddr = _pif_act_data->dstAddr_1;
        ethernet->__dstAddr_1 = _pif_act_data->dstAddr_0;

    }
    return _pif_return;
}

static int pif_action_exec_ingress__srv6_t_insert_2(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__srv6_t_insert_2 *_pif_act_data = (__xread struct pif_action_actiondata_ingress__srv6_t_insert_2 *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_srv6_list *srv6_list___1;
    __lmem struct pif_header_srv6_list *srv6_list;
    __lmem struct pif_header_ipv6_outer *ipv6_outer;
    __lmem struct pif_header_srv6_list *srv6_list___0;
    __lmem struct pif_header_srv6 *srv6;
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__srv6_t_insert_2");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__srv6_t_insert_2");
#endif

    srv6_list___1 = (__lmem struct pif_header_srv6_list *) (_pif_parrep + PIF_PARREP_srv6_list_STACK_OFF_LW(1));
    srv6_list = (__lmem struct pif_header_srv6_list *) (_pif_parrep + PIF_PARREP_srv6_list_OFF_LW);
    ipv6_outer = (__lmem struct pif_header_ipv6_outer *) (_pif_parrep + PIF_PARREP_ipv6_outer_OFF_LW);
    srv6_list___0 = (__lmem struct pif_header_srv6_list *) (_pif_parrep + PIF_PARREP_srv6_list_STACK_OFF_LW(0));
    srv6 = (__lmem struct pif_header_srv6 *) (_pif_parrep + PIF_PARREP_srv6_OFF_LW);
    PIF_PARREP_SET_srv6_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_srv6_list_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_ipv6_outer_DIRTY(_pif_ctldata);

    {
        /* modify_field(ipv6_outer.payload_len,_expression_srv6_t_insert_2_0) */
        unsigned int pif_expression__expression_srv6_t_insert_2_0_register_2;

        /* primitive body */
        //expression _expression_srv6_t_insert_2_0: ((((ipv6_outer.payload_len) + (0x0028))) & (0xffff))
        {
        unsigned int pif_expression__expression_srv6_t_insert_2_0_register_0;
        unsigned int pif_expression__expression_srv6_t_insert_2_0_register_1;
        //subexpression 4: 0x0028
        // constant : 0x28

        //subexpression 1: (ipv6_outer.payload_len)+(0x0028)
        pif_expression__expression_srv6_t_insert_2_0_register_1 = ipv6_outer->payload_len;
        pif_expression__expression_srv6_t_insert_2_0_register_2 = 0x28;
        pif_expression__expression_srv6_t_insert_2_0_register_0 = pif_expression__expression_srv6_t_insert_2_0_register_1 + pif_expression__expression_srv6_t_insert_2_0_register_2;
        pif_expression__expression_srv6_t_insert_2_0_register_0 &= 0xffff;
        //subexpression 2: 0xffff
        // constant : 0xffff

        //subexpression 0: (((ipv6_outer.payload_len)+(0x0028)))&(0xffff)
        pif_expression__expression_srv6_t_insert_2_0_register_1 = 0xffff;
        pif_expression__expression_srv6_t_insert_2_0_register_2 = pif_expression__expression_srv6_t_insert_2_0_register_0 & pif_expression__expression_srv6_t_insert_2_0_register_1;
        }

        ipv6_outer->payload_len = pif_expression__expression_srv6_t_insert_2_0_register_2;

    }
    {
        /* add_header(srv6_list[0]) */

        /* primitive body */
#define TOPUSH 1
#define STACKMAX 3
#define STACKOFF 0
        {
            unsigned int i;
            unsigned int stacktop = PIF_PARREP_srv6_list_STACKCNT(_pif_ctldata);

            /* cull the entries that would exceed stack boundary */
            if (stacktop >= STACKMAX - TOPUSH)
                stacktop = STACKMAX - TOPUSH;

            while (stacktop > STACKOFF) {
                unsigned int destoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop + TOPUSH - 1);
                unsigned int srcoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop - 1);

                for (i = 0; i < PIF_PARREP_srv6_list_LEN_LW; i++) {
                    *(_pif_parrep + destoff + i) = *(_pif_parrep + srcoff + i);

                }
                stacktop--;
            }
            PIF_PARREP_srv6_list_STACKPUSH(_pif_ctldata, TOPUSH);
            PIF_PARREP_SET_srv6_list_VALID(_pif_ctldata);

        }
#undef TOPUSH
#undef STACKMAX
#undef STACKOFF
    }
    {
        /* modify_field(srv6_list[0].segment_id,s1) */

        /* primitive body */
        srv6_list___0->segment_id = _pif_act_data->s1_3;
        srv6_list___0->__segment_id_1 = _pif_act_data->s1_2;
        srv6_list___0->__segment_id_2 = _pif_act_data->s1_1;
        srv6_list___0->__segment_id_3 = _pif_act_data->s1_0;

    }
    {
        /* add_header(srv6_list[1]) */

        /* primitive body */
#define TOPUSH 1
#define STACKMAX 3
#define STACKOFF 1
        {
            unsigned int i;
            unsigned int stacktop = PIF_PARREP_srv6_list_STACKCNT(_pif_ctldata);

            /* cull the entries that would exceed stack boundary */
            if (stacktop >= STACKMAX - TOPUSH)
                stacktop = STACKMAX - TOPUSH;

            while (stacktop > STACKOFF) {
                unsigned int destoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop + TOPUSH - 1);
                unsigned int srcoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop - 1);

                for (i = 0; i < PIF_PARREP_srv6_list_LEN_LW; i++) {
                    *(_pif_parrep + destoff + i) = *(_pif_parrep + srcoff + i);

                }
                stacktop--;
            }
            PIF_PARREP_srv6_list_STACKPUSH(_pif_ctldata, TOPUSH);
            PIF_PARREP_SET_srv6_list_VALID(_pif_ctldata);

        }
#undef TOPUSH
#undef STACKMAX
#undef STACKOFF
    }
    {
        /* modify_field(srv6_list[1].segment_id,s2) */

        /* primitive body */
        srv6_list___1->segment_id = _pif_act_data->s2_3;
        srv6_list___1->__segment_id_1 = _pif_act_data->s2_2;
        srv6_list___1->__segment_id_2 = _pif_act_data->s2_1;
        srv6_list___1->__segment_id_3 = _pif_act_data->s2_0;

    }
    {
        /* modify_field(ipv6_outer.dst_addr,s2) */

        /* primitive body */
        ipv6_outer->dst_addr = _pif_act_data->s2_3;
        ipv6_outer->__dst_addr_1 = _pif_act_data->s2_2;
        ipv6_outer->__dst_addr_2 = _pif_act_data->s2_1;
        ipv6_outer->__dst_addr_3 = _pif_act_data->s2_0;

    }
    {
        /* add_header(srv6) */

        /* primitive body */
        {
            PIF_PARREP_SET_srv6_VALID(_pif_ctldata);
        }
    }
    {
        /* modify_field(srv6.next_hdr,0x11) */

        /* primitive body */
        srv6->next_hdr = 0x11;

    }
    {
        /* modify_field(srv6.hdr_ext_len,0x04) */

        /* primitive body */
        srv6->hdr_ext_len = 0x4;

    }
    {
        /* modify_field(srv6.routing_type,0x04) */

        /* primitive body */
        srv6->routing_type = 0x4;

    }
    {
        /* modify_field(srv6.segment_left,0x01) */

        /* primitive body */
        srv6->segment_left = 0x1;

    }
    {
        /* modify_field(srv6.last_entry,0x01) */

        /* primitive body */
        srv6->last_entry = 0x1;

    }
    {
        /* modify_field(srv6.flags,0x00) */

        /* primitive body */
        srv6->flags = 0x0;

    }
    {
        /* modify_field(srv6.tag,0x0000) */

        /* primitive body */
        srv6->tag = 0x0;

    }
    {
        /* modify_field(ipv6_outer.next_hdr,0x2b) */

        /* primitive body */
        ipv6_outer->next_hdr = 0x2b;

    }
    return _pif_return;
}

static int pif_action_exec_ingress__srv6_t_insert_3(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__srv6_t_insert_3 *_pif_act_data = (__xread struct pif_action_actiondata_ingress__srv6_t_insert_3 *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_srv6_list *srv6_list___0;
    __lmem struct pif_header_srv6_list *srv6_list___1;
    __lmem struct pif_header_srv6_list *srv6_list;
    __lmem struct pif_header_ipv6_outer *ipv6_outer;
    __lmem struct pif_header_srv6_list *srv6_list___2;
    __lmem struct pif_header_srv6 *srv6;
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__srv6_t_insert_3");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__srv6_t_insert_3");
#endif

    srv6_list___0 = (__lmem struct pif_header_srv6_list *) (_pif_parrep + PIF_PARREP_srv6_list_STACK_OFF_LW(0));
    srv6_list___1 = (__lmem struct pif_header_srv6_list *) (_pif_parrep + PIF_PARREP_srv6_list_STACK_OFF_LW(1));
    srv6_list = (__lmem struct pif_header_srv6_list *) (_pif_parrep + PIF_PARREP_srv6_list_OFF_LW);
    ipv6_outer = (__lmem struct pif_header_ipv6_outer *) (_pif_parrep + PIF_PARREP_ipv6_outer_OFF_LW);
    srv6_list___2 = (__lmem struct pif_header_srv6_list *) (_pif_parrep + PIF_PARREP_srv6_list_STACK_OFF_LW(2));
    srv6 = (__lmem struct pif_header_srv6 *) (_pif_parrep + PIF_PARREP_srv6_OFF_LW);
    PIF_PARREP_SET_srv6_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_srv6_list_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_ipv6_outer_DIRTY(_pif_ctldata);

    {
        /* modify_field(ipv6_outer.payload_len,_expression_srv6_t_insert_3_0) */
        unsigned int pif_expression__expression_srv6_t_insert_3_0_register_2;

        /* primitive body */
        //expression _expression_srv6_t_insert_3_0: ((((ipv6_outer.payload_len) + (0x0038))) & (0xffff))
        {
        unsigned int pif_expression__expression_srv6_t_insert_3_0_register_0;
        unsigned int pif_expression__expression_srv6_t_insert_3_0_register_1;
        //subexpression 4: 0x0038
        // constant : 0x38

        //subexpression 1: (ipv6_outer.payload_len)+(0x0038)
        pif_expression__expression_srv6_t_insert_3_0_register_1 = ipv6_outer->payload_len;
        pif_expression__expression_srv6_t_insert_3_0_register_2 = 0x38;
        pif_expression__expression_srv6_t_insert_3_0_register_0 = pif_expression__expression_srv6_t_insert_3_0_register_1 + pif_expression__expression_srv6_t_insert_3_0_register_2;
        pif_expression__expression_srv6_t_insert_3_0_register_0 &= 0xffff;
        //subexpression 2: 0xffff
        // constant : 0xffff

        //subexpression 0: (((ipv6_outer.payload_len)+(0x0038)))&(0xffff)
        pif_expression__expression_srv6_t_insert_3_0_register_1 = 0xffff;
        pif_expression__expression_srv6_t_insert_3_0_register_2 = pif_expression__expression_srv6_t_insert_3_0_register_0 & pif_expression__expression_srv6_t_insert_3_0_register_1;
        }

        ipv6_outer->payload_len = pif_expression__expression_srv6_t_insert_3_0_register_2;

    }
    {
        /* add_header(srv6_list[0]) */

        /* primitive body */
#define TOPUSH 1
#define STACKMAX 3
#define STACKOFF 0
        {
            unsigned int i;
            unsigned int stacktop = PIF_PARREP_srv6_list_STACKCNT(_pif_ctldata);

            /* cull the entries that would exceed stack boundary */
            if (stacktop >= STACKMAX - TOPUSH)
                stacktop = STACKMAX - TOPUSH;

            while (stacktop > STACKOFF) {
                unsigned int destoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop + TOPUSH - 1);
                unsigned int srcoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop - 1);

                for (i = 0; i < PIF_PARREP_srv6_list_LEN_LW; i++) {
                    *(_pif_parrep + destoff + i) = *(_pif_parrep + srcoff + i);

                }
                stacktop--;
            }
            PIF_PARREP_srv6_list_STACKPUSH(_pif_ctldata, TOPUSH);
            PIF_PARREP_SET_srv6_list_VALID(_pif_ctldata);

        }
#undef TOPUSH
#undef STACKMAX
#undef STACKOFF
    }
    {
        /* modify_field(srv6_list[0].segment_id,s1) */

        /* primitive body */
        srv6_list___0->segment_id = _pif_act_data->s1_3;
        srv6_list___0->__segment_id_1 = _pif_act_data->s1_2;
        srv6_list___0->__segment_id_2 = _pif_act_data->s1_1;
        srv6_list___0->__segment_id_3 = _pif_act_data->s1_0;

    }
    {
        /* add_header(srv6_list[1]) */

        /* primitive body */
#define TOPUSH 1
#define STACKMAX 3
#define STACKOFF 1
        {
            unsigned int i;
            unsigned int stacktop = PIF_PARREP_srv6_list_STACKCNT(_pif_ctldata);

            /* cull the entries that would exceed stack boundary */
            if (stacktop >= STACKMAX - TOPUSH)
                stacktop = STACKMAX - TOPUSH;

            while (stacktop > STACKOFF) {
                unsigned int destoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop + TOPUSH - 1);
                unsigned int srcoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop - 1);

                for (i = 0; i < PIF_PARREP_srv6_list_LEN_LW; i++) {
                    *(_pif_parrep + destoff + i) = *(_pif_parrep + srcoff + i);

                }
                stacktop--;
            }
            PIF_PARREP_srv6_list_STACKPUSH(_pif_ctldata, TOPUSH);
            PIF_PARREP_SET_srv6_list_VALID(_pif_ctldata);

        }
#undef TOPUSH
#undef STACKMAX
#undef STACKOFF
    }
    {
        /* modify_field(srv6_list[1].segment_id,s2) */

        /* primitive body */
        srv6_list___1->segment_id = _pif_act_data->s2_3;
        srv6_list___1->__segment_id_1 = _pif_act_data->s2_2;
        srv6_list___1->__segment_id_2 = _pif_act_data->s2_1;
        srv6_list___1->__segment_id_3 = _pif_act_data->s2_0;

    }
    {
        /* add_header(srv6_list[2]) */

        /* primitive body */
#define TOPUSH 1
#define STACKMAX 3
#define STACKOFF 2
        {
            unsigned int i;
            unsigned int stacktop = PIF_PARREP_srv6_list_STACKCNT(_pif_ctldata);

            /* cull the entries that would exceed stack boundary */
            if (stacktop >= STACKMAX - TOPUSH)
                stacktop = STACKMAX - TOPUSH;

            while (stacktop > STACKOFF) {
                unsigned int destoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop + TOPUSH - 1);
                unsigned int srcoff = PIF_PARREP_srv6_list_STACK_OFF_LW(stacktop - 1);

                for (i = 0; i < PIF_PARREP_srv6_list_LEN_LW; i++) {
                    *(_pif_parrep + destoff + i) = *(_pif_parrep + srcoff + i);

                }
                stacktop--;
            }
            PIF_PARREP_srv6_list_STACKPUSH(_pif_ctldata, TOPUSH);
            PIF_PARREP_SET_srv6_list_VALID(_pif_ctldata);

        }
#undef TOPUSH
#undef STACKMAX
#undef STACKOFF
    }
    {
        /* modify_field(srv6_list[2].segment_id,s3) */

        /* primitive body */
        srv6_list___2->segment_id = _pif_act_data->s3_3;
        srv6_list___2->__segment_id_1 = _pif_act_data->s3_2;
        srv6_list___2->__segment_id_2 = _pif_act_data->s3_1;
        srv6_list___2->__segment_id_3 = _pif_act_data->s3_0;

    }
    {
        /* modify_field(ipv6_outer.dst_addr,s3) */

        /* primitive body */
        ipv6_outer->dst_addr = _pif_act_data->s3_3;
        ipv6_outer->__dst_addr_1 = _pif_act_data->s3_2;
        ipv6_outer->__dst_addr_2 = _pif_act_data->s3_1;
        ipv6_outer->__dst_addr_3 = _pif_act_data->s3_0;

    }
    {
        /* add_header(srv6) */

        /* primitive body */
        {
            PIF_PARREP_SET_srv6_VALID(_pif_ctldata);
        }
    }
    {
        /* modify_field(srv6.next_hdr,0x11) */

        /* primitive body */
        srv6->next_hdr = 0x11;

    }
    {
        /* modify_field(srv6.hdr_ext_len,0x06) */

        /* primitive body */
        srv6->hdr_ext_len = 0x6;

    }
    {
        /* modify_field(srv6.routing_type,0x04) */

        /* primitive body */
        srv6->routing_type = 0x4;

    }
    {
        /* modify_field(srv6.segment_left,0x02) */

        /* primitive body */
        srv6->segment_left = 0x2;

    }
    {
        /* modify_field(srv6.last_entry,0x02) */

        /* primitive body */
        srv6->last_entry = 0x2;

    }
    {
        /* modify_field(srv6.flags,0x00) */

        /* primitive body */
        srv6->flags = 0x0;

    }
    {
        /* modify_field(srv6.tag,0x0000) */

        /* primitive body */
        srv6->tag = 0x0;

    }
    {
        /* modify_field(ipv6_outer.next_hdr,0x2b) */

        /* primitive body */
        ipv6_outer->next_hdr = 0x2b;

    }
    return _pif_return;
}

static int pif_action_exec_ingress__drop(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__drop *_pif_act_data = (__xread struct pif_action_actiondata_ingress__drop *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__drop");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__drop");
#endif


    {
        /* drop() */

        /* primitive body */
        _pif_return = PIF_RETURN_DROP;
    }
    return _pif_return;
}

extern __forceinline int pif_action_exec_op(__lmem uint32_t *parrep, __xread uint32_t *_actdata)
{
    __xread union pif_action_opdata *opdata = (__xread union pif_action_opdata *) _actdata;
    int ret = -1;

    if (opdata->action_id > PIF_ACTION_ID_MAX) {
        /* FIXME: TODO: account for bad action id */
        return -1;
    }

    PIF_DEBUG_SET_STATE(PIF_DEBUG_STATE_ACTION, opdata->action_id);
    switch (opdata->action_id) {
    case PIF_ACTION_ID_ingress__ipv6_forward:
        ret = pif_action_exec_ingress__ipv6_forward(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__srv6_t_insert_2:
        ret = pif_action_exec_ingress__srv6_t_insert_2(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__srv6_t_insert_3:
        ret = pif_action_exec_ingress__srv6_t_insert_3(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__drop:
        ret = pif_action_exec_ingress__drop(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    }
#ifdef PIF_DEBUG
        mem_incr64((__mem __addr40 uint64_t *)(pif_act_stats + opdata->action_id));
#endif

    return ret;
}

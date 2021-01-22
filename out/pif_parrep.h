/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PARREP_H__
#define __PIF_PARREP_H__

/* Generated C source defining layout of parsed representation */
/* Warning: your edits to this file may be lost */

/*
 * Parsed representation control data
 */
struct pif_parrep_ctldata {
    unsigned int valid:1;
    unsigned int t0_valid:1;
    unsigned int t0_dirty:1;
    unsigned int t0_orig_len:1;
    unsigned int t1_valid:1;
    unsigned int t1_dirty:1;
    unsigned int t1_orig_len:1;
    unsigned int t2_valid:1;
    unsigned int t2_dirty:1;
    unsigned int t2_orig_len:1;
    unsigned int t3_valid:1;
    unsigned int t3_dirty:1;
    unsigned int t3_orig_len:1;
    unsigned int t4_valid:1;
    unsigned int t4_dirty:1;
    unsigned int t4_orig_len:1;
    unsigned int t5_valid:1;
    unsigned int t5_dirty:1;
    unsigned int t5_orig_len:1;
    unsigned int t6_valid:1;
    unsigned int t6_dirty:1;
    unsigned int t6_orig_len:1;
    unsigned int t7_valid:1;
    unsigned int t7_type:2;
    unsigned int t7_dirty:1;
    unsigned int t7_orig_len:5;
    unsigned int _padding_0:1;
    unsigned int t8_valid:3;
    unsigned int t8_dirty:1;
    unsigned int t8_orig_len:6;
};

#define PIF_PARREP_CTLDATA_OFF_LW 0
#define PIF_PARREP_CTLDATA_LEN_LW 2

/*
 * Parsed representation layout
 */

/* Parsed represention tier types */
/* tier 7 */
#define PIF_PARREP_TYPE_tcp_inner 0
#define PIF_PARREP_TYPE_udp_inner 1
#define PIF_PARREP_TYPE_srv6 2

/* Parse state values */
#define PIF_PARREP_STATE_exit -1
#define PIF_PARREP_STATE_parse_udp_inner 8
#define PIF_PARREP_STATE_parse_tcp_inner 9
#define PIF_PARREP_STATE_parse_udp 2
#define PIF_PARREP_STATE_parse_gtp_ext 5
#define PIF_PARREP_STATE_start 0
#define PIF_PARREP_STATE_parse_pdu_container 6
#define PIF_PARREP_STATE_parse_ipv6_inner 7
#define PIF_PARREP_STATE_parse_srv6 3
#define PIF_PARREP_STATE_parse_gtp 4
#define PIF_PARREP_STATE_parse_ipv6_outer 1
#define PIF_PARREP_MAX_STATE 9

/* Tier 0 */
#define PIF_PARREP_T0_OFF_LW 2
#define PIF_PARREP_T0_LEN_LW 4
#define PIF_PARREP_ethernet_OFF_LW (PIF_PARREP_T0_OFF_LW)
#define PIF_PARREP_ethernet_LEN_LW 4
#define PIF_PARREP_ethernet_LEN_B 14

/* Tier 1 */
#define PIF_PARREP_T1_OFF_LW 6
#define PIF_PARREP_T1_LEN_LW 10
#define PIF_PARREP_ipv6_outer_OFF_LW (PIF_PARREP_T1_OFF_LW)
#define PIF_PARREP_ipv6_outer_LEN_LW 10
#define PIF_PARREP_ipv6_outer_LEN_B 40

/* Tier 2 */
#define PIF_PARREP_T2_OFF_LW 16
#define PIF_PARREP_T2_LEN_LW 2
#define PIF_PARREP_udp_OFF_LW (PIF_PARREP_T2_OFF_LW)
#define PIF_PARREP_udp_LEN_LW 2
#define PIF_PARREP_udp_LEN_B 8

/* Tier 3 */
#define PIF_PARREP_T3_OFF_LW 18
#define PIF_PARREP_T3_LEN_LW 2
#define PIF_PARREP_gtp_OFF_LW (PIF_PARREP_T3_OFF_LW)
#define PIF_PARREP_gtp_LEN_LW 2
#define PIF_PARREP_gtp_LEN_B 8

/* Tier 4 */
#define PIF_PARREP_T4_OFF_LW 20
#define PIF_PARREP_T4_LEN_LW 1
#define PIF_PARREP_gtp_ext_OFF_LW (PIF_PARREP_T4_OFF_LW)
#define PIF_PARREP_gtp_ext_LEN_LW 1
#define PIF_PARREP_gtp_ext_LEN_B 1

/* Tier 5 */
#define PIF_PARREP_T5_OFF_LW 21
#define PIF_PARREP_T5_LEN_LW 1
#define PIF_PARREP_pdu_container_OFF_LW (PIF_PARREP_T5_OFF_LW)
#define PIF_PARREP_pdu_container_LEN_LW 1
#define PIF_PARREP_pdu_container_LEN_B 3

/* Tier 6 */
#define PIF_PARREP_T6_OFF_LW 22
#define PIF_PARREP_T6_LEN_LW 10
#define PIF_PARREP_ipv6_inner_OFF_LW (PIF_PARREP_T6_OFF_LW)
#define PIF_PARREP_ipv6_inner_LEN_LW 10
#define PIF_PARREP_ipv6_inner_LEN_B 40

/* Tier 7 */
#define PIF_PARREP_T7_OFF_LW 32
#define PIF_PARREP_T7_LEN_LW 5
#define PIF_PARREP_tcp_inner_OFF_LW (PIF_PARREP_T7_OFF_LW)
#define PIF_PARREP_tcp_inner_LEN_LW 5
#define PIF_PARREP_tcp_inner_LEN_B 20
#define PIF_PARREP_udp_inner_OFF_LW (PIF_PARREP_T7_OFF_LW)
#define PIF_PARREP_udp_inner_LEN_LW 2
#define PIF_PARREP_udp_inner_LEN_B 8
#define PIF_PARREP_srv6_OFF_LW (PIF_PARREP_T7_OFF_LW)
#define PIF_PARREP_srv6_LEN_LW 2
#define PIF_PARREP_srv6_LEN_B 8

/* Tier 8 */
#define PIF_PARREP_T8_OFF_LW 37
#define PIF_PARREP_T8_LEN_LW 12
#define PIF_PARREP_srv6_list_OFF_LW (PIF_PARREP_T8_OFF_LW)
#define PIF_PARREP_srv6_list_LEN_LW 4
#define PIF_PARREP_srv6_list_LEN_B 16
#define PIF_PARREP_srv6_list_STACK_OFF_LW(_x) (PIF_PARREP_T8_OFF_LW + PIF_PARREP_srv6_list_LEN_LW * (_x))
#define PIF_PARREP_srv6_list_STACKTOP_OFF_LW(_ctrl) (PIF_PARREP_srv6_list_STACK_OFF_LW(ffs(~(_ctrl->t8_valid)) - 1))

/*
 * Metadata
 */

#define PIF_PARREP_standard_metadata_OFF_LW 49
#define PIF_PARREP_standard_metadata_LEN_LW 4

#define PIF_PARREP_scalars_OFF_LW 53
#define PIF_PARREP_scalars_LEN_LW 4

#define PIF_PARREP_LEN_LW 57

/* Parsing branches to a constant control entry point */
#define PIF_PARREP_NO_VARIABLE_EXIT

/* Control data macros */
#define PIF_PARREP_VALID(_ctl) (_ctl->valid)
#define PIF_PARREP_SET_VALID(_ctl) \
    do { _ctl->valid = 1; } while (0)

/* Tier 0 */
#define PIF_PARREP_T0_TYPE(ctl) ( ((ctl)->t0_type))
#define PIF_PARREP_T0_VALID(ctl) ( ((ctl)->t0_valid))
#define PIF_PARREP_ethernet_VALID(ctl) ( ((ctl)->t0_valid) )
#define PIF_PARREP_SET_ethernet_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ethernet_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 0; \
    } while(0);

#define PIF_PARREP_ethernet_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_T0_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_CLEAR_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_DIRTY(_ctl) \
    do { \
        (_ctl)->t0_dirty = 1; \
    } while(0);

#define PIF_PARREP_T0_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_SET_T0_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ethernet_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_CLEAR_ethernet_ORIG_LEN(ctl) \
    do { \
        (ctl)->t0_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = 1; \
    } while(0);

/* Tier 1 */
#define PIF_PARREP_T1_TYPE(ctl) ( ((ctl)->t1_type))
#define PIF_PARREP_T1_VALID(ctl) ( ((ctl)->t1_valid))
#define PIF_PARREP_ipv6_outer_VALID(ctl) ( ((ctl)->t1_valid) )
#define PIF_PARREP_SET_ipv6_outer_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ipv6_outer_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 0; \
    } while(0);

#define PIF_PARREP_ipv6_outer_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_T1_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_CLEAR_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv6_outer_DIRTY(_ctl) \
    do { \
        (_ctl)->t1_dirty = 1; \
    } while(0);

#define PIF_PARREP_T1_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv6_outer_LEN_B : 0)
#define PIF_PARREP_SET_T1_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ipv6_outer_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv6_outer_LEN_B : 0)
#define PIF_PARREP_CLEAR_ipv6_outer_ORIG_LEN(ctl) \
    do { \
        (ctl)->t1_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv6_outer_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = 1; \
    } while(0);

/* Tier 2 */
#define PIF_PARREP_T2_TYPE(ctl) ( ((ctl)->t2_type))
#define PIF_PARREP_T2_VALID(ctl) ( ((ctl)->t2_valid))
#define PIF_PARREP_udp_VALID(ctl) ( ((ctl)->t2_valid) )
#define PIF_PARREP_SET_udp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_udp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 0; \
    } while(0);

#define PIF_PARREP_udp_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_T2_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_CLEAR_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_DIRTY(_ctl) \
    do { \
        (_ctl)->t2_dirty = 1; \
    } while(0);

#define PIF_PARREP_T2_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_udp_LEN_B : 0)
#define PIF_PARREP_SET_T2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_udp_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_udp_LEN_B : 0)
#define PIF_PARREP_CLEAR_udp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t2_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = 1; \
    } while(0);

/* Tier 3 */
#define PIF_PARREP_T3_TYPE(ctl) ( ((ctl)->t3_type))
#define PIF_PARREP_T3_VALID(ctl) ( ((ctl)->t3_valid))
#define PIF_PARREP_gtp_VALID(ctl) ( ((ctl)->t3_valid) )
#define PIF_PARREP_SET_gtp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_gtp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 0; \
    } while(0);

#define PIF_PARREP_gtp_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_T3_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_CLEAR_T3_DIRTY(_ctl)     do { \
        (_ctl)->t3_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T3_DIRTY(_ctl)     do { \
        (_ctl)->t3_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_gtp_DIRTY(_ctl) \
    do { \
        (_ctl)->t3_dirty = 1; \
    } while(0);

#define PIF_PARREP_T3_ORIG_LEN(ctl) (((ctl)->t3_orig_len) ? PIF_PARREP_gtp_LEN_B : 0)
#define PIF_PARREP_SET_T3_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_gtp_ORIG_LEN(ctl) (((ctl)->t3_orig_len) ? PIF_PARREP_gtp_LEN_B : 0)
#define PIF_PARREP_CLEAR_gtp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t3_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_gtp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = 1; \
    } while(0);

/* Tier 4 */
#define PIF_PARREP_T4_TYPE(ctl) ( ((ctl)->t4_type))
#define PIF_PARREP_T4_VALID(ctl) ( ((ctl)->t4_valid))
#define PIF_PARREP_gtp_ext_VALID(ctl) ( ((ctl)->t4_valid) )
#define PIF_PARREP_SET_gtp_ext_VALID(ctl) \
    do { \
        (ctl)->t4_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_gtp_ext_VALID(ctl) \
    do { \
        (ctl)->t4_valid = 0; \
    } while(0);

#define PIF_PARREP_gtp_ext_DIRTY(_ctl) ((_ctl)->t4_dirty)
#define PIF_PARREP_T4_DIRTY(_ctl) ((_ctl)->t4_dirty)
#define PIF_PARREP_CLEAR_T4_DIRTY(_ctl)     do { \
        (_ctl)->t4_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T4_DIRTY(_ctl)     do { \
        (_ctl)->t4_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_gtp_ext_DIRTY(_ctl) \
    do { \
        (_ctl)->t4_dirty = 1; \
    } while(0);

#define PIF_PARREP_T4_ORIG_LEN(ctl) (((ctl)->t4_orig_len) ? PIF_PARREP_gtp_ext_LEN_B : 0)
#define PIF_PARREP_SET_T4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t4_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_gtp_ext_ORIG_LEN(ctl) (((ctl)->t4_orig_len) ? PIF_PARREP_gtp_ext_LEN_B : 0)
#define PIF_PARREP_CLEAR_gtp_ext_ORIG_LEN(ctl) \
    do { \
        (ctl)->t4_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_gtp_ext_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t4_orig_len = 1; \
    } while(0);

/* Tier 5 */
#define PIF_PARREP_T5_TYPE(ctl) ( ((ctl)->t5_type))
#define PIF_PARREP_T5_VALID(ctl) ( ((ctl)->t5_valid))
#define PIF_PARREP_pdu_container_VALID(ctl) ( ((ctl)->t5_valid) )
#define PIF_PARREP_SET_pdu_container_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_pdu_container_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 0; \
    } while(0);

#define PIF_PARREP_pdu_container_DIRTY(_ctl) ((_ctl)->t5_dirty)
#define PIF_PARREP_T5_DIRTY(_ctl) ((_ctl)->t5_dirty)
#define PIF_PARREP_CLEAR_T5_DIRTY(_ctl)     do { \
        (_ctl)->t5_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T5_DIRTY(_ctl)     do { \
        (_ctl)->t5_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_pdu_container_DIRTY(_ctl) \
    do { \
        (_ctl)->t5_dirty = 1; \
    } while(0);

#define PIF_PARREP_T5_ORIG_LEN(ctl) (((ctl)->t5_orig_len) ? PIF_PARREP_pdu_container_LEN_B : 0)
#define PIF_PARREP_SET_T5_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_pdu_container_ORIG_LEN(ctl) (((ctl)->t5_orig_len) ? PIF_PARREP_pdu_container_LEN_B : 0)
#define PIF_PARREP_CLEAR_pdu_container_ORIG_LEN(ctl) \
    do { \
        (ctl)->t5_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_pdu_container_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len = 1; \
    } while(0);

/* Tier 6 */
#define PIF_PARREP_T6_TYPE(ctl) ( ((ctl)->t6_type))
#define PIF_PARREP_T6_VALID(ctl) ( ((ctl)->t6_valid))
#define PIF_PARREP_ipv6_inner_VALID(ctl) ( ((ctl)->t6_valid) )
#define PIF_PARREP_SET_ipv6_inner_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ipv6_inner_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 0; \
    } while(0);

#define PIF_PARREP_ipv6_inner_DIRTY(_ctl) ((_ctl)->t6_dirty)
#define PIF_PARREP_T6_DIRTY(_ctl) ((_ctl)->t6_dirty)
#define PIF_PARREP_CLEAR_T6_DIRTY(_ctl)     do { \
        (_ctl)->t6_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T6_DIRTY(_ctl)     do { \
        (_ctl)->t6_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv6_inner_DIRTY(_ctl) \
    do { \
        (_ctl)->t6_dirty = 1; \
    } while(0);

#define PIF_PARREP_T6_ORIG_LEN(ctl) (((ctl)->t6_orig_len) ? PIF_PARREP_ipv6_inner_LEN_B : 0)
#define PIF_PARREP_SET_T6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ipv6_inner_ORIG_LEN(ctl) (((ctl)->t6_orig_len) ? PIF_PARREP_ipv6_inner_LEN_B : 0)
#define PIF_PARREP_CLEAR_ipv6_inner_ORIG_LEN(ctl) \
    do { \
        (ctl)->t6_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv6_inner_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len = 1; \
    } while(0);

/* Tier 7 */
#define PIF_PARREP_T7_TYPE(ctl) ( ((ctl)->t7_type))
#define PIF_PARREP_T7_VALID(ctl) ( ((ctl)->t7_valid & 0x1) )
#define PIF_PARREP_tcp_inner_VALID(ctl) ( ((ctl)->t7_valid & 0x1) && ((ctl)->t7_type == PIF_PARREP_TYPE_tcp_inner) )
#define PIF_PARREP_SET_tcp_inner_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 1; \
        (ctl)->t7_type = PIF_PARREP_TYPE_tcp_inner; \
    } while(0);
#define PIF_PARREP_CLEAR_tcp_inner_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 0; \
    } while(0);
#define PIF_PARREP_udp_inner_VALID(ctl) ( ((ctl)->t7_valid & 0x1) && ((ctl)->t7_type == PIF_PARREP_TYPE_udp_inner) )
#define PIF_PARREP_SET_udp_inner_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 1; \
        (ctl)->t7_type = PIF_PARREP_TYPE_udp_inner; \
    } while(0);
#define PIF_PARREP_CLEAR_udp_inner_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 0; \
    } while(0);
#define PIF_PARREP_srv6_VALID(ctl) ( ((ctl)->t7_valid & 0x1) && ((ctl)->t7_type == PIF_PARREP_TYPE_srv6) )
#define PIF_PARREP_SET_srv6_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 1; \
        (ctl)->t7_type = PIF_PARREP_TYPE_srv6; \
    } while(0);
#define PIF_PARREP_CLEAR_srv6_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 0; \
    } while(0);

#define PIF_PARREP_tcp_inner_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_udp_inner_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_srv6_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_T7_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_CLEAR_T7_DIRTY(_ctl)     do { \
        (_ctl)->t7_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T7_DIRTY(_ctl)     do { \
        (_ctl)->t7_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_tcp_inner_DIRTY(_ctl) \
    do { \
        (_ctl)->t7_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_udp_inner_DIRTY(_ctl) \
    do { \
        (_ctl)->t7_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_srv6_DIRTY(_ctl) \
    do { \
        (_ctl)->t7_dirty = 1; \
    } while(0);

#define PIF_PARREP_T7_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_SET_T7_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_T7_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);
#define PIF_PARREP_tcp_inner_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_CLEAR_tcp_inner_ORIG_LEN(ctl) \
    do { \
        (ctl)->t7_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_tcp_inner_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_tcp_inner_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);
#define PIF_PARREP_udp_inner_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_CLEAR_udp_inner_ORIG_LEN(ctl) \
    do { \
        (ctl)->t7_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_inner_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_udp_inner_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);
#define PIF_PARREP_srv6_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_CLEAR_srv6_ORIG_LEN(ctl) \
    do { \
        (ctl)->t7_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_srv6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_srv6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);

/* Tier 8 */
#define PIF_PARREP_T8_TYPE(ctl) ( ((ctl)->t8_type))
#define PIF_PARREP_T8_VALID(ctl) ( ((ctl)->t8_valid & 0x1) )
#define PIF_PARREP_srv6_list_VALID(ctl) ( ((ctl)->t8_valid & 0x1) )
#define PIF_PARREP_SET_srv6_list_VALID(ctl) \
    do { \
    } while(0);
#define PIF_PARREP_CLEAR_srv6_list_VALID(ctl) \
    do { \
        (ctl)->t8_valid = 0; \
    } while(0);
#define PIF_PARREP_srv6_list_STACKVALID(ctl, idx) ((((ctl)->t8_valid) >> (idx)) & 0x1)
#define PIF_PARREP_srv6_list_STACKCNT(ctl) (ffs(~((ctl)->t8_valid)))
#define PIF_PARREP_srv6_list_STACKPUSH(_ctl, _cnt) \
    do { \
        (_ctl)->t8_valid = ((1 << _cnt) - 1) | ((_ctl)->t8_valid  << _cnt); \
    } while(0);
#define PIF_PARREP_srv6_list_STACKPOP(_ctl, _cnt) \
    do { \
        (_ctl)->t8_valid >>= _cnt; \
    } while(0);
#define PIF_PARREP_T8_STACKVALID(ctl, idx) ((((ctl)->t8_valid) >> (idx)) & 0x1)
#define PIF_PARREP_T8_STACKCNT(ctl) (ffs(~((ctl)->t8_valid)))
#define PIF_PARREP_T8_STACKPUSH(_ctl, _cnt) \
    do { \
        (_ctl)->t8_valid = ((1 << _cnt) - 1) | ((_ctl)->t8_valid  << _cnt); \
    } while(0);
#define PIF_PARREP_T8_STACKPOP(_ctl, _cnt) \
    do { \
        (_ctl)->t8_valid >>= _cnt; \
    } while(0);

#define PIF_PARREP_srv6_list_DIRTY(_ctl) ((_ctl)->t8_dirty)
#define PIF_PARREP_T8_DIRTY(_ctl) ((_ctl)->t8_dirty)
#define PIF_PARREP_CLEAR_T8_DIRTY(_ctl)     do { \
        (_ctl)->t8_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T8_DIRTY(_ctl)     do { \
        (_ctl)->t8_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_srv6_list_DIRTY(_ctl) \
    do { \
        (_ctl)->t8_dirty = 1; \
    } while(0);

#define PIF_PARREP_T8_ORIG_LEN(ctl) ((ctl)->t8_orig_len)
#define PIF_PARREP_SET_T8_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t8_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_T8_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t8_orig_len += len; \
    } while(0);
#define PIF_PARREP_srv6_list_ORIG_LEN(ctl) ((ctl)->t8_orig_len)
#define PIF_PARREP_CLEAR_srv6_list_ORIG_LEN(ctl) \
    do { \
        (ctl)->t8_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_srv6_list_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t8_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_srv6_list_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t8_orig_len += len; \
    } while(0);



void pif_value_set_scan_configs();

#endif /* __PIF_PARREP_H__ */

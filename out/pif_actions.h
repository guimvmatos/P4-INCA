/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_ACTIONS_H__
#define __PIF_ACTIONS_H__

/* Warning: generated file - your edits to this file may be lost */

/* Action operation IDs */

#define PIF_ACTION_ID_ingress__ipv6_forward 0
#define PIF_ACTION_ID_ingress__srv6_t_insert_2 1
#define PIF_ACTION_ID_ingress__srv6_t_insert_3 2
#define PIF_ACTION_ID_ingress__drop 3
#define PIF_ACTION_ID_MAX 3

/* Match action data structure */

__packed struct pif_action_actiondata_ingress__ipv6_forward {
    uint32_t dstAddr_1; /* dstAddr[48:16] */
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint16_t port;
    uint16_t dstAddr_0; /* dstAddr[16:0] */
};

__packed struct pif_action_actiondata_ingress__srv6_t_insert_2 {
    uint32_t s1_3; /* s1[128:96] */
    uint32_t s1_2; /* s1[96:64] */
    uint32_t s1_1; /* s1[64:32] */
    uint32_t s1_0; /* s1[32:0] */
    uint32_t s2_3; /* s2[128:96] */
    uint32_t s2_2; /* s2[96:64] */
    uint32_t s2_1; /* s2[64:32] */
    uint32_t s2_0; /* s2[32:0] */
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__srv6_t_insert_3 {
    uint32_t s1_3; /* s1[128:96] */
    uint32_t s1_2; /* s1[96:64] */
    uint32_t s1_1; /* s1[64:32] */
    uint32_t s1_0; /* s1[32:0] */
    uint32_t s2_3; /* s2[128:96] */
    uint32_t s2_2; /* s2[96:64] */
    uint32_t s2_1; /* s2[64:32] */
    uint32_t s2_0; /* s2[32:0] */
    uint32_t s3_3; /* s3[128:96] */
    uint32_t s3_2; /* s3[96:64] */
    uint32_t s3_1; /* s3[64:32] */
    uint32_t s3_0; /* s3[32:0] */
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__drop {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

#endif /* __PIF_ACTIONS_H__ */

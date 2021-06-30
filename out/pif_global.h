/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_GLOBAL_H__
#define __PIF_GLOBAL_H__

#define PIF_GLOBAL_FLOWKEY_MAX_LW 19
__packed_bits struct pif_global_flowkey_ipv6_outer {
    unsigned int ipv6_outer__dst_addr:32;
    unsigned int ipv6_outer____dst_addr_1:32;
    unsigned int ipv6_outer____dst_addr_2:32;
    unsigned int ipv6_outer____dst_addr_3:32;
};

__packed_bits struct pif_global_flowkey_gtp {
    unsigned int gtp__spare:1;
    unsigned int gtp__teid:32;
    unsigned int __padding:31;
};

__packed_bits struct pif_global_flowkey_pdu_container {
    unsigned int pdu_container__qosid:6;
    unsigned int __padding:26;
};

__packed_bits struct pif_global_flowkey_ipv6_inner {
    unsigned int ipv6_inner__next_hdr:8;
    unsigned int ipv6_inner__src_addr:32;
    unsigned int ipv6_inner____src_addr_1:32;
    unsigned int ipv6_inner____src_addr_2:32;
    unsigned int ipv6_inner____src_addr_3:32;
    unsigned int ipv6_inner__dst_addr:32;
    unsigned int ipv6_inner____dst_addr_1:32;
    unsigned int ipv6_inner____dst_addr_2:32;
    unsigned int ipv6_inner____dst_addr_3:32;
    unsigned int __padding:24;
};

__packed_bits struct pif_global_flowkey_tcp_inner {
    unsigned int tcp_inner__dstPort:16;
    unsigned int tcp_inner__srcPort:16;
};

__packed_bits struct pif_global_flowkey_udp_inner {
    unsigned int udp_inner__dport:16;
    unsigned int udp_inner__sport:16;
};


void pif_global_metadata_init(__lmem uint32_t *parrep);

unsigned int pif_global_get_stdmd_egress_spec(__lmem uint32_t *parrep);
unsigned int pif_global_get_stdmd_egress_port(__lmem uint32_t *parrep);
void pif_global_set_stdmd_egress_port(__lmem uint32_t *parrep, unsigned int port_spec);
void pif_global_set_stdmd_instance_type(__lmem uint32_t *parrep, unsigned int instance_type);
void pif_global_set_stdmd_egress_instance(__lmem uint32_t *parrep, unsigned int egress_instance);
void pif_global_set_stdmd_parser_status(__lmem uint32_t *parrep, unsigned int success);
void pif_global_set_stdmd_parser_error_location(__lmem uint32_t *parrep, unsigned int node);
void pif_global_set_pktmd_nic_vlan(__lmem uint32_t *parrep);
void pif_global_get_nic_rxoffload(__lmem uint32_t *parrep);
void pif_global_set_flow_id(__lmem uint32_t *parrep, __mem __addr40 void *act_buf);
void pif_global_get_wq_metawords(__lmem uint32_t *parrep, __gpr uint32_t *mw0,  __gpr uint32_t *mw1);

#endif /* __PIF_GLOBAL_H__ */

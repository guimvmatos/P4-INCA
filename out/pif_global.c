/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <stdint.h>
#include <nfp/me.h>
#include <nfp/mem_bulk.h>
#include "pif_common.h"
#include "port_config.h"

#define PIF_EGRESS_DROP 0xffff
extern __forceinline void pif_global_metadata_init(__lmem uint32_t *parrep)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);

    PIF_HEADER_SET_standard_metadata___egress_spec(standard_metadata, PIF_EGRESS_DROP);
    PIF_HEADER_SET_standard_metadata___packet_length(standard_metadata, pif_pkt_info_global.p_nbi.len);
    PIF_HEADER_SET_standard_metadata___ingress_port(standard_metadata, PIF_PKT_P4PORT(&pif_pkt_info_global));
    PIF_HEADER_SET_standard_metadata___instance_type(standard_metadata, 0);
    PIF_HEADER_SET_standard_metadata___egress_instance(standard_metadata, 0);
}

extern __forceinline unsigned int pif_global_get_stdmd_egress_spec(__lmem uint32_t *parrep)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___egress_spec(standard_metadata);
}

extern __forceinline unsigned int pif_global_get_stdmd_egress_port(__lmem uint32_t *parrep)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___egress_port(standard_metadata);
}

extern __forceinline void pif_global_set_stdmd_egress_port(__lmem uint32_t *parrep, unsigned int port_spec)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___egress_port(standard_metadata, port_spec);
}

extern __forceinline void pif_global_set_stdmd_instance_type(__lmem uint32_t *parrep, unsigned int instance_type)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___instance_type(standard_metadata, instance_type);
}

extern __forceinline void pif_global_set_stdmd_egress_instance(__lmem uint32_t *parrep, unsigned int egress_instance)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___egress_instance(standard_metadata, egress_instance);
}

extern __forceinline void pif_global_set_stdmd_parser_status(__lmem uint32_t *parrep, unsigned int error)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
    if (error >= PIF_PARSE_ERROR_LAST)
           error = PIF_PARSE_ERROR_LAST; //custom error reflected only as custom
    PIF_HEADER_SET_standard_metadata___parser_status(standard_metadata, error);
}

extern __forceinline void pif_global_set_stdmd_parser_error_location(__lmem uint32_t *parrep, unsigned int node)
{
    __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___parser_error_location(standard_metadata, node);
}

extern __forceinline void pif_global_set_pktmd_nic_vlan(__lmem uint32_t *parrep)
{
}

extern __forceinline void pif_global_get_nic_rxoffload(__lmem uint32_t *parrep)
{
}
extern __forceinline void pif_global_set_flow_id(__lmem uint32_t *parrep, __mem __addr40 void *act_buf)
{
}

extern __forceinline void pif_global_get_wq_metawords(__lmem uint32_t *parrep, __gpr uint32_t *mw0,  __gpr uint32_t *mw1)
{
    *mw0 = 0;
    *mw1 = 0;
}


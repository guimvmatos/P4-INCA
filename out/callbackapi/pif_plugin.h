/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_H__
#define __PIF_PLUGIN_H__

/* This file is generate, edit at your peril */

#include <stdint.h>
#include <nfp.h>
#include "pif_common.h"

#define EXTRACTED_HEADERS_T __lmem uint32_t
#define MATCH_DATA_T __xread uint32_t
#define ACTION_DATA_T __xread uint32_t

#define PIF_PLUGIN_RETURN_DROP PIF_RETURN_DROP
#define PIF_PLUGIN_RETURN_EXIT PIF_RETURN_EXIT
#define PIF_PLUGIN_RETURN_FORWARD PIF_RETURN_FORWARD

#include "pif_plugin_metadata.h"
#ifdef PIF_PLUGIN_INIT
void pif_plugin_init(); /* called once per worker thread */
void pif_plugin_init_master(); /* called once system wide */
#endif /* PIF_PLUGIN_INIT */
#include "pif_plugin_tcp_inner.h"
#include "pif_plugin_udp.h"
#include "pif_plugin_srv6_list.h"
#include "pif_plugin_gtp_ext.h"
#include "pif_plugin_udp_inner.h"
#include "pif_plugin_ipv6_outer.h"
#include "pif_plugin_ipv6_inner.h"
#include "pif_plugin_pdu_container.h"
#include "pif_plugin_gtp.h"
#include "pif_plugin_srv6.h"
#include "pif_plugin_ethernet.h"

#endif /* __PIF_PLUGIN_H__ */

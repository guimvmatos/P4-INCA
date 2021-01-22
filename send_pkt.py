#!/usr/bin/env python
import argparse
import sys
import socket
import random
import struct
import argparse

from scapy.all import sendp, send, get_if_list, get_if_hwaddr, hexdump
from scapy.all import Packet
from scapy.all import Ether, IP, IPv6, UDP, TCP

def main():
    iface = "vf0_0" 

    print "sending on interface %s" % (iface)
    pkt =  Ether(src='00:15:4d:00:00:00', dst='00:15:4d:00:00:03')
    pkt = pkt / IPv6(dst="fc00::4" , src="fc00::1") #/ UDP() #/ sys.argv[1]
    pkt.show2()
    sendp(pkt, iface=iface, verbose=False)

if __name__ == '__main__':
    main()

# When SRv6 meets 5G Core: Implementation and Deployment of a Network Service Chaining Function in SmartNICs

## Abstract
Currently, we have witnessed a myriad of solutions that benefit from programmable hardware. The 5G Core (5GC)can and should  also  benefit  from  such  paradigm  to  offload certain  functions  to  the  dataplane.  In  this  work,  we  designed and  implemented  a  P4-based  solution  for  traffic  identification and chaining using the Netronome Agilo SmartNIC. The solution here  presented  is  deployed  in-between  the  RAN  and  UPF  (UserPlane Function) so that traffic coming from the RAN is identified and chained using SRv6 based on different rules defined by the control  plane.  The  traffic  identification  and  the  construction  of the SRv6 list of segments are done entirely in the SmartNIC. A minimalist  Proof-of-Concept  (PoC)  was  deployed  and  evaluated to  show  that  this  function  is  perfectly  capable  to  build  service function  chainings  in  a  transparent  and  efficient  way.

## Introduction

By leveraging network softwarization technologies such as Software Defined Networking (SDN) and Network Functions Virtualization (NFV), a high level of programmability, flexibility, and modularity may be created on top of a common network. 

Aligned with such softwarization, SRv6 has became a key element for the IPv6 data-plane instantiation of Segment Routing. SRv6 works as an extension of IPv6 header, creating a segment list of IPv6 addressees having a pointer to identify which segment is active. Every time that the packet pass through a segment endpoint (SR-capable nodes whose address is in the IPv6 destination address) the pointer decreases, and the new segment-id of the segment list is copied to the destination address. Undoubtedly, SRv6 is an enabler to satisfy new consumer, service and business demands for 5G and beyound

In this demonstration, we will show a P4-based solution capable of identifying traffic and building the list of SRv6 segments in the dataplane, named INCA (In-Network IdentifiCation and chAining). The solution is deployed in-between the RAN and UPF so that traffic is transparently captured, identified and chained according to the control plane pre-defined policies. INCA is capable of parsing traffic coming from the RAN, analysing different types of fields for classification such as IPv6 header (inner/outter), TEID (Tunnel Endpoint ID), QoS ID, among others. In this work, GTP is used as the tunneling protocol between the RAN and UPF. 

The deployment was done using a Netronome Agilio CX 2x10GbE SmartNIC. We evaluated the solution by using DASH traffic as well as ICMP traffic from an emulated UE to test different service chaining based on general policies. The evaluation shows the feasibility of INCA in supporting such approach entirely in the dataplane. 

## Design and working flow

<img src="https://raw.githubusercontent.com/guimvmatos/P4-INCA/main/INCA%20flow%20complete.png">

Figure above ilustrates how our solution works. For sake of simplicity, only the UE, RAN, UPF and DN are shown in the figure. In addition, we also have two examples of network functions, A:: and B::. 

In (1) a packet leaves the UE to the DN. When this packet arrives in the RAN (2) it is then tunneled with the standard 5G stack (UDP + IPv6 + GTP) and sent to UPF. INCA transparently captures this traffic before the UPF and applies the rules according to what was configured by the control plane. Several fields may be used to control the traffic such as the Tunnel Endpoint ID (TEID - inside GTP), QoS ID, transport and network layers of the user's original packet and slice ID. In addition, we can also detect traffic at the flow level (5-tuple), services, QoS or any combination of those elements.  

In step (3), INCA builds an SRv6 header and forwards the packet to the first function. The last VNF forwards the packet back to INCA so that the SRv6 header is removed and the original traffic is sent to the UPF (7), which in turn delivers the packet to its destination (8).

## PoC Deployment

The Netronome SmartNIC uses single-root input/output virtualization (SRIOV), which enables virtual functions (VFs) to be created from a physical function (PF). The VFs thus share the resources of a PF, while VFs remain isolated from each other. The isolated VFs are typically assigned to virtual machines (VMs) on the host. In this way, the VFs allow the VMs to directly access the PCI device, thereby bypassing the host kernel. In our solution, we have two physical (p0, p1) and five virtual interfaces (Vf0\_1 to Vf0\_5).

Figure below summarizes the setup, showing seven virtual machines used to host the UE, RAN, UPF and DN, as well as three virtual functions: NFV1 (Intrusion Detection System), NFV2 (Intrustion Prevention System) and NFV3 (Packet Filter). To encapsulate and decapsulate packets into GTP tunnels (in the RAN and UPF) we are using Python scripts with the Scapy library.

<img src="https://github.com/guimvmatos/P4-INCA/blob/main/Disposição%20física%20netronomes.png">

In this scenario, the UE runs two applications: a DASH client (VLC) and a ICMP monitoring tool. Using the QoS ID field, the DASH traffic is identified to go through two virtual functions, NFV1 and NFV2. The ICMP traffic is identified to go through the functions NFV1 and NFV3. This last function is configured to block ICMP traffic.

No scalability evaluation was done so far. The PoC here presented shows that it is possible to build SFC using SRv6 entirely in the dataplane. The NFs and the services used are just examples of what can be done once the INCA is running, and any other NF can be used since INCA is agnostic of the functions applied in the traffic. 

In summary, INCA may be used as a starting point framework to create several different chainings using SRv6 in the dataplane. In addition, the usage of Stratum for configuring the rules in INCA is a natural step in this work so that INCA becomes adherent to the ONF next generation SDN.

## Conclusion

In our initial tests, we can conjecture that the INCA perform the task of classifying the packages perfectly, constructing and removing the SRv6 header and also the correct routing between functions. We were able to create two different paths with three functions, where each path passes through only two of these.

In the next works we will to make more tests with more functions and chainings, we want to build chainings with more than two functions, in addition to collecting performance data.


### Link to a DEMO Presentation published on 2021 P4 Workshop
- https://www.youtube.com/watch?v=0BnOH88fgGU

This work is divided into three repositories:
- P4-INCA: The main contribution. Here you can find the INCA P4 code for Netronome Agilio SmartNIC and its instructions to deploy it and configure.
- [P4-BMv2-RAN-UPF](https://github.com/guimvmatos/P4-BMv2-RAN-UPF): Auxiliary P4 code to build a RAN and UPF on context of 5G simulations for INCA Project.
- [SFC-SRv6-topology](https://github.com/guimvmatos/SFC-SRv6-topology): Repository with instructions to complete the construction of the necessary topology for INCA tests and simulations.


# Deployment

To reproduce these repositories, you'll need the following requirements:

- Netronme Agilio SmartNIC
- Vagrant
- VirtualBox
- Python

Once you already have your netronome installed and configured on you machine, follow the steps:

## Steps

1. INCA
First, you must configure your card to have at least 7 logical interfaces (VFs). You can configure this setting by editing the following file: `/lib/systemd/system/nfp-sdk6-rte.service`. locate and change the following line.

`Environment=NUM_VFS=7`

Once this is done, proceed with the inca code P4. You have to clone this repository inside your source codes of netronome, generally its inside `path_for_agilio/src/p4-16`.

```
git clone git@github.com:guimvmatos/P4-INCA.git
cd P4-INCA
sudo /opt/netronome/p4/bin/./nfp4build --nfp4c_p4_version 16 --no-debug-info -p out -o firmware.nffw -l lithium -4 entryv2.p4
sudo /opt/netronome/p4/bin/./rtecli design-load -f firmware.nffw -p out/pif_design.json
```

If you want, you can check the configured rules.
```
sudo /opt/netronome/p4/bin/./rtecli tables -i 0 list-rules
```

Now your netronome is configured with INCA. Let's proceed with configurations of RAN, UPF and others VMs.

2. RAN / UPF

Follow the instructions of [P4-BMv2-RAN-UPF Repository](https://github.com/guimvmatos/P4-BMv2-RAN-UPF)

After this, you'll have two VMs running and linked with INCA.

3. VFs topology

Follow the instructions of [SFC-SRv6-topology](https://github.com/guimvmatos/SFC-SRv6-topology)


Now, you have all topology running. You can ping from clientVlc to dashServer with `ping6 fc20::2`. You can capture the packets passing through NFVs with tcpdump.


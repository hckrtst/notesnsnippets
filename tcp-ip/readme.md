<!-- vscode-markdown-toc -->
* 1. [Intro](#Intro)
* 2. [circuit switching vs packet switching](#circuitswitchingvspacketswitching)
* 3. [message tx methods](#messagetxmethods)
* 4. [Terms to understand](#Termstounderstand)
* 5. [perf metrics](#perfmetrics)
* 6. [OSI model](#OSImodel)
* 7. [L4 (transport)](#L4transport)
* 8. [PPP - point to point protocol](#PPP-pointtopointprotocol)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Intro'></a>Intro
* protocols have header and trailer (happens to frames)
* this is metadata that is needed to transport data

##  2. <a name='circuitswitchingvspacketswitching'></a>circuit switching vs packet switching
* instead of fixed and dedicated paths (like in circuit switching), we break data into packets
* packets can take different paths based on things like congestion, outages etc.

##  3. <a name='messagetxmethods'></a>message tx methods

1. unicast
* point to point

2. broadcast (not for IPv6 - instead uses multicast groups)
* one entity sends packets to all receivers

3. multicast
* one entity sends packets to a group (which some receivers joined)

4. anycast (IPv6 only)
* send datagram to nearest node

##  4. <a name='Termstounderstand'></a>Terms to understand
* simplex - public one way comms 
* half duplex - two way comms, but one party can talk at a time. a walkie-talkie. ham radio. wireless networks. ethernet hub.
* full duplex - a conversation between two people.
* intranet - internal network within networks
* extranet - you connect your network to a customer/vendor. special use.
* PAN: personal - bluetooth, LAN, WLAN, CAN (campus area nw), MAN (metropolitan area net), WAN (wide area net)

##  5. <a name='perfmetrics'></a>perf metrics

##  6. <a name='OSImodel'></a>OSI model

see https://en.wikipedia.org/wiki/OSI_model

* PDU - protocol data unit (the packaged data received from layers above or below)
![](image.png)

* L2/ethernet has a header and footer. the footer has a checksum in it. 

##  7. <a name='L4transport'></a>L4 (transport)

![Alt text](image-1.png)

* In V6, NDP takes care of the work ARP did in IPv4
* IP => **routed protocol**
* RIP/Hello/EIGRP/OSPF(open shortest path first)/BGP(border gateway protocol) => **routing protocols** NOTE the distinction. forward IP datagrams from one device to another.

##  8. <a name='PPP-pointtopointprotocol'></a>PPP - point to point protocol

* SLIP (Serial line internet protocol) is the predecessor
  * for TCP/IP over physical link when there is no layer2 protocol
  * fills gap between physical layer 1 and IP layer 3
  * RFC 1055 - published but did not become standard

* PPP RFC 1661, 1662, 2153
  * developed to address shortcomings of SLIP such as no compression, no security, no error corrections etc
* link layer
* popular to carry datagrams over serial lines (DSL). stream of bits.
* links established using LCP (link control protocol)
* a family of NCP(network control protocols) establish network links after LCP sets up basic connection
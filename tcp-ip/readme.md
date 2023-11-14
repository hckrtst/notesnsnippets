<!-- vscode-markdown-toc -->
* 1. [Intro](#Intro)
* 2. [circuit switching vs packet switching](#circuitswitchingvspacketswitching)
* 3. [message tx methods](#messagetxmethods)
* 4. [Terms to understand](#Termstounderstand)
* 5. [perf metrics](#perfmetrics)
* 6. [OSI model](#OSImodel)
* 7. [L4 (transport)](#L4transport)
* 8. [PPP - point to point protocol](#PPP-pointtopointprotocol)
	* 8.1. [PPP LQM and LQR](#PPPLQMandLQR)
	* 8.2. [PPP compression control protocol (CCP)](#PPPcompressioncontrolprotocolCCP)
	* 8.3. [PPP encryption control protocol (ECP)](#PPPencryptioncontrolprotocolECP)
	* 8.4. [PPP multilink protocol (MP)](#PPPmultilinkprotocolMP)

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

![PPP suite High level](image-2.png)

![Alt text](image-3.png)

###  8.1. <a name='PPPLQMandLQR'></a>PPP LQM and LQR
* PPP and TCP have methods for error detection and corruption checking
* Link Quality monitoring (LQM) let's devices analyze link quality
* LQR (reporting) requests other device on link track stats report peridically (send me a link report from your end)
  * ex: num frames sent/recvd per sec

###  8.2. <a name='PPPcompressioncontrolprotocolCCP'></a>PPP compression control protocol (CCP)
* optional way to cpmpress data
* defines compression scheme to be used by hosts
* separate algos for compression/decompression

###  8.3. <a name='PPPencryptioncontrolprotocolECP'></a>PPP encryption control protocol (ECP)
* typically IPSec or SSL/TLS
* optional and seldom used

###  8.4. <a name='PPPmultilinkprotocolMP'></a>PPP multilink protocol (MP)
* sometimes you need more L1 connectiosn for higher bandwidth
* optional

## Extensible authentication protocol (EAP)
* commonly used
* 40 methods
* used for wired and wireless nets
* initial EAPOL protocol
* transport level security, one-time passcode 

![Alt text](image-4.png)
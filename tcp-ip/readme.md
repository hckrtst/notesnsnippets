<!-- vscode-markdown-toc -->
* 1. [Intro](#Intro)
* 2. [circuit switching vs packet switching](#circuitswitchingvspacketswitching)
* 3. [message tx methods](#messagetxmethods)

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

## Terms to understand
* simplex - public one way comms 
* half duplex - two way comms, but one party can talk at a time. a walkie-talkie. ham radio. wireless networks. ethernet hub.
* full duplex - a conversation between two people.
* intranet - internal network within networks
* extranet - you connect your network to a customer/vendor. special use.
* PAN: personal - bluetooth, LAN, WLAN, CAN (campus area nw), MAN (metropolitan area net), WAN (wide area net)

## perf metrics

## OSI model

see https://en.wikipedia.org/wiki/OSI_model

* PDU - protocol data unit (the packaged data received from layers above or below)


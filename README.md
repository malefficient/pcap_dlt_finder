# pcap_dlt_finder
Ironically brute-forces the libpcap DLT_ numberspace

Compilation:
$ gcc -Wall  -O2  -I/usr/local/opt/libpcap/include -L/usr/local/opt/libpcap/lib -o ./pcap_dlt_finder ./pcap_dlt_finder.c -lpcap

Exmple output:
0268|SDLC|IBM SDLC frames
0269|TI_LLN_SNIFFER|TI LLN sniffer frames
0271|VSOCK|Linux vsock
0272|NORDIC_BLE|Nordic Semiconductor Bluetooth LE sniffer frames
0273|DOCSIS31_XRA31|Excentis XRA-31 DOCSIS 3.1 RF sniffer frames
0274|ETHERNET_MPACKET|802.3br mPackets
0275|DISPLAYPORT_AUX|DisplayPort AUX channel monitoring data
0276|LINUX_SLL2|Linux cooked v2

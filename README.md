# pcap_dlt_finder
Ironically brute-forces the libpcap DLT_ numberspace

Compilation:
$ gcc -Wall  -O2  -I/usr/local/opt/libpcap/include -L/usr/local/opt/libpcap/lib -o ./pcap_dlt_finder ./pcap_dlt_finder.c -lpcap

Exmple output:
* 0268|SDLC|IBM SDLC frames
* 0269|TI_LLN_SNIFFER|TI LLN sniffer frames
* 0271|VSOCK|Linux vsock
* 0276|LINUX_SLL2|Linux cooked v2

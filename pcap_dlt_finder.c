#include <stdlib.h>
#include <string.h>
#include <pcap/pcap.h>
/***
 *  pcap_dlt_finder
 *  Iterates over libcap datalink types (DLT), 
 *  Since there is apparently no legitimate API to do this, bruteforce all possible DLT's between 0-65535
 ***/

#define DLT_MAX_CHECK 65535
/*
 * example: Compile/link against brew's libpcap on MacOS
 * $ gcc -Wall  -O2  -I/usr/local/opt/libpcap/include -L/usr/local/opt/libpcap/lib -o ./pcap_dlt_finder ./pcap_dlt_finder.c -lpcap
 */

struct entry_s 
{
	int dlt_num;
	const char *dlt_name;
	const char *dlt_descr;
	struct entry_s *next;
};

void print_entries(struct entry_s *s)
{
	while (s->next != NULL)
	{
		printf("%04d|%s|%s\n",s->dlt_num, s->dlt_name, s->dlt_descr);
		s=s->next;
	}
}

int main(int argc, char **argv)
{
    int i=0;
    int num_found=0;
    struct entry_s *start;
    struct entry_s *S; 
    start = S = ( struct entry_s *) malloc(sizeof(struct entry_s));
    memset(S,0x00,sizeof(struct entry_s));
    
    while( i <= DLT_MAX_CHECK)
	{
      const char *c =pcap_datalink_val_to_description(i);
      if ( c != NULL)
      {
    	S->next = ( struct entry_s *) malloc(sizeof(struct entry_s));
    	S->dlt_num=i;
    	S->dlt_descr = c;
    	num_found++;
    	
    	S->dlt_name=pcap_datalink_val_to_name(i);
    	S=S->next;
      }	
      i+=1;
	}
	print_entries(start);
	fprintf(stderr, "%s: %d unique DLTs computed. Searched up to: %d\n", argv[0], num_found,DLT_MAX_CHECK);

	return 0;
}

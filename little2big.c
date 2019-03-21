#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int num;
        int onebyte;
        int twbyte;
        int thrbyte;
        int fourbyte;
}types;

enum {bitmask = 0xff};

unsigned int little2big(types *ptype, int n){
    ptype->num = n;
    
    ptype->onebyte  = (ptype->num&bitmask);  
    ptype->twbyte   = (ptype->num&(bitmask<<8))>>8;
    ptype->thrbyte  = (ptype->num&(bitmask<<16))>>16;
    ptype->fourbyte = (ptype->num&(bitmask<<24))>>24; 
   
    return (
           (ptype->fourbyte)  | \
           (ptype->thrbyte<<8)| \
           (ptype->twbyte<<16)| \
           (ptype->onebyte<<24) \
           );
}
        
int main(int argc, char *argv[]){
    types *ptype = malloc(sizeof(types)); 
    unsigned int num;
    sscanf(argv[1], "%x", (&num));
    
    printf("ret: %x\n", little2big(ptype,num));
    free(ptype);
    return 0x0;
}

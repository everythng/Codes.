#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
        size_t getvalue;
        size_t byte1;
        size_t byte2;
        size_t byte3;
        size_t byte4;
}bytes;

enum {bitmask = 0xFF};

unsigned int little2big(bytes *pbytes, uint32_t value){
    
    pbytes->getvalue = value;    
    pbytes->byte1 = (pbytes->getvalue&(bitmask));  
    pbytes->byte2 = (pbytes->getvalue&(bitmask << 8))  >> 8;
    pbytes->byte3 = (pbytes->getvalue&(bitmask << 16)) >> 16;
    pbytes->byte4 = (pbytes->getvalue&(bitmask << 24)) >> 24; 
   
    return (
           (pbytes->byte4)       | \
           (pbytes->byte3 << 8)  | \
           (pbytes->byte2 << 16) | \
           (pbytes->byte1 << 24)   \
           );
}
        
int main(int argc, char *argv[]){
    bytes *pbytes = malloc(sizeof(bytes)); 
    
    if(argc != 2){
       printf("%s [hex value].\n", argv[0]);
       exit(-1);      
    }
    
    unsigned int value;
    sscanf(argv[1], "%x", (&value));
    
    printf("ret: %x\n", little2big(pbytes, value));
    free(pbytes);   
    return 0x0;
}

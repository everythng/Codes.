#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *xor_encrypt(char *msg, char *key){
     int len = strlen(msg), j=0;
     char *ptr = malloc(len+1);
     
     while(j<(len)){
          ptr[j++] = (*msg++)^(key[j%len]);
     }         
     
     return ptr;
}

int main(int argc, char *argv[]){
    char *msg = "sct-msg";
    char *pr = xor_encrypt(msg, argv[1]);
    
    printf("%-5s\n", pr);
    free(pr);
    return 0x0;
}

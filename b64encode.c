#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int len;
    char *aux;
    unsigned char pad:6;
        
}aux;    
      
const char charb64set[] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz"
                           "0123456789"
                           "+/";
                                 
int myslen(const char *str){
    int j = 0;
    while(str[j]) j++;
    return j;
}      
      
int rsizeb64(size_t len){
    return((len+2)/3)*4;
}       
       
char *encode2base64(char *src, aux *p){       
    
    	  if(!src) return NULL;      
    	
        p->pad = 0x3d;
    	  p->len = myslen(src);
        p->aux = malloc(rsizeb64(p->len)+1);  	
    	
    	  int i=0, j=0, pbyte=0;	   	   	   
       
    do{ 
           	       
        p->aux[i]   = charb64set[(src[j]   & 0xfc) >> 2];
        p->aux[i+1] = charb64set[(src[j]   & 0x03) << 4 | (src[j+1] & 0xf0) >> 4];
        p->aux[i+2] = charb64set[(src[j+1] & 0x0f) << 2 | (src[j+2] & 0xc0) >> 6];
        p->aux[i+3] = charb64set[(src[j+2] & 0x3f)];
        
        
        i+=4; j+=3;
    	} while(i<rsizeb64(p->len));
         
        pbyte=p->len%3; 
        
        (pbyte ? 
         p->aux[i-1] = p->pad : 0);
        (pbyte==1 ? 
         p->aux[i-2] = p->pad : 0); 
        
         p->aux[i] = 0;       
         return p->aux;
}

int main(int argc, char **argv){
    aux *ptr = malloc(sizeof(aux));
    char *ret = encode2base64(argv[1], ptr);
    
    printf("%-5s\n", ret);
    
    free(ret);
    free(ptr);
    
    return 0;
}

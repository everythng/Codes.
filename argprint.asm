section .rodata
        b db 0xa

section .text
        global _start
 
_start:

    mov edi, [esp+8]
    
    not ecx
repne scasb 
  
    not ecx
      dec ecx    
       
    mov edx, ecx
    mov ecx, [esp+8]           
             
    push ebp
    mov ebp, esp
        
    sub esp, 8
 
    mov eax, 4
    mov ebx, 1
    
    mov [ebp-4], ecx
    mov [ebp-8], edx           
                          
    call pstr
    int 80h

exit:

   mov eax,4
   mov edx,1    	 
   mov ecx,b
   mov ebx,1

   int 80h

   mov eax,1
   sub ebx,ebx
    
   int 80h

pstr:     
       push ebp
       mov ebp,esp
     
      add esp, 12
      mov ecx,[ebp+12]
      mov edx,[ebp+8]
      
      leave
      ret  
       

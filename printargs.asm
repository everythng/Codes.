section .rodata
      n db 0xa

section .text
      global _start

_start:

      mov ebp, [esp]        
            
           .loop:
             add esp, 4
                 mov edi, [esp]

              mov ecx, 0xffffffff
              xor eax,eax
      repne scasb
              inc ecx
              not ecx
      
      
      mov al, 4 
      mov edx, ecx 

      mov ebx, 1
      mov ecx, [esp]   
      int 0x80 
     
      mov eax, 4
      mov edx, 1
      mov ecx, n
      int 0x80
 
      sub ebp, 1
      cmp ebp, 0
      jne .loop

      mov eax, 1
      xor ebx, ebx
      int 0x80

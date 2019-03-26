%macro exit 0
       mov eax, 1
       xor ebx, ebx
       int 0x80
%endmacro

section .rodata
        n db 0xa
                
%macro write_nl 0
       mov eax, 4
       mov ebx, 1
       mov edx, 1
       mov ecx, n
       int 0x80
%endmacro

section .bss
        num resb 10

section .text
         global _start
         
_start:
         xor ecx,ecx
         
          .loop:
          
                 inc ecx
                 add ecx, '0'
                 
                 mov [num], ecx
                 push ecx
                
                 mov eax, 4
                 mov ebx, 1
                 mov edx, 1
                 mov ecx, num
                 
                 int 0x80
                 
                 pop ecx
                 sub ecx, '0'
                               
                 cmp ecx, 9
                 jne .loop
                      
           write_nl
           exit
      

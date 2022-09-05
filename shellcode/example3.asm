;run /bin/sh and normal exit
;nasm -f elf32 -o example3.o example3.asm
;ld -m elf_i386 -o example3 example3.o && ./example3
; 32-bit linux

section .bss


section .text
    global _start       ; must be decleared for linker

_start:                 ; linker to entry point

    ;xoring anything with itself clears itself
    xor eax, eax        ;zero out eax
    xor ebx, ebx        ;zero out ebx
    xor ecx, ecx        ;zero out ecx
    xor edx, edx        ;zero out edx

    push eax            ; string terminator
    push 0x68732f6e     ;"hs/n"
    push 0x69622f2f     ;"ib//"
    mov ebx, esp        ;"//bin/sh",0 pointer is esp
    mov al, 0xb         ; mov eax, 11: execve
    int 0x80            ;syscall
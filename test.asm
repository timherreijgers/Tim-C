global _start

section .bss

x: resb 4

section .text 

_start:
    mov eax, 69
    mov [x], eax
    mov rax, 60
    mov rdi, [x]
    syscall

; _start:
;     push rbp
;     mov rbp, rsp

;     call foo
;     mov [rbp-4], eax
    
;     mov rax, 60
;     mov rdi, [rbp-4]
;     syscall

; foo:
;     push rbp
;     mov rbp, rsp
;     mov eax, 40
;     pop rbp
;     ret
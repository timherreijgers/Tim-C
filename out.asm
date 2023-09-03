global _start

bar:
        push    rbp
        mov     rbp, rsp
        mov     DWORD [rbp-4], 4
        mov     eax, DWORD [rbp-4]
        add     eax, 2
        pop     rbp
        ret
foo:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 4
        mov     DWORD [rbp-4], 2
        call    bar
        mov     edx, DWORD [rbp-4]
        add     eax, edx
        leave
        ret
_start:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 4
        call    foo
        mov     DWORD [rbp-4], eax
        mov     rax, 60
        mov     edi, DWORD [rbp-4]
        syscall
section .data
    msg db "Hello world!", 0ah   ; Define a string "Hello world!" followed by a newline character (0ah)

section .text
    global _start               ; Declare _start as a global symbol

_start:
    mov rax, 1                  ; Move the system call number for sys_write into rax (syscall number 1)
    mov rdi, 1                  ; Move the file descriptor for stdout into rdi (1)
    mov rsi, msg                ; Move the address of the message string into rsi
    mov rdx, 13                 ; Move the length of the message string into rdx (13 characters including the newline)
    syscall                     ; Invoke the system call to write the message to stdout

    mov rax, 60                 ; Move the system call number for sys_exit into rax (syscall number 60)
    mov rdi, 0                  ; Move the exit status (0) into rdi
    syscall                     ; Invoke the system call to exit the program

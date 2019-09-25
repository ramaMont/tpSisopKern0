#include <sys/syscall.h>  // SYS_write, SYS_exit
.globl main
main:

        mov $SYS_write, %eax   // %eax == syscall number
        mov $1, %ebx           // %ebx == first argument (fd)
        mov $(%esp+8), %ecx         // %ecx == second argument (buf)
        mov %esp, %edx         // %edx == third argument (count)
        int $0x80

        push $7
        call return


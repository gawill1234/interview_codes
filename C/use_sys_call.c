#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

/*
 *   Normal use of system calls.
 *   Though, no error checking here and
 *   in practice there should be.
 *   But, as a syscall demo, it will do
 */
void uselibwrapper() {
char buffer[128];
int fd, count;

   fd = open("syscall1.txt", O_RDONLY);
   count = read(fd, &buffer[0], 128);
   write(1, &buffer[0], count);
   close(fd);

   return;
}

/*
 *   syscall invocation of syscall.
 *   Again, no error checking here and
 *   in practice there should be.
 *   But, as a syscall demo, it will do
 *   Also, in some instances doing it this
 *   way has been deprecated.  So it may
 *   or may not work/compile.
 */
void usesyscall() {
char buffer[128];
int fd, count;

    syscall(SYS_open, "syscall2.txt", O_RDONLY, &fd);
    syscall(SYS_read, fd, &buffer[0], 128, &count);
    syscall(SYS_write, 1, &buffer[0], count);
    syscall(SYS_write, 1, "\n", 2);
    syscall(SYS_close, fd);
    return;
}

/*
 *   Still working on the assembly method
 */
void useassembly() {

   return;
}

int main() {

   uselibwrapper();
   usesyscall();
   useassembly();

   exit(0);
}

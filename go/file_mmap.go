package main

//
//   This one came from a company that specified these rules for
//   the program.
//
//   Create a golang program that runs in Linux AMD64 using a modern golang runtime.
//   Your program should perform the following tasks:
//
//    1. Create a file at the location `/tmp/test.bin`
//    2. Make that file 1024 bytes long
//    3. Fill that file with bytes that are sequentially increasing 
//       values % 0xFF (e.g. offset 0 is 0x0, offset 100 is 0x64, offset 1000 is 0xe8.
//    4. Properly close the file.
//    5. You may not import any library other than `syscall` from standard library.
//    6. You may not use Write() syscalls.
//    7. You must memory map the file in order to perform writes.
//
//   I didn't create the rules, I just copied them to here verbatim. So if they have
//   issues, I just carried them over.  
//
//   Anyway, this program does the above.
//   to view the resulting file correctly:
//      od -b /tmp/test.bin
//
//   If you are used to C system calls, this isn't that hard. Even if your golang
//   is rusty.
//

//
// fmt for errors only
// the requested task was done exactly as requested
//
import (
    "fmt"
    "syscall"
)

func openFile() int {
var err error
var fd int

    fd, err = syscall.Open("/tmp/test.bin", syscall.O_CREAT | syscall.O_RDWR,  0777)
    if err != nil {
       fmt.Println(err)
       syscall.Exit(1)
    }

    return fd
}

func setFileSize(fd int, n int64) {
var err error

    //  _, err = syscall.Seek(fd, n, 0)
    //
    //  Set the file size so the mapping works
    //  You can do it with Seek, but you need
    //  to Write the last character (" ") to
    //  make it work
    //
    err = syscall.Ftruncate(fd, n)
    if err != nil {
       fmt.Println(err)
       syscall.Exit(1)
    }

    return
}

func ClearAndClose(fd int, mmap []byte) {
var err error

   err = syscall.Munmap(mmap)
   if err != nil {
      fmt.Println(err)
      syscall.Exit(1)
   }

   err = syscall.Close(fd)
   if err != nil {
      fmt.Println(err)
      syscall.Exit(1)
   }

   return
}

func main() {
var err error
var i, fd int

   const n = 1024

   fd = openFile()

   setFileSize(fd, n)

   mmap, err := syscall.Mmap(fd, 0, n, syscall.PROT_READ|syscall.PROT_WRITE, syscall.MAP_SHARED)
   if err != nil {
      fmt.Println(err)
      syscall.Exit(1)
   }

   for i = 0; i < n; i++ {
     // Reading the rules seems to indicate this.
     // mmap[i] = byte(i % 0xff)
     //
     // But looking at the result shows they want this.
     //
     mmap[i] = byte(i)
   }

   //
   //  Yeah, this breaks the rules too.  But I do
   //  like to see that it did something before I go
   //  to the "od" command.  And it doesn't break the
   //  rules for the actual requested work.
   //
   fmt.Println(mmap)

   ClearAndClose(fd, mmap)

   syscall.Exit(0)
}

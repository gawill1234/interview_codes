//
//  Another one that was part of an application 
//  process/question.  Instructions are as given in
//  the application process.
//
//  Write a Go program which does the following:
//  
//  * Creates a synchronous channel of integers
//  * Launches 10 producer goroutines numbered 0 through 9, which attempt to 
//  write their number to the channel until signaled to exit. These goroutines 
//  should print a message when they start and when they exit.
//
//  * Launches a consumer goroutine which reads from the channel, printing 
//  each number it reads, until it is either signaled to exit or it has 
//  read 30 numbers. If 30 numbers are read, the consumer goroutine should 
//  return and signal the entire program to shut down. The consumer should 
//  sleep 500 milliseconds between each read from the channel. The consumer 
//  should print a message when it starts and when it exits.
//
//  The program should catch the os.Interrupt signal and properly 
//  shut down all goroutines if it is received. If no signal is received, 
//  the program should shut down once the consumer has read 30 numbers 
//  from the channel. The program should not exit until all goroutines 
//  have returned (printing their exit messages), at which point it 
//  should print "Main routine exiting" and exit.
//
package main

import (
    "fmt"
    "time"
    "sync"
    "os"
    "os/signal"
    "syscall"
)

//
//   Producer.  Dump the producer number to the channel
//   until it is signaled to quit.
//
func pushMyNumber (mynum int, vals chan int,
                   wg *sync.WaitGroup, ch <-chan bool) {

   defer wg.Done()
   fmt.Println("Worker starting: ", mynum)
   for {
      //
      //   Make waiting on the quit non-blocking
      //
      select {
         case <-ch:
            fmt.Println("worker done: ", mynum)
            return
         default:
            //
            //   Make waiting on the integer channel non-blocking
            //
            select {
                case vals <- mynum:
                   continue
                default:
                   continue
            }
      }
   }
}
//
//   Consumer.  Gets up to 30 numbers from the channel
//   If it gets to 30, is sets a quit value and returns/exits
//   If it is interrupted (SIGINT) it sets a quit value
//   and returns/exits
//
func getMyNumbers(vals chan int, wg *sync.WaitGroup,
                  ch chan bool, signals chan os.Signal) {

   defer wg.Done()
   fmt.Println("Consumer starting")
   for i := 0; i < 30; i += 1 {
      //
      //   make waiting on a signal non-blocking
      //   if we get a signal, set the quit value
      //   and return/exit
      //   otherwise
      //   continue to get numbers  (until we have 30)
      //
      select {
         case sig := <-signals:
            fmt.Println("Consumer exiting: ", sig)
            ch <- true
            return
         default:
            time.Sleep(500 * time.Millisecond)
            mynumber := <-vals
            fmt.Printf("value:   %d, %d\n", mynumber, i + 1)
      }
   }

   fmt.Println("Consumer exiting")

   ch <- true

   return
}

func main() {
   var wg sync.WaitGroup

   ch := make(chan bool)
   vals := make(chan int)
   signals := make(chan os.Signal, 1)

   //
   //  Register the channel to receive SIGINT and SIGTERM.
   //
   signal.Notify(signals, syscall.SIGINT, syscall.SIGTERM)

   //
   //   10 producer routines
   //
   for i := 0; i < 10; i += 1 {
      wg.Add(1)
      go pushMyNumber(i, vals, &wg, ch)
   }

   //
   //   1 consumer routine
   //
   wg.Add(1)
   go getMyNumbers(vals, &wg, ch, signals)
   fmt.Println("Waiting on consumer with ch")
   <-ch

   //
   //   All done, shutting down, cleaning up
   //
   fmt.Println("Closing ch")
   close(ch)

   fmt.Println("Waiting")
   wg.Wait()

   fmt.Println("Main routine exiting")
   os.Exit(1)
}

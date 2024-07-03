using System;

namespace Rotate {

   class RotateArr {

      static void printarray(int[] myarray, int arrsz) {
      int i;
      
         Console.Write("Array: ");
         for (i = 0; i < arrsz; i++) {
            Console.Write(" " +  myarray[i]);
         }
         Console.WriteLine("\n");
      
         return;
      }
      
      static int divisor(int shift, int arrsz) {
      int temp;
      
         while (arrsz > 0) {
            if (arrsz == 0) {
               return shift; 
            } else {
               temp = shift;
               shift = arrsz;
               arrsz = temp % arrsz;
            }
         }
         return(shift);
      } 
      
      //
      //   Allows the use of any value as the shift.
      //   Negative, larger than the array, whatever,
      //   this will put the shift to a number that
      //   makes sense.
      //
      static int getrealshift(int arrsz, int shift) {
      
         if (shift < 0) {
            shift = shift * (-1);
            shift = arrsz - (shift % arrsz);
         } else {
            shift = shift % arrsz;
         }
      
         return(shift);
      }
      
      //
      //  Given a value and a shift, locate where
      //  the second value should go within the 
      //  array.
      //
      static int secondpos(int start, int arrsz, int shift) {
      int newpos;
      
         newpos = start + shift;
         if (newpos > (arrsz - 1)) {
            newpos = newpos - arrsz;
         }
      
         return(newpos);
      }
      
      //
      //   Uses a second array to store the values
      //   in the new positions and returns it.
      //   The easy way ...
      //   While you need a second array, this one is
      //   done is one pass through the original array.
      //   Everything goes to the right position on the
      //   first (single) pass.
      //   Shift is to the right.
      //
      static int[] rotate(int[] myarray, int arrsz, int shift) {
      int i, j;
      int[] newarray = new int[myarray.Length];
      
         Console.WriteLine("Supplied shift: " + shift);
         shift = getrealshift(arrsz, shift);
         Console.WriteLine("Actual shift  : " + shift);
      
         for (i = 0; i < arrsz; i++) {
            j = secondpos(i, arrsz, shift);
            newarray[j] = myarray[i];
         }
      
         return(newarray);
      }
      
      //
      //   The hard way.  Rotate the array
      //   "in place".  This one is in place,
      //   but it takes "longer" since it can
      //   only go so far through the array at a
      //   time.  So things get moved more
      //   than once.  If the array size is a prime
      //   number size, the shift is always one at
      //   a time.
      //   The divisor thing is a sort of performance
      //   improvement.  If you want it easier, rotate
      //   can always be 1 and it will work just fine.
      //   Shift is to the right.
      //
      static void rotate2(int[] myarray, int arrsz, int shift) {
      int i, newhead, tail, temp, rotate, done;
      
         Console.WriteLine("Supplied shift: " + shift);
         shift = getrealshift(arrsz, shift);
         Console.WriteLine("Actual shift  : " + shift);
         rotate = divisor(shift, arrsz); 
         Console.WriteLine("shift:  " + shift + ",   rotate2: " + rotate);
      
         for (i = 0; i < (arrsz - shift); i++) {
            temp = myarray[i];
            done = 0;
            newhead = i;
            while (done != 1) {
               tail = secondpos(newhead, arrsz, rotate);
               if (tail == i) {
                  done = 1;
               } else {
                  myarray[newhead] = myarray[tail];
                  newhead = tail;
               }
            }
            myarray[newhead] = temp;
         }
      
         return;
      }
      
      //
      //   Need to reinitialize the array for
      //   the inplace rotation.
      //
      static void reinit(int[] myarray, int arrsz) {
      int i;
      
         for (i = 0; i < arrsz; i++) {
            myarray[i] = i;
         }
         return;
      }
      
      static void main() {
      int[] myarray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
      int[] newarray;
      int arrsz, shift;
      
         arrsz = myarray.Length;
      
         shift = 5;
         Console.WriteLine("shift: " +  shift + ",  rotate()");
         newarray = rotate(myarray, arrsz, shift);
         printarray(myarray, arrsz);
         printarray(newarray, arrsz);
         Console.WriteLine("\n");
      
         Console.WriteLine("shift: " +  shift + ",  rotate()");
         reinit(myarray, arrsz);
         printarray(myarray, arrsz);
         rotate2(myarray, arrsz, shift);
         printarray(myarray, arrsz);
         Console.WriteLine("\n");
      
         shift = 31;
         reinit(myarray, arrsz);
         Console.WriteLine("shift: " +  shift + ",  rotate()");
         newarray = rotate(myarray, arrsz, shift);
         printarray(myarray, arrsz);
         printarray(newarray, arrsz);
         Console.WriteLine("\n");
      
         reinit(myarray, arrsz);
         Console.WriteLine("shift: " +  shift + ",  rotate()");
         printarray(myarray, arrsz);
         rotate2(myarray, arrsz, shift);
         printarray(myarray, arrsz);
         Console.WriteLine("\n");
      
         shift = -2;
         reinit(myarray, arrsz);
         Console.WriteLine("shift: " +  shift + ",  rotate()");
         newarray = rotate(myarray, arrsz, shift);
         printarray(myarray, arrsz);
         printarray(newarray, arrsz);
         Console.WriteLine("\n");
      
         reinit(myarray, arrsz);
         Console.WriteLine("shift: " +  shift + ",  rotate()");
         printarray(myarray, arrsz);
         rotate2(myarray, arrsz, shift);
         printarray(myarray, arrsz);
         Console.WriteLine("\n");
      }
   }
}

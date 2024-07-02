//
// C# program to find the largest
// integer in an array.
//
using System; 

// namespace declaration 
namespace MaxElemApp { 
    
    // Class declaration 
    class Geeks { 

	static int maxelem(int[] elemarr) {
           int i, curmax;

	   //
	   //   Sorry, there is nothing fancy or tricky
	   //   about finding the largest element in an
	   //   array.  You have to look at all of the
	   //   elements.  This uses and integer array.
	   //   Loop starts at 1 because you initialize
	   //   curmax with 0.
	   //
	   curmax = elemarr[0];
	   for (i = 1; i < elemarr.Length; i++) {
	      if (elemarr[i] > curmax) {
	         curmax = elemarr[i];
	      }
	   }

	   return(curmax);

	}

        
        // Main Method 
        static void Main(string[] args) { 
           int[] elemarr = {401, 1, 99, 3, 5, 8, 462, 102, 4, 199, 301, 14, 87, 71, 5, 9, 200, 151, 88, 400};
	   int arrmax;

	   if (elemarr.Length > 0) {
	      arrmax = maxelem(elemarr);
	      Console.WriteLine("Max element: " + arrmax);
	   } else {
              Console.WriteLine("Max element: None<array size is 0>");
	   }
        } 
    } 
} 

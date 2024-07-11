//
// C# program to swap the position of
// 2 variable values.
//
using System; 

// namespace declaration 
namespace SwapApp { 
    
    // Class declaration 
    class Geeks { 

	//
	//   Swap two variables without a third
	//   temporary container variable.
	//
	static void swap2(int a, int b) {

	   Console.WriteLine("NOT SWAPPED, a: " + a + ", b: " + b);

           a = a + b;
           b = a - b;
	   a = a - b;

	   Console.WriteLine("ARE SWAPPED, a: " + a + ", b: " + b + "\n");
	   return;

	}

        
        // Main Method 
        static void Main(string[] args) { 
            
            swap2(18, 32); 
            swap2(-2, 103); 
            swap2(54, -19); 
            swap2(-2, -9); 
            swap2(10024, 29); 
        } 
    } 
} 

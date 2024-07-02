//
//
using System; 

// namespace declaration 
namespace CircleApp { 
    
    // Class declaration 
    class Geeks { 

	public static double PI = 3.1415926;

	static double areaofcircle(double r) {

	   return(PI * (r * r));

	}

	static double areaofcircle2(double r) {

	   return(PI * Math.Pow(r, 2.0));

	}

	static double circumferenceofcircle(double r) {

	   return(2 * PI * r);

	}

        
        // Main Method 
        static void Main(string[] args) { 
	double a;
            
	    a = 3.0;
	    Console.WriteLine("Circle radius: " + a + ", Circle(mult) area: " + areaofcircle(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle(pow) area: " + areaofcircle2(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle circumference: " + circumferenceofcircle(a) + "\n");

	    a = 8.25;
	    Console.WriteLine("Circle radius: " + a + ", Circle(mult) area: " + areaofcircle(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle(pow) area: " + areaofcircle2(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle circumference: " + circumferenceofcircle(a) + "\n");

	    a = 3.1415926;
	    Console.WriteLine("Circle radius: " + a + ", Circle(mult) area: " + areaofcircle(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle(pow) area: " + areaofcircle2(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle circumference: " + circumferenceofcircle(a) + "\n");

	    a = 2.1;
	    Console.WriteLine("Circle radius: " + a + ", Circle(mult) area: " + areaofcircle(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle(pow) area: " + areaofcircle2(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle circumference: " + circumferenceofcircle(a) + "\n");

	    a = 1.0;
	    Console.WriteLine("Circle radius: " + a + ", Circle(mult) area: " + areaofcircle(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle(pow) area: " + areaofcircle2(a));
	    Console.WriteLine("Circle radius: " + a + ", Circle circumference: " + circumferenceofcircle(a));
        } 
    } 
} 

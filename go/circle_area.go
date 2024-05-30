package main
  
import ("fmt";"math")

var PI float64 = 3.1415926

/*
 *   area using radius squared
 *   by multiplying by itself
 */
func areaofcircle(r float64) float64{

   return(PI * (r * r))
}

/*
 *   area using radius squared
 *   by using pow() function.
 *   Only reason math.h is included.
 */
func areaofcircle2(r float64) float64 {

   return(PI * math.Pow(r, 2))
}

func main() {
var a float64

   a = 3.0
   fmt.Printf("(mult) Circle radius: %f, Circle area: %f\n", a, areaofcircle(a))
   fmt.Printf("(pow)  Circle radius: %f, Circle area: %f\n", a, areaofcircle2(a))
   fmt.Printf("\n")
   a = 8.25
   fmt.Printf("(mult) Circle radius: %f, Circle area: %f\n", a, areaofcircle(a))
   fmt.Printf("(pow)  Circle radius: %f, Circle area: %f\n", a, areaofcircle2(a))
   fmt.Printf("\n")
   a = 3.1415926
   fmt.Printf("(mult) Circle radius: %2.7f, Circle area: %f\n", a, areaofcircle(a))
   fmt.Printf("(pow)  Circle radius: %2.7f, Circle area: %f\n", a, areaofcircle2(a))
   fmt.Printf("\n")
   a = 2.1
   fmt.Printf("(mult) Circle radius: %f, Circle area: %f\n", a, areaofcircle(a))
   fmt.Printf("(pow)  Circle radius: %f, Circle area: %f\n", a, areaofcircle2(a))
   fmt.Printf("\n")
   a = 1.0
   fmt.Printf("(mult) Circle radius: %f, Circle area: %f\n", a, areaofcircle(a))
   fmt.Printf("(pow)  Circle radius: %f, Circle area: %f\n", a, areaofcircle2(a))
}

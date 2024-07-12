using System;

namespace StrRev {
   class ReverseIt {
      
      /*********************************************************************/
      /*  The string reverse problem
          There are 3 different(well almost different) solutions presented
          here.  There is a FOR loop, a WHILE loop, and a DO-WHILE loop.
          They all work.  Take your pick.
      */
      static void str_reverse (char[] goofy)
      {
      char c;
      int i, len, transit;
      
         if (goofy == null)
            return;
      
         len = goofy.Length;
         transit = (len + 1) / 2;
      
         /*  Technically, we could check for 1 instead of zero, but lets
             show that the loop works in all situations
         */
         if (len > 0) {
            Console.Write("string reverse(for, start string, {0})   :  {1}\n", len, string.Join("", goofy));
      
            for (i = 0; i < transit; i++) {
               c = goofy[len - (i + 1)];
               goofy[len - (i + 1)] = goofy[i];
               goofy[i] = c;
            }
      
            Console.Write("string reverse(for, final string, {0})   :  {1}\n", len, string.Join("", goofy));
         } else {
            Console.Write("string_reverse, for,  {0})   :  NOTHING TO REVERSE\n", len);
         }
      }
      
      static void str_reverse2(char[] goofy)
      {
      char c;
      int len, done;
      
         if (goofy == null)
            return;
      
         len = goofy.Length;
      
         /*  Technically, we could check for 1 instead of zero, but lets
             show that the loop works in all situations
         */
         if (len > 0) {
      
            Console.Write("string reverse2(while, start string, {0})   :  {1}\n", len, string.Join("", goofy));
      
            done = 0;
      
            while (len > done) {
               len--;
               c = goofy[len];
               goofy[len] = goofy[done];
               goofy[done] = c;
               done++;
            }
      
            Console.Write("string reverse2(while, final string, {0})   :  {1}\n",
                    len + done, string.Join("", goofy));
         } else {
            Console.Write("string_reverse2, while,  {0})   :  NOTHING TO REVERSE\n", len);
         }
      }
      
      static void str_reverse3(char[] goofy)
      {
      char c;
      int len, done;
      
         if (goofy == null)
            return;
      
         len = goofy.Length;
      
         /*  Technically, we could check for 1 instead of zero, but lets
             show that the loop works in all situations
         */
         if (len > 0) {
      
            Console.Write("string reverse3(do, start string, {0})   :  {1}\n", len, string.Join("", goofy));
      
            done = 0;
      
            do {
               len--;
               c = goofy[len];
               goofy[len] = goofy[done];
               goofy[done] = c;
               done++;
            } while (len > done);
      
            Console.Write("string reverse3(do, final string, {0})   :  {1}\n",
                    len + done, string.Join("", goofy));
         } else {
            Console.Write("string_reverse3, do,  {0})   :  NOTHING TO REVERSE\n", len);
         }
      }
      /***************************************************/
      static void Main(string[] args)
      {
      char[] blarg;

         blarg = new char[512];
      
         blarg = "hello there odd".ToCharArray();
         str_reverse(blarg);
         blarg = "hello there even".ToCharArray();
         str_reverse(blarg);
         blarg = "I".ToCharArray();
         str_reverse(blarg);
         blarg = "".ToCharArray();
         str_reverse(blarg);
         Console.Write("\n\n");

         blarg = "hello there odd".ToCharArray();
         str_reverse2(blarg);
         blarg = "hello there even".ToCharArray();
         str_reverse2(blarg);
         blarg = "I".ToCharArray();
         str_reverse2(blarg);
         blarg = "".ToCharArray();
         str_reverse2(blarg);
         Console.Write("\n\n");

         blarg = "hello there odd".ToCharArray();
         str_reverse3(blarg);
         blarg = "hello there even".ToCharArray();
         str_reverse3(blarg);
         blarg = "I".ToCharArray();
         str_reverse3(blarg);
         blarg = "".ToCharArray();
         str_reverse3(blarg);
         Console.Write("\n\n");
      
      }
   }
}

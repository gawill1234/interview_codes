using System;
using System.Linq;

//
//  Count vowels and consonants in a string.
//  First make sure what you are looking at
//  is a letter, not some other character.
//  Then see if it is a vowel or not.
//
namespace Stuff {
   class gleeb {

      static string vowels = "aeiou";
      static string zozo = "abcdefghijklmnopqrstuvwxyz";

      static (int, int) vowel(string mystring) {
      int vowel_count, cons_count;
      vowel_count = cons_count = 0;

         foreach (char letter in mystring.ToLower().ToCharArray()) {
            if (zozo.Contains(letter)) {
               if (vowels.Contains(letter)) {
                  vowel_count += 1;
               } else {
                  cons_count += 1;
               }
            }
         }

         return(vowel_count, cons_count);
      }

      static void Main(string[] args) {
      int vowel_count, cons_count;
      string mystring;

         mystring = "this is stuff";
         (vowel_count, cons_count) = vowel(mystring);
         Console.Write($"String: \"{mystring}\"\n");
         Console.Write($"Vowels: {vowel_count}, Consonants: {cons_count}\n\n");

         mystring = "abcdefghijklmnopqrstuvwxyz";
         (vowel_count, cons_count) = vowel(mystring);
         Console.Write($"String: \"{mystring}\"\n");
         Console.Write($"Vowels: {vowel_count}, Consonants: {cons_count}\n\n");

         mystring = "ABC! DEF^ G..,, HIJKLMNOPQRSTUVWXYZ";
         (vowel_count, cons_count) = vowel(mystring);
         Console.Write($"String: \"{mystring}\"\n");
         Console.Write($"Vowels: {vowel_count}, Consonants: {cons_count}\n\n");

         mystring = "This is a real sentence.  With punctuation and everything!";
         (vowel_count, cons_count) = vowel(mystring);
         Console.Write($"String: \"{mystring}\"\n");
         Console.Write($"Vowels: {vowel_count}, Consonants: {cons_count}\n\n");

         mystring = "0123456789";
         (vowel_count, cons_count) = vowel(mystring);
         Console.Write($"String: \"{mystring}\"\n");
         Console.Write($"Vowels: {vowel_count}, Consonants: {cons_count}\n");
      }
   }
}

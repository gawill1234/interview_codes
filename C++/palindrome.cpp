#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

// 65 - 90  Ascii uppercase
// 97  - 122 Ascii lowercase
/*
 *  For us, palindromes are generally
 *  defined by the letters only.  So,
 *  something like "Madam, I', Adam"
 *  becomes a palindrome.  But, you have
 *  remove all of the spaces and the
 *  punctuation while leaving the letters
 *  in order.  Also, making all of the
 *  letters the same case helps.
 */

class palindromeString {

   public:
      char *origstring, *newstring;
      bool palindrome;

   palindromeString(std::string mystring) {

      palindrome = false;

      /*
       *   Transfer all values completely to class
       */
      origstring = (char *)calloc(mystring.length() + 1, 1);
      strcpy(origstring, mystring.c_str());

      onlyletters();
      isitpalindrome();

      return;
   }

   ~palindromeString() {

      free(newstring);
      free(origstring);
      std::printf("Destructor complete\n\n");

      return;
   }

   
   void outputresult() {
      if (palindrome) {
         std::printf("IS a palindrome\n");
      } else {   
         std::printf("NOT a palindrome\n");
      }
   
      return;
   }

   private:

   /*
    *   Compare the letters from the
    *   front to those in the back
    *   to see if they are the same.
    *   If they are, palindrome.  If
    *   not, not a palindrome.
    *   Simple.
    */
   void isitpalindrome() {
   int mlen, trac, i;
   
      mlen = strlen(newstring);
   
      i = 0;
      trac = (mlen + 1) / 2;
      mlen--;
   
      while (i < trac) {
         if (newstring[i] != newstring[mlen - i]) {
            palindrome = false;
            return;
         }
         i++;
      }
   
      palindrome = true;
      return;
   }

   void onlyletters() {
   int i, j;
   char a;
   
      newstring = (char *)calloc(strlen(origstring), sizeof(char));
   
      /*
       *   Make all letters the same case
       */
      for (i = 0; i < strlen(origstring); i++) {
         origstring[i] = tolower(origstring[i]);
      }
   
      /*
       *   Remove everything but the letters.
       *   So get rid of spaces and punctuation,
       *   etc.
       */
      j = 0;
      for (i = 0; i < strlen(origstring); i++) {
         /*
          *   If the character is within the ascii
          *   lower case realm, keepit.  Otherwise,
          *   drop it.
          *   No numbers right now.
          *
          *   Found out by accident that I could use
          *   string mystring here (from the constructor)
          *   and it would work just fine.  I didn't expect
          *   that.  Referencing std::string mystring as an
          *   array element did work.  ... note to self.
          *   It also worked in the for loop above.
          */
         if ((int)origstring[i] >= 97) {
            if ((int)origstring[i] <= 122) {
               newstring[j] = origstring[i];
               j++;
            }
         }
      }
   
      return;
      
   }
   
};

void shrinkwrap(std::string mystring) {

   std::printf("SHRINKWRAP use of object\n");
   std::printf("Working with:  %s\n", mystring.c_str());
   palindromeString *myPal = new palindromeString(mystring);
   myPal->outputresult();

   /*
    *   Since this object was dynamically allocated (new),
    *   the destructor will NOT be called automatically.  It
    *   has to be called explicitly.
    */
   myPal->~palindromeString();
   return;
}

void shrinkwrap2(std::string mystring) {

   std::printf("SHRINKWRAP2 use of object\n");
   std::printf("Working with:  %s\n", mystring.c_str());
   palindromeString myPal(mystring);
   myPal.outputresult();

   /*
    *  The use of this function with a return
    *  causes the "myPal" object to go out of
    *  scope which causes the object destructor
    *  to be called on return.
    */
   return;
}

int main() {
std::string str1 = "kayak\0";
std::string str2 = "Deified\0";
std::string str3 = "Madam, in Eden, I'm Adam\0";
std::string str4 = "Henry, I am here\0";
std::string str5 = "Henry, I am yrneh\0";
std::string str6 = "Red roses run no risk, sir, on Nurse’s order.\0";
char *newstr;

   shrinkwrap(str1);
   shrinkwrap2(str1);
   std::printf("#############\n\n");
   shrinkwrap(str2);
   shrinkwrap2(str2);
   std::printf("#############\n\n");
   shrinkwrap(str3);
   shrinkwrap2(str3);
   std::printf("#############\n\n");
   shrinkwrap(str4);
   shrinkwrap2(str4);
   std::printf("#############\n\n");
   shrinkwrap(str5);
   shrinkwrap2(str5);
   std::printf("#############\n\n");
   shrinkwrap(str6);
   shrinkwrap2(str6);

}

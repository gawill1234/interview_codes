#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
char *onlyletters(char mystring[]) {
char *newstring;
int i, j;
char a;

   newstring = (char *)calloc(strlen(mystring), sizeof(char));

   /*
    *   Make all letters the same case
    */
   for (i = 0; i < strlen(mystring); i++) {
      mystring[i] = tolower(mystring[i]);
   }

   /*
    *   Remove everything but the letters.
    *   So get rid of spaces and punctuation,
    *   etc.
    */
   j = 0;
   for (i = 0; i < strlen(mystring); i++) {
      /*
       *   If the character is within the ascii
       *   lower case realm, keepit.  Otherwise,
       *   drop it.
       *   No numbers right now.
       */
      if ((int)mystring[i] >= 97) {
         if ((int)mystring[i] <= 122) {
            newstring[j] = mystring[i];
            j++;
         }
      }
   }

   return(newstring);
   
}

/*
 *   Compare the letters from the
 *   front to those in the back
 *   to see if they are the same.
 *   If they are, palindrome.  If
 *   not, not a palindrome.
 *   Simple.
 */
int isitpalindrome(char *mystring) {
int mlen, trac, i;

   mlen = strlen(mystring);

   i = 0;
   trac = (mlen + 1) / 2;
   mlen--;

   while (i < trac) {
      if (mystring[i] != mystring[mlen - i]) {
         return(0);
      }
      i++;
   }

   return(1);
}

void outputresult(int value) {
   if (value) {
      printf("IS a palindrome\n");
   } else {   
      printf("NOT a palindrome\n");
   }

   return;
}

int main() {
char str1[] = "kayak\0";
char str2[] = "Deified\0";
char str3[] = "Madam, in Eden, I'm Adam\0";
char str4[] = "Henry, I am here\0";
char str5[] = "Henry, I am yrneh\0";
char str6[] = "Red roses run no risk, sir, on Nurse’s order.\0";
char *newstr;

   printf("Working with:  %s\n", str1);
   newstr = onlyletters(str1);
   outputresult(isitpalindrome(newstr));
   free(newstr);
   printf("#############\n\n");

   printf("Working with:  %s\n", str2);
   newstr = onlyletters(str2);
   outputresult(isitpalindrome(newstr));
   free(newstr);
   printf("#############\n\n");

   printf("Working with:  %s\n", str3);
   newstr = onlyletters(str3);
   outputresult(isitpalindrome(newstr));
   free(newstr);
   printf("#############\n\n");

   printf("Working with:  %s\n", str4);
   newstr = onlyletters(str4);
   outputresult(isitpalindrome(newstr));
   free(newstr);
   printf("#############\n\n");

   printf("Working with:  %s\n", str5);
   newstr = onlyletters(str5);
   outputresult(isitpalindrome(newstr));
   free(newstr);
   printf("#############\n\n");

   printf("Working with:  %s\n", str6);
   newstr = onlyletters(str6);
   outputresult(isitpalindrome(newstr));
   free(newstr);
}

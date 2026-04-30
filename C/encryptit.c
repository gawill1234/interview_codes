#include <stdio.h>

/*
 * KEY must be an int for this purpose
 */
#define KEY 22

int main() {
char text[100];
int i;
   
   // Input text
   printf("Enter text to encrypt: ");
   fgets(text, 100, stdin);
   
   // Encrypt text
   for (i=0; text[i] != '\0'; i++)
   {
   	text[i] = text[i] ^ (KEY + (i % KEY));
   }
   
   printf("Encrypted text: %s\n", text);
   
   // Decrypt text
   for (i = 0; text[i] != '\0'; i++)
   {
   	text[i] = text[i] ^ (KEY + (i % KEY));
   }
   	
   printf("Original text: %s\n", text);
   
   return 0;
}

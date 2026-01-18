#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/*
 *  This is what qsort wants, so this is
 *  what qsort gets.
 */
int compare_chars(const void *a, const void *b) {

    return (*(char *)a - *(char *)b);
}


void runnit(char *mystring) {
int n;

    printf("String before sorting: %s\n", mystring);
    n = strlen(mystring);
    qsort(mystring, n, sizeof(char), compare_chars);
    printf("String after sorting:  %s\n", mystring);

    return;

}

int main() {
char mystring[64];

   strcpy(mystring, "hello");
   runnit(mystring);
   strcpy(mystring, "massive flood");
   runnit(mystring);
   strcpy(mystring, "mississippi");
   runnit(mystring);
   strcpy(mystring, "smile");
   runnit(mystring);
   strcpy(mystring, "limes");
   runnit(mystring);
   strcpy(mystring, "slime");
   runnit(mystring);
   strcpy(mystring, "multi space with punctuation!");
   runnit(mystring);
   strcpy(mystring, "2468097135");
   runnit(mystring);
}

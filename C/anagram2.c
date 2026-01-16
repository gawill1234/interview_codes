#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Anagrams using qsort to sort.
 *
 *   Compare routine for qsort.
 */
int compare_chars(const void *a, const void *b) {
    /*
     *  Cast the void pointers to char pointers and dereference them
     *  This is bascially defined by what qsort needs to work
     *  properly.
     */
    return (*(char *)a - *(char *)b);
}

void wordstocompare(char str[], char str2[]) {
    int n;

    printf("String 1 before sorting: %s\n", str);
    n = strlen(str);
    qsort(str, n, sizeof(char), compare_chars);
    printf("String 1 after sorting:  %s\n", str);

    printf("String 2 before sorting: %s\n", str2);
    n = strlen(str2);
    qsort(str2, n, sizeof(char), compare_chars);
    printf("String 2 after sorting:  %s\n", str2);

    if (strcmp(str, str2) == 0) {
       printf("They are anagrams\n");
    } else {
       printf("They are not anagrams\n");
    }

    return;
}

int main() {
    char str[32], str2[32];

    strcpy(str, "slime\0");
    strcpy(str2, "limes\0");
    wordstocompare(str, str2);
    printf("\n");

    strcpy(str, "storm\0");
    strcpy(str2, "rotten\0");
    wordstocompare(str, str2);
    printf("\n");

    strcpy(str, "traps\0");
    strcpy(str2, "strap\0");
    wordstocompare(str, str2);
    printf("\n");

    strcpy(str, "slime\0");
    strcpy(str2, "limes\0");
    wordstocompare(str, str2);
    printf("\n");

    strcpy(str, "abcdef\0");
    strcpy(str2, "ghijkl\0");
    wordstocompare(str, str2);
    printf("\n");

    strcpy(str, "123456789\0");
    strcpy(str2, "987654321\0");
    wordstocompare(str, str2);

    return 0;
}

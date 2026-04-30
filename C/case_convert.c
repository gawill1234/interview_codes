#include <stdio.h>

int main()
{
char q, r, s;

    r = 'a';
    s = 'A';
    // Convert to lowercase
    printf("Convert any case to lower:\n");
    printf("'a' => '%c'\n", ('a' | ' '));
    printf("'A' => '%c'\n", ('A' | ' '));

    q = r | ' ';
    printf("'%c' => '%c'\n", r, q);
    q = s | ' ';
    printf("'%c' => '%c'\n", s, q);

    // Convert to uppercase
    printf("\nConvert any case to upper:\n");
    printf("'a' => '%c'\n", ('a' & '_'));
    printf("'A' => '%c'\n", ('a' & '_'));

    q = r & '_';
    printf("'%c' => '%c'\n", r, q);
    q = s & '_';
    printf("'%c' => '%c'\n", s, q);

    return 0;
}

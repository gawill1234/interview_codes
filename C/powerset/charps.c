#include <stdio.h>

#define BUF_SIZE 100

static void powerset(char *set, char *part)
{
   if (*set == '\0') {
      printf("{%s}\n", part);
   } else {
      part[-1] = set[0]; // s_0 is e
      powerset(set + 1, &part[-1]);
      powerset(set + 1, part);
   }
}

void enumerate_powerset_of_string(char *set)
{
char buf[BUF_SIZE]; // buffer for partial sets

   buf[BUF_SIZE - 1] = '\0';

   powerset(set, &buf[BUF_SIZE - 1]);

}

int main(void)
{
char *set = "ABCDEF";

   enumerate_powerset_of_string(set);
   return 0;
}

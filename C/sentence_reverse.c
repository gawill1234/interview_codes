#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sent_reverse(char *goofy)
{
int len;
char *holder, *marker, *word;

   if (goofy == NULL)
      return;

   len = strlen(goofy);

   if (len > 0) {
      holder = (char *)malloc(len + 1);
      marker = holder;

      printf("Sentence reverse(before):  %s\n", goofy);

      while ((word = strrchr(goofy, ' ')) != NULL) {
         *word = '\0';
         word++;
         strcpy(marker, word);
         marker = marker + strlen(word);
         *marker = ' ';
         marker++;
      }

      strcpy(marker, goofy);

      printf("                (after):   %s\n", holder);
      free(holder);
   } else {
      printf("Sentence reverse:          NOTHING TO REVERSE\n");
   }
 
}

int main()
{
char blarg[64];

   strcpy(blarg, "hello there");
   sent_reverse(blarg);
   strcpy(blarg, "hello      there");
   sent_reverse(blarg);
   strcpy(blarg, "only");
   sent_reverse(blarg);
   strcpy(blarg, "When in the course of human events");
   sent_reverse(blarg);
   strcpy(blarg, "exercise interesting an was this");
   sent_reverse(blarg);

}

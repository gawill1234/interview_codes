#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

struct ll {
   char *subheader;
   char *line;
   struct ll *next;
};

struct ll *newnode(char *subheader, char *line) {
struct ll *curr;
int len;

   curr = (struct ll *)malloc(sizeof(struct ll));

   len = strlen(subheader);
   curr->subheader = (char *)calloc(len, 1);
   memcpy(curr->subheader, (void *)subheader, len);

   len = strlen(line);
   curr->line = (char *)calloc(len, 1);
   memcpy(curr->line, (void *)line, len);

   curr->next =  NULL;

   return(curr);
}

void destroynode(struct ll *node) {

   free(node->line);
   free(node->subheader);
   free(node);

   return;
}

void printnode(struct ll *node) {

   //if (node->subheader != NULL) {
   //   printf("subheader:  %s\n", node->subheader);
   //}
   if (node->line != NULL) {
      printf("      {\"line\" :  \"%s\"}", node->line);
   }
}

void printlist(struct ll *head, int newheader) {
struct ll *trac;

   if (head != NULL) {
      trac = head;
      printf("{\"%s\": [\n", trac->subheader);
      while (trac != NULL) {
         printnode(trac);
         trac = trac->next;
         if (trac != NULL) {
            printf(",\n");
         }
      }
      if (newheader) {
         printf("\n   ]\n},\n");
      } else {
         printf("\n   ]\n}\n");
      }
   }

   return;
}

void destroylist(struct ll *head) {
struct ll *trac;

   if (head != NULL) {
      trac = head;
      while (head != NULL) {
         trac = head->next;
         destroynode(head);
         head = trac;
      }
   }

   return;
}

struct ll *addnode(struct ll *head, char *subheader, char *line) {
struct ll *trac;

   if (head == NULL) {
      head = newnode(subheader, line);
   } else {
      trac = head;
      while (trac->next != NULL) {
         trac = trac->next;
      }
      trac->next = newnode(subheader, line);
   }

   return(head);
}

int main(int argc, char **argv) {
struct ll *head = NULL;

   head = addnode(head, "tryit", "abcdefgh");
   head = addnode(head, "tryit", "123456789");
   head = addnode(head, "tryit", "zyzhabkdy");
   head = addnode(head, "tryit", "this is a goofy test");
   head = addnode(head, "tryit", "I hate psirt stuff");
   head = addnode(head, "tryit", "psirt stuff really sucks");

   printlist(head, 1);
   printlist(head, 0);

   destroylist(head);
}

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
 *   Detect a cycle using tortoise
 *   and hare.  Also contains the code
 *   to break a cycle.
 *   See function showacycle()
 */

typedef int boolean;
#define TRUE 1
#define FALSE 0

struct ll {
   char *subheader;
   char *line;
   int visited;
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

   curr->visited = 0;
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
int dumpcount = 0;

   if (head != NULL) {
      trac = head;
      printf("{\"%s\": [\n", trac->subheader);
      while (trac != NULL) {
         printnode(trac);
         dumpcount += 1;
         if (dumpcount > 100) {
            printf("\nCycle print demo done\n");
            printf("   Terminated at 100 nodes, not because list ended\n");
            return;
         }
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

/*
 *   Put a cycle at the third node
 *   of the linked list.
 */
void createacycle(struct ll *head) {
struct ll *trac, *third;
int count = 0;

   if (head != NULL) {
      trac = head;
      while (trac->next != NULL) {
         count += 1;
         if (count == 3) {
            third = trac;
            printf("Cycle created\n");
         }
         trac = trac->next;
      }
      /*
       *   Create the cycle
       */
      trac->next = third;
   }

   return;
}

/*
 *   See break_cycle.c for a more
 *   in depth explanation of this.
 */
void breakacycle(struct ll *head) {
struct ll *trac;

   if (head != NULL) {
      trac = head;
      while (trac != NULL) {
         if (trac->next->visited == 1) {
            trac->next = NULL;
            printf("Cycle broken\n");
         }
         trac->visited = 1;
         trac = trac->next;
      }
   }

   return;
}

/*
 *   Tortoise and hare technique to
 *   show a cycle exists.
 *   Though it does not show where the
 *   cycle starts.
 */
boolean showacycle(struct ll *head) {
struct ll *trac1, *trac2;

   if (head != NULL) {
      trac1 = trac2 = head;
      /*
       *   trac2 is the "hare" so
       *   it will find  NULL before
       *   the tortoise if NULL is to
       *   be found.  So check it for 
       *   NULL rather than the slower
       *   one.
       *   trac1 goes to trac1->next
       *   trac2 goes to trac2->next->next
       *   if possible.  If it is not, there
       *   is no cycle.
       */
      while (trac2 != NULL) {
         trac2 = trac2->next;
         if (trac2 != NULL) {
            /*
             *   Second increment of trac2
             *   the hare
             */
            trac2 = trac2->next;
            trac1 = trac1->next;
            if (trac1 == trac2) {
                printf("##### Cycle detected #####\n");
                return(TRUE);
            }
         }
      }
   }

   printf("List ended, no cycle\n");
   return(FALSE);
}


int main(int argc, char **argv) {
struct ll *head = NULL;

   head = addnode(head, "tryit", "abcdefgh");
   head = addnode(head, "tryit", "123456789");
   head = addnode(head, "tryit", "zyzhabkdy");
   head = addnode(head, "tryit", "this is a goofy test");
   head = addnode(head, "tryit", "I hate psirt stuff");
   head = addnode(head, "tryit", "psirt stuff really sucks");

   printf("Print list to show no cycle\n");
   printlist(head, 1);
   showacycle(head);

   createacycle(head);
   printf("Print list to show cycle was created\n");
   printlist(head, 1);
   if (showacycle(head)) {
      breakacycle(head);
   }

   printf("Print list to show no cycle\n");
   printf("   Should be the same as the first list print\n");

   printlist(head, 0);

   destroylist(head);

   exit(0);
}

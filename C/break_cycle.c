#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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
 *   Here is one way to break a cycle.
 *   Did it this way because it is easier
 *   than making a list of node addresses;
 *   which you could do instead.  The
 *   principle is the same.  But, you be
 *   checking the address of trac->next
 *   with a list of stored addresses to
 *   see if you were already there.  If
 *   you were, again, set next to NULL.
 *
 *   Yes, puting "visited" into your 
 *   linked list node implies you are
 *   debugging.  But honestly, so do
 *   the other methods.  One the "cycle
 *   bug" is fixed, you probably won't
 *   check for it any more.
 *
 *   If someone expects that check to be
 *   left in the working code, just tell
 *   them you are a better programmer than
 *   that and find it is best not to create
 *   the cycle in the first place.
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

   createacycle(head);
   printf("Print list to show cycle was created\n");
   printlist(head, 1);

   breakacycle(head);
   printf("Print list to show no cycle\n");
   printf("   Should be the same as the first list print\n");
   //printlist(head, 1);

   printlist(head, 0);

   destroylist(head);
}

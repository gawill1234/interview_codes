#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct ll {
   int node_value;
   struct ll *next;
};

/*
 *   Create a new node and initialize
 */
struct ll *newnode(int value) {
struct ll *curr;
int len;

   curr = (struct ll *)malloc(sizeof(struct ll));

   curr->node_value = value;
   curr->next = NULL;

   return(curr);
}

void printnode(struct ll *node) {

   printf("      {\"line\" :  \"%d\"}", node->node_value);
   return;
}

/*
 *   Print all the nodes in a list
 */
void printlist(struct ll *head) {
struct ll *trac;

   if (head != NULL) {
      trac = head;
      while (trac != NULL) {
         printnode(trac);
         trac = trac->next;
         if (trac != NULL) {
            printf(",\n");
         }
      }
      printf("\n");
   }

   return;
}

/*
 *   Destroy all the nodes in a list
 */
void destroylist(struct ll *head) {
struct ll *trac;

   if (head != NULL) {
      trac = head;
      while (head != NULL) {
         trac = head->next;
         free(head);
         head = trac;
      }
   }

   return;
}

/*
 *   Add a node to a linked list.
 *   Maintain numerical order (lower to higher).
 */
struct ll *addnode(struct ll *head, struct ll *in_node) {
struct ll *trac, *prev;

   if (head == NULL) {
      head = in_node;
   } else {
      if (in_node->node_value <= head->node_value) {
         in_node->next = head;
         head = in_node;
      } else {
         prev = trac = head;
         while ((trac->next != NULL) &&
                (in_node->node_value > trac->node_value)) {
            prev = trac;
            trac = trac->next;
         }
         if (trac->next == NULL) {
            if (in_node->node_value > trac->node_value) {
               trac->next = in_node;
            } else {
               in_node->next = trac;
               prev->next = in_node;
            }
         } else {
            in_node->next = trac;
            prev->next = in_node;
         }
      }
   }

   return(head);
}

/*
 *   Non-destructive merge of head and head2.
 *   The values in head2 are used to create
 *   new nodes  which are merged into head.
 */
struct ll *merge_list1(struct ll *head, struct ll *head2) {
struct ll *trac = NULL;

   trac = head2;
   while (trac != NULL) {
      head = addnode(head, newnode(trac->node_value));
      trac = trac->next;
   }

   return(head);
}

/*
 *   Destructive merge of head and head2.
 *   The actual nodes of head2 are merged into
 *   head thus destroying head2 in the process.
 */
struct ll *merge_list2(struct ll *head, struct ll *head2) {
struct ll *trac = NULL;

   trac = head2;
   while (trac != NULL) {
      head2 = trac->next;
      trac->next = NULL;
      head = addnode(head, trac);
      trac = head2;
   }

   return(head);
}

struct ll *createsmalllist(int first, int increment) {
struct ll *head = NULL;
int i;

   for (i = 0; i < 6; i++) {
      head = addnode(head, newnode(first));
      first += increment;
   }
   return(head);
}

int main(int argc, char **argv) {
struct ll *head = NULL;
struct ll *head2 = NULL;
struct ll *head3 = NULL;

   head2 = createsmalllist(1, 2);
   head = createsmalllist(2, 2);
   head3 = createsmalllist(2, 4);

   printf("Even list\n");
   printlist(head);
   printf("\n");

   printf("Even list(second)\n");
   printlist(head3);
   printf("\n");

   printf("Odd list\n");
   printlist(head2);
   printf("\n");

   /*
    *   Non-destructive merge of two
    *   lists.  Creates a new node
    *   using the values in head2 and
    *   merges the new node in to head.
    */
   head = merge_list1(head, head2);
   printf("Merged list (non-destructive)\n");
   printlist(head);
   printf("\n");

   /*
    *   Destructive merge of two
    *   lists.  head2 is destroyed
    *   as its nodes are merged in to
    *   head3.
    */
   head3 = merge_list2(head3, head2);
   printf("Merged list (destructive)\n");
   printlist(head3);

   /*
    *  head2 was destroyed.
    *  nothing to free.
    */
   destroylist(head);
   destroylist(head3);
}

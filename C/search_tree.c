#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
 *   A basic binary tree program
 *   Nothing fancy.  Just
 *      create node
 *      add node to tree
 *      then search for the nodes
 *      in the tree.
 *   This tree is just built as
 *   the values "appear".  There is
 *   no attempt to enforce balance.
 */

struct mynode {
   int myvalue;
   struct mynode *right, *left;
};

/*
 *   Search the tree for a given value.
 */
struct mynode *searchtreecmd(int srchvalue, struct mynode *parent) {
struct mynode *r;
int found = 0;
int count = 0;

   r = parent;
   while ((r != NULL) && (found != 1)) {
      count += 1;
      if (r->myvalue == srchvalue)
         found = 1;
      else {
         if (srchvalue < r->myvalue)
            r = r->left;
         else
            r = r->right;
      }
   }

   printf("LOOK UPS: %d, ", count);
   if (found == 1)
      return(r);
   else
      return(NULL);
}

/*
 *   Insert a new node into the tree.
 */
struct mynode *trinsert(struct mynode *tree, struct mynode *item) {

   struct mynode *trac;

   trac = tree;

   while (trac != NULL) {
      if (item->myvalue <= trac->myvalue) {
         if (trac->left != NULL) {
            trac = trac->left;
         } else {
            trac->left = item;
            return(tree);
         }
      } else if (item->myvalue > trac->myvalue) {
         if (trac->right != NULL) {
            trac = trac->right;
         } else {
            trac->right = item;
            return(tree);
         }
      } else {
         return(tree);
      }
   }

   return(tree);
}

/*
 *   Dump the values in the tree
 */
void printout(struct mynode *tree) {

   if (tree->right != NULL) 
      printout(tree->right);

   printf("%d\n", tree->myvalue);

   if (tree->left != NULL) 
      printout(tree->left);
}

/*
 *   Create a new node
 */
struct mynode *newnode(int value)
{
struct mynode *curr;

   curr = (struct mynode *)malloc(sizeof(struct mynode));
   curr->myvalue = value;
   curr->left =  NULL;
   curr->right = NULL;

   return(curr);
}

int main() {
   struct mynode *curr, *root;
   int i, valarr[1024];

   root = NULL;
   srand48((long)time(NULL));

   /*
    *   Add a bunch of random values
    *   to the tree.
    */
   for (i = 0; i < 1024; i++) {
      curr = newnode((int)(drand48() * (double)10000));
      /*
       *   Save each value that is added to
       *   the tree in and array so we can search
       *   for that value later.
       */
      valarr[i] = curr->myvalue;
      if ( curr != NULL ) {
         if (root == NULL) {
            root = curr;
         } else {
            root = trinsert(root, curr);
         }
      } else {
         printf("Malloc failed ...\n");
      }
   }

   //printout(root);
   /*
    *   Search for every value that was put
    *   in the tree.
    */
   for (i = 0; i < 1024; i++) {
      curr = searchtreecmd(valarr[i], root);
      printf("FOUND:  %d\n", curr->myvalue);
   }
}

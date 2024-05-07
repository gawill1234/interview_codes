#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
 *   A basic binary tree program
 *   Nothing fancy.  Just
 *      create node
 *      add node to tree
 *      dump tree
 */

struct mynode {
   int myvalue;
   struct mynode *right, *left;
};

struct mynode *trinsert(struct mynode *tree, struct mynode *item) {

   struct mynode *trac;

   if ( tree == NULL ) {
      printf("tree is NULL\n");
      fflush(stdout);
   }

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

void printout(struct mynode *tree) {

   if (tree->right != NULL) 
      printout(tree->right);

   printf("%d\n", tree->myvalue);

   if (tree->left != NULL) 
      printout(tree->left);
}

struct mynode *newnode(int value)
{
struct mynode *curr;

   printf("ADDING:  %d\n", value);
   fflush(stdout);
   curr = (struct mynode *)malloc(sizeof(struct mynode));
   curr->myvalue = value;
   curr->left =  NULL;
   curr->right = NULL;

   return(curr);
}

int main() {
   struct mynode *curr, *root;
   int i;

   root = NULL;
   srand48((long)time(NULL));

   for (i = 0; i < 25; i++) {
      curr = newnode((int)(drand48() * (double)10000));
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

   printout(root);
}

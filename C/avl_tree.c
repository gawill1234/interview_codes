#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *   Pretty generic implementation of an AVL tree.
 *   A basic balanced binary search tree.
 */

struct mynode {
   int myval;
   int height;
   struct mynode* left;
   struct mynode* right;
};

/*
 *  Get the maximum of two integers
 *  Simple utility function
 *
 *  You can do return((x > y) ? x : y); 
 *  But a basic if is clearer, to me.
 */
int MAX(int x, int y) {

   if (x > y)
      return(x);

   return(y);
}

/*
 *   Get balance/height of the node
 */
int getheight(struct mynode *bh)
{

   if (bh == NULL)
      return(0);

   return(bh->height);
}

/*
 *  Create a new node
 */
struct mynode* createmynode(int myval)
{
struct mynode *newnode;
 
   newnode = (struct mynode *)malloc(sizeof(struct mynode));

   newnode->myval = myval;
   newnode->height = 1;
   newnode->left = NULL;
   newnode->right = NULL;

   return(newnode);
}

/*
 *  Get balance of a node
 */
int getbalance(struct mynode *bn)
{
   if (bn == NULL)
      return(0);

   return(getheight(bn->left) - getheight(bn->right));
}

/*
 *  Right rotation
 */
struct mynode *rightrotate(struct mynode *y)
{
struct mynode *x, *tmp;

   x = y->left;
   tmp = x->right;
   /*
    *  Rotate
    */
   x->right = y;
   y->left = tmp;

   /*
    *  Update heights
    */
   y->height = MAX(getheight(y->left), getheight(y->right)) + 1;
   x->height = MAX(getheight(x->left), getheight(x->right)) + 1;

   return(x);
}

/*
 * Left rotation
 */
struct mynode *leftrotate(struct mynode *x)
{
struct mynode *y, *tmp;

   y = x->right;
   tmp = y->left;
   /*
    *  Rotate
    */
   y->left = x;
   x->right = tmp;

   /*
    *  Update heights
    */
   x->height = MAX(getheight(x->left), getheight(x->right)) + 1;
   y->height = MAX(getheight(y->left), getheight(y->right)) + 1;

   return(y);
}

/*
 *  Left/Right rotation
 */
struct mynode *leftright(struct mynode *p) {

   p->left = leftrotate(p->left);
   return(rightrotate(p));
}

/*
 *  Right/Left rotation
 */
struct mynode *rightleft(struct mynode *p) {

   p->right = rightrotate(p->right);
   return(leftrotate(p));
}

/*
 *  Insert myval into tree
 */
struct mynode *insert(struct mynode *node, int myval)
{
int balance;

   /*
    *  Insert new node
    */
   /*
    *   First node, it is the first root
    */
   if (node == NULL)
      return(createmynode(myval));

   /*
    *  Subsequent node insertions
    */
   if (myval < node->myval)
      node->left = insert(node->left, myval);
   else if (myval > node->myval)
      node->right = insert(node->right, myval);
   else // Equal myvals are not allowed in BST
      return(node);

   /*
    *  Update height of this ancestor node
    */
   node->height = 1
                  + MAX(getheight(node->left),
                        getheight(node->right));

   /*
    *  Check whether this node became unbalanced
    */
   balance = getbalance(node);

   /*
    *   If the node becomes unbalanced, then there are 4
    *   cases
    */

   /*
    *  Left Case
    */
   if (balance > 1 && myval < node->left->myval)
      return(rightrotate(node));

   /*
    *  Right Case
    */
   if (balance < -1 && myval > node->right->myval)
      return(leftrotate(node));

   /*
    *  Left Right Case
    */
   if (balance > 1 && myval > node->left->myval) {
      return(leftright(node));
   }

   /*
    *  Right Left Case
    */
   if (balance < -1 && myval < node->right->myval) {
      return(rightleft(node));
   }
   
   /*
    *   Node is not changed
    */
   return(node);
}

/*
 *  Perform preorder traversal of tree
 */
void dumptree(struct mynode *root)
{
   if (root != NULL) {
      dumptree(root->left);
      printf("%d\n", root->myval);
      dumptree(root->right);
   }
}

int main()
{
int i, tt;
struct mynode* root = NULL;

   srand48((long)time(NULL));

   /*
    *  Insert a bunch of nodes into the tree
    */
   for (i = 0; i < 1024; i++) {
      tt  =  (int)(drand48() * (double)100000);
      root = insert(root, tt);
   }

   /*
    *  Print the tree contents
    */
   printf("Dump the contents of the tree:\n");
   dumptree(root);

   exit(0);
}

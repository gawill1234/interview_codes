#include <stdio.h>
#include <stdlib.h>

/*
 *  I freely admit I swiped this one.  I wanted it 
 *  available but was too lazy to do the work.  So
 *  this is basically an internet "canned" version
 *  of quick sort.  Normally I'd use qsort.  Just
 *  wanted what was happening "under the sheets"
 *  available to look at.
 */

/*
 *   Implementation of qsort(quick sort)
 */
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;

   return;
}

int partition(int arr[], int low, int high) {
int p, i, j;

   /*
    * Initialize pivot to be the first element
    */
   p = arr[low];
   i = low;
   j = high;

   while (i < j) {

      /*
       * Find the first element greater than
       * the pivot (from starting)
       */
      while (arr[i] <= p && i <= high - 1) {
         i++;
      }

      /*
       * Find the first element smaller than
       * the pivot (from last)
       */
      while (arr[j] > p && j >= low + 1) {
         j--;
      }
      if (i < j) {
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[low], &arr[j]);
   return(j);
}

void quickSort(int arr[], int low, int high) {
int pi;

   if (low < high) {

      /*
       * call partition function to find Partition Index
       */
      pi = partition(arr, low, high);

      /*
       * Recursively call quickSort() for left and right
       * half based on Partition Index
       */
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
   }

   return;
}

int main() {
int arr[] = { 47, 34, 25, 12, 22, 11, 91, 3, 103, 21, 83 };
int n;

   n = sizeof(arr) / sizeof(arr[0]);

   quickSort(arr, 0, n - 1);

   for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");

   exit(0);
}

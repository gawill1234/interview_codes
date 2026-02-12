#include <stdio.h>
#include <stdlib.h>

/*
 * A version of Bubble Sort 
 */
void bubbleSort(int arr[], int n) {
int swapped, tmp;
int i, j;
  
   for (i = 0; i < n - 1; i++) {
      swapped = 0;
      for (j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            swapped = 1;
         }
      }
      
      /*
       *  If nothing was swapped, then return
       */
      if (!swapped)
         return;
   }

   return;
}

/*
 *   Print the array contents
 */
void printArray(int arr[], int n) {
int i;

   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
   return;
}

int main() {
int arr[] = { 47, 34, 25, 12, 22, 11, 91, 3, 103, 21, 83 };

   bubbleSort(arr, 10);
   printf("Sorted array: \n");
   printArray(arr, 10);
   exit(0);
}

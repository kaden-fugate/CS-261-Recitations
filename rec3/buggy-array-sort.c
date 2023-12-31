/*
 * This program should sort an array by decreasing value using insertion sort,
 * but it's currently broken.  Use GDB and Valgrind to help debug it.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * This function swaps the values of two integers, using their memory addresses
 * (i.e. using pointers to those integers).
 */
void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
 * This function implements insertion sort:
 *
 *   https://en.wikipedia.org/wiki/Insertion_sort
 *
 * Here, we specifically sort an array of integers by decreasing value (i.e.
 * the largest value should be at the front of the array after it's sorted).
 */
void insertion_sort(int* array, int n) {
  for (int i = 1; i < n; i++) { // starting at second index
    for (int j = i; j < n; j++) { // starting at i
      if (array[i-1] >= array[j]) { // if prev is greater than next, loop
        continue;
      }
      swap(&array[i-1], &array[j]); // else, swap vals
    }
  }
}

int main(int argc, char const *argv[]) {
  /*
   * Generate an array containing 16 random values between 0 and 100.
   */
  int n = 16;
  int* array = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 100;
  }

  /*
   * Print the unsorted array.
   */
  printf("The unsorted array values are:\n");
  for (int i = 0; i < n; i++) {
    printf("  %d", array[i]);
  }
  printf("\n\n");

  /*
   * Sort the array and print it again.
   */
  insertion_sort(array, n);
  printf("The sorted array values are:\n");
  for (int i = 0; i < n; i++) {
    printf("  %d", array[i]);
  }
  printf("\n");

  return 0;
}

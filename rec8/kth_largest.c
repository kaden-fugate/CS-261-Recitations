#include <stdio.h>
#include <stdlib.h>
#include "kth_largest.h"

void print(int *arr, int size)
{

    printf("Heap: ");

    for(int i = 0; i < size; i++)
    {

        printf("%d ", arr[i]);

    }

    printf("\n\n");

}

int *make_heap(int *nums, int numsSize, int heap_size)
{

    int i = 0; // size counter

    int *heap = malloc( heap_size * sizeof( int ) ); // heap only needs to hold k elements

    for(i; i < heap_size; i++) // fill init heap
    {
        heap[i] = nums[i];

        percolate_up( &heap, heap_size, i ); // percolate up added node

    }

    for(i; i < numsSize; i++) // cycle through nums[k + 1] to nums[n]
    {

        /* if min in heap of size k less than a new num then we know that 
        the prev min num will not be within the k greatest*/
        if( nums[i] > heap[0] ) 
        {
            heap[0] = nums[i];

            percolate_down( &heap, heap_size, 0 );
        }
    }

    return heap;

}



// ^ cooler way



void swap( int **heap, int parent_idx, int child_idx )
{

    int temp = (*heap)[parent_idx]; // store parents val

    (*heap)[parent_idx] = (*heap)[child_idx]; // swap vals

    (*heap)[child_idx] = temp;

}

void percolate_up( int **heap, int heap_size, int idx )
{

    if( idx == 0 ){ return; } // base case

    if( idx % 2 == 1 )
    {

        if( (*heap)[idx] < (*heap)[ (idx - 1) / 2 ] )
        {

            swap( heap, idx, ( idx - 1 ) / 2 );
            percolate_up( heap, heap_size, ( idx - 1 ) / 2 ); // try to percolate until impossible

        }

    }
    else
    {

        if( (*heap)[idx] < (*heap)[ (idx - 2) / 2 ] )
        {

            swap( heap, idx, ( idx - 2 ) / 2 );
            percolate_up( heap, heap_size, ( idx - 2 ) / 2 ); // try to percolate until impossible

        }

    }

    

}

void percolate_down( int **heap, int heap_size, int idx )
{

    if( ( 2 * idx ) + 1 >= heap_size ){ return; } // base case

    int min_priority_idx = (2 * idx) + 1; // assume left node is min priority idx

    if( ( 2 * idx ) + 2 < heap_size ) // check if right node is min priority
    {

        if( (*heap)[ (2 * idx) + 2 ] < (*heap)[ min_priority_idx ] ) // if right node min priority, set it as so
        {

            min_priority_idx = (2 * idx) + 2;

        }

    }

    if( (*heap)[idx] > (*heap)[min_priority_idx] )
    {

        swap( heap, idx, min_priority_idx );
        percolate_down( heap, heap_size, min_priority_idx); // try to percolate until impossible

    }

}

int *create_heap(int *nums, int numsSize)
{

    int *heap = malloc( numsSize * sizeof( int ) );

    for(int i = 0; i < numsSize; i++)
    {

        heap[i] = nums[i]; // insert num at end of heap

        percolate_up( &heap, numsSize, i ); // percolate the number up

    }

    return heap;

}

int heap_sort(int *heap, int numsSize, int k)
{
    for(int i = numsSize - 1; i > 0; i--)
    {

        swap( &heap, i, 0 );

        percolate_down( &heap, i, 0);

    }

    return heap[k - 1];
    
}



int findKthLargest(int* nums, int numsSize, int k)
{
    if( k < 1 || numsSize <= 0){ return -1; }

    int *heap = create_heap(nums, numsSize);
    return heap_sort(heap, numsSize, k);


    /*
    cooler way:
    //int *heap = make_heap(nums, numsSize, k);
    return heap[0]; // k-th greatest always stored at root of heap
    */

    
}



int main(int argc, char **argv)
{
    
    printf("\nTest 1...\n");
    int num1[6] = {3,2,1,5,6,4};
    printf("2nd largest in [3 2 1 5 6 4]\n");
    printf("Expected: 5\n");
    printf("Actual: %d\n", findKthLargest(num1, 6, 2));

    printf("\nTest 2...\n");
    int num2[9] = {3,2,3,1,2,4,5,5,6};
    printf("4th largest in [3 2 3 1 2 4 5 5 6]\n");
    printf("Expected: 4\n");
    printf("Actual: %d\n", findKthLargest(num2, 9, 4));


    printf("\nTest 3...\n");
    int num3[5] = {10,10,10,10,10};
    printf("5th largest in [10 10 10 10 10]\n");
    printf("Expected: 10\n");
    printf("Actual: %d\n", findKthLargest(num3, 5, 5));

    printf("\nTest 4...\n");
    int num4[7] = {-10,10,-10,10,-10,10,0};
    printf("4th largest in [-10 10 -10 10 -10 10 0]\n");
    printf("Expected: 0\n");
    printf("Actual: %d\n", findKthLargest(num4, 7, 4));

    printf("\nTest 5...\n");
    int num5[10] = {10,9,8,7,6,5,4,3,2,1};
    printf("1st largest in [10 9 8 7 6 5 4 3 2 1]\n");
    printf("Expected: 10\n");
    printf("Actual: %d\n", findKthLargest(num5, 10, 1));


    return 0;
}
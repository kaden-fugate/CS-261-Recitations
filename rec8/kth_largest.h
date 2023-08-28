#ifndef KTH_LARGEST_H
#define KTH_LARGEST_H

void print(int *arr, int size);
int *make_heap(int *nums, int numsSize, int heap_size);
void swap( int **heap, int parent_idx, int child_idx );
void percolate_up( int **heap, int heap_size, int idx );
void percolate_down( int **heap, int heap_size, int idx );
int *create_heap(int *nums, int numsSize);
int heap_sort(int *heap, int numsSize, int k);
int findKthLargest(int* nums, int numsSize, int k);

#endif
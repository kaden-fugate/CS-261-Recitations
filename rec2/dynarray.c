/* CS261 - Reciation 2*/
/* Description: create a array of integers and struct student by giving the size of array, 
                and sort them using sort() and function pointers
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

struct student{
	int id;
	int score;
};

//helper function to compare students by their scores
int compare_student (void* x, void* y){
	struct student *s1 = x;
	struct student *s2 = y;
	return s1->score > s2->score ? 1 : 0;
}

//helper function to compare two ints
int compare_int (void* x, void* y){
	int* a = x, *b = y;
	return *a > *b ? 1 : 0;
}

/* sort the arr array by using a function pointer to 
 * compare its elements
 * Param: 
 *		void** arr                 - array of generic type 
 *      int n                      - array size
 *      int(*cmp)(void* a, void* b)- function pointer to compare two elements in the array 
 */

void sort(void** arr, int n, int cmp(void* a, void* b)){

    for (int i = 0; i < n - 1; i++){
        // last i elements are already in place
        for (int j = 0; j < n - i - 1; j++){

            if( cmp( arr[j], arr[j + 1]) == 1){

                int* temp = arr[j+1]; 
                arr[j+1] = arr[j];
                arr[j] = temp;

            }

        }
    }
}


/* free the memeory allocated by arr
 * Param: 
 *      void** arr                 - array of generic type 
 *      int n                      - array size
 */
void free_arr (void** arr, int n){
	
    for(int i = 0; i < n; i++){

        free(arr[i]);

    }
    free(arr);
}

int main(){

    srand(time(NULL));

    /*Declare an integer n and assign 10 to it.*/
    int n = 10;

    /***Step 1: sort an integer array ***/
    
    /*Allocate memory for n integers using malloc.*/
    int **arr = malloc( n * sizeof( int* ) );
    
    /*Generate random ints (0-100, inclusive) for the n integers, using rand().*/

    for(int i = 0; i < n; i++){ 

        arr[i] = malloc(sizeof(int));
        *(arr[i]) = (rand() % 101);

    }

    /*Print the contents of the array of n students.*/
    printf("\nBefore sorting....\n");

    for(int i = 0; i < n; i++){ printf("%d ", **(arr + i)); }
    printf("\n");
    
    /*call sort() function to sort*/

    sort( (void **) arr, n, &compare_int);

    /*Print the contents of the array of n students.*/
    printf("\nAfter sorting....\n");

    for(int i = 0; i < n; i++){ printf("%d ", **(arr + i)); }
    printf("\n");
    
    /***Step 2: After modifying sort() by using function pointer, modify your sort() function call above ****/

    

    /*** Step 3: sort an array of students ***/



    /*Allocate memory for n students using malloc.*/
    struct student **students = malloc( n * sizeof( struct student* ) );

    int *ids = malloc ( 101 * sizeof( int ) );
    for(int i = 0; i < 101; i++){

        *( ids + i ) = i;

    }
    
    /*Generate random IDs and scores for the n students, using rand().*/
    /*note: 
     *    1. no two students should have the same ids 
     *    2. score and id range: 0-100, inclusive
     */
    
    for(int i = 0; i < n; i++){
        students[i] = malloc( sizeof( struct student ) );
        while(1){
            int temp = ids[ rand() % 101 ];
            if(temp < 101){ 
                ids[temp - 1] = 101; 
                students[i]->id = temp;
                break; 
            }
        }
        
        students[i]->score = rand() % 101;

    }

    /*Print the contents of the array of n students.*/
    printf("\nBefore sorting....\n");

    for(int i = 0; i < n; i++){ printf("id: %d, score: %d\n", students[i]->id, students[i]->score); }
    printf("\n");

    /*call sort() function to sort*/

    sort( (void**) students, n, &compare_student );
    
    /*Print the contents of the array of n students.*/
    printf("\nAfter sorting....\n");

    for(int i = 0; i < n; i++){ printf("id: %d, score: %d\n", students[i]->id, students[i]->score); }
    printf("\n");

    /***Step 4: free the memory allocated in Step 1-3 by calling free_arr() ***/

    free_arr( (void**) arr, n);
    free_arr( (void**) students, n);
    free(ids);
    

    return 0;
}

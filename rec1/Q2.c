/* CS261- Recitation 1 - Q.2
 * Solution description: call the function foo using "reference" to see the values before and after the function
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/

    *a = *a * 2;

    /*Set b to half its original value*/

    *b = *b / 2;

    /*Assign a+b to c*/

    c = *a + *b;

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/

    int x = 7, y = 8, z = 9;
    
    /*Print the values of x, y and z*/

    printf("x val: %d\ny val: %d\nz val: %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/

    /*Print the value returned by foo*/

    printf("foo val: %d\n", foo(&x, &y, z));

    /*Print the values of x, y and z again*/

    printf("x val: %d\n y val: %d\n z val: %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why? */

    // because x and y were passed by reference, their original vals were changed while c's val was not

    return 0;
}
    
    

#include <stdio.h>
#include <stdlib.h>

int sqrt_func(int x)
{

    if(x < 2){ return x; } // 0^2 = 0, 1^2 = 1

    int sqrt;
    int lb = 1, ub = x / 2; // x / 2 <= sqrt(x) when x > 1
 
    while(lb <= ub)
    {

        long mid = (lb + ub) / 2; // find between lb and ub
 
        if(mid * mid == x){ return mid; } // return mid if sqr is x

        else if(mid * mid < x){
        
            lb = mid + 1; 
            sqrt = mid; // store floor(x)
        }
        else{

            ub = mid - 1;

        }
        
    }

    return sqrt;
}

int main(int argc, char **argv)
{
    printf("Square root of 2: \nExpected: 1\tActual: %d\n", sqrt_func(2));
    printf("Square root of 4: \nExpected: 2\tActual: %d\n", sqrt_func(4));
    printf("Square root of 8: \nExpected: 2\tActual: %d\n", sqrt_func(8));
    printf("Square root of 9: \nExpected: 3\tActual: %d\n", sqrt_func(9));
    printf("Square root of 1024: \nExpected: 32\tActual: %d\n", sqrt_func(1024));
    printf("Square root of 555555: \nExpected: 745\tActual: %d\n", sqrt_func(555555));
    printf("Square root of 123456789: \nExpected: 11111\tActual: %d\n", sqrt_func(123456789));
    printf("\nFor the example below, think of integer overflow: \n");
    printf("Square root of 2147395600: \nExpected: 46340\tActual: %d\n", sqrt_func(2147395600));



    return 0;
}

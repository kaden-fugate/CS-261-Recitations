#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * return true (1) if n is happy, false (0) otherwise
 */
bool isHappy (int n){

	int *map = malloc(sizeof(int) * 1000); // max int size in test has 3 digits - will not reach or exceed 1000.

	int demoninator = 10, sum = 0;

	while(map[n] != 1)
	{
		map[n] = 1; // n to mapping
		while(n != 0) // while n != 0 ( 0 when digits done being assessed )
		{

			sum += ( ( n % demoninator ) * ( n % demoninator ) ); // add smallest digit squared
			n /= demoninator; // shift nums right 1 digit

		}
		if(sum == 1){ return 1; } // if sum == 1, happy
		n = sum; // reset n and sum
		sum = 0;
	}

	return 0;
}


/*
 * Below are testing functions... DO NOT MODIFY!!!
 */

void show_result(int e, int r){
	printf("Expected: %d\nActual: %d...", e, r);
	if (r != e) 
        printf("FAIL\n\n\n");
    else 
        printf("OK\n\n\n");
}



int main()
{
	printf("\nTEST 1...19\n");
	show_result(1, isHappy(19));

	printf("\nTEST 2...2\n");
	show_result(0, isHappy(2));

	printf("\nTEST 3...7\n");
	show_result(1, isHappy(7));

	printf("\nTEST 4...176\n");
	show_result(1, isHappy(176));

	printf("\nTEST 5...36\n");
	show_result(0, isHappy(36));

	

	return 0;
}

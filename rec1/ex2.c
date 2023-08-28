#include <stdio.h>

int function(int num, int ctr) {
  int i;
  for(i = 2;i <= num/2; i++){
    if(num % i==0){ // if num even, ctr will no longer be zero
      ctr++;
      break;
    }
  }
  if(ctr == 0 && num != 1) // if counter did not go up and num is not equal to one, return 1
    return 1;
  
  else // counter went up or num is 1, return 0
    return 0;
}
// prime detector ^ 

int main(){

  int num, ctr = 0, r = -1;
  printf("Input a number: ");
  scanf("%d",&num);
  
  r = function(num, ctr);
  printf("%d\n", r);

  return 0;
}
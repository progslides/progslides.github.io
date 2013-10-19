#include <stdio.h>

int main()

{

  int sum = 0;
  int product = 0;
  int result = 0;
  int result1 = 0;
  int result2 = 0;
  int result3 = 0;
  float result4 = 0.0;
  
  
  sum = 1 + 1 + 1;
	product = 1 * 1 * 1;
	
	result = ++product - sum++; 
	result1 = result * sum;
	printf("Result = %d\n", result1);
	
	result2 = result1 / 1;
	printf("Integer division = %d\n", result2);
	
	result3 = result1 % 1;
	printf("Remainder = %d\n", result3);
	
	result4 = result1;
	result4 = result1 / 1.0;
	printf("Division = %0.2f\n", result4);
	return 0;

}

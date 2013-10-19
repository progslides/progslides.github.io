//-----------------------------------------------------------------------------
// hw1a.c
//
// Slightly modified "Matrikelnummer"
//
// Group:10 - study assistant Andreas	
//
// Authors: *** *** ***
//
// Latest Changes: 16.10.2013 (by ***)
//-----------------------------------------------------------------------------
//

#include <stdio.h>
int main ()
{
  int sum = 9;
  int product = 20;
  
  int subtraction = ((++product) - (sum++));
  int result = subtraction  * sum;
  int integerdivision = (result / (10));
  int remainder = result %10;
  

printf("Result = %d\n", result );
printf("Integer division = %d\n", integerdivision );
printf("Remainder = %d\n", remainder );
printf("Division = %.2f\n", result / 10.0 );

return 0;
}

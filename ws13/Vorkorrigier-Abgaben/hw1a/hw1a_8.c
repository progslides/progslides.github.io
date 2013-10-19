
//-----------------------------------------------------------------------------
// hw1a.c
//
// Slightly modified "hw1a"
//
// Group: 10 study assistant Andreas
//
// Authors: *****
//
// Latest Changes: 15.10.2013 (****)
//-----------------------------------------------------------------------------

#include <stdio.h>


int main()
{
int sum;
int product;
int Result;
int Integer_division;
int Remainder;
int Division;

sum = 1+1+1;
product = 1*1*1;


Result =(++product - sum++);
Result *= sum;

   printf("Result = %d\n",Result);
   

Integer_division = Result/(2+1)	;

   printf("Integer division = %d\n",Integer_division);
   

Remainder = Result%(2+1) ;

   printf("Remainder = %d\n",Remainder);
   

Division = (float)Result/(2+1) ;

   printf("Division = %.2f\n",(float)Division);

return 0 ; 

}

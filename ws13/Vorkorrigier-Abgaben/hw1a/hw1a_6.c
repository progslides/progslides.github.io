//-----------------------------------------------------------------------------
// hw1a.c
//
// Arithmetische Operatoren
//
// Group: 10 study assistant Andreas
//
// Authors: ***** *****
//
// Latest Changes: 14.10.2013 (by ***)
//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include <stdio.h>

int sum = 10;
int product = 28;
int ziffer = 4;

int main ()
{  int differenz = ++product - sum++;
   int result = differenz * sum;
   int division = result / ++ziffer;
   int remainder = result % ziffer;
   float divisionf = (float)result / ziffer;
   
   printf("Result = %d\n",result);
   printf("Integer division = %d\n",division);
   printf("Remainder = %d\n",remainder);
   printf("Division = %.2f\n",divisionf);
   return 0;
}


//-----------------------------------------------------------------------------
// hw1a.c
//
// Group: 10 study assistant Andreas
//
// Authors: ****
//
//-----------------------------------------------------------------------------
//
#include <stdio.h>

int product = 0;
int sum = 4;
int Rest;
int IntegerDivision;
int ergebnis;
float division;

int main()
{
  ergebnis = ++product - sum++;
  ergebnis = ergebnis * sum;
  printf("Result = %d\n", ergebnis);

  IntegerDivision = ergebnis / 7;
  printf("Integer division = %d\n", IntegerDivision);

  Rest = ergebnis % 7;
  printf("Remainder = %d\n", Rest);

  division = ergebnis / 7;
  printf("Division = %f\n", division);

  return 0;
}

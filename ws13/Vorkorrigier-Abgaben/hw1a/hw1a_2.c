//-----------------------------------------------------------------------------
// hw1a.c
//
// Homework demonstrating the work with datatypes
//
// Group: 8 study assistant Anja Karl
//
// Authors: ----- ---- ---
// Latest Changes: 14.10.2013 (by ---- ----)
//-----------------------------------------------------------------------------



#include <stdio.h>

//-----------------------------------------------------------------------------
///
/// Main routine of the homework program
///
/// @return int 0
//
int main()
{
  //my matrikel number is ---------
  
  int sum = 1 + 1 + 1 //sum = 10
  int product = 1 * 1 * 1S; //product = 0
  float last_Matr_Nr = 2;

  int minuend = ++product;
  int subtrahend = sum++;

  //printf("SUBTR:%d SUM:%d\n",subtrahend, sum);
  
  int res_Sub = minuend - subtrahend;
  
  int res_Mult = res_Sub * sum;  
  printf("Result = %d\n", res_Mult);

  int res_Int_Div = res_Mult / (++last_Matr_Nr);
  printf("Integer division = %d\n", res_Int_Div);

  int modulo_Int_Div = res_Mult % res_Int_Div;
  printf("Remainder = %d\n", modulo_Int_Div);
 
  float res_Float_Div = res_Mult / (last_Matr_Nr);
  //%.2f means: 2 tailing zeroes. 
  printf("Division = %.2f\n", res_Float_Div);

  return 0;
}



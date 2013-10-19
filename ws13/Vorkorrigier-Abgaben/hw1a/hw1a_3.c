//-----------------------------------------------------------------------------
// hw1a.c
//
// Slightly modified "arithmetic operators"
//
// Group: 8 study assistant Anja Karl
//
// Authors: ---- ----- ------
//
// Latest Changes: 15.10.2013 (by ---- -----)
//-----------------------------------------------------------------------------
//

#include <stdio.h>

//-----------------------------------------------------------------------------
//
// The main program.
// 
//
// @return always zero
//

// matrikelnumber -----
int sum = 6, l = 0, z = 0, m = 0;                    
// sum = - + - + - = 6
int product = 0, result, integerdivision, rest ;    
// product = - * - * - = 0
double division ;            

int main()
{
  l = ++product;                                
  // prae-increment of product
  z = sum++;                                    
  // post-increment of sum
    result = (l - z) * sum;
    printf ("Result = %d\n", result);
  m = 8 + 1;
    integerdivision = (result / m);
    printf ("Integer division = %d\n", integerdivision) ; 
    rest = (result % m) ;
    printf ("Rest = %d\n", rest) ; 
    division = (-35.00 / 9.00) ;
    printf ("Division = %.2f\n", division) ;
  return 0;  
 }


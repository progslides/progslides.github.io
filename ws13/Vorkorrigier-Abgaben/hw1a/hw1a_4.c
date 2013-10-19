  //-----------------------------------------------------
  // hw1a.c
  //
  // Handling with basic arithmetic Operaters
  //
  // Group: 8 study assistant Anja Karl
  //
  // Authors: ----- ----- -------- 
  //
  // Latest Changes: 15.10.2013 (by -----) 
  //-----------------------------------------------------

  #include <stdio.h>

  int main()
  {
    int sum = 1+1+1;   
    int product = 1*1*1;
	
    int product1 = ++product;  //Pre-Increment of Product 
    int sum1 = sum++;		   //Post-Increment of Sum 	

    int result = (product1 - sum1) * sum; //Result of Difference between  product1 
                                          //and sum1 multiplicate with original Sum 
    int integer_division = result / 7;    
    int rest = result%7;
    double double_result = result;        //Double Value of Result for Division
  	double double_division = double_result / 7;  //Division without Rest

    printf("Result = %d\n",result);
    printf("Integer division = %d\n",integer_division);
    printf("Rest = %d\n",rest);
    printf("Division = %.2f\n",double_division);

    return 0;

  }
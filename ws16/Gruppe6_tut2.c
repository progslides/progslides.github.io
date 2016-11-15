#include <stdio.h>
int main()
{
/*
  //Schleifen
  int counter = 0;
  for(counter = 1; counter <= 10; counter++)
  {
    printf("%d\n", counter);
  }
  
  int counter_while = 1;
  while(counter_while <= 10);
  {
    printf("%d\n", ++counter_while)
  }
  
  
  int counter_do_while = 1;
  do 
  {
    printf("%d\n", ++counter_do_while)
  }
  while(counter_do_while <= 10);
  */
  //If Statements
  
  /*
  int a = 22;
  if(a % 5 == 0)
  {
    printf("a is divisible by 5\n");
  }
  else if(a % 2 == 0)
  {
    printf("a is divisible by 2\n");
  }*/
  
  int sum = 7;
  int product = 4;
  int difference = ++sum - product++;
  printf("%d\n", difference);
  printf("%f\n", (float) sum / product);
  printf("%f\n", (float) 1 / 2);
  printf("%f\n", 1.0 / 2);
  printf("%d\n", 1 / 2);


  return 0;
}
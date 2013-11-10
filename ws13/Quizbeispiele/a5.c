#include<stdio.h>

int main()
{
  int array[10] = { 5, 13, 2, 29, 99, 70, 1, -5, 52, 11, -13};
  
  int i = 0;
  for(i = 0; i < 10; i++)
  {
    printf("%d.tes Zeichen in meinem Array ist: %d", i, array[i]);
  }
  
  return 0;
}
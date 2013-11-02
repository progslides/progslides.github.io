#include <stdio.h>

int main()
{
  int* data = malloc(sizeof(int) * 4);
  //data is not initialized!
  int i = 0;
  for(i = 0; i < 100; i++)
    printf("Data: %d\n", data[i]);
  
  free(data);
  return 0;
}
#include <stdio.h>

int main()
{
  int* data = malloc(sizeof(int) * 4);
  data[4] = 10;
  return 0;
}
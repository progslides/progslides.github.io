#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *str = malloc(10);
  gets(str);
  printf("%s\n",str);
  free(str);
  return 0;
}
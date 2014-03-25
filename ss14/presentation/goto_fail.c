#include <stdio.h>
#define true 1
#define false 0

int other_function(int x);

int main(int argc, char const *argv[])
{
  int x;
  other_function(x);
  return 0;
}

int other_function(int x)
{
  if (x)
    printf("Brackets are important.\n");
    return true;
  printf("Also known as GOTO-Fail.\n");
}

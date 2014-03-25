#include <stdio.h>
#define NEVER_TRUE 0

int main(int argc, char const *argv[])
{
  if(NEVER_TRUE)
    printf("This statement will never be reached.\n");

  printf("Returning.\n");
  return 0;
}



#include<stdio.h>
#include<stdlib.h>

int main()
{
  char* text = malloc(50 * sizeof(char));
  
  int i = 0;
  for(i = 0; i < 50; i++)
  {
    text[i] = 'a';
  }
  
  printf("%s", text);
  return 0;
}
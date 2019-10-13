#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char a;
  int x, y;
} dummy;

typedef struct {
  int** array;
  int x, y;
} MyArray;


void freeMyArray(MyArray array)
{
  for(int count = 0; count < array.x; count++)
  {
    if(array.array[count] != NULL)
      free(array.array[count]);
  }

  free(array.array);
}

MyArray generate(int x, int y)
{
  MyArray array;
  array.array = NULL;
  array.x = x;
  array.y = y;

  array.array = calloc(sizeof(int*), x);
  if(array.array == NULL)
  {
    array.array = NULL;
    return array;
  }

  for(int count = 0; count < x; count++)
  {
    if(count == 3)
      array.array[count] = NULL;
    else
      array.array[count] = malloc(sizeof(int) * y);

    if(array.array[count] == NULL)
    {
      freeMyArray(array);
      array.array = NULL;
      return array;
    }
  }

  return array;
}

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    printf("usage: ./a.out <x> <y>\n");
    return 1;
  }

  int x=0, y=0;
  x = atoi(argv[1]);
  y = atoi(argv[2]);
  printf("%d, %d\n", x, y);

  MyArray array = generate(x,y);
  if(array.array == NULL)
    return 2;

  //array.array[3][3] = 5;
  freeMyArray(array);
  return 0;
}

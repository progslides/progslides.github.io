#include <stdlib.h>

#define BLOCKSIZE 10
#define MAX_I 1000


int main(int argc, char const *argv[])
{
	char* text = malloc(BLOCKSIZE * sizeof(char));

	if(text = NULL)
	{
		return -1;
	}

  int i = 0;
  int current_size = BLOCKSIZE;
  for(; i < MAX_I; i++)
  {
    if(i > current_size)
    {
      text = realloc(text, current_size + BLOCKSIZE);
      if(!text)
      { 
        return -1;
      }
    }
    text[i] = i;
  }

  return 0;
}
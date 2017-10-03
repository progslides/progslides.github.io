#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct _Vector2D_
{
  int x;
  int y;
} Vector2D;


typedef struct _Mario_
{
  char size;
  Vector2D position;
} Mario;


void printVector2D(Vector2D vector)
{
  printf("(%d / %d)\n", vector.x, vector.y);
}

void printMario(Mario mario)
{
  printf("Size: %d\n", mario.size);
  printVector2D(mario.position);
}

void marioRun(Mario* mario, Vector2D direction)
{
  mario->position.x += direction.x;
  (*mario).position.y += direction.y;
}

void saveMario(Mario mario, char* file_name)
{
  FILE* file = fopen(file_name, "wb");

  fwrite(&mario, sizeof(Mario), 1, file);

  fclose(file);

}

Mario loadMario(char* file_name)
{
  Mario mario;
  mario.position.x = 0;
  mario.position.y = 0;
  mario.size = 0;
  FILE* file = fopen(file_name, "rb");

  if (file == NULL)
  {
    printf("Error: file %s could not be opened!\n", file_name);
    return mario;
  }

  fread(&mario, sizeof(Mario), 1, file);

  fclose(file);

  return mario;
}



int main(int argc, char *argv[])
{
  Mario mario;
  mario.size = 0;
  mario.position.x = 0;
  mario.position.y = 0;
  
  printMario(mario);
  if (argc == 2)
  {
    mario = loadMario(argv[1]);
  }
  if (argc == 3)
  {
    mario.position.x = atoi(argv[1]);
    mario.position.y = atoi(argv[2]);
    
  }
  

  

  /*Vector2D direction;
  direction.x = 10;
  direction.y = 0;
  marioRun(&mario, direction);
  printMario(mario);
  saveMario(mario, "mario.save");*/

  

  printMario(mario);



  return 0;
}

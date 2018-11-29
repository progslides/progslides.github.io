#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // initialise pseudo-random-number generator with current time
  srand(time(NULL));
  
  //generate a pseudo-random-number
  int min = 10;
  int max = 20;
  int range = max - min;
  int random_number = rand() % range + min;
  
  int counter = 0;
  int guess = 0;
  do
  {
    //read input
    printf("Bitte Zahl eingeben!\r\n");
    counter++;
    guess = 0;
    scanf("%d", &guess);
    /* note: here no error handling is done. if no integer can be read scanf
     * returnes an error value. The value is not removed from the stdin and
     * will be read again. Try it out!
     */
  
    //evaluate guess
    if (random_number == guess)
    {
      printf("Richtig geraten!");
    }
    else
    {
      printf("Falsch geraten!");
    }
    
    //end loop when4 guesses are exceeded or number was guessed correctly
  } while(counter < 3 && random_number != guess); 
  
  printf("Die richtige Zahl wäre: %d", random_number);
  
  return 0;
}

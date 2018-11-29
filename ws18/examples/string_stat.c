#include <string.h>
#include <stdio.h>

#define NUMBER_OF_CHARACTERS 256

int sumUpArrayRange(int* array, int start, int end)
{
  int sum = 0;
  for(int index = start; index <= end; index++)
  {
    sum += array[index];
  }
  return sum;
}

void evaluation(int* stat_array)
{
  int number_count = sumUpArrayRange(stat_array, '0', '9');
  int small_letter_count = sumUpArrayRange(stat_array, 'a', 'z');
  int big_letter_count = sumUpArrayRange(stat_array, 'A', 'Z');
  int all_char_count = sumUpArrayRange(stat_array, 0, NUMBER_OF_CHARACTERS - 1);

  int others_count =
    all_char_count - number_count - small_letter_count - big_letter_count;

  printf("------------------------------\n");
  printf("Statistics:\n");
  printf("All Characters:\t\t%d\n", all_char_count);
  printf("Numbers: \t\t\t%d\n", number_count);
  printf("Small letters:\t\t%d\n", small_letter_count);
  printf("Big letters:\t\t%d\n", big_letter_count);
  printf("Other characters:\t%d\n", others_count);
}

void calcStat(int* stat_array, char* string)
{
  int string_length = strlen(string);

  for(int index = 0; index < string_length; index++)
  {
    char single_character = string[index];
    stat_array[single_character] += 1;
  }
}

int main()
{
  char string[100];
  printf("Enter a string to analyse: ");
  int number_read = scanf("%s", string);
  if (number_read == 0)
  {
    printf("No string entered.\n");
    return 0;
  }

  int stat_array[NUMBER_OF_CHARACTERS];

  /*
   * index <= NUMBER_OF_CHARACTERS ist FALSCH, da das Array nur NOC Zeichen hat.
   * Wenn die Bedingung <= lautet, wird am Stack der eingelesene String wieder
   * überschrieben.
   */
  for (int index = 0; index < NUMBER_OF_CHARACTERS; index++)
  {
    stat_array[index] = 0; //NULL // '\0'
  }

  calcStat(stat_array, string);

  evaluation(stat_array);

  return 0;
}

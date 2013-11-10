

int main()
{
  int i = 0;
  int j = 0;
  
  for(i = 0; i < 10; i++)
  {
    for(j = 0; j < 10; j++)
    {
      
      if(i == 5)
      {
        //Break out of both loops
        break;
        break;
      }
      printf("i: %d | j: %d\n", i, j);
    }
  
  }

  return 0;
}
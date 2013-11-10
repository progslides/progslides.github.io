

void sum(int result, int a, int b)
{
  result = a + b;
}

int main()
{
  int result = 0;
  int a = 4;
  int b = 6;
  
  sum(result, a, b);
  
  printf("%d + %d = %d\n", a, b, result);
  
  return 0;
}
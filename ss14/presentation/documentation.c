#include <stdio.h>
#define true 1

int other_function(void);

int main(int argc, char const *argv[])
{
  other_function();
  return 0;
}

///----
/// stuff
/// @param this whatever
/// @return
int other_function(void)
{
    return true;
}

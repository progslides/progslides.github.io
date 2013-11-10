// Start programm with ./beispiel <Number>
// Will print <Number> lines to STDOUT


#include <stdio.h>

void printNLines(int n)
{
	int i = 0;
	for(; i < n; i++)
	printf("Line %d\n", i);
}

int main(int argc, char const *argv[])
{
	if(argc > 0)
	printNLines(argv[0][0]);

	return 0;
}

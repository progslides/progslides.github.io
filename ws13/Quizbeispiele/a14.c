

#include <stdio.h>

#define NUM_LINES 100
#define LINE_SIZE 15

int main()
{
	char** text;
	allocText(&text);
	fillText(text);
	printText(&text);
}

int allocText(char*** text)
{
	*text = malloc(NUM_LINES * sizeof(char));

	if(*text == NULL)
	{
		return 0;
	}

	int i = 0;
	for(; i < NUM_LINES; ++i)
	{
		*text[i] = malloc(LINE_SIZE * sizeof(char));
	}
	return 0;
}

int printText(char** text)
{
	int i = 0;
	for(i = NUM_LINES; i >= 0; i--)
	{
		printf("%s\n", text[i]);
	}
	return 0;
}

int fillText(char** text)
{
	for(int i = 0; i < NUM_LINES; i++)
	{
		sprintf(text[i],"This is line %d", i + 1);
	}

	return 0;
}
#include <string.h>
#include <stdio.h>


char getFromBoard(char* board, int row, int column)
{
	return board[column + 5 * row];
}

void setToBoard(char* board, int row, int column, char input)
{
	board[column + 5 * row] = input;
}


void printBoard(char* board)
{
	int row = 0;
	int column = 0;
	printf("-----\n");
	for (row = 0; row < 5; row++)
	{
		for (column = 0; column < 5; column++)
		{
			printf("%c", getFromBoard(board, row, column));
		}

		printf("\n");

	}
	printf("-----\n");
}

void fillBoard(char* board, char fill_char)
{
	int row = 0;
	int column = 0;

	for (row = 0; row < 5; row++)
	{
		for (column = 0; column < 5; column++)
		{
			setToBoard(board, row, column, fill_char);
		}
	}
}

void inputToken(char* board, int column, char token)
{
	int row = 4;

	for (row = 4; row >= 0; row--)
	{
		if (getFromBoard(board, row, column) == ' ')
		{
			setToBoard(board, row, column, token);
			return;
		}
	}

}

int main()
{
	char board[25];

	fillBoard(board, ' ');

	printBoard(board);

	

	inputToken(board, 2, 'o');

	printBoard(board);

	inputToken(board, 2, 'x');

	printBoard(board);

	return 0;
}


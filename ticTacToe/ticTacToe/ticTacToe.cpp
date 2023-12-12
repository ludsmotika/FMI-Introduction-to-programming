#include <iostream>

const size_t N = 4;
const unsigned PLAYERS_COUNT = 3;
const unsigned LINE_LENGTH = 3;
const char EMPTY_FIELD = ' ';

void initializeField(char field[][N], char defaultSymbol)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			field[i][j] = defaultSymbol;
		}
	}
}

void print(char field[][N])
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cout << '|' << field[i][j];
		}
		std::cout << '|' << std::endl;
	}
}

bool areValidIndices(int row,int col) 
{
	return row >= 0 && row < N && col >= 0 && col < N;
}

void input(char field[][N], int& row, int& col)
{
	while (true)
	{
		std::cin >> row >> col;

		if (areValidIndices && field[row][col] == ' ')
		{
			break;
		}
	}
}

int getConsecutiveDirection(char field[][N], int row, int coll, int rowMove, int collMove)
{
	char ch = field[row][coll];

	int count = 0;
	while (areValidIndices(row, coll) && field[row][coll] == ch)
	{
		count++;
		row += rowMove;
		coll += collMove;
	}
	return count;
}

unsigned getConsecutiveOnLine(char field[][N], int row, int coll, int rowMove, int collMove)
{
	return getConsecutiveDirection(field, row, coll, rowMove, collMove) +
		getConsecutiveDirection(field, row, coll, -rowMove, -collMove) - 1;//because we count the starting point twice.
}

bool isWinningMove(char field[][N], int row, int coll)
{
	return   getConsecutiveOnLine(field, row, coll, 0, 1) >= LINE_LENGTH || //horizontal
		getConsecutiveOnLine(field, row, coll, 1, 0) >= LINE_LENGTH || //vertical
		getConsecutiveOnLine(field, row, coll, 1, 1) >= LINE_LENGTH || //main diagonal
		getConsecutiveOnLine(field, row, coll, 1, -1) >= LINE_LENGTH;   //anti diagonal
}

int main()
{
	char field[N][N];

	initializeField(field, EMPTY_FIELD);
	print(field);

	for (size_t i = 0, currentPlayer = 0; i < N * N; i++)
	{
		int row, col;
		input(field, row, col);

		field[row][col] = 'A' + (currentPlayer % PLAYERS_COUNT);
		currentPlayer++;

		print(field);

		if (isWinningMove(field, row,col))
		{
			std::cout << "winner " << field[row][col];
			break;
		}


	}
}

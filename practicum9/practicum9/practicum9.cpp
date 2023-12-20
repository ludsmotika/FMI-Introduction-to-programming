#include <iostream>
const size_t N = 3;

void printPrimaryAndSeconsdaryDiagonal(const int matrix[][N], size_t n)
{
	int smallest = matrix[0][0];

	for (size_t i = 0; i < n; i++)
	{
		std::cout << matrix[i][i] << " ";
	}

	std::cout << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << matrix[i][n - i - 1] << " ";
	}

	std::cout << std::endl;
}


int findSmallestElement(const int matrix[][N], size_t n, size_t m)
{
	int smallest = matrix[0][0];

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (matrix[i][j] < smallest)
			{
				smallest = matrix[i][j];
			}
		}
	}

	return smallest;
}

void printInZigZag(const int matrix[][N], size_t n, size_t m)
{
	for (size_t j = 0; j < n; j++)
	{
		if (j % 2 == 0)
		{
			for (size_t i = 0; i < m; i++)
			{
				std::cout << matrix[j][i] << " ";
			}
		}
		else
		{
			for (int i = m - 1; i >= 0; i--)
			{
				std::cout << matrix[j][i] << " ";
			}
		}

		std::cout << std::endl;

	}
}

bool isMatrixTriangle(const int matrix[][N], size_t n, size_t m)
{
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

void copyValuesFromOneToAnother(int copy[][N], int original[][N], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			original[i][j] = copy[i][j];
		}
	}
}

void transposeMatrix(int matrix[][N], size_t n)
{
	int tempMatrix[N][N];
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			tempMatrix[j][i] = matrix[i][j];
		}
	}

	copyValuesFromOneToAnother(tempMatrix, matrix, n);
}
void printMatrix(int matrix[][N], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;

	}
}

bool isMatrixMagic(int matrix[][N], size_t n)
{
	int sumOfFirstRow = 0;
	for (size_t i = 0; i < n; i++)
	{
		sumOfFirstRow += matrix[0][i];
	}

	//check the rows
	int currentRowSum = 0;
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			currentRowSum += matrix[i][j];
		}

		if (currentRowSum != sumOfFirstRow)
		{
			return false;
		}
		else
		{
			currentRowSum = 0;
		}
	}

	//check the columns
	int currentColumnSum = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			currentColumnSum += matrix[j][i];
		}

		if (currentColumnSum != sumOfFirstRow)
		{
			return false;
		}
		else
		{
			currentColumnSum = 0;
		}
	}


	int mainDiagonalSum = 0;
	for (size_t i = 0; i < n; i++)
	{
		mainDiagonalSum += matrix[i][i];
	}

	int secondaryDiagonalSum = 0;

	for (size_t i = 0; i < n; i++)
	{
		secondaryDiagonalSum += matrix[i][n - i - 1];
	}

	return sumOfFirstRow == mainDiagonalSum && sumOfFirstRow == secondaryDiagonalSum;
}

void sumTwoMatrices(const int matrix[][N], const  int matrix2[][N], int answer[][N], size_t m, size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			answer[i][j] = matrix[i][j] + matrix2[i][j];
		}
	}
}

void  multiplyMatrix(int matrix[][N], size_t n, size_t m, int multiplier)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			matrix[i][j] *= multiplier;
		}
	}
}

void multiplyMatrices(const int matrix1[][2], const int matrix2[][3], int answer[][3], size_t n1, size_t m1, size_t n2, size_t m2)
{
	for (size_t i = 0; i < n1; i++)
	{
		for (size_t j = 0; j < m2; j++)
		{
			int sum = 0;
			for (size_t p = 0; p < n2; p++)
			{
				sum += matrix1[i][p] * matrix2[p][j];
			}
			answer[i][j] = sum;
		}
	}

	printMatrix(answer, 5, 3);
}

void changeDirection(char& direction)
{
	switch (direction) {
	case 'r':
		direction = 'd';
		break;
	case 'd':
		direction = 'l';
		break;
	case 'l':
		direction = 'u';
		break;
	case 'u':
		direction = 'r';
		break;
	default:
		std::cout << "Invalid input";
		break;
	}
}

bool areValidIndexes(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void changeCoordinatesToTheNextValid(const int matrix[][N], int& x, int& y, char& direction)
{

	int newX = x;
	int newY = y;

	switch (direction) {
	case 'r':
		newY++;
		break;
	case 'd':
		newX++;
		break;
	case 'l':
		newY--;
		break;
	case 'u':
		newX--;
		break;
	default:
		std::cout << "Invalid input";
		break;
	}

	if (!areValidIndexes(newX, newY) || matrix[newX][newY] == ' ')
	{
		changeDirection(direction);
		changeCoordinatesToTheNextValid(matrix, x, y, direction);

	}
	else
	{
		x = newX;
		y = newY;
	}
}


void printMatrixSpirally(int matrix[][N], size_t n, size_t m)
{
	//possible directions r-right l-left d-down u-up
	char currentDirection = 'r';
	int x = 0;
	int y = 0;

	for (size_t i = 1; i <= n * m; i++)
	{
		std::cout << matrix[x][y] << " ";

		matrix[x][y] = ' ';

		if (i != m * n)
		{
			changeCoordinatesToTheNextValid(matrix, x, y, currentDirection);
		}
	}
}

void rotateMatrixToTheRight(int matrix[][N], int answer[][N], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			answer[i][n - 1 - j] = matrix[j][i];
		}
	}
}
int main()
{
}



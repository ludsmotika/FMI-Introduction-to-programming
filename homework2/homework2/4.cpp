#include <iostream>
bool isRowValid(int x, int rows)
{
	return (x >= 0 && x < rows);
}


bool isColumnValid(int y, int cols)
{
	return (y > 0 && y <= cols);
}

int maxElementInJaggedArray(int** matrix, int rows)
{
	if (!matrix)
	{
		return 0;
	}
	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			return 0;
		}
	}

	int max = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j <= matrix[i][0]; j++)
		{
			if (matrix[i][j]>max)
			{
				max = matrix[i][j];
			}
		}
	}

	return max;
}

//void printJaggedArray(int** matrix, int rows)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j <= matrix[i][0]; j++)
//		{
//			std::cout << matrix[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}


int dfs(int** matrix, int rows,int** longestPathsHistory, int x, int y, int prevValue, int currentLength)
{
	if (!(isRowValid(x, rows) && isColumnValid(y, matrix[x][0])) || matrix[x][y] <= prevValue)
	{
		return currentLength;
	}

	if (longestPathsHistory[x][y]!=-1)
	{
		return currentLength + longestPathsHistory[x][y];
	}

	int changes[] = { 1,0,0,1,-1,0,0,-1,-1,-1,+1,+1, +1,-1,-1,+1 };
	int results[8] = { 0 };

	for (size_t i = 0; i < 8; i++)
	{
		results[i] = dfs(matrix, rows,longestPathsHistory, x + changes[2 * i], y + changes[(2 * i) + 1], matrix[x][y], currentLength + 1);
	}

	int max = 0;
	for (size_t i = 0; i < 8; i++)
	{
		if (results[i] > max)
		{
			max = results[i];
		}
	}

	return max;
}

int longestIncreasingPath(int** matrix, int rows)
{
	if (!matrix)
	{
		return 0;
	}

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			return 0;
		}
	}

	int** longestPathsHistory = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		longestPathsHistory[i] = new int[matrix[i][0] + 1];
		longestPathsHistory[i][0] = matrix[i][0];

		for (size_t j = 1; j <= matrix[i][0]; j++)
		{
			longestPathsHistory[i][j] = -1;
		}
	}

	
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 1; j <= matrix[i][0]; j++)
		{
			longestPathsHistory[i][j] = dfs(matrix, rows, longestPathsHistory, i, j, 1 << 31, 0);
		}
	}

	//printJaggedArray(longestPathsHistory,rows);
	int longestPathLength = maxElementInJaggedArray(longestPathsHistory,rows);

	delete[] longestPathsHistory;

	return longestPathLength;
}

//int main()
//{
//	int n;
//	std::cin >> n;
//
//	int** matrix = new int* [n];
//
//	for (size_t i = 0; i < n; i++)
//	{
//		int currentRowLength;
//		std::cin >> currentRowLength;
//
//		matrix[i] = new int[currentRowLength + 1];
//		matrix[i][0] = currentRowLength;
//
//		for (size_t j = 1; j <= currentRowLength; j++)
//		{
//			std::cin >> matrix[i][j];
//		}
//	}
//
//	std::cout << longestIncreasingPath(matrix, n);
//}
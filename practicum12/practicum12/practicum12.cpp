#include <iostream>

void printIntMatrix(int** matrix, int rowsCount, int rowLength)
{
	if (!matrix)
		return;

	for (size_t i = 0; i < rowsCount; i++)
	{
		if (!matrix[i])
			return;
	}

	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < rowLength; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int** deleteIRowInMatrix(int** matrix, int rowsCount, int rowLength, int rowToDelete)
{
	if (!matrix)
		return nullptr;

	for (size_t i = 0; i < rowsCount; i++)
	{
		if (!matrix[i])
			return nullptr;
	}

	int** newMatrix = new int* [rowsCount - 1];

	bool isRowPassed = false;
	for (size_t i = 0; i < rowsCount; i++)
	{
		if (rowToDelete - 1 == i)
		{
			isRowPassed = true;
			continue;
		}

		newMatrix[isRowPassed ? i - 1 : i] = new int[rowLength];
		for (size_t j = 0; j < rowLength; j++)
		{
			newMatrix[isRowPassed ? i - 1 : i][j] = matrix[i][j];
		}
	}

	return newMatrix;
}


int** deleteIColumnInMatrix(int** matrix, int rowsCount, int rowLength, int colToDelete)
{
	if (!matrix)
		return nullptr;

	for (size_t i = 0; i < rowsCount; i++)
	{
		if (!matrix[i])
			return nullptr;
	}

	int** newMatrix = new int* [rowsCount];

	for (size_t i = 0; i < rowsCount; i++)
	{
		newMatrix[i] = new int[rowLength - 1];

		int index = 0;
		for (size_t j = 0; j < rowLength; j++)
		{
			if (j == colToDelete - 1)
			{
				continue;
			}
			newMatrix[i][index++] = matrix[i][j];
		}
	}

	return newMatrix;
}

int** returnTransponatedMatrix(int** matrix, int rowsCount, int rowsLength)
{
	if (!matrix)
		return nullptr;

	for (size_t i = 0; i < rowsCount; i++)
	{
		if (!matrix[i])
			return nullptr;
	}

	int** transponated = new int* [rowsLength];

	for (size_t i = 0; i < rowsLength; i++)
	{
		transponated[i] = new int[rowsCount];
	}

	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < rowsLength; j++)
		{
			transponated[j][i] = matrix[i][j];
		}
	}

	return transponated;
}

void printCharMatrix(char** matrix, int rowsCount)
{
	if (!matrix)
		return;

	for (size_t i = 0; i < rowsCount; i++)
	{
		if (!matrix[i])
			return;
	}

	for (size_t i = 0; i < rowsCount; i++)
	{
		std::cout << matrix[i] << std::endl;
	}

}

char** createMatrixOutOfText(char* text, int rows)
{
	char** matrix = new char* [3];
	int firstRowLength = 0;
	int secondRowLength = 0;
	int thirdRowLength = 0;

	int curIndex = 0;
	while (text[curIndex])
	{
		if (curIndex % 4 == 0)
		{
			firstRowLength++;
		}
		else if (curIndex % 2 == 1)
		{
			secondRowLength++;
		}
		else if ((curIndex - 2) % 4 == 0)
		{
			thirdRowLength++;
		}

		curIndex++;
	}

	firstRowLength += (firstRowLength - 1) * 3;
	secondRowLength += secondRowLength - 1;
	thirdRowLength += (thirdRowLength - 1) * 3;

	matrix[0] = new char[firstRowLength + 1];
	matrix[1] = new char[secondRowLength + 1];
	matrix[2] = new char[thirdRowLength + 1];
	matrix[0][firstRowLength] = '\0';
	matrix[1][secondRowLength] = '\0';
	matrix[2][thirdRowLength] = '\0';

	int index = 0;
	int indexForFirstRow = 0;
	int indexForSecondRow = 0;
	int indexForThirdRow = 0;
	while (text[index])
	{
		if (index % 4 == 0)
		{
			if (indexForFirstRow != 0)
			{
				matrix[0][indexForFirstRow++] = ' ';
				matrix[0][indexForFirstRow++] = ' ';
				matrix[0][indexForFirstRow++] = ' ';
			}
			matrix[0][indexForFirstRow++] = text[index];
		}
		else if (index % 2 == 1)
		{
			if (indexForSecondRow != 0)
			{
				matrix[1][indexForSecondRow++] = ' ';
			}
			matrix[1][indexForSecondRow++] = text[index];
		}
		else if ((index - 2) % 4 == 0)
		{
			if (indexForThirdRow != 0)
			{
				matrix[2][indexForThirdRow++] = ' ';
				matrix[2][indexForThirdRow++] = ' ';
				matrix[2][indexForThirdRow++] = ' ';
			}
			matrix[2][indexForThirdRow++] = text[index];
		}

		index++;
	}

	return matrix;
}

char** createMatrixFromSplittedWords(char* text, char separator)
{
	if (!text)
		return nullptr;

	int countOfWords = 1;

	int currentIndex = 0;
	while (text[currentIndex])
	{
		if (text[currentIndex] == separator)
		{
			countOfWords++;
		}

		currentIndex++;
	}

	char** words = new char* [countOfWords];

	int index = 0;
	int wordsIndex = 0;
	while (text[index==0?index:index-1])
	{
		if (text[index] != separator)
		{
			int currentWordLength = 0;
			while (text[currentWordLength + index])
			{
				if (text[currentWordLength + index] == separator)
				{
					break;
				}
				currentWordLength++;
			}


			words[wordsIndex] = new char[currentWordLength+1];
			words[wordsIndex][currentWordLength] = '\0';

			for (size_t i = 0; i < currentWordLength; i++)
			{
				words[wordsIndex][i] = text[index + i];
			}

			index += currentWordLength;
		}
		
		index++;
	}

	return words;
}

int main()
{
	/*int rowsCount = 2;
	int rowsLength = 3;

	int** matrix = new int* [2];
	matrix[0] = new int[3] { 1, 2, 3 };
	matrix[1] = new int[3] { 4, 5, 6 };

	printIntMatrix(returnTransponatedMatrix(matrix, 2, 3), 3, 2);*/

	//char text[] = "PAYPALISHIRING";
	//int rowsCount = 0;

	//char** matrix = createMatrixOutOfText(text,rowsCount);

	//printCharMatrix(matrix,3);

	char text[] = "Hello:my:name:is";
	char** matrix = createMatrixFromSplittedWords(text,':');
	printCharMatrix(matrix,4);
}

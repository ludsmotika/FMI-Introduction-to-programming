#include <iostream>

int getCountOfDevisableByK(const int* ptr, size_t size, int k)
{
	if (!ptr)
	{
		return 0;
	}

	int count = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (ptr[i] % k == 0)
		{
			count++;
		}
	}

	return count;
}

int* getElementsOfNewArray(const int* ptr1, size_t size1, const int* ptr2, size_t size2, int k)
{
	if (!ptr1 || !ptr2)
	{
		return nullptr;
	}

	int countOfDevisableByK = getCountOfDevisableByK(ptr1, size1, k) + getCountOfDevisableByK(ptr2, size2, k);
	int* result = new int[countOfDevisableByK];

	for (size_t i = 0; i < size1; i++)
	{
		if (ptr1[i] % k == 0)
		{
			*result = ptr1[i];
			result++;
		}
	}
	for (size_t i = 0; i < size2; i++)
	{
		if (ptr2[i] % k == 0)
		{
			*result = ptr2[i];
			result++;
		}
	}

	result -= countOfDevisableByK;

	return result;
}

//03
void shiftOnes(int* ptr, size_t size)
{
	if (!ptr)
	{
		return;
	}

	int last = ptr[size - 1];

	for (int i = size - 1; i > 0; i--)
	{
		ptr[i] = ptr[i - 1];
	}

	ptr[0] = last;
}

void cycleArr(int* ptr, size_t size, int rotations)
{
	if (!ptr)
	{
		return;
	}

	rotations = rotations % size;

	for (size_t i = 0; i < rotations; i++)
	{
		shiftOnes(ptr, size);
	}

}

bool isDevisableByNeightbours(int* ptr, size_t size, int i)
{
	if (i == 0)
	{
		return (ptr[i] % ptr[i + 1] == 0);
	}
	else if (i == size - 1)
	{
		return (ptr[i] % ptr[i - 1] == 0);
	}

	return (i >= 1 && i <= size - 2) ? (ptr[i] % ptr[i - 1] == 0 || ptr[i] % ptr[i + 1] == 0) : false;
}

int getCountOfValidElements(int* ptr, size_t size)
{
	if (!ptr)
	{
		return 0;
	}

	unsigned count = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (isDevisableByNeightbours(ptr, size, i))
		{
			count++;
		}
	}

	return count;
}

int* getELementsWhichDevideByTheirNeighbours(int* ptr, size_t size)
{
	if (!ptr)
	{
		return nullptr;
	}

	int length = getCountOfValidElements(ptr, size);

	int* result = new int[length];

	for (size_t i = 0; i < size; i++)
	{
		if (isDevisableByNeightbours(ptr, size, i))
		{
			*result = ptr[i];
			result++;
		}
	}

	result -= length;

	return result;
}

int countOfLetterByType(char* ptr, size_t size, bool isUpperCase)
{
	if (!ptr)
	{
		return 0;
	}

	int count = 0;
	char lowerBound = 'a';
	char upperBound = 'z';

	if (isUpperCase)
	{
		lowerBound += ('A' - 'a');
		upperBound += ('A' - 'a');
	}

	for (size_t i = 0; i < size; i++)
	{
		if (ptr[i] >= lowerBound && ptr[i] <= upperBound)
		{
			count++;
		}
	}

	return count;
}

bool isLowerCase(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}
bool isUpperCase(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

char* getConcatedStringFromLowerAndUpperCase(char* ptr1, size_t size1, char* ptr2, size_t size2)
{
	if (!ptr1 || !ptr2)
	{
		return nullptr;
	}

	int countOfNewArray = countOfLetterByType(ptr1, size1, 0) + countOfLetterByType(ptr2, size2, 1);

	char* result = new char[countOfNewArray];

	for (size_t i = 0; i < size1; i++)
	{
		if (isLowerCase(ptr1[i]))
		{
			*result = ptr1[i];
			result++;
		}
	}
	for (size_t i = 0; i < size2; i++)
	{
		if (isUpperCase(ptr2[i]))
		{
			*result = ptr2[i];
			result++;
		}
	}

	*result = '\0';

	result -= countOfNewArray;

	return result;
}

bool isIndexValid(int i, size_t size)
{
	return (i >= 0 && i <= size);
}


bool isSymbolUniqueInString(char* ptr, size_t size, int index)
{
	if (!ptr || !isIndexValid(index, size))
	{
		return false;
	}

	char currentSymbol = ptr[index];

	for (size_t i = 0; i < size; i++)
	{
		if (i == index)
		{
			continue;
		}

		if (currentSymbol == ptr[i])
		{
			return false;
		}
	}

	return true;
}

char* getUniqueSymbols(char* ptr, size_t size)
{
	if (!ptr)
	{
		return nullptr;
	}

	int countOfUnique = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (isSymbolUniqueInString(ptr, size, i))
		{
			countOfUnique++;
		}
	}

	char* result = new char[countOfUnique];

	for (size_t i = 0; i < size; i++)
	{
		if (isSymbolUniqueInString(ptr, size, i))
		{
			*result = ptr[i];
			result++;
		}
	}

	*result = '\0';

	result -= countOfUnique;

	return result;
}

int mystrlen(char* ptr)
{
	if (!ptr)
	{
		return false;
	}

	int count = 0;

	while (*ptr)
	{
		count++;
		ptr++;
	}

	return count;
}

char* insertSymbolOnPositions(char* ptr, int* positions, int positionsCount, char symbol)
{
	if (!ptr || !positions)
	{
		return nullptr;
	}

	int stringLength = mystrlen(ptr);

	int lengthOfNewString = stringLength + positionsCount;

	char* result = new char[lengthOfNewString];

	int currentPositions = *positions;
	positions++;

	for (int i = 0; i < stringLength; i++)
	{
		if (i == currentPositions)
		{
			*result = symbol;
			result++;
			currentPositions = *positions;
			positions++;
		}

		*result = ptr[i];
		result++;
	}

	*result = '\0';
	result -= lengthOfNewString;

	return result;
}

int firstWordLettersCount(char* ptr, int size)
{
	if (!ptr)
	{
		return 0;
	}

	int count = 0;

	while (*ptr)
	{
		if (*ptr ==' ')
		{
			break;
		}
		count++;
		ptr++;
	}

	return count;
}

int lastWordLettersCount(char* ptr, int size)
{
	if (!ptr)
	{
		return 0;
	}

	int count = 0;
	ptr += size-1;

	while (*ptr)
	{
		if (*ptr ==' ')
		{
			break;
		}
		count++;
		ptr--;
	}

	return count;
}

char* concatFirstAndLastWord(char* ptr)
{
	if (!ptr)
	{
		return nullptr;
	}

	int stringLength = mystrlen(ptr);

	int firstWordLettersC = firstWordLettersCount(ptr, stringLength);
	int lastWordLettersC = lastWordLettersCount(ptr, stringLength);

	int newStringLength = firstWordLettersC + lastWordLettersC + 1;

	char* result = new char[newStringLength];

	for (size_t i = 0; i < firstWordLettersC; i++)
	{
		*result = ptr[i];
		result++;
	}

	*result = ' ';
	result++;

	for (size_t i = stringLength - lastWordLettersC; i < stringLength; i++)
	{
		*result = ptr[i];
		result++;
	}

	*result = '\0';

	return result -= newStringLength;
}

int main()
{
	//01

	/*int n;
	std::cin >> n;

	int* arr = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	for (int i = n-1; i >=0; i--)
	{
		std::cout << arr[i]<< " ";
	}*/

	//02

	/*int ptr1[] = { 2, 4, 5, 8 };
	int* ptrOne = ptr1;

	int ptr2[] = { 3, 16, 7 ,9, 10 };
	int* ptrTwo = ptr2;

	int* ptr = getElementsOfNewArray(ptrOne, 4, ptrTwo, 5, 2);

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << ptr[i] << " ";
	}*/


	//03

	//int ptr2[] = { 3, 16, 7 ,9, 10 };
	//int* ptrTwo = ptr2;

	//cycleArr(ptrTwo, 5, 4);

	//for (size_t i = 0; i < 5; i++)
	//{
	//	std::cout << ptr2[i] << " ";
	//}

	//04

	/*int arr[] = { 5, 10, 20, 4,2, 7 };
	int* ptr = arr;

	int* result = getELementsWhichDevideByTheirNeighbours(ptr, 5);

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << result[i] << " ";
	}*/

	//05

	/*char arr[] = "abcAGHp";
	char* ptr = arr;

	char arr2[] = "mnAHGT5saP";
	char* ptr2 = arr2;

	char* result = getConcatedStringFromLowerAndUpperCase(ptr, 7, ptr2, 10);

	std::cout << result;*/

	//06

	/*char arr[] = "aklahk3g*5ggkkks";
	char* ptr = arr;

	char* result = getUniqueSymbols(ptr, 16);

	std::cout << result;*/

	//07

	/*char arr[] = "Hi here nice o mee you.";
	char* ptr = arr;

	int arr2[] = { 3,13,18 };
	int* ptr2 = arr2;

	char* result = insertSymbolOnPositions(ptr, ptr2, 3, 't');

	std::cout << result;*/

	//08


	char arr[] = "Hello hi hey";
	char* ptr = arr;

	char* result = concatFirstAndLastWord(ptr);

	std::cout << result;

}
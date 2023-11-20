#include <iostream>

void print(const char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

char getSymbolFromIndex(int ind)
{
	if (ind >= 0 && ind <= 9)
		return ind + '0';

	if (ind >= 10)
		return (ind - 10) + 'A';

	return 0;
}

int fromDecimalToRandom(unsigned n, char to[], size_t size, unsigned k)
{
	int counter = 0;

	for (int arrayIter = size - 1; arrayIter >= 0; arrayIter--)
	{
		int ind = n % k;
		char current = getSymbolFromIndex(ind);
		to[arrayIter] = current;
		counter++;
		n /= k;
	}

	return counter;
}

int getIndexOfSymbol(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else if (ch >= 'A' && ch <= 'Z')
		return 10 + (ch - 'A');
	else
		return -1;
}

unsigned int fromRandomToDecimal(const char from[], size_t size, unsigned k)
{
	int result = 0;

	for (int i = size - 1, mult = 1; i >= 0; i--, mult *= k)
		result += getIndexOfSymbol(from[i]) * mult;
	return result;
}

void incrementByOne(char arr[], int size, int k)
{
	int currentIndex = size - 1;

	while (true)
	{
		int index = getIndexOfSymbol(arr[currentIndex]);

		char nextSymbol = getSymbolFromIndex(index + 1);

		if (getIndexOfSymbol(nextSymbol) >= k)
		{
			arr[currentIndex] = '0';
			currentIndex--;
		}
		else
		{
			arr[currentIndex] = nextSymbol;
			break;
		}
	}
}

void decrementByOne(char arr[], int size, int k)
{
	int indexForChangedSymbol = -1;

	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] != '0')
		{
			int index = getIndexOfSymbol(arr[i]);

			char previousSymbol = getSymbolFromIndex(index - 1);

			arr[i] = previousSymbol;

			indexForChangedSymbol = i;

			break;
		}
	}

	for (int i = indexForChangedSymbol + 1; i <= size - 1; i++)
	{
		arr[i] = getSymbolFromIndex(k - 1);
	}
}

void addTwoNums(const char arr1[], const char arr2[], int size, int k, char answer[])
{
	int remainder = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		int sum = getIndexOfSymbol(arr1[i]) + getIndexOfSymbol(arr2[i]) + remainder;
		remainder = sum / k;
		answer[i] = getSymbolFromIndex(sum % k);
	}
}

bool isDecimalNumPalindromInRandom(unsigned decimalNum , int k)
{
	constexpr int maxSize = 1000;
	char arr[maxSize];
	char size = fromDecimalToRandom(decimalNum, arr, 3, k);

	for (size_t i = 0; i <size/2; i++)
	{
		if (arr[i]!= arr[size-i-1])
		{
			return false;
		}
	}

	return true;
}

bool areTwoNumsFromDifferenSystemEqual(char arr1[], int size1, int k1, char arr2[], int size2, int k2)
{
	int first = fromRandomToDecimal(arr1, size1, k1);
	int second = fromRandomToDecimal(arr2, size2, k2);

	if (first == second)
	{
		return true;
	}

	return false;
}

int main()
{
	char arr1[] = { '3','4','5' };
	char arr2[] = { 'E','5'};

	std::cout << areTwoNumsFromDifferenSystemEqual(arr1, 3, 8, arr2, 2, 16);
}
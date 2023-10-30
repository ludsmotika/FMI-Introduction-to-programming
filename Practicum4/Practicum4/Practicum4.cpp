#include <iostream>


int abs(int n)
{
	return n > 0 ? n : -n;
}


double fabs(double n)
{
	return n > 0 ? n : -n;
}

char to_lower(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
	{
		return symbol - ('A' - 'a');
	}
	return -1;
}

char to_upper(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
	{
		return symbol + ('A' - 'a');
	}
	return -1;
}


int convertCharToInt(char symbol)
{
	return int(symbol - '0');
}


char convertIntToChar(int symbol)
{
	return char(symbol + '0');
}

int numberOfDigits(int n)
{
	int count = 0;

	do
	{
		n /= 10;
		count++;

	} while (n != 0);


	return count;
}

int digitByIndex(int n, int index)
{
	int countOfDigitsToSkip = numberOfDigits(n) - index;

	while (countOfDigitsToSkip != 0)
	{
		countOfDigitsToSkip--;
		n /= 10;
	}

	return n % 10;
}

int remainder(int first, int second)
{
	while (first >= second)
	{
		first -= second;
	}

	return first;
}

int devidor(int first, int second)
{
	int result = 0;
	while (first >= second)
	{
		first -= second;
		result++;
	}

	return result;
}

int squareRoot(int n)
{
	for (int i = 0; i <= n / 2; i++)
	{
		if (i * i > n)
		{
			return i - 1;
		}
	}
}

bool haveSqrtExactRoot(int n)
{
	for (int i = 0; i <= n / 2; i++)
	{
		if (i * i == n)
		{
			return true;
		}
	}
	return false;
}

int nokOfThreeNumbers(int first, int second, int third)
{
	int devidor = first;
	while (true)
	{
		if (devidor % first == 0 && devidor % second == 0 && devidor % third == 0)
		{
			return devidor;
		}

		devidor += first;
	}
}

bool isInCircle(int x1, int y1, int x2, int y2, int x3, int y3, int radius)
{
	double fromFirstPointToCenter = sqrt(x1 * x1 + y1 * y1);
	double fromSecondPointToCenter = sqrt(x2 * x2 + y2 * y2);
	double fromThirdPointToCenter = sqrt(x3 * x3 + y3 * y3);

	if (radius - fromFirstPointToCenter >= 0 && radius - fromSecondPointToCenter >= 0 && radius - fromThirdPointToCenter >= 0)
	{
		return true;
	}

	return false;
}

int concatenateNums(int first, int second)
{
	int secondCopy = second;

	while (secondCopy != 0)
	{
		first *= 10;
		secondCopy /= 10;
	}

	return first + second;
}

long long sumOfDigits(long long n)
{
	long long sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int returnSortedNumber(int n)
{

	int orderedNumber = 0;
	int copyOfN = n;

	for (int i = 1; i < copyOfN; i *= 10)
	{
		int copyofN = n;

		int currentBiggest = 0;
		int indexOfCurrentBiggestNumber = 0;

		for (int k = 10; k <= n * 10; k *= 10)
		{
			int current = copyofN % 10;
			copyofN /= 10;

			if (current >= currentBiggest)
			{
				currentBiggest = current;
				indexOfCurrentBiggestNumber = k;
			}
		}

		int toRemove = (currentBiggest * (indexOfCurrentBiggestNumber / 10));
		n -= toRemove;

		orderedNumber = (currentBiggest * i) + orderedNumber;
	}

	return orderedNumber;
}

int main()
{
	std::cout << returnSortedNumber(25372454);
}
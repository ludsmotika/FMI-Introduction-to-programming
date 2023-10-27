#include <iostream>

//01 
int moduleOfN(int n)
{
	return n < 0 ? -n : n;
}

//02

int countOfN(int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return count;
}

//03

double parameterOfTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double firstSide = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	double secondSide = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	double thirdSide = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));


	return firstSide + secondSide + thirdSide;
}

//04 

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

//05

int reverseAndConcatenateNum(int n)
{
	int reverseOfN = 0;
	int copyOfN = n;
	while (copyOfN != 0)
	{
		reverseOfN *= 10;
		reverseOfN += copyOfN % 10;
		copyOfN /= 10;
	}

	return concatenateNums(reverseOfN, n);
}

//06

int primeDevidorsOfN(int n)
{
	int countOfDevisors = 0;

	int currentDevisor = 2;

	int lastDevisor = 1;

	while (n >= currentDevisor)
	{
		if (n % currentDevisor == 0)
		{
			n /= currentDevisor;
			if (lastDevisor != currentDevisor)
			{
				countOfDevisors++;
				lastDevisor = currentDevisor;
			}
		}
		else
		{
			currentDevisor++;
		}
	}

	return countOfDevisors;
}

int getNumsWithDevidorInRange(int a, int b, int k)
{
	int countOfValidNumsInRange = 0;

	for (int i = a; i <= b; i++)
	{
		if (primeDevidorsOfN(i) == k)
		{
			countOfValidNumsInRange++;
		}
	}

	return countOfValidNumsInRange;
}

//07

bool doesNumberHasOrder(int n)
{
	bool isOrderIncreasing = (n % 10 - ((n % 100) / 10) >= 0) ? true : false;

	int previousDigit = n % 10;
	n /= 10;

	while (n != 0)
	{
		int currentDigit = n % 10;

		if ((isOrderIncreasing && currentDigit > previousDigit) || (!isOrderIncreasing && currentDigit < previousDigit))
		{
			return false;
		}

		n /= 10;
	}

	return true;

}

//08

bool doesAllDigitsAreSame(int n)
{
	int previousDigit = n % 10;

	while (n != 0)
	{
		if (previousDigit == n % 10)
		{
			n /= 10;
		}
		else
		{
			return false;
		}
	}
	return true;

}

//09

int returnSortedNumber(int n)
{

	int orderedNumber = 0;
	int copyOfN = n;

	//<=n
	for (int i = 1; i < copyOfN; i *= 10)
	{
		int copyofN = n;

		int currentBiggest = 0;
		int indexOfCurrentBiggestNumber = 0;
		//not sure about the n*10
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

		//remove the biggest number by math operation because you know the index
		int toRemove = (currentBiggest * (indexOfCurrentBiggestNumber / 10));
		n -= toRemove;

		orderedNumber = (currentBiggest * i) + orderedNumber;
	}

	return orderedNumber;
}

//12

int returnDigitFromSymbol(char symbol) 
{
	if (symbol>='0' && symbol <= '9')
	{
		return int(symbol) - int('0');
	}

	return -1;
}

int main()
{
	std::cout << returnDigitFromSymbol('9');
}


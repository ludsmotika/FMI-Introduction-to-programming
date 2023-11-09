#include <iostream>

void swapValues(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

int countOfDigits(int n)
{
	int count = 0;

	while (n != 0)
	{
		count++;
		n /= 10;
	}

	return count;
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

int power(int a, int b)
{
	int powerd = a;

	if (b == 0)
	{
		return a;
	}

	while (b != 0)
	{
		powerd *= a;
		b--;
	}

	return powerd;
}

void cropNumber(int& num, int index)
{
	//12345678 3
	int copy = num;
	int countOfDigitsOfNum = countOfDigits(num);

	if (countOfDigitsOfNum == index)
	{
		num /= 10;
		return;
	}

	for (size_t i = 0; i <= countOfDigitsOfNum - index; i++)
	{
		copy /= 10;
	}

	int secondPart = num % (power(10, countOfDigitsOfNum - index - 1));
	num = concatenateNums(copy, secondPart);

}

void findShortenRationalNumber(int& rational, int& denominator)
{
	int smaller = (rational < denominator ? rational : denominator);

	for (int i = 2;i <= smaller; i++)
	{
		if (rational % i == 0 && denominator % i == 0)
		{
			rational /= i;
			denominator /= i;
			i--;
		}
	}
}

void getRationalAndDenominator(int& a, int& b, int c, int d)
{
	a = (a * d) + (b * c);
	b = b * d;
}

int reverseNum(int n)
{
	int reverseOfN = 0;
	int copyOfN = n;
	while (copyOfN != 0)
	{
		reverseOfN *= 10;
		reverseOfN += copyOfN % 10;
		copyOfN /= 10;
	}

	return reverseOfN;
}

void swapTwoDigitsFromNumbersByIndex(int& a, int& b, int index)
{
	int aReversed = reverseNum(a);
	int bReversed = reverseNum(b);

	int countOfDigitsOfA = countOfDigits(a);
	int countOfDigitsOfB = countOfDigits(b);

	for (int i = 1; i < index; i++)
	{
		aReversed /= 10;
		bReversed /= 10;
	}
	int numToRemoveFromA = aReversed % 10;
	int numToRemoveFromB = bReversed % 10;


	//4353 3

	a -= (numToRemoveFromA * power(10, countOfDigitsOfA - index - 1));
	b -= (numToRemoveFromB * power(10, countOfDigitsOfB - index - 1));

	a += (numToRemoveFromB * power(10, countOfDigitsOfA - index - 1));
	b += (numToRemoveFromA * power(10, countOfDigitsOfB - index - 1));
}

void devideByIndexes(int& fromEvenIndexes, int& fromOddIndexes, int a)
{
	int countOfDigitsOfA = countOfDigits(a);

	int reversedA = reverseNum(a);

	int copyOfA = a;
	int countOfEndingZeros = 0;

	while (copyOfA % 10 != 0)
	{
		copyOfA /= 10;
		countOfEndingZeros++;
	}

	for (int i = 1; i <= countOfDigitsOfA; i++)
	{
		int currentDigit = reversedA % 10;
		reversedA /= 10;

		if (i % 2 == 0)
		{
			fromEvenIndexes = fromEvenIndexes * 10 + currentDigit;
		}
		else
		{
			fromOddIndexes = fromOddIndexes * 10 + currentDigit;
		}
	}

	if (countOfEndingZeros>0)
	{
		for (int i = countOfDigitsOfA - countOfEndingZeros; i < countOfDigitsOfA; i++)
		{
			if (i%2==0) 
			{
				fromEvenIndexes *= 10;
			}
			else 
			{
				fromOddIndexes *= 10;
			}
		}
	}
}


int countOfSimpleDevisors(int num)
{
	int simpleDevisors = 0;
	for (int i = 2; i <= num/2; i++)
	{
		if (num%i==0) 
		{
			simpleDevisors++;
			i--;
			num = num/ i;
		}
	}
	if (simpleDevisors==0)
	{
		return 1;
	}

	return simpleDevisors;
}

void changeValuesWithNumsInIntervals(int& a,int& b, int k)
{

	for (int i = a; i <= b; i++)
	{
		int current = countOfSimpleDevisors(i);
		if (countOfSimpleDevisors(i) == k)
		{
			a = i;
			break;
		}
	}
	
	for (int i = b; i >= a; i--)
	{
		int current = countOfSimpleDevisors(i);

		if (countOfSimpleDevisors(i) == k)
		{
			b = i;
			break;
		}
	}
}

int main()
{
	int a;
	int b;
	int k;
	std::cin >> a >> b >> k;

	changeValuesWithNumsInIntervals(a, b, k);

	std::cout << a << " " << b;

	//19 32 3
}

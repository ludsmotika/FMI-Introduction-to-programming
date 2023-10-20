#include <iostream>

int main()
{
	//01

	/*int n;
	std::cin >> n;

	int sum = 0;

	while (n!=0)
	{
		sum+=n;
		std::cin >> n;
	}

	std::cout << sum;*/

	//02

	/*int smaller, bigger;
	std::cin >> smaller >> bigger;

	if (smaller > bigger)
	{
		int temp = smaller;
		smaller = bigger;
		bigger = temp;
	}

	for (int i = smaller; i >= 1; i--)
	{
		if ((smaller % i == 0) && (bigger % i == 0))
		{
			std::cout << i << " ";
		}
	}*/

	//03

	//int number;
	//std::cin >> number;

	//int copyOfNumber = number;
	//int countOfDigits = 0;
	//int outputNumber = 0;

	////getting the number of the digits of the input number 

	//while (copyOfNumber % 10 != 0)
	//{
	//	copyOfNumber /= 10;
	//	countOfDigits++;
	//}

	////we are going fto create the new number by getting and multiplying 
	////each digit by multiplier for the dozens hundreds.... except the middle ones

	//int currentMultiplyier = 1;

	//for (int i = 1; i <= countOfDigits; i++)
	//{
	//	int currentDigit = 0;
	//	int copyOfNumberForGettingTheCurrentDigit = number;

	//	for (int k = 1; k <= i; k++)
	//	{
	//		currentDigit = copyOfNumberForGettingTheCurrentDigit % 10;
	//		copyOfNumberForGettingTheCurrentDigit /= 10;
	//	}

	//	if (countOfDigits % 2 == 0 && i != countOfDigits / 2 && i != (countOfDigits / 2) + 1)
	//	{
	//		outputNumber += currentMultiplyier * currentDigit;
	//	}
	//	else if (countOfDigits % 2 == 1 && i != (countOfDigits + 1) / 2)
	//	{
	//		outputNumber += currentMultiplyier * currentDigit;
	//	}
	//	else 
	//	{
	//		continue;
	//	}
	//	currentMultiplyier *= 10;
	//}

	//std::cout << outputNumber << ", " << outputNumber + 1;

	//04

	/*int smaller, bigger;
	std::cin >> smaller >> bigger;

	if (smaller >= bigger)
	{
		return 0;
	}
	else
	{
		for (int i = smaller; i <= bigger; i++)
		{

			bool isPrime = true;

			for (int k = 2, maxDevisor = std::sqrt(i); k <= maxDevisor; k++)
			{
				if (i % k == 0)
				{
					isPrime = false;
				}
			}

			if (isPrime && i!=1)
			{
				std::cout << i << " ";
			}
		}
	}*/

	//05

	//int number;
	//std::cin >> number;

	//bool isPower = false;

	//for (int i = 1; i <= number; i *= 2)
	//{
	//	if (number == i)
	//	{
	//		isPower = true;
	//	}
	//}

	//std::cout << (isPower ? "true" : "false");

	//06

	/*int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	for (int i = -100; i <= 100; i++)
	{
		int result = (a * std::pow(i, 4)) + (b * std::pow(i, 3)) + (c * std::pow(i, 2)) + (d * i) + e;
		if (result >= 0)
		{
			std::cout << i << " ";
		}
	}*/

	//07

	/*int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= i; k++)
		{
			std::cout << "$ ";
		}

		std::cout << std::endl;
	}*/

	//08

	/*int n;
	std::cin >> n;

	for (int i = 1; i <= n * 2 - 1; i++)
	{
		for (int k = n; k >= 1; k--)
		{
			if (i <= n && k <= i)
			{
				std::cout << k;
			}
			else if (i > n && k <= 2*n-i)
			{
				std::cout << k;
			}
			else
			{
				std::cout << " ";
			}
		}

		std::cout << std::endl;
	}*/

	//09

	/*int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{

			int elementBefore = k*n;

			if (k%2==0)
			{
				elementBefore += n-i;
			}
			else
			{
				elementBefore += i-1;
			}

			std::cout << elementBefore + 1- n << " ";
		}
		std::cout << std::endl;
	}*/

	//10

	/*int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{

		for (int k = 1; k <= n; k++)
		{

			if (i % 2 == 0)
			{
				std::cout << (n - k) + ((i - 1) * n) + 1 << " ";
			}
			else
			{
				std::cout << k + ((i - 1) * n) << " ";
			}
		}
		std::cout << std::endl;

	}*/

	//11

	//int n;
	//std::cin >> n;
	////draw first line

	//std::cout << "+ ";
	//for (int i = 1; i <= n - 2; i++)
	//{
	//	std::cout << "- ";
	//}

	//std::cout << "+" << std::endl;

	////draw body

	//for (int i = 1; i <= n-2; i++)
	//{
	//	std::cout << "| ";
	//	for (int k = 1; k <= n-2; k++)
	//	{
	//		std::cout << "- ";

	//	}
	//	std::cout << "|"<< std::endl;

	//}

	////draw last line
	//std::cout << "+ ";
	//for (int i = 1; i <= n - 2; i++)
	//{
	//	std::cout << "- ";
	//}

	//std::cout << "+" << std::endl;


	//16

	int n;
	std::cin >> n;

	int first = n;
	int second = 0;

	int iterations = n;

	for (int i = 0; i < iterations; i++)
	{
		std::cin >> n;

		if (n > second)
		{

			if (n > first)
			{
				second = first;
				first = n;
			}
			else
			{
				second = n;
			}
		}


	}

	std::cout << first << " " << second;
}


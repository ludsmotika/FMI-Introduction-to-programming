
#include <iostream>

int main()
{
	//01
	/*int first;
	int last;

	std::cin >> first >> last;

	if (first < 0 || first >256 || last < 0 || last >256)
	{
		std::cout << "Invalid codes!";
	}
	else
	{
		for (int i = first; i <= last; i++)
		{
			std::cout << i << ">>" << (char)i << std::endl;
		}
	}*/

	//02

	/*int n;

	std::cin >> n;

	int fact = 1;

	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}

	std::cout << "Factorial: " << fact;*/

	//03

	/*int n;

	std::cin >> n;

	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= i; k++)
		{
			sum += k;
		}
	}

	std::cout << sum;*/

	//04

	/*int n;

	std::cin >> n;

	int sum = 0;

	int step = 9;

	for (int i = 1; i <= n; i++)
	{
		sum += step;

		step = (step * 10) + 9;
	}

	std::cout << sum;*/


	//05

	/*int n;

	std::cin >> n;

	int previous = 1;
	int prePrevious = 1;


	std::cout << "0 1 1";

	for (int i = 1; i <= n-3; i++)
	{
		int current = previous + prePrevious;
		prePrevious = previous;
		previous = current;


		std::cout << " " << current;
	}*/

	//06

	/*int n;
	std::cin >> n;

	int current;
	std::cin >> current;

	int sum = 0;

	while (current != -1)
	{
		if (current < n && current%2==0)
		{
			sum += current;
		}
		std::cin >> current;
	}

	std::cout << sum;*/

	//07

	/*int start;
	int last;
	std::cin >> start >> last;

	for (int i = start; i <= last; i++)
	{
		int sum = 0;

		for (int k = 1; k < i; k++)
		{
			if (i % k == 0)
			{
				sum += k;
			}
		}

		if (sum == i)
		{
			std::cout << i << std::endl;
		}

	}*/

	//08

	/*int n;
	std::cin >> n;

	for (int i = 3; i < n/2; i++)
	{
		bool isPrime = true;

		int sqrtI = sqrt(i);
		for (int k = 2; k <= sqrtI; k++)
		{
			if (i % k == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			int opposite = n - i;

			int sqrtOfOpp = sqrt(opposite);

			bool isOppositePrime = true;
			for (int k = 2; k <= sqrtOfOpp; k++)
			{
				if (opposite % k == 0)
				{
					isOppositePrime = false;
				}
			}


			if (isOppositePrime && opposite!=1)
			{
				std::cout << n << "=" << i << " + " << n - i << std::endl;
			}
		}

	}*/

	//09

	/*int n;
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

	std::cout << first << " " << second;*/

	//10

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

	//for (int i = 1; i <= n - 2; i++)
	//{
	//	std::cout << "| ";
	//	for (int k = 1; k <= n - 2; k++)
	//	{
	//		std::cout << "- ";

	//	}
	//	std::cout << "|" << std::endl;

	//}

	////draw last line
	//std::cout << "+ ";
	//for (int i = 1; i <= n - 2; i++)
	//{
	//	std::cout << "- ";
	//}

	//std::cout << "+" << std::endl;


//12
//
//	int n;
//	std::cin >> n;
//
//
//	//rows
//	for (int i = 1; i <= 2 * n - 1; i++)
//	{
//
//		//cols
//
//		//first third
//
//		for (int k = 1; k <= n; k++)
//		{
//			if (k <= i && i <= n)
//			{
//				std::cout << k << " ";
//			}
//			else if (k <= n-(i-n) && i > n)
//			{
//				std::cout << k << " ";
//			}
//			else
//			{
//				std::cout << "  ";
//			}
//		}
//
//		//second third
//		for (int k = 1; k <= n; k++)
//		{
//			if (i == n)
//			{
//				std::cout << "-";
//			}
//			else
//			{
//				std::cout << " ";
//			}
//		}
//		std::cout << " ";
//
//
//		//last third
//		for (int k = n; k >= 1; k--)
//		{
//			if (k <= i && i <= n)
//			{
//				std::cout << k << " ";
//			}
//			else if (k <= n-(i - n) && i > n)
//			{
//				std::cout << k << " ";
//			}
//			else
//			{
//				std::cout << "  ";
//			}
//		}
//
//		std::cout << std::endl;
//	}

	//13

	int n;
	std::cin >> n;

	for (int i = 1; i <= 2 * n + 3; i++)
	{
		if (i == 1 || i == 2 * n + 3)
		{
			for (int j = 1; j <= n + 2; j++)
			{
				std::cout << "#";
			}
		}
		else if (i == n + 2)
		{
			for (int i = 1; i <= n + 2; i++)
			{
				if (i == 1 || i == n + 2)
				{
					std::cout << "#";
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		else
		{
			if (i <= n + 1)
			{
				for (int k = 1; k <= n + 2; k++)
				{
					if (k == 1 || k == n + 2)
					{
						std::cout << "#";
					}
					else
					{
						int toPrint = 0;

						toPrint = ((i-3 + k) % n);


						if (toPrint == 0)
						{
							toPrint = n;
						}
						std::cout << toPrint;;
					}
				}
			}
			else
			{


				for (int k = n + 2; k >= 1; k--)
				{
					if (k == 1 || k == n + 2)
					{
						std::cout << "#";
					}
					else
					{
						int toPrint = 0;

						toPrint = (i + k+1)%n;

						if (toPrint == 0)
						{
							toPrint = n;
						}
						std::cout << toPrint;;
					}
				}
			}
		}

		std::cout << std::endl;
	}

	//14

		//int n;
		//std::cin >> n;

		//for (int i = 1; i <= n; i++)
		//{
		//	for (int k = 1; k <= n; k++)
		//	{

		//		int elementBefore = k * n;

		//		if (k % 2 == 0)
		//		{
		//			elementBefore += n - i;
		//		}
		//		else
		//		{
		//			elementBefore += i - 1;
		//		}

		//		std::cout << elementBefore + 1 - n << " ";
		//	}
		//	std::cout << std::endl;
		//}
}

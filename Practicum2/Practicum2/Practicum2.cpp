#include <iostream>

int main()
{
	//01 


	/*int n;
	std::cin >> n;

	switch (n)
	{
	case 1:
		std::cout << "I";
		break;
	case 2:
		std::cout << "II";
		break;
	case 3:
		std::cout << "III";
		break;
	case 4:
		std::cout << "IV";
		break;
	case 5:
		std::cout << "V";
		break;
	case 6:
		std::cout << "VI";
		break;
	case 7:
		std::cout << "VII";
		break;
	case 8:
		std::cout << "VIII";
		break;
	case 9:
		std::cout << "IX";
		break;
	default:
		break;
	}*/


	//02


	/*char symbol;

	std::cin >> symbol;

	if (symbol == 'I' || symbol == 'V' || symbol == 'X' || symbol == 'C' || symbol == 'L' || symbol == 'M' || symbol == 'D')
	{
		std::cout << (int)symbol;
	}
	else
	{
		std::cout << -1;
	}*/


	//03

	/*int year;
	std::cin >> year;

	bool isleap = false;

	if (year % 4 == 0)
	{
		isleap = true;
		if (year % 100 == 0)
		{
			isleap = false;

			if (year%400 == 0)
			{
				isleap = true;
			}
		}
	}
	std::cout << (isleap ? "leap year" : "not a leap year");*/

	//04

	/*char s;
	std::cin >> s;

	if (s >= 65 && s <= 90)
	{
		std::cout << char(s+32)<< std::endl;
		if (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U' || s == 'Y')
		{
			std::cout << "vowel";
		}
		else
		{
			std::cout << "not a vowel";
		}
	}
	else if (s >= 97 && s <= 122)
	{
		std::cout << char(s-32) << std::endl;
		if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y')
		{
			std::cout << "vowel";
		}
		else
		{
			std::cout << "not a vowel";
		}
	}
	else
	{
		std::cout << "Invalid character";
	}*/

	//05

	/*int a, b, c;
	std::cin >> a >> b >> c;

	if (a > b)
	{
		if (c>a)
		{
			std::cout << b << a << c;
		}
		else if(c>b)
		{
			std::cout << b << c << a;
		}
		else
		{
			std::cout << c << b << a;
		}
	}
	else
	{
		if (c > b)
		{
			std::cout << a << b << c;
		}
		else if (c > a)
		{
			std::cout << a << c << b;
		}
		else
		{
			std::cout << c << a << b;
		}
	}*/

	//06

	/*int n;
	std::cin >> n;

	if (n == 0)
	{
		std::cout << 0 << std::endl << "Even";

	}
	else if (n % 2 == 0)
	{
		std::cout << "Even";
	}
	else
	{
		std::cout << "Odd";
	}*/

	//07

	/*int a, b, c;
	std::cin >> a >> b >> c;

	if (a > b)
	{
		if (c > a)
		{
			std::cout << c*100 + a*10 + b;
		}
		else if (c > b)
		{
			std::cout << a*100 + c*10 + b;
		}
		else
		{
			std::cout << a*100 + b*10 + c;
		}
	}
	else
	{
		if (c > b)
		{
			std::cout << c*100 + b*10 + a;
		}
		else if (c > a)
		{
			std::cout << b*100 + c*10 + a;
		}
		else
		{
			std::cout << b*100 + a*10 + c;
		}
	}*/


	//08

	/*double r, a, b;
	std::cin >> r >> a >> b;

	r *= r;

	double distanceFromPointToCenter = (a * a) + (b * b);

	if (r == distanceFromPointToCenter)
	{
		std::cout << "On the circle";
	}
	else if (r >= distanceFromPointToCenter)
	{
		std::cout << "In the circle";
	}
	else if (r <= distanceFromPointToCenter)
	{
		std::cout << "Out of the circle";
	}*/

	//09

	//int day, month, year;
	//std::cin >> day >> month >> year;

	//bool isMonthValid = month >= 1 && month <= 12;

	//bool isDayValid = false;

	//bool isLeap = false;

	//if (year % 4 == 0)
	//{
	//	isLeap = true;
	//	if (year % 100 == 0)
	//	{
	//		isLeap = false;

	//		if (year % 400 == 0)
	//		{
	//			isLeap = true;
	//		}
	//	}
	//}

	////valid month and day
	////1-31 2-28 3-31 4-30 5-31 6-30 7-31 8-31 9-30 10-31 11-30 12-31

	//int largestValidDayForThisMonth = 0;

	//if (isMonthValid)
	//{
	//	switch (month)
	//	{
	//	case 1:
	//	case 3:
	//	case 5:
	//	case 7:
	//	case 8:
	//	case 10:
	//	case 12:
	//		largestValidDayForThisMonth = 31;
	//		break;
	//	case 4:
	//	case 6:
	//	case 9:
	//	case 11:
	//		largestValidDayForThisMonth = 30;
	//		break;
	//	case 2:
	//		largestValidDayForThisMonth = (isLeap ? 29 : 28);
	//		break;
	//	default:
	//		break;
	//	}
	//}

	//if (day >= 1 && day <= largestValidDayForThisMonth)
	//{
	//	isDayValid = true;
	//}

	//std::cout << (isDayValid && isMonthValid);

	//10

	/*double a;
	char symbol;
	double b;

	std::cin >> a >> symbol >> b;

	double result = 0;

	if (symbol == '+')
	{
		result = a + b;
	}
	else if (symbol == '-')
	{
		result = a - b;
	}
	else if (symbol == '*')
	{
		result = a * b;
	}
	else if (symbol == '/')
	{
		if (b != 0)
		{
			result = a / b;
		}
		else
		{
			std::cout << "cannot devide by zero";
		}
	}

	std::cout << result;*/

	//11

	/*int n;
	std::cin >> n;

	int firstNum = ((n / 1000) * 10) + (n % 10);

	int secondNum = ((n / 100) % 10) * 10 + ((n / 10) % 10);

	if (firstNum == secondNum)
	{
		std::cout << firstNum << '=' << secondNum;
	}
	else if (firstNum > secondNum)
	{
		std::cout << firstNum << '>' << secondNum;
	}
	else
	{
		std::cout << firstNum << '<' << secondNum;
	}*/

	//12

	/*int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	bool isSecondValid = ((b >= a && b >= c) || (b <= a && b <= c));
	bool isThirdValid = ((c >= b && c >= d) || (c <= b && c <= d));
	bool isFourthValid = ((d >= c && d >= e) || (d <= c && d <= e));

	std::cout << (isSecondValid && isThirdValid && isFourthValid ? "yes" : "no");*/

}

#include <iostream>

int main()
{
	//01

	/*int dayAsANum;
	std::cin >> dayAsANum;

	switch (dayAsANum)
	{
	case 1: std::cout << "Monday"; break;
	case 2: std::cout << "Tuesday"; break;
	case 3: std::cout << "Wednesday"; break;
	case 4: std::cout << "Thursday"; break;
	case 5: std::cout << "Friday"; break;
	case 6: std::cout << "Saturday"; break;
	case 7: std::cout << "Sunday"; break;
	default:
		std::cout << "Invalid day!";
		break;
	}*/

	//02

	/*int num;
	std::cin >> num;

	if (num < 100)
	{
		std::cout << "Less than 100";
	}
	else if (num > 200)
	{
		std::cout << "Greater than 200";
	}
	else
	{
		std::cout << "Between 100 and 200";
	}*/

	//03

	/*double speed;
	std::cin >> speed;

	const double minDiff= 0.0001;

	if (speed - 10 <= minDiff)
	{
		std::cout << "slow";
	}
	else if (speed - 50 <= minDiff)
	{
		std::cout << "average";
	}
	else if (speed - 150 <= minDiff)
	{
		std::cout << "fast";
	}
	else if (speed - 1000 <= minDiff)
	{
		std::cout << "ultra fast";
	}
	else
	{
		std::cout << "extremely fast";
	}*/

	//04

	/*char typeOfFigure;
	std::cin >> typeOfFigure;
	double area = 0;

	if (typeOfFigure == 's')
	{
		double side;
		std::cin >> side;
		area = side * side;
	}
	else if (typeOfFigure == 'r')
	{
		double width;
		std::cin >> width;
		double length;
		std::cin >> length;

		area = width * length;
	}
	else if (typeOfFigure == 'c')
	{
		double radius;
		std::cin >> radius;

		area = 3.14 * radius * radius;
	}
	else if (typeOfFigure == 't')
	{
		double side;
		std::cin >> side;
		double height;
		std::cin >> height;

		area = side * height / 2;
	}

	std::cout << area;*/

	//05

	/*int hours;
	std::cin >> hours;

	int minutes;
	std::cin >> minutes;

	minutes += 15;

	if (minutes >=60)
	{
		hours++;
		if (hours>=24)
		{
			hours = 0;
		}
		minutes -= 60;
	}

	std::cout << (hours>=0 && hours <=9 ?"0":"") << hours << ":" << (minutes >= 0 && minutes <= 9 ? "0" : "") << minutes;*/

	//06

	/*int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	bool isSecondValid = ((b >= a && b >= c) || (b <= a && b <= c));
	bool isThirdValid = ((c >= b && c >= d) || (c <= b && c <= d));
	bool isFourthValid = ((d >= c && d >= e) || (d <= c && d <= e));

	std::cout << (isSecondValid && isThirdValid && isFourthValid ? "yes" : "no");*/

	//07

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
}


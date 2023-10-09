#include <iostream>

using namespace std;

int main()
{

	//01

		//cout << ((false || ((true && true) || false)) && false);

	//02
		//int a = 5;
		//int b = 2;

		//double c = a / (b * (15 / 10));
		//// c = 2  

		//double d = a / (b * 1.5);
		//// d = 5/3.0 ? 

		//cout << c << endl;
		//cout << d << endl;

	//03
		//double a = 5.02;
		//double b = 4.99;
		//int c = a + b; // 10.01 to int is 10
		//cout << c;

	//04
		//int a = 10;
		//cout << ((a == 6) && (a / !a));
		//         (false && whatever)


	//problems i wrote

	//01 
		/*int firstNum;
		cin >> firstNum;
		int secondNum;
		cin >> secondNum;

		cout << "The quotient of the division is : " << (firstNum / secondNum) << endl;
		cout << "The remainder of the division is : " << (firstNum % secondNum);*/

		//02
			/*double ratio = 0.393701;

			double sentimeters;
			cin >> sentimeters;

			cout << (sentimeters*ratio);*/
			//1sm = 0.393701 inch

		//03
			/*double length;
			cin >> length;
			double width;
			cin >> width;

			cout << "Perimeter: " << ((2 * length) + (2 * width)) << endl;
			cout << "Area: " << (length * width) << endl;*/

			//04
				/*int seconds;
				cin >> seconds;

				int days = seconds / (60 * 60 * 24);
				seconds -= days * (60 * 60 * 24);

				int hours = seconds / (60 * 60);
				seconds -= hours * (60 * 60);

				int minutes = seconds / 60;
				seconds -= minutes * 60;

				cout << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";*/

				//6 days, 4 hours, 13 minutes and 48 seconds

			//05
	/*double first;
	double second;
	double third;
	double fourth;
	cin >> first >> second >> third >> fourth;

	bool firstCase = (second >= third);
	bool secondCase = (first <= fourth && first >= second);
	bool thirdCase = (third <= fourth && third >= second);
	bool fourthCase = (fourth >= first);

	cout << (firstCase || secondCase || thirdCase || fourthCase);*/

	//06

	/*int a, b, c, d;
	cin >> a >> b >> c >> d;

	int sum = 0;
	sum += a * (a % 2 == 0);
	sum += b * (b % 2 == 0);
	sum += c * (c % 2 == 0);
	sum += d * (d % 2 == 0);

	cout << (sum);*/

	//07

	/*int a, b, c, d;
	cin >> a >> b >> c >> d;

	int firstDiff = (a - b);
	int secondDiff = (b - c);
	int thirdDiff = (c - d);

	cout << ((firstDiff == secondDiff) && (secondDiff == thirdDiff));*/

	//08
	/*int a, b, c, d;
	cin >> a >> b >> c >> d;

	double q = (1.0*a) / b;
	cout << ((q == ((1.0 * b) / c)) && (q == ((1.0 * c) / d)));*/

	//09

	/*double a, b;
	cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << a << endl << b;*/

	//10
	/*double a, b;
	cin >> a >> b;

	cout <<  (a * (a > b)) + (b * (b>=a));*/

	//11

	/*int a;
	cin >> a;

	cout << (a * (a >= 10 && a <= 99)) + (!(a >= 10 && a <= 99) * (a % 10));*/
}
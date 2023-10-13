// FirstPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	//First Exercise

	// 01

	/*int num;
	cin >> num;
	cout << (num%2==0);*/

	// 02

	/*int num;
	cin >> num;
	int invertedAndIncrementedNum = (num % 10) * 100 + (num / 10 % 10) * 10 + (num / 100) + 1;
	cout << invertedAndIncrementedNum;*/

	// 03

	//a, e, o, u, i, y

	/*char letter;
	cin >> letter;
	cout << ((letter == 97) || (letter == 65) || (letter == 69) || (letter == 101) || (letter == 79) || (letter == 111) || (letter == 85) || (letter == 117) || (letter == 89) || (letter == 121));*/

	// 04

	//int grade;
	//cin >> grade;
	//cout << ((grade >= 2) && (grade <= 6));

	// 05

	/*int num;
	cin >> num;
	cout << num / 10;*/

	// 06

	/*int a;
	cin >> a;
	int b;
	cin >> b;

	cout << ((a + b) * (a + b) * (a + b) * (a + b) - (a - b) * (a - b));*/

	// 07

	/*int currency;
	cin >> currency;

	int inHundred = currency / 100;
	currency -= inHundred * 100;

	int inFifty = currency / 50;
	currency -= inFifty * 50;

	int inTwenty = currency / 20;
	currency -= inTwenty * 20;

	int inFive = currency / 5;
	currency -= inFive * 5;

	int inTwo = currency / 2;
	currency -= inTwo * 2;

	int inOne = currency / 1;
	currency -= inOne * 1;

	cout << inHundred<< "x100lv "<< inFifty << "x50lv  "<< inTwenty <<"x20lv  "<< inFive <<"x5lv  "<< inTwo <<"x2lv  "<< inOne <<"x1lv";
	*/

	// 08

	int a;
	cin >> a;
	int b;
	cin >> b;

	cout << ((a+b+abs(a-b))/2); 
}


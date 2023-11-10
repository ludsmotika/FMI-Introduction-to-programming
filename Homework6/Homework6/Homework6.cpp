#include <iostream>

bool isArrayPalindrom(const int arr[], int size, int start, int stop)
{

	for (int i = start; i < stop / 2; i++)
	{
		if (arr[i] != arr[size - i - 1])
		{
			return false;
		}
	}

	return true;
}

void swapValuesForTwoVariables(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}


int least_common_multiple(int num1, int num2)
{
	if (num1 > num2)
	{
		swapValuesForTwoVariables(num1, num2);
	}

	int copyOfNum2 = num2;

	while (true)
	{
		if (num2 % num1 == 0)
		{
			return num2;
		}
		else
		{
			num2 += copyOfNum2;
		}
	}
}


int lowestCommonMultipleForArray(const int arr[], int size)
{
	if (size == 1)
	{
		return arr[0];
	}

	int lowestCommonMultiple = least_common_multiple(arr[0], arr[1]);

	for (int i = 2; i < size; i++)
	{
		lowestCommonMultiple = (least_common_multiple(lowestCommonMultiple, arr[i]));
	}

	return lowestCommonMultiple;
}


int least_common_devisor(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


int lowestCommonDevisorForArray(const int arr[], int size)
{
	if (size == 1)
	{
		return arr[0];
	}

	int lowestCommonMultiple = least_common_devisor(arr[0], arr[1]);

	for (int i = 2; i < size; i++)
	{
		lowestCommonMultiple = (least_common_devisor(lowestCommonMultiple, arr[i]));
	}

	return lowestCommonMultiple;
}

bool isArrayAConcatenationOfTwoPalindromeArrays(const int arr[], int size)
{
	for (int i = 1; i < size - 1; i++)
	{
		if (isArrayPalindrom(arr, i, 0, i) && isArrayPalindrom(arr, size - i, i, size))
		{
			return true;
		}
	}
	return false;
}

int getCountOfInversionsForNumberOfSomeIndex(const int arr[], int size, int index)
{
	int currentNumber = arr[index];

	int countOfInversions = 0;

	for (int i = index + 1; i < size; i++)
	{
		if (currentNumber > arr[i])
		{
			countOfInversions++;
		}
	}

	return countOfInversions;
}

int countOfInversionsInArray(const int arr[], int size)
{
	int totalCountOfInversions = 0;

	for (int i = 0; i < size - 1; i++)
	{
		totalCountOfInversions += getCountOfInversionsForNumberOfSomeIndex(arr, size, i);
	}

	return totalCountOfInversions;
}

int getSmallestMissingNumber(const int arr[], int size)
{
	int start = 0;
	int stop = size - 1;

	int mid = (start + stop) / 2;

	while (true)
	{
		if (arr[mid] - arr[start] < ((stop- start)/2) + 2)
		{
			stop = mid;
		}
		else if (arr[mid] - arr[start] < stop - start)
		{
			start = mid;
		}

		if (start == stop)
		{
			break;
		}

		mid = start / 2 + stop / 2;
	}

	return arr[start] + 1;
}

int main()
{
	constexpr int maxSize = 1000;
	int arr[maxSize];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}


	std::cout << getSmallestMissingNumber(arr, size);
}

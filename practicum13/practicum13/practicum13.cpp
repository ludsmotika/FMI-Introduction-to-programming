#include <iostream>

int binarySearch(const int arr[], int len, int el)
{
	int left = 0;
	int right = len - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		//left + right) / 2;
		if (el > arr[mid])
			left = mid + 1;
		else if (el < arr[mid])
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}

int binarySearchForRows(const int arr[], int len, int el)
{
	int left = 0;
	int right = len - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (el > arr[mid])
			left = mid + 1;
		else if (el < arr[mid])
			right = mid - 1;
		else
			return mid;

	}
	return -1;
}

void getIndexesOfElement(int** mtx, int rowsCount, int colsCount, int numToSearchFor, int& x, int& y)
{
	int* arr = new int[rowsCount];

	for (size_t i = 0; i < rowsCount; i++)
	{
		arr[0] = i + 1;
	}


	int left = 0;
	int right = rowsCount - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int result = binarySearch(mtx[mid], 3, numToSearchFor);

		if (result == -1 && numToSearchFor > mtx[mid][0])
		{
			left = mid + 1;
		}
		else if (result == -1 && numToSearchFor < mtx[mid][0])
		{
			right = mid - 1;
		}
		else
		{
			x = mid;
			y = result;
			break;
		}

	}

}

int positionToInsert(int* arr, int size, int elementToInsert)
{
	if (elementToInsert < arr[0])
	{
		return 0;
	}

	if (elementToInsert > arr[size - 1])
	{
		return size;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > elementToInsert)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	//01 demo
	/*unsigned size = 5;
	int** matrix = new int* [size];
	matrix[0] = new int[5] {1, 2, 3, 4, 5};
	matrix[1] = new int[5] {6, 7, 8, 9, 10};
	matrix[2] = new int[5] {11, 12, 13, 14, 15};
	matrix[3] = new int[5] {16, 17, 18, 19, 20};
	matrix[4] = new int[5] {21, 22, 23, 24, 25};

	int x = 0;
	int y = 0;

	getIndexesOfElement(matrix, 5, 5, 17, x, y);

	std::cout << x << " ";
	std::cout << y;*/


	//02 demo

	//int arr[] = { 1,3,7,13,20 };
	//std::cout<<positionToInsert(arr,5,4);

	//03 demo


}

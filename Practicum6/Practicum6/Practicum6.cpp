#include <iostream>


int getTheClosestToAverage(const int arr[], int size, double average)
{
	int closest = 0;
	int closestDifference = abs(arr[0] - average);

	for (int i = 0; i < size; i++)
	{
		if (abs(arr[i] - average) <= closestDifference)
		{
			closest = arr[i];
			closestDifference = abs(arr[i] - average);
		}
	}

	return closest;

}


double returnTheAverage(const int arr[], int size)
{
	double average = 0;

	for (int i = 0; i < size; i++)
	{
		average += arr[i];
	}

	average /= size;

	return average;
}

bool isArraySorted(const int arr[], int size)
{
	bool isAscending = false;

	if (size == 1)
	{
		return true;
	}

	if (arr[0] > arr[1])
	{
		isAscending = false;
	}
	else
	{
		isAscending = true;
	}

	for (int i = 1; i < size; i++)
	{
		if (!((arr[i] > arr[i - 1] && isAscending == true) || (arr[i] < arr[i - 1] && isAscending == false)))
		{
			return false;
		}
	}

	return true;
}

void swapTheFirstNElements(int arr[], int size, int howManyToSwap)
{

	for (int i = 0; i < howManyToSwap / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[howManyToSwap - i - 1];
		arr[howManyToSwap - i - 1] = temp;
	}
}

void printArray(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int getTheBiggestRepeatingNumberInARow(const int arr[], int size)
{

	int globalLongest = 0;

	int currentLongest = 1;

	for (int i = 1; i < size; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			currentLongest++;
		}
		else
		{
			if (currentLongest > globalLongest)
			{
				globalLongest = currentLongest;
			}
			currentLongest = 1;
		}
	}

	return globalLongest;
}

void fillDifferencesArrayBetweenElements(const int arr[], int size, int differencesArray[])
{
	for (int i = 0; i < size - 1; i++)
	{
		differencesArray[i] = abs(arr[i + 1] - arr[i]);
	}
}

bool isSubarrayFromN(const int arr[], int size, const int subarr[], int size2, int startingIndex)
{
	for (int i = startingIndex; i < size2 + startingIndex; i++)
	{
		if (subarr[i - startingIndex] != arr[i])
		{
			return false;
		}
	}

	return true;
}

bool isArraySubarray(const int arr[], int size, const int subarr[], int size2)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == subarr[0])
		{
			if (isSubarrayFromN(arr, size, subarr, size2, i))
			{
				return true;
			}
		}
	}

	return false;
}

void shiftArray(int arr[], int size, int startingIndex)
{
	for (int i = startingIndex; i <= size - startingIndex; i++)
	{
		arr[i] = arr[i + 1];
	}
}

void filterArrayToBeOnlyWithPossitive(int arr[], int& size)
{

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			shiftArray(arr, size, i);
			i--;
			size--;
		}
	}
}

int FindOccurencesInArray(const int arr[], int size, int numberToSearchFor) 
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i]==numberToSearchFor)
		{
			count++;
		}
	}

	return count;
}

bool isOneArrayPermutationOfOther(const int arr[], int size,const int arr2[], int size2)
{
	for (int i = 0; i <= 9; i++)
	{
		int occurencesInFirstArr = FindOccurencesInArray(arr, size, i);
		int occurencesInSecondArr = FindOccurencesInArray(arr2, size2, i);
		if (occurencesInFirstArr != occurencesInSecondArr)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	//01 demo
	/*constexpr int maxSize = 1000;
	int arr[maxSize];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}


 double average = returnTheAverage(arr, size);


 std::cout << average << std::endl;
 std::cout << getTheClosestToAverage(arr, size, average);*/


 //02 demo

	/*constexpr int maxSize = 1000;
	int arr[maxSize];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}


	std::cout << isArraySorted(arr, size);*/


	//03 demo 

	/*constexpr int maxSize = 1000;
	int arr[maxSize];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int howManyToSwap;
	std::cin >> howManyToSwap;

	swapTheFirstNElements(arr, size, howManyToSwap);

	printArray(arr, size);*/

	//04 demo

	/*constexpr int maxSize = 1000;
	int arr[maxSize];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}


   std::cout << getTheBiggestRepeatingNumberInARow(arr, size);*/


   //05 demo 

   /*constexpr int maxSize = 1000;
   int arr[maxSize];

   int size;
   std::cin >> size;

   for (int i = 0; i < size; i++)
   {
	   std::cin >> arr[i];
   }

   int differencesArray[maxSize - 1];

   fillDifferencesArrayBetweenElements(arr, size, differencesArray);
   printArray(differencesArray, size -1 );*/


   //06 demo 

   /*constexpr int maxSize = 1000;
   int arr[maxSize];

   int size;
   std::cin >> size;

   for (int i = 0; i < size; i++)
   {
	   std::cin >> arr[i];
   }

   int arr2[maxSize];

   int size2;
   std::cin >> size2;

   for (int i = 0; i < size2; i++)
   {
	   std::cin >> arr2[i];
   }

   std::cout << isArraySubarray(arr, size, arr2 , size2);*/


   //07 demo

	/*constexpr int maxSize = 1000;
	int arr[maxSize];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	filterArrayToBeOnlyWithPossitive(arr, size);

	printArray(arr, size);*/

	//08 demo

	/*constexpr int maxSize = 1000;
	int arr[maxSize];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int arr2[maxSize];

	int size2;
	std::cin >> size2;

	for (int i = 0; i < size2; i++)
	{
		std::cin >> arr2[i];
	}

	std::cout << isOneArrayPermutationOfOther(arr, size, arr2, size2);*/
}
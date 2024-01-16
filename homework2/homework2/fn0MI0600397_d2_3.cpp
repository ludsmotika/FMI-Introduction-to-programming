/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author <Daniel Stefanov>
* @idnumber <0MI0600397>
* @task <3>
*
*/

#include <iostream>

//char* countingSortString(const char* text, int size)
//{
//	if (!text)
//	{
//		return nullptr;
//	}
//
//	char* answer = new char[size+1];
//	answer[size] = '\0';
//	int arr[255] = { 0 };
//
//	for (size_t i = 0; i < size; i++)
//	{
//		arr[text[i] + 128]++;
//	}
//
//
//	for (size_t i = 0; i < 256; i++)
//	{
//		while (arr[i] > 0)
//		{
//			*answer = i - 128;
//			arr[i]--;
//			answer++;
//		}
//	}
//
//	answer -= size;
//
//	return answer;
//}

char* countingSort(const char* text, int size)
{
	if (!text)
		return nullptr;

	const int charRange = 256;
	int count[charRange] = { 0 };

	for (int i = 0; i < size; ++i) {
		++count[text[i]];
	}

	for (int i = 1; i < charRange; ++i) {
		count[i] += count[i - 1];
	}

	char* answer = new char[size];
	answer[size] = '\0';

	for (int i = size - 1; i >= 0; --i) {
		answer[--count[text[i]]] = text[i];
	}

	return answer;
}

int mstrlen(const char* ptr)
{
	if (!ptr)
	{
		return 0;
	}

	int count = 0;
	while (*ptr)
	{
		count++;
		ptr++;
	}

	return count;
}


void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

int indexOfFirstSymbolToSwap(const char* str, int size)
{
	if (!str)
	{
		return -1;
	}

	for (int i = size - 2; i >= 0; i--)
	{
		if (str[i] < str[i + 1])
		{
			return i;
		}
	}

	return -1;
}

int indexOfSecondSymbolToSwap(const char* str, int size, int indexOfFirst)
{
	if (!str)
	{
		return -1;
	}

	for (int i = size - 1; i > indexOfFirst; i--)
	{
		if (str[indexOfFirst] < str[i])
		{
			return i;
		}
	}

	return -1;
}

void reversePartOfString(char* str, int startIndex, int endIndex)
{
	if (!str)
	{
		return;
	}

	int middle = (startIndex + endIndex) / 2;

	for (int i = startIndex;i <= middle;i++)
	{
		int temp = str[i];
		str[i] = str[endIndex - (i - startIndex)];
		str[endIndex - (i - startIndex)] = temp;
	}
}


void getFirstNLexicographicPermutations(const char* str, int n) {

	int textLength = mstrlen(str);

	char* currentLexicographic = countingSort(str, textLength);
	std::cout << currentLexicographic << std::endl;

	for (size_t i = 0; i < n - 1; i++)
	{
		int firstIndex = indexOfFirstSymbolToSwap(currentLexicographic, textLength);

		int secondIndex = indexOfSecondSymbolToSwap(currentLexicographic, textLength, firstIndex);

		if (firstIndex == -1)
		{
			break;
		}

		swap(currentLexicographic[firstIndex], currentLexicographic[secondIndex]);

		reversePartOfString(currentLexicographic, firstIndex + 1, textLength - 1);

		std::cout << currentLexicographic << std::endl;
	}
}

constexpr int MaxLineLength = 100;

//int main() {
//	char text[MaxLineLength];
//	std::cin.getline(text, MaxLineLength, ' ');
//
//	int countOfNext;
//	std::cin >> countOfNext;
//
//	getFirstNLexicographicPermutations(text, countOfNext);
//}
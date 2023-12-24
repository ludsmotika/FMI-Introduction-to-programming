#include <iostream>

void countingSortString(char* text, int size)
{
	if (!text)
	{
		return;
	}

	int arr[255] = { 0 };

	for (size_t i = 0; i < size; i++)
	{
		arr[text[i] + 128]++;
	}

	for (size_t i = 0; i < 256; i++)
	{
		while (arr[i] > 0)
		{
			*text = i - 128;
			arr[i]--;
			text++;
		}
	}

	text -= size;
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


void getFirstNLexicographicPermutations(char* str, int n) {

	int textLength = mstrlen(str);

	countingSortString(str, textLength);
	std::cout << str << std::endl;


	for (size_t i = 0; i < n; i++)
	{
		int firstIndex = indexOfFirstSymbolToSwap(str, textLength);

		int secondIndex = indexOfSecondSymbolToSwap(str, textLength, firstIndex);

		swap(str[firstIndex], str[secondIndex]);

		reversePartOfString(str, firstIndex + 1, textLength - 1);

		std::cout << str << std::endl;
	}
}

//int main() {
//	char arr[] = "bbaaacqrzzzzzzzzzzzzz";
//
//	getFirstNLexicographicPermutations(arr, 400);
//}

//#include <iostream>
//
//// Function to swap characters at positions i and j in a string
//void swap(char& a, char& b) {
//	char temp = a;
//	a = b;
//	b = temp;
//}
//
//// Function to generate lexicographically smallest strings
//void generateLexicographicStrings(char* input, int length, int N, int& count) {
//	if (count >= N) {
//		return;
//	}
//
//	// Print the current string
//	std::cout << input << std::endl;
//	count++;
//
//	// Generate the next lexicographically smallest string
//	int i = length - 2;
//	while (i >= 0 && input[i] >= input[i + 1]) {
//		i--;
//	}
//
//	if (i < 0) {
//		return; // All strings generated
//	}
//
//	int j = length - 1;
//	while (input[j] <= input[i]) {
//		j--;
//	}
//
//	// Swap characters at positions i and j
//	swap(input[i], input[j]);
//
//	// Reverse the substring after i
//	int left = i + 1;
//	int right = length - 1;
//	while (left < right) {
//		swap(input[left], input[right]);
//		left++;
//		right--;
//	}
//
//	// Recursively generate the next string
//	generateLexicographicStrings(input, length, N, count);
//}
//
//int main() {
//	// Read a string and an integer N from the standard input
//	const int MAX_LENGTH = 100;
//	char input[MAX_LENGTH];
//
//	std::cout << "Enter a string: ";
//	std::cin >> input;
//
//	std::cout << "Enter the value of N: ";
//	int N;
//	std::cin >> N;
//
//	int count = 0;
//
//	// Generate and print lexicographically smallest strings
//	std::cout << "Lexicographically smallest strings:" << std::endl;
//	generateLexicographicStrings(input, strlen(input), N, count);
//
//	return 0;
//}
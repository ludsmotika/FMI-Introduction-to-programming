#include <iostream>

constexpr int maxLength = 1000;

int strlen(char* text)
{
	int counter = 0;

	while (*text != '\0')
	{
		counter++;
		text++;
	}

	return counter;
}

//01
void insertElementOnIndex(char* text, char* result, char symbol, int index)
{
	if (!text || !result)
	{
		return;
	}

	int counter = 0;

	while (*text != '\0')
	{
		if (index == counter)
		{
			*result = symbol;
			result++;
		}

		*result = *text;

		counter++;
		text++;
		result++;
	}

	*result = '\0';
}

//02
void createString(const char* source, char* result)
{
	if (!source || !result)
	{
		return;
	}
	int lenghtOfSource = strlen(source);

	while (*source != '\0')
	{
		char currentSymbol = *source++;
		int index = *source - '0';

		result[index] = currentSymbol;
	}


	result += (lenghtOfSource / 2);
	*result = '\0';
}

//03

void fillCountOfOccurrences(char* sourceptr, int* arr,int isEqualTo)
{
	int counter = 0;
	while (*sourceptr != '\0')
	{
		if ((*sourceptr) - '0' == isEqualTo)
		{
			arr[isEqualTo]++;
		}

		counter++;
		sourceptr++;
	}

	sourceptr -= counter;
}

void createStringFromStringOfNumbers(char* sourceptr, char* result)
{

	if (!sourceptr)
	{
		return;
	}

	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };

	for (size_t i = 0; i <= 9; i++)
	{
		fillCountOfOccurrences(sourceptr, arr, i);
	}

	for (size_t i = 0; i < 9; i++)
	{
		if (arr[i] != 0)
		{
			*result = arr[i] + '0';
			result++;
			*result = 'x';
			result++;
			*result = i + '0';
			result++;
			*result = ',';
			result++;

		}
	}

	*(--result) = '\0';
}

//04

void shiftAllToTheLeft(char* source)
{
	if(!source)
	{
		return;
	}

	while (source != "\0")
	{
		source++;
		char current = *source;
		source--;
		*source = current;
		source++;
	}
}

void removeSymbolFromIndex(char* source, char symbolToRemove) 
{
	if (!source) 
	{
		return;
	}

	while (*source!='\0')
	{
		if (*source==symbolToRemove) 
		{
			shiftAllToTheLeft(source);
			source--;
		}

		source++;
	}

}

int main()
{
	char text[maxLength] = "Hello, my friend!";
	char* textptr = text;
	//char result[maxLength];
	//char* resultptr = result;

	removeSymbolFromIndex(textptr, 'e');

	std::cout << text;
}
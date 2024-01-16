/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author <Daniel Stefanov>
* @idnumber <0MI0600397>
* @task <1>
*
*/


#include <iostream>

int mystrlen(const char* ptr)
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

char encodeSymbol(char& symbol, bool isFirstPart)
{
	char result = 0;

	for (size_t i = 0; i < 4; i++)
	{
		if (symbol & 1)
		{
			result |= 1;
			result <<= 1;
			if (i != 3)
			{
				result <<= 1;
			}
		}
		else
		{
			result <<= 1;
			result |= 1;
			if (i != 3)
			{
				result <<= 1;
			}
		}

		symbol >>= 1;
	}

	return result;
}

char reverseBitsForChar(char symbol)
{
	char result = 0;

	for (size_t i = 0; i < 8; i++)
	{
		if (symbol & 1)
		{
			result |= 1;
		}

		if (i == 7)
		{
			continue;
		}

		result <<= 1;
		symbol >>= 1;
	}

	return result;
}

char* encodeText(const char* ptr)
{
	if (!ptr)
	{
		return nullptr;
	}

	int stringLen = mystrlen(ptr);

	if (stringLen > 64)
	{
		return nullptr;
	}

	char* result = new char[(stringLen * 2) + 1];
	result[stringLen * 2] = '\0';
	int resultIndex = 0;

	for (size_t i = 0; i < stringLen; i++)
	{
		char currentSymbol = ptr[i];

		currentSymbol = reverseBitsForChar(currentSymbol);

		char firstPartOfEncodedSymbol = encodeSymbol(currentSymbol, 1);
		char secondPartOfEncodedSymbol = encodeSymbol(currentSymbol, 0);

		result[resultIndex] = firstPartOfEncodedSymbol;
		result[resultIndex + 1] = secondPartOfEncodedSymbol;

		resultIndex += 2;
	}

	return result;
}

constexpr int MaxLineLength = 64;

//int main()
//{
//	char text[MaxLineLength];
//	std::cin.getline(text,MaxLineLength);
//
//	char* result = encodeText(text);
//
//	std::cout << result;
//
//	delete[] result;
//}
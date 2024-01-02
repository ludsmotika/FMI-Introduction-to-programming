#include <iostream>

bool isLetter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isNumber(char ch)
{
	return (ch >= '0' && ch <= '9');
}

bool checkIfTheCurrentSymbolIsValid(char patternSymbol, char textSymbol)
{
	bool isValid = true;

	if (patternSymbol == '@' && !isLetter(textSymbol))
	{
		isValid = false;
	}
	else if (patternSymbol == '%' && !isNumber(textSymbol))
	{
		isValid = false;
	}

	if (patternSymbol != '*' && patternSymbol != '%' && patternSymbol != '@' && patternSymbol != textSymbol)
	{
		isValid = false;
	}

	return isValid;
}


int prefixesCount(const char* text, const char* pattern, bool isNested)
{
	if (!text || !pattern)
	{
		return 0;
	}

	if (*text == '\0')
	{
		return 0;
	}

	int count = 0;

	while (*text && *pattern)
	{
		bool isCurrentSymbolValid = checkIfTheCurrentSymbolIsValid(*pattern, *text);

		if (!isCurrentSymbolValid)
		{
			break;
		}

		if (*pattern == '%')
		{
			if (isNested)
			{
				count += prefixesCount(text + 1, pattern + 1, false);
			}
			else
			{
				count += prefixesCount(text + 1, pattern, true);
			}
		}

		text++;
		pattern++;
	}


	if (!(*pattern) && count == 0)
	{
		count++;
	}

	return count;
}

int countOfMatchesOfPattern(const char* ptr, const char* pattern)
{
	if (!ptr || !pattern)
	{
		return 0;
	}

	int count = 0;

	while (*ptr)
	{
		int current = prefixesCount(ptr, pattern, false);

		/*std::cout << ptr << std::endl;
		std::cout << pattern << std::endl;

		std::cout << current << std::endl;*/

		count += current;
		ptr++;
	}

	return count;
}

int main()
{
	char arr[] = "12345";

	//char arr[] = "123";
	char* text = arr;

	char patternText[] = "%%";
	//char patternText[] = "%%";

	//valid are: 1234 2345 3456 4567 123 234 345 456 567 12 23 34 45 56 67

	char* pattern = patternText;

	int result = countOfMatchesOfPattern(text, pattern);

	std::cout << result;
}
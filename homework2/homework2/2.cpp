#include <iostream>

bool isLetter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isNumber(char ch)
{
	return (ch >= '0' && ch <= '9');
}

void checkTheCurrentSymbol(char patternSymbol, char textSymbol, bool& wasPreviousSymbolPercent, bool& isPrefix)
{
	if (patternSymbol == '@')
	{
		if (!isLetter(textSymbol))
		{
			isPrefix = false;
		}
	}
	else if (patternSymbol == '%')
	{
		wasPreviousSymbolPercent = true;
		if (!isNumber(textSymbol))
		{
			isPrefix = false;
		}
	}
	else if (patternSymbol != '*' && (textSymbol != patternSymbol))
	{
		isPrefix = false;
	}

}


bool isPatternPrefix(const char* text, const char* pattern)
{
	if (!text || !pattern)
	{
		return false;
	}

	bool isPrefix = true;
	bool wasPreviousSymbolPercent = false;

	while (*text && *pattern)
	{
		char currentPatternSymbol = *pattern;
		char currentTextSymbol = *text;

		checkTheCurrentSymbol(currentPatternSymbol, currentTextSymbol, wasPreviousSymbolPercent, isPrefix);

		if (!isPrefix && wasPreviousSymbolPercent && isNumber(currentTextSymbol))
		{
			isPrefix = true;
			pattern--;
		}
		
		if (currentPatternSymbol != '%')
		{
			wasPreviousSymbolPercent = false;
		}

		if (!isPrefix)
		{
			break;
		}

		text++;
		pattern++;
	}

	//if there are symbols still left in the pattern but not in the text
	if ((*pattern) && !(*text))
	{
		return false;
	}

	return isPrefix;
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
		if (isPatternPrefix(ptr, pattern))
		{
			count++;
		}

		ptr++;
	}

	return count;
}

//int main()
//{
//	char arr[] = "te3t zdrte44q     t£3A     te44t  t33t";
//	char* text = arr;
//
//	char patternText[] = "t*%@";
//	char* pattern = patternText;
//
//	int result = countOfMatchesOfPattern(text, pattern);
//
//	std::cout << result;
//}
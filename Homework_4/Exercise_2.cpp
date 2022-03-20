#include <iostream>

bool isPrefix(const char* text, const char* pattern)
{
	if (*pattern == '\0')
		return true;
	return *text == *pattern && isPrefix(text + 1, pattern + 1);
}

char* getSubstring(char* text, unsigned startIndex)
{
	unsigned textLength = strlen(text);
	char* temp = new char[textLength];
	for (unsigned i = startIndex; text[i] != '\0'; i++)
	{
		temp[i - startIndex] = text[i];
	}
	temp[textLength - startIndex] = '\0';
	return temp;
}

int replace(char* text, const char* const str1, const char* const str2)
{
	unsigned changesCounter = 0;
	unsigned i = 0;
	for (i = 0; text[i] != '\0'; i++)
	{
		if (isPrefix(text + i, str1))
		{
			changesCounter++;
			unsigned str2Length = strlen(str2);
			char* substring = getSubstring(text, i + strlen(str1));
			for (unsigned j = i; j < i + str2Length; j++)
			{
				text[j] = str2[j - i];
			}
			unsigned k = i + str2Length;
			unsigned substringIndex = 0;
			for (; substring[substringIndex] != '\0'; k++)
			{
				text[k] = substring[substringIndex++];
			}
			text[k] = '\0';
			delete[] substring;
		}
	}
	return changesCounter;
}

int main()
{
	const unsigned BufferSize = 100;
	char text[BufferSize];
	std::cin.getline(text, BufferSize);
	char str1[BufferSize];
	std::cin.getline(str1, BufferSize);
	char str2[BufferSize];
	std::cin.getline(str2, BufferSize);
	std::cout << replace(text, str1, str2) << std::endl;
	std::cout << text;
}

#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

bool isAlpha(char element)
{
	return element >= 97 && element <= 122;
}

char toUpper(char element)
{
	char newElement = element - 32;
	return newElement;
}

char** letterCasePermutation(unsigned lettersCount, char* input)
{
	unsigned max = 1 << lettersCount;
	char** result = new char* [100];
	for (unsigned row = 0; row < max; row++)
	{
		char* combination = new char[100];
		strcpy(combination, input);
		for (unsigned j = 0; j < lettersCount; j++)
		{
			if (((row >> (lettersCount-1-j)) & 1) == 1)
			{
				combination[j] = toUpper(input[j]);
			}
		}
		result[row] = combination;
	}
	return result;
}

char* getLetters(char* str)
{
	unsigned counter1 = 0;
	unsigned counter2 = 0;

	char* letter = new char[100];
	while (str[counter1] != '\0')
	{
		if (isAlpha(str[counter1]))
		{
			letter[counter2++] = str[counter1];
		}
		counter1++;
	}
	letter[counter2] = '\0';
	return letter;
}

unsigned* getLettersIndex(char* str, char* letters)
{
	unsigned* indexPosition = new unsigned[strlen(letters)];
	unsigned counter = 0;
	for (unsigned index = 0; str[index]!='\0'; index++)
	{
		if (isAlpha(str[index]))
		{
			indexPosition[counter++] = index;
		}
	}
	return indexPosition;
}

void printPermutations(char* str, const unsigned size)
{
	char* letters = getLetters(str);
	unsigned lettersCount = strlen(letters);
	unsigned lettersCountSquared = 1 << lettersCount;
	char** result = letterCasePermutation(strlen(letters), letters);
	unsigned* indexPosition = getLettersIndex(str, letters);
	for (unsigned row = 0; row < lettersCountSquared; row++)
	{
		for (unsigned column = 0; column < lettersCount; column++)
		{
			str[indexPosition[column]] = result[row][column];
		}
		std::cout << str << " ";
	}
	delete[] indexPosition;
	delete[] letters;

	for (unsigned row = 0; row < lettersCountSquared; row++)
	{
		delete[] result[row];
	}
	delete[] result;
}

int main()
{
	const unsigned SIZE = 100;
	char str[SIZE];
	std::cin >> str;

	printPermutations(str, SIZE);
}

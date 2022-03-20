#include <iostream>

using namespace std;

const unsigned maxWordLength = 20;

unsigned maxValue(int val1, int val2)
{
	return (val1 > val2) ? val1 : val2;
}

unsigned letterDiff(const char biggerWord[maxWordLength], const char smallerWord[maxWordLength], unsigned maxLength)
{
	unsigned missMatched = 0;
	for (unsigned i = 0; i < maxLength; i++)
	{
		if (biggerWord[i] != smallerWord[i - missMatched])
		{
			missMatched++;
		}
	}
	return missMatched;
}

unsigned letterDiffZero(const char biggerWord[maxWordLength], const char smallerWord[maxWordLength], unsigned maxLength)
{
	unsigned missMatched = 0;
	for (unsigned i = 0; i < maxLength; i++)
	{
		if (biggerWord[i] != smallerWord[i])
		{
			missMatched++;
		}
	}
	return missMatched;
}

unsigned getLength(const char* arr)
{
	unsigned length = 0;
	while (arr[length] != '\0')
	{
		length++;
	}
	return length;
}

bool isCorrect(const char sequence[][maxWordLength], int sequenceSize)
{
	for (unsigned i = 0; i < sequenceSize - 1; i++)
	{
		unsigned currentWordLength = getLength(sequence[i]);
		unsigned nextWordLength = getLength(sequence[i + 1]);
		int lengthDiff = currentWordLength - nextWordLength;
		unsigned maxLength = maxValue(currentWordLength, nextWordLength);
		unsigned missMatchedLetter;
		if (lengthDiff > 1 || lengthDiff < -1)
		{
			return false;
		}
		else if (lengthDiff == 1)
		{
			missMatchedLetter = letterDiff(sequence[i], sequence[i + 1], maxLength);
		}
		else if (lengthDiff == -1)
		{
			missMatchedLetter = letterDiff(sequence[i + 1], sequence[i], maxLength);
		}
		else
		{
			missMatchedLetter = letterDiffZero(sequence[i + 1], sequence[i], maxLength);
		}

		if (missMatchedLetter != 1)
		{
			return false;
		}
	}
	return true;
}

void fillSequence(char sequence[][maxWordLength], int sequenceSize)
{
	for (int i = 0; i < sequenceSize; i++)
	{
		cin >> sequence[i];
	}
}

int main()
{
	const unsigned minWordsCount = 2;
	const unsigned maxWordsCount = 50;
	unsigned N;
	cin >> N;

	if (!(N >= minWordsCount && N <= maxWordsCount))
	{
		cout << "-1";
		return 0;
	}

	char sequence[maxWordsCount][maxWordLength];

	fillSequence(sequence, N);
	cout << boolalpha << isCorrect(sequence, N);
}

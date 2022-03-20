//Task1
int getLength(long num)
{
	int counter = 0;
	while (num != 0)
	{
		counter++;
		num /= 10;
	}
	return counter;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int* convertNum(long num, int k, int m)
{
	int numLength = getLength(num);
	int* array = new int[numLength];
	for (int i = numLength - 1; i >= 0; i--)
	{
		int currentDigit = num % 10;
		array[i] = currentDigit;
		num /= 10;
	}
	swap(array[k - 1], array[m - 1]);
	return array;
}


//Task2
int getAvg(int* arr, int M)
{
	int sum = 0;
	for (unsigned i = 0; i < M; i++)
	{
		sum += arr[i];
	}
	return (sum / M);
}

int** splitArr(int* arr, int M)
{
	const int cols = 2;
	const int numberIndex = 0;
	const int avgIndex = 1;
	int** result = new int* [M];
	int avg = getAvg(arr, M);
	for (unsigned i = 0; i < M; i++)
	{
		result[i] = new int[cols];
		result[i][numberIndex] = arr[i];
		result[i][avgIndex] = avg;
	}
	return result;
}


//Task 3
bool isLower(char element)
{
	return 'a' <= element && element <= 'z';
}

int getSmallLetterCount(char* str, int startIndex, int size)
{
	int smallLetters = 0;
	int border = startIndex + size;
	for (unsigned i = startIndex; i < border; i++)
	{
		if (isLower(str[i]))
			smallLetters++;
	}
	return smallLetters;
}

bool checkBorder(char element)
{
	return element != ' ' && element != '\t' && element != '\0';
}

int maxWord(char* str)
{
	int maxCounter = 0;
	int startIndex = 0;
	int maxStartindex = 0;
	for (unsigned i = 0; str[i] != '\0'; i++)
	{
		int counter = 0;
		if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t')
		{
			startIndex = i;
			for (; checkBorder(str[i]); i++)
			{
				counter++;
			}

			if (counter > maxCounter)
			{
				maxCounter = counter;
				maxStartindex = startIndex;
			}
		}
	}
	int smallLettersCount = getSmallLetterCount(str, maxStartindex, maxCounter);
	int result = maxCounter * smallLettersCount;
	return result;
}

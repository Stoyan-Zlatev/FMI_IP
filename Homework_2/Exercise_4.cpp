#include <iostream>

using namespace std;

int getLength(int number)
{
	int length = 0;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return length;
}

int getLength(int array[])
{
	int length = 0;
	for (int i = 0; i < 20; i++)
	{
		if (array[i] < 0)
		{
			break;
		}
		length++;
	}
	return length;
}

void distinctArray(int* array, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (array[i] == array[j])
			{
				array[j] = -1;
			}
		}
	}
}

int maxValue(int k, int n)
{
	return (k > n) ? k : n;
}

void swapNumbers(int& number1, int& number2)
{
	int temp = number1;
	number1 = number2;
	number2 = temp;
}

int containsDigit(int number, int array[])
{
	for (int i = 0; array[i] >= 0; i++)
	{
		if (number == array[i])
		{
			return i;
		}
	}
	return -1;
}

void fillArray(int* array, int length, int number)
{
	for (int i = length - 1; i >= 0; i--)
	{
		array[i] = number % 10;
		number /= 10;
	}
}

int main()
{
	const int maxNumber = 20;
	int n, k;
	cin >> n;
	cin >> k;

	if (n < 0 || k < 0)
	{
		cout << "-1";
		return 0;
	}

	int tempn = n;
	int tempk = k;
	int input[maxNumber];
	int output[maxNumber];
	int neutralArray[maxNumber];
	int copy[maxNumber];

	int inputLength = getLength(n);
	int outputLength = getLength(k);

	fillArray(input, inputLength, tempn);
	fillArray(output, outputLength, tempk);
	fillArray(copy, outputLength, tempk);

	distinctArray(copy, outputLength);

	int result = 0;
	int counter = 0;
	int addedDigits = 0;
	int existingDigits = 0;

	for (int i = 0; i < 20; i++)
	{
		neutralArray[i] = -1;
	}

	for (int i = 0; i < maxValue(outputLength, inputLength); i++)
	{
		int searchedNumber = output[i];
		int inputIndex = containsDigit(searchedNumber, input);
		if (inputIndex != -1 && inputIndex != i)
		{
			for (int j = 0; j < inputLength; j++)
			{
				if (searchedNumber == input[j])
				{
					existingDigits++;
				}
			}
		}
		if (inputIndex == -1 && searchedNumber != -1 && searchedNumber >= 0)
		{
			addedDigits++;
		}
		else if (inputIndex == i)
		{
			for (int j = 0; j < inputLength; j++)
			{
				if (copy[i] == input[j])
				{
					existingDigits++;
				}
			}
		}
	}

	int nonExistingDigits = inputLength - existingDigits;
	result += nonExistingDigits;
	result += addedDigits;
	for (int i = 0; i < inputLength; i++)
	{
		if (containsDigit(input[i], output) != -1)
		{
			neutralArray[counter++] = input[i];
			if (counter - 1 != containsDigit(neutralArray[counter - 1], input))
			{
				result++;
			}
		}
	}

	for (int i = 0; i < outputLength; i++)
	{
		int neutralIndex = containsDigit(neutralArray[i], output);
		if (neutralIndex != -1 && neutralIndex != i)
		{
			swapNumbers(neutralArray[i], neutralArray[neutralIndex]);
			result++;
		}
	}

	for (int i = 0; i < getLength(neutralArray); i++)
	{
		if (i < containsDigit(neutralArray[i], output))
		{
			result++;
		}
	}

	cout << result;
}

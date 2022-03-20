#include <iostream>

using namespace std;

bool contains(const char* arr, char element)
{
	for (int i = 0; i < arr[i] != '\0'; i++)
	{
		if (element == arr[i])
		{
			return true;
		}
	}
	return false;
}

void emptyString(char* arr)
{
	for (unsigned i = 0; arr[i] != '\0'; i++)
	{
		arr[i] = ' ';
	}
}

unsigned maxDiff(const char* arr)
{
	const unsigned bufferSize = 100;
	char maxArr[bufferSize];
	char currentArr[bufferSize];
	unsigned counter = 0;
	unsigned maxCounter = 0;
	for (unsigned i = 0; i < arr[i] != '\0'; i++)
	{
		if (contains(currentArr, arr[i]))
		{
			if (counter > maxCounter)
			{
				maxCounter = counter;
				currentArr[counter + 1] = '\0';
				emptyString(currentArr);
			}
			counter = 0;
		}
		currentArr[counter++] = arr[i];
	}

	if (counter > maxCounter)
	{
		maxCounter = counter;
	}

	return maxCounter;
}

int main()
{
	const unsigned bufferSize = 100;
	char arr[bufferSize];
	cin >> arr;
	cout << maxDiff(arr);
}

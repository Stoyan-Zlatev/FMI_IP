#include <iostream>

using namespace std;

int longestDist(const int arr[], const int arrSize)
{
	unsigned counter;
	unsigned maxDistance = 0;
	int minIndex = -1;
	for (unsigned i = 0; i < arrSize - 1; i++)
	{
		counter = 0;
		for (unsigned j = i + 1; j < arrSize; j++)
		{
			counter++;
			if (arr[i] == arr[j] && counter > maxDistance)
			{
				maxDistance = counter;
				minIndex = i;
			}
		}
	}
	return minIndex;
}

void fillArray(int* array, int arrSize)
{
	for (unsigned i = 0; i < arrSize; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int arrSize;
	cin >> arrSize;
	const int bufferSize = 100;
	const int minArraySize = 2;
	int arr[bufferSize];

	fillArray(arr, arrSize);

	if (arrSize < minArraySize)
	{
		cout << "-2";
		return 0;
	}

	cout << longestDist(arr, arrSize);
	return main();
}

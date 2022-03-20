#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	int temp = n;

	while (temp != 0)
	{
		temp /= 10;
		count++;
	}

	int newNumber = 0;

	for (int i = 1; i <= count; i++)
	{
		temp = n;
		for (int j = i; j < count; j++)
		{
			temp /= 10;
		}

		int lastDigit = temp % 10;
		if (lastDigit % 2 != 0)
		{
			newNumber *= 10;
			newNumber += lastDigit;
		}
	}

	cout << newNumber;
}

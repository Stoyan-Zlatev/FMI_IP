#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter a number between 1 and 10^9: ";
	cin >> n;
	if (n < 1 || n>1000000000)
	{
		cout << "-1";
		return 0;
	}

	int counter = 0;
	int temp = n;
	while (temp != 0)
	{
		temp /= 10;
		counter++;
	}

	for (int i = 0; i < (counter + 1) / 2; i++)
	{
		temp = n;
		int startIndex = counter - i;
		for (int k = counter; k > startIndex; k--)
		{
			temp /= 10;
		}
		int backDigit = temp % 10;
		for (int j = 1; j < startIndex - i; j++)
		{
			temp /= 10;
		}

		int frontDigit = temp % 10;

		if (backDigit != frontDigit)
		{
			int max = frontDigit > backDigit ? frontDigit : backDigit;
			cout << max;
			if (i != (counter + 1) / 2)
			{
				cout << " ";
			}
		}
	}
}

#include <iostream>

using namespace std;


int getLength(int n)
{
	int length = 0;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return length;
}

bool isPalyndrome(int n)
{
	int length = getLength(n);
	for (int i = 0; i < (length + 1) / 2; i++)
	{
		int temp = n;
		int startIndex = length - i;
		for (int k = length; k > startIndex; k--)
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
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	if (n < 1 || n>1000000000)
	{
		cout << "-1";
		return 0;
	}

	int lower = n - 1;
	int bigger = n + 1;
	int size = 0;
	while (true)
	{
		if (isPalyndrome(lower) && lower > 100)
		{
			cout << lower;
			break;
		}
		else if (isPalyndrome(bigger) && bigger > 100)
		{
			cout << bigger;
			break;
		}
		lower--;
		bigger++;
	}

}

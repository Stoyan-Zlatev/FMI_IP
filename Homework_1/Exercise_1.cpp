#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter a number between 1 and 9: ";
	cin >> n;

	if (n < 1 || n > 9)
	{
		cout << "-1";
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			cout << " ";
		}
		for (int k = i; k <= n; k++)
		{
			cout << k;
		}
		cout << endl;
	}

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << " ";
		}
		for (int k = n; k >= i; k--)
		{
			cout << k;
		}
		cout << endl;
	}
}

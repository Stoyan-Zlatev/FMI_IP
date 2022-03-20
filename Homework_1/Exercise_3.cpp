#include <iostream>

using namespace std;

int main()
{
	int websitesCount;
	cout << "Enter number between 1 and 10: ";
	cin >> websitesCount;
	if (websitesCount < 1 || websitesCount > 10)
	{
		cout << "-1";
		return 0;
	}
	cout << "Enter number between 700 and 1500";
	int salary;
	cin >> salary;

	if ( salary < 700 || salary > 1500)
	{
		cout << "-1";
		return 0;
	}

	char website;

	for (int i = 1; i <= websitesCount; i++)
	{
		cin >> website;

		switch (website)
		{
		case 'f':
		case 'F':salary -= 150; break;
		case 'i':
		case 'I':salary -= 100; break;
		case 'r':
		case 'R':salary -= 50; break;
		case 'D':
		case 'd':break;
		default: cout << "-1"; return 0;
		}
		if (salary <= 0)
		{
			cout << "You have lost your salary.";
			return 0;
		}
	}

	cout << salary;
}

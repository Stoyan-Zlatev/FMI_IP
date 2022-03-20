#include <iostream>

using namespace std;

void printDate(unsigned int date[])
{
	if (date[3] < 10)
	{
		cout << "0" << date[3] << ".";
	}
	else
	{
		cout << date[3] << ".";
	}
	if (date[4] < 10)
	{
		cout << "0" << date[4] << ".";
	}
	else
	{
		cout << date[4] << ".";
	}
	cout << date[5] << " ";
	if (date[2] < 10)
	{
		cout << "0" << date[2] << ":";
	}
	else
	{
		cout << date[2] << ":";
	}
	if (date[1] < 10)
	{
		cout << "0" << date[1] << ":";
	}
	else
	{
		cout << date[1] << ":";
	}
	if (date[0] < 10)
	{
		cout << "0" << date[0];
	}
	else
	{
		cout << date[0];
	}
}

int main()
{
	unsigned int seconds;
	cin >> seconds;
	unsigned int startDate[6] = { 0,0,0,1,1,1970 };
	startDate[0] = seconds % 60;
	seconds -= seconds % 60;
	startDate[1] = (seconds % 3600) / 60;
	seconds -= seconds % 3600;
	startDate[2] = (seconds % (3600 * 24)) / 3600;
	seconds -= (seconds % (3600 * 24));
	unsigned int days = seconds / (3600 * 24);
	int currentMonth = 1;
	int currentYear = 1970;
	while (days / 31 > 0)
	{
		if (currentMonth == 1 || currentMonth == 3 || currentMonth == 5 || currentMonth == 7 || currentMonth == 8 || currentMonth == 10 || currentMonth == 12)
		{
			days -= 31;
		}
		else if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11)
		{
			days -= 30;
		}
		else
		{
			if (((currentYear % 4 == 0) && (currentYear % 100 != 0)) || (currentYear % 400 == 0))
			{
				days -= 29;
			}
			else
			{
				days -= 28;
			}
		}
		if (currentMonth >= 12)
		{
			currentYear++;
			currentMonth = 1;
		}
		else
		{
			currentMonth++;
		}
	}
	startDate[3] = 1 + days;
	startDate[4] = currentMonth;
	startDate[5] = currentYear;
	printDate(startDate);
}

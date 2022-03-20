#include <iostream>

using namespace std;

bool CompareDoubles(double x, double y)
{
	double absXY = x < y ? y - x : x - y;
	return absXY < 0.000001;
}

int main()
{
	double smallCircleRadius = 1;
	double mediumCircleRadius = 2;
	double bigCircleRadius = 4;

	double x;
	cin >> x;
	double y;
	cin >> y;

	if (x >= -4 && x <= 4 && y <= 4 && y >= -4)
	{
		if ((x * x + y * y) > bigCircleRadius * bigCircleRadius)
		{
			cout << "White";
		}
		else if (CompareDoubles(x, bigCircleRadius) || CompareDoubles(y, bigCircleRadius))
		{
			cout << "Undefined";
		}
		else if (x < 0)
		{
			if (x >= -3 && x <= -1)
			{
				if (CompareDoubles((((x + 2) * (x + 2)) + y * y), smallCircleRadius * smallCircleRadius))
				{
					cout << "Undefined";
					return 0;
				}
				else if ((((x + 2) * (x + 2)) + y * y) < smallCircleRadius * smallCircleRadius)
				{
					cout << "White";
					return 0;
				}
			}
			if (CompareDoubles((((x + 2) * (x + 2)) + y * y), mediumCircleRadius * mediumCircleRadius) && y > 0)
			{
				cout << "Undefined";
				return 0;
			}
			else if ((((x + 2) * (x + 2)) + y * y) < mediumCircleRadius * mediumCircleRadius)
			{
				cout << "Black";
				return 0;
			}
			if (y > 0)
			{
				cout << "White";
			}
			else
			{
				cout << "Black";
			}
		}
		else if (x >= 0)
		{
			if (x <= 3 && x >= 1)
			{
				if (CompareDoubles((((x - 2) * (x - 2)) + y * y), smallCircleRadius * smallCircleRadius))
				{
					cout << "Undefined";
					return 0;
				}
				else if ((((x - 2) * (x - 2)) + y * y) < smallCircleRadius * smallCircleRadius)
				{
					cout << "Black";
					return 0;
				}
			}
			if (CompareDoubles((((x - 2) * (x - 2)) + y * y), mediumCircleRadius * mediumCircleRadius) && y < 0)
			{
				cout << "Undefined";
				return 0;
			}
			if ((((x - 2) * (x - 2)) + y * y) < mediumCircleRadius * mediumCircleRadius)
			{
				cout << "White";
				return 0;
			}
			if (y > 0)
			{
				cout << "White";
			}
			else
			{
				cout << "Black";
			}
		}
	}
	else
	{
		cout << "Outside";
	}
}

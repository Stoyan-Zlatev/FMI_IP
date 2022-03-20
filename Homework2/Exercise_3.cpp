#include <iostream>

using namespace std;

int main()
{
	int input;
	cin >> input;
	int output;
	cin >> output;
	int counter = 0;
	while (input != output)
	{
		if (output % 2 != 0)
		{
			output += 1;
		}
		else if (output < input)
		{
			output += 1;
		}
		else
		{
			output /= 2;
		}
		counter++;
	}
	cout << counter;
}

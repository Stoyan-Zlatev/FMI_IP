#include <iostream>

using namespace std;

unsigned int GetBinaryBase(unsigned int n)
{
	unsigned int binaryBase = 1;
	while (n > 1)
	{
		binaryBase *= 10;
		n /= 2;
	}
	return binaryBase;
}

unsigned int ConvertToBinary(unsigned int n)
{
	unsigned int multiplicator = 1;
	unsigned int binaryNum = GetBinaryBase(n);
	
	while (n > 1)
	{
		binaryNum += (multiplicator * (n % 2));
		n /= 2;
		multiplicator *= 10;
	}

	return binaryNum;
}

bool hasAlternatingBits(unsigned n)
{
	while (n > 10)
	{
		unsigned int bit1 = n % 10;
		unsigned int bit2 = (n /= 10) % 10;
		if (bit1 == bit2)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	if (n < 0)
	{
		cout << "-1";
		return 0;
	}

	cin >> n;
	cout << boolalpha << hasAlternatingBits(ConvertToBinary(n));
}

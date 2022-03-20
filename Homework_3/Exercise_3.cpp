#include <iostream>

using namespace std;

void generate(char* symbols, unsigned* numbers, unsigned a, unsigned b, unsigned counter)
{
	const unsigned firstSymbolBorder = 21;
	const unsigned secondSymbolBorder = 33;
	symbols[0] = '#' + (counter % firstSymbolBorder);
	symbols[1] = '@' + (counter % secondSymbolBorder);
	numbers[0] = (1 + (counter / b));
	numbers[1] = (1 + (counter % b));
}

void printPasswords(unsigned a, unsigned b, unsigned count)
{
	const unsigned bufferSize = 2;
	char symbols[bufferSize];
	unsigned numbers[bufferSize];
	for (unsigned i = 0; i < count && i < a * b; i++)
	{
		generate(symbols, numbers, a, b, i);
		cout << symbols[0] << symbols[1];
		cout << numbers[0];
		cout << numbers[1];
		cout << symbols[1] << symbols[0] << "|";
	}
}

int main()
{
	unsigned a, b, count;
	const unsigned maxNumber = 1000;
	const unsigned minNumber = 1;
	const unsigned minPasswordsCount = 1;
	const unsigned maxPasswordsCount = 1000000;

	cin >> a;
	if (!(a >= minNumber && a <= maxNumber))
	{
		cout << "-1";
		return 0;
	}

	cin >> b;
	if (!(b >= minNumber && b <= maxNumber))
	{
		cout << "-1";
		return 0;
	}

	cin >> count;
	if (!(count >= minPasswordsCount && count <= maxPasswordsCount))
	{
		cout << "-1";
		return 0;
	}

	printPasswords(a, b, count);
}

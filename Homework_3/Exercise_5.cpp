#include <iostream>

using namespace std;

unsigned getLength(const char* arr)
{
	unsigned length = 0;
	while (arr[length] != '\0')
	{
		length++;
	}
	return length;
}

bool fillArray(const char* X ,char* s, char* S)
{
	unsigned length = getLength(X);
	unsigned sCounter = 0;
	unsigned SCounter = 0;
	for (unsigned i = 0; i < length; i++)
	{
		if (X[i] >= 'A' && X[i] <= 'Z')
		{
			S[SCounter++] = X[i];
		}
		else if (X[i] >= 'a' && X[i] <= 'z')
		{
			s[sCounter++] = X[i];
		}
		else
		{
			return false;
		}
	}
	S[SCounter] = '\0';
	s[sCounter] = '\0';
	return true;
}

char toLower(char element)
{
	char el = element - 32;
	return el;
}

int main()
{
	const unsigned bufferSize = 255;
	char X[bufferSize];
	cin >> X;
	char s[bufferSize];
	char S[bufferSize];
	fillArray(X, s, S);
	unsigned sLength = getLength(s);
	unsigned SLength = getLength(S);
	if (sLength != SLength)
	{
		cout << "No";
	}
	else
	{
		for (unsigned i = 0; i < SLength; i++)
		{
			if (toLower(s[i]) != S[i])
			{
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
	}
}

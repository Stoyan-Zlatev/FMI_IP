#include <iostream>

bool Hacksaw(const int* numbers, unsigned size, bool bigger)
{
	if (size == 2)
	{
		return true;
	}
	if (bigger)
	{
		return numbers[1] < numbers[0] && numbers[1] < numbers[2] && Hacksaw(numbers + 1, size - 1, !bigger);
	}
	else
	{
		return numbers[1] > numbers[0] && numbers[1] > numbers[2] && Hacksaw(numbers + 1, size - 1, !bigger);
	}
}

int main()
{
	unsigned N;
	std::cin >> N;

	int* numbers = new int[N];
	for (unsigned i = 0; i < N; i++)
	{
		std::cin >> numbers[i];
	}

	if (N < 3 || N> 1000)
	{
		std::cout << "-1";
		return 0;
	}

	bool bigger;
	if (numbers[1] > numbers[0] && numbers[1] > numbers[2])
	{
		bigger = true;
	}
	else if (numbers[1] < numbers[0] && numbers[1] < numbers[2])
	{
		bigger = false;
	}
	else
	{
		std::cout << "no";
		return 0;
	}
	std::cout << (Hacksaw(numbers + 1, N - 1, bigger) ? "yes" : "no");
}

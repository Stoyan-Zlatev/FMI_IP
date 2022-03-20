#include <iostream>

void createMatrix(char** matrix, const unsigned SIZE)
{
	for (unsigned i = 0; i < SIZE; i++)
	{
		matrix[i] = new char[SIZE];
		for (unsigned j = 0; j < SIZE; j++)
		{
			if (i != j)
			{
				matrix[i][j] = 'x';
			}
			else
			{
				//same digit
				matrix[i][j] = 's';
			}
		}
	}
	matrix[0][8] = '+';
	matrix[1][7] = '+';
	matrix[2][3] = '0';
	matrix[3][2] = '0';
	matrix[3][5] = '0';
	matrix[3][9] = '+';
	matrix[5][3] = '0';
	matrix[5][6] = '+';
	matrix[5][9] = '+';
	matrix[6][0] = '0';
	matrix[6][0] = '0';
	matrix[6][5] = '-';
	matrix[6][8] = '+';
	matrix[6][9] = '0';
	matrix[7][1] = '-';
	matrix[8][0] = '-';
	matrix[8][6] = '-';
	matrix[8][9] = '-';
	matrix[9][0] = '0';
	matrix[9][3] = '-';
	matrix[9][5] = '-';
	matrix[9][6] = '0';
	matrix[9][8] = '+';
}

void parseSign(char sign, int& neutral)
{
	if (sign == '+')
	{
		neutral++;
	}
	else if (sign == '-')
	{
		neutral--;
	}
}
void parseOperation(unsigned originalDigit, unsigned newDigit, unsigned& operationsCount)
{
	if (originalDigit != newDigit)
	{
		operationsCount++;
	}
}

unsigned switchesCount(char firstSign, char secondSign, char resultSign)
{
	unsigned switches = 0;
	if (firstSign == '0')
	{
		switches++;
	}
	if (secondSign == '0')
	{
		switches++;
	}
	if (resultSign == '0')
	{
		switches++;
	}
	return switches;
}

char** fixProblem(char** matrix, char* input, const unsigned matrixSize)
{
	unsigned firstDigit = input[0] - '0';
	char sign = input[1];
	unsigned secondDigit = input[2] - '0';
	unsigned result = input[4] - '0';
	unsigned resultMatrixIndex = 0;
	char** resultMatrix = new char* [10];
	int neutral = 0;
	bool isCorrect = false;
	unsigned operationsCount = 0;
	for (unsigned firstDigitIndex = 0; firstDigitIndex < matrixSize; firstDigitIndex++)
	{
		if (matrix[firstDigit][firstDigitIndex] == 'x')
		{
			continue;
		}
		for (unsigned secondDigitIndex = 0; secondDigitIndex < matrixSize; secondDigitIndex++)
		{
			if (matrix[secondDigit][secondDigitIndex] == 'x')
			{
				continue;
			}
			for (unsigned resultIndex = 0; resultIndex < matrixSize; resultIndex++)
			{
				if (matrix[result][resultIndex] == 'x')
				{
					continue;
				}
				isCorrect = false;
				neutral = 0;
				operationsCount = 0;
				char tempSign = sign;
				if (sign == '+')
				{
					if ((firstDigitIndex + secondDigitIndex) == resultIndex)
					{
						isCorrect = true;
					}
					else if ((firstDigitIndex - secondDigitIndex) == resultIndex)
					{
						isCorrect = true;
						tempSign = '-';
						neutral--;
						operationsCount++;
					}
				}
				else
				{
					if ((firstDigitIndex - secondDigitIndex) == resultIndex)
					{
						isCorrect = true;
					}
					else if ((firstDigitIndex + secondDigitIndex) == resultIndex)
					{
						isCorrect = true;
						neutral++;
						tempSign = '+';
						operationsCount++;
					}
				}
				if (isCorrect)
				{
					char firstDigitSign = matrix[firstDigit][firstDigitIndex];
					char secondDigitSign = matrix[secondDigit][secondDigitIndex];
					char resultDigitSign = matrix[result][resultIndex];
					parseSign(firstDigitSign, neutral);
					parseSign(secondDigitSign, neutral);
					parseSign(resultDigitSign, neutral);
					parseOperation(firstDigit, firstDigitIndex, operationsCount);
					parseOperation(secondDigit, secondDigitIndex, operationsCount);
					parseOperation(result, resultIndex, operationsCount);
					unsigned switches = switchesCount(firstDigitSign, secondDigitSign, resultDigitSign);
					if (neutral == 0 && operationsCount <= 2 && switches < 2)
					{
						resultMatrix[resultMatrixIndex] = new char[6];
						resultMatrix[resultMatrixIndex][0] = firstDigitIndex + '0';
						resultMatrix[resultMatrixIndex][1] = tempSign;
						resultMatrix[resultMatrixIndex][2] = secondDigitIndex + '0';
						resultMatrix[resultMatrixIndex][3] = '=';
						resultMatrix[resultMatrixIndex][4] = resultIndex + '0';
						resultMatrix[resultMatrixIndex][5] = '\0';
						resultMatrixIndex++;
					}
				}
			}
		}
	}
	resultMatrix[resultMatrixIndex] = new char[1];
	resultMatrix[resultMatrixIndex][0] = '\0';
	return resultMatrix;
}

int main()
{
	const unsigned SIZE = 10;
	char** matrix = new char* [SIZE];
	createMatrix(matrix, SIZE);
	const unsigned inputSize = 6;
	char input[inputSize];
	std::cin >> input;
	char** result = fixProblem(matrix, input, SIZE);
	unsigned i = 0;
	if (result[0][0] == '\0')
	{
		std::cout << "No";
	}
	while (result[i][0] != '\0')
	{
		std::cout << result[i] << std::endl;
		delete[] result[i++];
	}
	delete[] result;
}

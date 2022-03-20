#include <iostream>

void deleteMatrix(double** matrix, unsigned rowsCount)
{
	for (unsigned i = 0; i < rowsCount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

bool contains(unsigned* array, unsigned element, unsigned arrayLength)
{
	for (unsigned i = 0; i < arrayLength; i++)
	{
		if (array[i] == element)
		{
			return true;
		}
	}
	return false;
}

int findFirstNonZeroElementInRow(double** matrix, const unsigned currentRow, const unsigned rowLength)
{
	for (unsigned i = 0; i < rowLength; i++)
	{
		if (matrix[currentRow][i] != 0)
		{
			return i;
		}
	}
	return -1;
}

int countZeros(double** matrix, const unsigned currentRow, const unsigned rowLength)
{
	int zeros = 0;
	for (unsigned currentColumn = 0; currentColumn < rowLength; currentColumn++)
	{
		if (matrix[currentRow][currentColumn] == 0)
		{
			zeros++;
		}
	}
	return zeros;
}

int countZeros(double** matrix, const unsigned currentRow, const unsigned rowLength, int& currentTotalZeros)
{
	int zeros = 0;
	for (unsigned currentColumn = 0; currentColumn < rowLength; currentColumn++)
	{
		if (matrix[currentRow][currentColumn] == 0)
		{
			currentTotalZeros++;
			zeros++;
		}
	}
	return zeros;
}

int mostNonZeroRow(double** matrix, const unsigned rowsCount, const unsigned rowLength, unsigned* array, unsigned arrayLength)
{
	int index = -1;
	unsigned min = rowsCount + 1;
	for (unsigned i = 0; i < rowsCount; i++)
	{
		unsigned zeros = 0;
		for (unsigned j = 0; j < rowLength; j++)
		{
			if (matrix[i][j] == 0)
			{
				zeros++;
			}
		}
		if (zeros < min && (rowLength - zeros)>1)
		{
			index = i;
		}
	}
	return index;
}

int mostNonZeroCol(double** matrix, const unsigned rowsCount, const unsigned rowLength, unsigned* array, unsigned arrayLength)
{
	unsigned index = -1;
	unsigned min = rowsCount + 1;
	for (unsigned i = 0; i < rowLength; i++)
	{
		unsigned zeros = 0;
		for (unsigned j = 0; j < rowsCount; j++)
		{
			if (matrix[j][i] == 0)
			{
				zeros++;
			}
		}
		if (zeros < min && !contains(array, i, rowLength) && (rowsCount - zeros)>1)
		{
			index = i;
		}
	}
	return index;
}

int nonZeroRows(double** matrix, const unsigned rowsCount, const unsigned rowLength)
{
	int counter = rowsCount;
	for (unsigned i = 0; i < rowsCount; i++)
	{
		if (countZeros(matrix, i, rowLength) == rowLength)
			counter--;
	}
	return counter;
}

int rowWithLeastNonZeroElementes(double** matrix, const unsigned rowsCount, const unsigned rowLength, int& currentTotalZeros, bool* isUsed)
{
	int max[2] = { -1,-1 };
	currentTotalZeros = 0;
	for (unsigned currentRow = 0; currentRow < rowsCount; currentRow++)
	{
		int currentRowZeros = countZeros(matrix, currentRow, rowLength, currentTotalZeros);
		if (currentRowZeros > max[1] && isUsed[currentRow] == false)
		{
			max[0] = currentRow;
			max[1] = currentRowZeros;
		}
	}
	return max[0];
}

void printMatrix(double** matrix, const unsigned rowsCount, const unsigned rowLength)
{
	std::cout << std::endl;
	for (unsigned i = 0; i < rowsCount; i++)
	{
		for (unsigned j = 0; j < rowLength; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

double** getBasis(double** matrix, unsigned rowsCount, const unsigned rowLength)
{
	int subCount = nonZeroRows(matrix, rowsCount, rowLength);
	unsigned indexToSubSize = rowLength - subCount;
	unsigned* indexToSub = new unsigned[indexToSubSize];
	unsigned counter = 0;
	while (true)
	{
		int index = mostNonZeroCol(matrix, rowsCount, rowLength, indexToSub, rowLength - subCount);
		if (index == -1)
		{
			break;
		}
		indexToSub[counter++] = index;
	}
	if (counter < indexToSubSize)
	{
		for (counter; counter < indexToSubSize; counter++)
		{
			int rowIndex = mostNonZeroRow(matrix, rowsCount, rowLength, indexToSub, rowLength - subCount);
			if (rowIndex == -1)
				break;
			indexToSub[counter] = findFirstNonZeroElementInRow(matrix, rowIndex, rowLength);
		}
	}

	double** basis = new double* [counter];
	for (unsigned i = 0; i < counter; i++)
	{
		basis[i] = new double[rowLength];
		for (unsigned j = 0; j < rowLength; j++)
		{
			if (!contains(indexToSub, j, counter))
			{
				if (matrix[i][j] == 0)
				{
					for (unsigned k = 0; k < subCount; k++)
					{
						if (k != i)
						{
							int sum = 0;
							for (unsigned c = 0; c < counter; c++)
							{
								basis[i][indexToSub[c]] = c == i ? 1.0 : 0.0;
								sum -= (matrix[k][indexToSub[c]] * basis[i][indexToSub[c]]);
							}
							double del = sum / matrix[k][j];
							basis[i][j] = sum / matrix[k][j];
							break;
						}
					}
				}
				else
				{
					double sum = 0;
					for (unsigned c = 0; c < counter; c++)
					{
						basis[i][indexToSub[c]] = c == i ? 1.0 : 0.0;
						sum -= (matrix[i][indexToSub[c]] * basis[i][indexToSub[c]]);
					}
					double del = sum / matrix[i][j];
					basis[i][j] = sum / matrix[i][j];
				}
			}
		}
	}
	return basis;
}

double** gaussElimination(double** matrix, const unsigned rowsCount, const unsigned rowLength)
{
	int currentTotalZeros = -1;
	bool* isUsedRow = new bool[rowsCount];
	for (unsigned i = 0; i < rowsCount; i++)
	{
		isUsedRow[i] = false;
	}
	while (true)
	{
		int previousTotalZeros = currentTotalZeros;
		int currentRow = rowWithLeastNonZeroElementes(matrix, rowsCount, rowLength, currentTotalZeros, isUsedRow);
		isUsedRow[currentRow] = 1;
		if (currentRow == -1)
		{
			break;
		}
		int nonZeroIndex = findFirstNonZeroElementInRow(matrix, currentRow, rowLength);
		if (nonZeroIndex == -1)
		{
			continue;
		}
		double mainElement = matrix[currentRow][nonZeroIndex];
		for (unsigned rowToEliminate = 0; rowToEliminate < rowsCount; rowToEliminate++)
		{
			if (rowToEliminate == nonZeroIndex)
			{
				continue;
			}
			double neutralizator = -(matrix[rowToEliminate][nonZeroIndex] / matrix[nonZeroIndex][nonZeroIndex]);
			for (unsigned tempColumn = 0; tempColumn < rowLength; tempColumn++)
			{
				matrix[rowToEliminate][tempColumn] += matrix[nonZeroIndex][tempColumn] * neutralizator;
			}
		}
	}
	return matrix;
}

double** simplifyMatrix(double** matrix, unsigned& rowsCount, const unsigned rowLength)
{
	unsigned tempRowsConut = rowsCount;
	rowsCount = nonZeroRows(matrix, rowsCount, rowLength);
	double** simplifiedMatrix = new double* [rowsCount];
	unsigned indexCounter = 0;
	for (unsigned i = 0; i < tempRowsConut; i++)
	{
		if (countZeros(matrix, i, rowLength) < rowLength)
		{
			simplifiedMatrix[indexCounter] = new double[rowLength];
			for (unsigned j = 0; j < rowLength; j++)
			{
				simplifiedMatrix[indexCounter][j] = matrix[i][j];
			}
			indexCounter++;
		}
	}
	return simplifiedMatrix;
}

void fillMatrix(double** matrix, const unsigned rowsCount, const unsigned rowLength)
{
	for (unsigned i = 0; i < rowsCount; i++)
	{
		matrix[i] = new double[rowLength];
		for (unsigned j = 0; j < rowLength; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

double** concatMatrix(double** matrixA, unsigned aSize, double** matrixB, unsigned bSize)
{
	const unsigned rowLength = 4;
	double** resultMatrix = new double* [aSize + bSize];
	for (unsigned i = 0; i < aSize; i++)
	{
		resultMatrix[i] = new double[rowLength];
		for (unsigned j = 0; j < rowLength; j++)
		{
			resultMatrix[i][j] = matrixA[i][j];
		}
	}
	for (unsigned i = 0; i < bSize; i++)
	{
		resultMatrix[aSize + i] = new double[rowLength];
		for (unsigned j = 0; j < rowLength; j++)
		{
			resultMatrix[aSize + i][j] = matrixB[i][j];
		}
	}
	return resultMatrix;
}

int main()
{
	const unsigned rowLength = 4;
	unsigned m;
	std::cout << "m = ";
	std::cin >> m;
	unsigned n;
	std::cout << "n = ";
	std::cin >> n;
	std::cout << std::endl;

	double** A = new double* [n];
	fillMatrix(A, n, rowLength);
	
	double** B = new double* [m];
	fillMatrix(B, m, rowLength);
	
	double** basisB = getBasis(B, m, rowLength);
	unsigned nonZeroRowsA = n;
	double** simplifiedMatrixA = simplifyMatrix(gaussElimination(A, n, rowLength), nonZeroRowsA, rowLength);
	double** resultMatrix = concatMatrix(simplifiedMatrixA, nonZeroRowsA, basisB, m);
	unsigned resultSize = nonZeroRowsA + m;
	unsigned nonZeroRowsResult = resultSize;
	double** gaussMatrixResult = gaussElimination(resultMatrix, resultSize, rowLength);
	double** simplifiedMatrixR = simplifyMatrix(gaussMatrixResult, nonZeroRowsResult, rowLength);
	
	printMatrix(simplifiedMatrixR, nonZeroRowsResult, rowLength);
	
	deleteMatrix(A, n);
	deleteMatrix(B, m);
	deleteMatrix(basisB, m);
	deleteMatrix(resultMatrix, resultSize);
	deleteMatrix(simplifiedMatrixR, nonZeroRowsResult);
}

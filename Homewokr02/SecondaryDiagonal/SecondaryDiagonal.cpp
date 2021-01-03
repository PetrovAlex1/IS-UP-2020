#include <iostream>

int** FillInMatrix(int** matrix, int n)
{
	int countNullsInRow = n - 1;
	for (int i = 0; i < n; i++)
	{
		int j = 0;

		for (j = 0; j < countNullsInRow; j++)
		{
			matrix[i][j] = 0;
		}

		countNullsInRow--;

		matrix[i][j] = 1;

		for (int l = j + 1; l < n; l++)
		{
			matrix[i][l] = 2;
		}
	}

	return matrix;
}

int** CreateMatrix(int n)
{
	int** matrix = 0;
	matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}

	return matrix;
}

int main()
{
	int n;

	std::cin >> n;

	int** matrix = CreateMatrix(n);


	matrix = FillInMatrix(matrix, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	return 0;
}
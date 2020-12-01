#include <iostream>
#include <string>
#include <math.h>
#include <vector>

struct Vertex
{
	int matrix[32][32] = { 0 };
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (vertex.matrix[i][j] != 0)
			{
				stream << vertex.matrix[i][j] << " ";
			}
		}

		stream << std::endl;
	}

	return stream;
}

std::vector<Vertex> CalculateSumCubicMatrix(std::vector<Vertex> matrices, int rows, int cols, int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				matrices[i].matrix[row][col] += matrices[i].matrix[row][col];
			}
		}
	}

	return matrices;
}

int CalculateDeterminant(int matrix[32][32], int count)
{
	int determinant = 0;
	int subMatrix[32][32];
	int subRow = 0;
	int subCol = 0;

	if (count == 2)
	{
		return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
	}
	else
	{
		for (int colToIsolate = 0; colToIsolate < count; colToIsolate++)
		{
			subRow = 0;

			for (int row = 1; row < count; row++)
			{
				subCol = 0;
				for (int col = 0; col < count; col++)
				{
					if (col != colToIsolate)
					{
						subMatrix[subRow][subCol] = matrix[row][col];
						subCol++;
					}
				}

				subRow++;
			}

			determinant += pow(-1, colToIsolate) * matrix[0][colToIsolate] * CalculateDeterminant(subMatrix, count - 1);
		}
	}

	return determinant;
}

int CalculateSpecialDeterminant(std::vector<Vertex> matrices, int count, char symbol)//calculates both super and hyper determinant
{
	int determinant = 0;
	int subMatrix[32][32];

	for (int l = 0; l < count; l++)
	{
		if (symbol == '+')
		{
			determinant += CalculateDeterminant(matrices[l].matrix, count);
		}
		else
		{
			determinant *= CalculateDeterminant(matrices[l].matrix, count);

		}

	}


	return determinant;
}

void PrintMatrix(const std::vector<Vertex>& matrices, int rows, int cols, int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				std::cout << matrices[i].matrix[row][col] << " ";
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
}

std::vector<Vertex> TransposeCubicMatrix(const std::vector<Vertex> matrices, int rows, int cols, int count)
{
	std::vector<Vertex> transposeCubicMatrix;

	for (int i = 0; i < count; i++)
	{
		Vertex currentTransoseMatrix;

		for (int row = 0; row < cols; row++)
		{
			for (int col = 0; col < rows; col++)
			{
				currentTransoseMatrix.matrix[row][col] = matrices[i].matrix[col][row];
			}
		}

		transposeCubicMatrix.emplace_back(currentTransoseMatrix);
	}

	return transposeCubicMatrix;
}

void PrintFlatCubicMatrix(std::vector<Vertex> matrices, int rows, int cols, int count)
{
	int flatMatrix[32][32];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			int currentValue = 0;

			for (int i = 0; i < count; i++)
			{
				currentValue += matrices[i].matrix[row][col];
			}

			flatMatrix[row][col] = currentValue;
		}
	}

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			std::cout << flatMatrix[row][col] << " ";
		}

		std::cout << std::endl;
	}
}

int main()
{
	int rows, cols, count;
	std::cin >> rows;
	std::cin >> cols;
	std::cin >> count;
	std::vector<Vertex> cubicMatrix;
	Vertex currentCubicMatrix;

	for (int i = 0; i < count; i++)
	{
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				std::cin >> currentCubicMatrix.matrix[row][col];
			}
		}

		cubicMatrix.emplace_back(currentCubicMatrix);
	}

	std::cout << "Cubic matrix is saved.";
	std::cout << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::string actionToDo;
		std::cout << "Enter what action you want to calculate: ";
		std::cin >> actionToDo;

		if (actionToDo == "sum")
		{
			PrintMatrix(CalculateSumCubicMatrix(cubicMatrix, rows, cols, count), rows, cols, count);
		}
		else if (actionToDo == "super")
		{
			if (rows != cols)
			{
				std::cout << "There can not be find SuperDeterminant, because the matrices must be sqare!" << std::endl;
			}

			std::cout << CalculateSpecialDeterminant(cubicMatrix, count, '+') << std::endl;
		}
		else if (actionToDo == "hyper")
		{
			if (rows != cols)
			{
				std::cout << "There can not be find HyperDeterminant, because the matrices must be sqare!" << std::endl;
			}

			std::cout << CalculateSpecialDeterminant(cubicMatrix, count, '*') << std::endl;
		}
		else if (actionToDo == "transpose")
		{
			PrintMatrix(TransposeCubicMatrix(cubicMatrix, rows, cols, count), rows, cols, count);
		}
		else if (actionToDo == "flat")
		{
			PrintFlatCubicMatrix(cubicMatrix, rows, cols, count);
		}
		else
		{
			std::cout << "There's no such action!" << std::endl;
		}
	}

	return 0;
}

#include <iostream>
#include <cmath>

void FindDegree(int number, int degree, int n)//find the closest degree to the number
{
	int currentDegreedNumber = 1;
	int previousDegreedNumber = 1;

	while (true)
	{
		degree++;
		currentDegreedNumber *= n;

		if (abs(number - previousDegreedNumber) == abs(number - currentDegreedNumber))
		{
			std::cout << number << " -> " << degree - 1 << ", " << degree;
			break;
		}
		else if (abs(number - previousDegreedNumber) < abs(number - currentDegreedNumber))
		{
			std::cout << number << " -> " << degree - 1;
			break;
		}

		previousDegreedNumber = currentDegreedNumber;
	}
}

int main()
{
	int number, degree = 0;
	bool isSquare = true;
	std::cin >> number;
	int n = number;

	while (number > 0)//check if the number is degree of 2
	{
		if (number % 2 == 0)
		{
			number /= 2;
		}
		else if (number == 1)
		{
			break;
		}
		else
		{
			isSquare = false;
			break;
		}
	}

	if (isSquare)
	{
		FindDegree(n, degree, 3);
	}
	else
	{
		FindDegree(n, degree, 5);
	}

	return 0;
}
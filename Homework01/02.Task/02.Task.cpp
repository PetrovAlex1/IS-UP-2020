#include <iostream>
#include <cmath>

void FindDegree(int number, int degree, int n)
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
	int num, degree = 0;
	bool isSquare = true;
	std::cin >> num;
	int n = num;

	while (num > 0)
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else if (num == 1)
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
}
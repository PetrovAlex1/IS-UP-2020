#include <iostream>

int main()
{
	int year;
	std::cin >> year;
	char thirdDigit = (year % 100) / 10;
	char fourthDigit = year % 1000;

	if (thirdDigit == 0 && fourthDigit == 0)
	{
		if (year % 400 == 0)
		{
			std::cout << year << " is a leap year." << std::endl;
		}
	}
	else if (year % 4 == 0)
	{
		std::cout << year << " is a leap year." << std::endl;
	}
	else
	{
		std::cout << year << " is not a leap year." << std::endl;
	}
}
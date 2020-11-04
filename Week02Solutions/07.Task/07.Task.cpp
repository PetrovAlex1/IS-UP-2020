#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	int firstDigit = number / 1000;
	int secondDigit = (number / 100) % 10;
	int thirdDigit = (number % 100) / 10;
	int fourthDigit = number % 1000;
	bool isOdd = firstDigit % 2 != 0;
	bool isTheLargest = (firstDigit > secondDigit) && (firstDigit > thirdDigit) && (firstDigit > fourthDigit);

	if (isOdd)
	{
		std::cout << "The first digit is odd." << std::endl;
	}
	else
	{
		std::cout << "The first digit is even." << std::endl;
	}
	if (isTheLargest)
	{
		std::cout << "The first digit is the largest." << std::endl;;
	}
	else
	{
		std::cout << "The first digit is not the largest." << std::endl;
	}
}
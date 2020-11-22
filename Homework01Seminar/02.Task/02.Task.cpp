#include <iostream>

int ConvertDecimalToBinary(int number)
{
	int result = 0, binaryResult[16], reminder, i = 0;

	while (number > 0)//convert from decimal to binary
	{
		reminder = number % 2;
		binaryResult[i] = reminder;
		i++;
		number /= 2;
	}
	for (int j = 0; j < i / 2; j++)//reverse the result to get the real decimal value
	{
		int temp = binaryResult[j];
		binaryResult[j] = binaryResult[i - j - 1];
		binaryResult[i - j - 1] = temp;
	}

	result += binaryResult[0];

	for (int j = 1; j < i; j++)
	{
		result = (result * 10) + binaryResult[j];
	}

	return result;
}


int main()
{
	int n, numbers[32], decimalSum = 0, binarySum = 0;
	double decimalAvarage = 0, binaryAvarage = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> numbers[i];
		decimalSum += numbers[i];
		std::cout << ConvertDecimalToBinary(numbers[i]) << std::endl;
	}

	binarySum = ConvertDecimalToBinary(decimalSum);
	decimalAvarage = decimalSum / n;
	binaryAvarage = ConvertDecimalToBinary(decimalAvarage);

	std::cout << decimalSum << std::endl << binarySum << std::endl << decimalAvarage << std::endl << binaryAvarage;
}
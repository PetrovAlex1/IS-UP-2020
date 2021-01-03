#include <iostream>

int CountDigits(char text[], int counter)
{
	int i = 0;

	while (text[i] != '\0')
	{
		if ((int)text[i] >= 48 && (int)text[i] <= 57)
		{
			counter++;
			text[i] = '*';
			return CountDigits(text, counter);
		}

		i++;
	}

	return counter;
}

int main()
{
	char text[64];

	std::cin.getline(text, 64);
	
	int countDigits = CountDigits(text, 0);

	std::cout << countDigits;

	return 0;
}
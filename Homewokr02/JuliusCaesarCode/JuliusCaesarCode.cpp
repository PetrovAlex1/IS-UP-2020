#include <iostream>

char* Decryption(char* code, int countElements, int n)
{
	for (int i = 0; i < countElements; i++)
	{
		if (((int)code[i] - n) >= 65 && (((int)code[i] - n) <= 90))
		{
			code[i] = (char)((int)code[i] - n);
		}
		else
		{
			code[i] = (char)((int)code[i] + 25 - n);
		}
	}

	return code;
}

int CountElements(char code[])
{
	int i = 0, counter = 0;

	while ((int)code[i] >= 65 && (int)code[i] <= 90)
	{
		i++;
		counter++;
	}

	return counter;
}

int main()
{
	char* code = new char[64];
	int n, i = 0;

	std::cin.getline(code, 64);
	std::cin >> n;

	int countElements = CountElements(code);

	code = Decryption(code, countElements, n);

	for (int i = 0; i < countElements; i++)
	{
		std::cout << code[i];
	}

	delete[] code;
	return 0;
}
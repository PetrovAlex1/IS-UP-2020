#include <iostream>

void ToLower(char* text)
{
	if (text[0] == '\0')
	{
		return;
	}
	if (text[0] >= 'A' && text[0] <= 'Z')
	{
		text[0] += 32;
	}

	return ToLower(text + 1);

}

int CountLetters(char* text)
{
	int counter = 0;

	while (text[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

bool CheckPalindromeRecursion(char* text, int countSymbols, int counter)
{
	static int half = countSymbols / 2;

	if (counter == half)
	{
		return true;
	}
	else if (text[0] == ' ')
	{
		return CheckPalindromeRecursion(text + 1, --countSymbols, counter);
	}
	else if (text[countSymbols] == ' ')
	{
		return CheckPalindromeRecursion(text, --countSymbols, counter);
	}
	else if (text[0] == text[countSymbols])
	{
		countSymbols -= 2;
		counter++;
		return CheckPalindromeRecursion(text + 1, countSymbols, counter);
	}
	else
	{
		return false;
	}

	return true;
}

bool CheckPalindrome(char* text, int countSymbols)
{
	int index = countSymbols - 1;

	for (int i = 0; i < countSymbols / 2; i++)
	{
		if (text[i] == ' ')
		{
			continue;
		}
		else if (text[index] == ' ')
		{
			index--;
			i--;
			continue;
		}
		else if (text[i] != text[index])
		{
			return false;
		}

		index--;
	}

	return true;
}

int main()
{
	char* palindorme = new char[128];
	int i = 0;

	std::cin.getline(palindorme, 128);

	ToLower(palindorme);

	int countSymbols = CountLetters(palindorme);
	bool checkPalindromR = CheckPalindromeRecursion(palindorme, countSymbols - 1, 0);
	bool checkPalindrom = CheckPalindrome(palindorme, countSymbols);

	std::cout << "Result with recursion : ";
	std::cout << std::boolalpha << checkPalindromR << std::endl;
	std::cout << "Result without recursion : ";
	std::cout << std::boolalpha << checkPalindrom << std::endl;

	delete[] palindorme;
	return 0;
}
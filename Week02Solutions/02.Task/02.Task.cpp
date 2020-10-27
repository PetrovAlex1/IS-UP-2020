#include <iostream>

int main()
{
	char letter;
	std::cin >> letter;

	if ((int)letter > 97 && (int)letter < 122)
	{
		letter = (char)(letter - 32);
		std::cout << "The upper case character corresponding to is " << letter;
	}
	else if ((int)letter > 65 && (int)letter < 90)
	{
		letter = (char)(letter + 32);
		std::cout << "The lower case character corresponding to is " << letter;
	}
	else
	{
		std::cout << "is not a letter";
	}
}
#include <iostream>

int main()
{
	double a, b, result;
	char symbol;
	std::cin >> a;
	std::cin >> symbol;
	std::cin >> b;

	switch (symbol)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	default:
		break;
	}

	std::cout << result << std::endl;
}
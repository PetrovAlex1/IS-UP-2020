#include <iostream>

int main()
{
	int a, b, result;
	std::cin >> a;
	std::cin >> b;

	if (-b % a == 0)
	{
		result = -b / a;
		std::cout << result;
	}
	else if (a == 0 && b == 0)
	{
		std::cout << "INF";
	}
	else
	{
		std::cout << "NO";
	}
}

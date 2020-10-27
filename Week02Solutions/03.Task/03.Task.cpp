#include <iostream>

int main()
{
	int month;
	std::cin >> month;

	switch (month)
	{
	case 12:
	case 1:
	case 2:
		std::cout << "The season is winter!";
		break;
	case 3:
	case 4:
	case 5:
		std::cout << "The season is spring!";
		break;
	case 6:
	case 7:
	case 8:
		std::cout << "The season is summer!";
		break;
	case 9:
	case 10:
	case 11:
		std::cout << "The season is autumn!";
	default:
		break;
	}
}
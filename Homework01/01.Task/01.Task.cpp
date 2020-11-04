#include <iostream>

bool CheckYear(int year)//checks if year is leap
{
	bool isLeap = false;

	int thirdDigit = (year % 100) / 10;
	int fourthDigit = year % 10;

	if (thirdDigit == 0 && fourthDigit == 0)
	{
		if (year % 400 == 0)
		{
			isLeap = true;
		}
	}
	else if (year % 4 == 0)
	{
		isLeap = true;
	}

	return isLeap;
}

void CheckDate(int day, int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)//for months with 31 days
	{
		if (day < 1 || day > 31)
		{
			std::cout << "Invalid day!" << std::endl;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)//for months with 30 days
	{
		if (day < 1 || day > 30)
		{
			std::cout << "Invalid day!" << std::endl;
		}
	}
	else//for february
	{
		if (CheckYear(year))
		{
			if (day < 1 && day > 29)
			{
				std::cout << "Invalid day!" << std::endl;
			}
		}
		else
		{
			if (day < 1 && day > 28)
			{
				std::cout << "Invalid day!" << std::endl;
			}
		}
	}
	if (month < 1 && month > 12)
	{
		std::cout << "Invalid month!" << std::endl;
	}
	if (year < 1900 && year > 2100)
	{
		std::cout << "Invald year!" << std::endl;
	}
}

int dayOfWeek(int year, int month, int day)
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	year-= month < 3;
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

int main()
{
	int day, month, year;
	std::cin >> day >> month >> year;

	CheckDate(day, month, year);

	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 30)
		{
			day += 1;
		}
		else
		{
			month += 1;
			day = 1;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 8:
	case 10:
		if (day < 31)
		{
			day += 1;
		}
		else
		{
			month += 1;
			day = 1;
		}
		break;
	case 12:
		if (day < 31)
		{
			day += 1;
		}
		else
		{
			year += 1;
			month = 1;
			day = 1;
		}
		break;
	case 2:
		if (CheckYear(year))//if is leap
		{
			if (day < 29)
			{
				day += 1;
			}
			else
			{
				month += 1;
				day = 1;
			}
		}
		else
		{
			if (day < 28)
			{
				day += 1;
			}
			else
			{
				month += 1;
				day = 1;
			}
		}
	}

	switch (dayOfWeek(year, month, day))
	{
	case 0:
		std::cout << "\nSunday";
		break;
	case 1:
		std::cout << "\nMonday";
		break;
	case 2:
		std::cout << "\nTuesday";
		break;
	case 3:
		std::cout << "\nWednesday";
		break;
	case 4:
		std::cout << "\nThursday";
		break;
	case 5:
		std::cout << "\nFriday";
		break;
	case 6:
		std::cout << "\nSaturday";
		break;
	}

	std::cout << ", " << day << ", ";

	switch (month)
	{
	case 1:
		std::cout << "January, ";
		break;
	case 2:
		std::cout << "February, ";
		break;
	case 3:
		std::cout << "March, ";
		break;
	case 4:
		std::cout << "April, ";
		break;
	case 5:
		std::cout << "May, ";
		break;
	case 6:
		std::cout << "June, ";
		break;
	case 7:
		std::cout << "July, ";
		break;
	case 8:
		std::cout << "August, ";
		break;
	case 9:
		std::cout << "September, ";
		break;
	case 10:
		std::cout << "October, ";
		break;
	case 11:
		std::cout << "November, ";
		break;
	case 12:
		std::cout << "December, ";
		break;
	default:
		break;
	}

	std::cout << year;

	return 0;
}
#include <iostream>
#include <cmath>

int ConvertCharsToDate(char currentNumber[4], int counter)//Convert from 14 to decimal
{
	int date = 0, degree = 0;

	for (int i = 3; i >= 0; i--)
	{
		int asciicode = (int)currentNumber[i];

		if (asciicode >= 97 && asciicode <= 122)//is letter
		{
			switch (currentNumber[i])
			{
			case 0:
				date += 0 * pow(14, degree);
				break;
			case 'a':
				date += 1 * pow(14, degree);
				break;
			case 'b':
				date += 2 * pow(14, degree);
				break;
			case 'c':
				date += 3 * pow(14, degree);
				break;
			case 'd':
				date += 4 * pow(14, degree);
				break;
			case 'e':
				date += 5 * pow(14, degree);
				break;
			case 'f':
				date += 6 * pow(14, degree);
				break;
			case 'g':
				date += 7 * pow(14, degree);
				break;
			case 'h':
				date += 8 * pow(14, degree);
				break;
			case 'i':
				date += 9 * pow(14, degree);
				break;
			case 'j':
				date += 10 * pow(14, degree);
				break;
			case 'k':
				date += 11 * pow(14, degree);
				break;
			case 'l':
				date += 12 * pow(14, degree);
				break;
			case 'm':
				date += 13 * pow(14, degree);
				break;
			default:
				break;
			}

			degree++;
		}
	}

	return date;
}
void PrintConvertedNumber(int number, char convertedNumber[8])//convert the number into the system and print it in the console
{
	int i = 0, reminder;

	while (number > 0)
	{
		reminder = number % 14;

		switch (reminder)
		{
		case 0:
			convertedNumber[i] = '0';
			break;
		case 1:
			convertedNumber[i] = 'a';
			break;
		case 2:
			convertedNumber[i] = 'b';
			break;
		case 3:
			convertedNumber[i] = 'c';
			break;
		case 4:
			convertedNumber[i] = 'd';
			break;
		case 5:
			convertedNumber[i] = 'e';
			break;
		case 6:
			convertedNumber[i] = 'f';
			break;
		case 7:
			convertedNumber[i] = 'g';
			break;
		case 8:
			convertedNumber[i] = 'h';
			break;
		case 9:
			convertedNumber[i] = 'i';
			break;
		case 10:
			convertedNumber[i] = 'j';
			break;
		case 11:
			convertedNumber[i] = 'k';
			break;
		case 12:
			convertedNumber[i] = 'l';
			break;
		case 13:
			convertedNumber[i] = 'm';
			break;
		}

		i++;
		number /= 14;
	}

	for (int j = 0; j < i - 1; j++)//arrange the result
	{
		int temp = convertedNumber[j];
		convertedNumber[j] = convertedNumber[j + 1];
		convertedNumber[j + 1] = temp;
	}
	for (int i = 0; i < 8; i++)//print the result in the console
	{
		if ((int)convertedNumber[i] >= 97 && (int)convertedNumber[i] <= 122)
		{
			std::cout << convertedNumber[i];
		}
	}
}

int dayOfWeek(int year, int month, int day)//returns the day of week form date
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

int main()
{
	char date[16];
	char convertedNumber[8];
	int resultDate[3];
	int number, i = 0, j = 0;
	std::cin >> date;
	std::cin >> number;

	while (j != 3)//take date from the console
	{
		char currentNumber[4];
		int counter = 0;

		while (date[i] != '.' && date[i] != '\0')
		{
			currentNumber[counter] = date[i];
			i++;
			counter++;
		}

		resultDate[j] = ConvertCharsToDate(currentNumber, counter);
		j++;
		i++;
	}

	switch (dayOfWeek(resultDate[2], resultDate[1], resultDate[0]))//year, month, day -> Printing if Bojinkata will play in Nation Team
	{

	case 1://weeekdays
	case 2:
	case 3:
	case 4:
	case 5:
		std::cout << "No, " << resultDate[0] << '.' << resultDate[1] << '.' << resultDate[2] << " is a working day.";
		break;
	case 6://holidays
	case 0:
		std::cout << "Yes, " << resultDate[0] << '.' << resultDate[1] << '.' << resultDate[2] << " isn't a working day.";
		break;
	}

	std::cout << " " << number << " -> ";

	PrintConvertedNumber(number, convertedNumber);

	return 0;
}
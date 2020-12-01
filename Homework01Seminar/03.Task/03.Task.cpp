#include <iostream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include <windows.h>

int points = 0;

void clear()
{
	std::cout << "\x1B[2J\x1B[H";
}

enum class Difficulty
{
	easy,
	medium,
	hard
};

std::string EnumToString(Difficulty difficulty)
{
	if (difficulty == Difficulty::easy)
	{
		return "easy";
	}
	else if (difficulty == Difficulty::medium)
	{
		return "medium";
	}
	else
	{
		return "hard";
	}

}


Difficulty DeterminDifficulty(std::string difficulty)
{
	if (difficulty == "easy")
	{
		return Difficulty::easy;
	}
	else if (difficulty == "medium")
	{
		return Difficulty::medium;
	}
	else
	{
		return Difficulty::hard;
	}
}

void GameStart(std::string difficulty)
{
	std::string states[8] = { "up", "left", "down", "right", "front", "back", "center", "everywhere" };
	std::string statesToCheck[8];
	srand(time(NULL));

	int countStates = 0;
	double period = 0.0, periodForConsole = 0.0;//period to print the firs message;
	Difficulty difficultyID = DeterminDifficulty(difficulty);

	if (difficultyID == Difficulty::easy)
	{
		countStates = 4;
		period = 1000;
		periodForConsole = 1;
	}
	else if (difficultyID == Difficulty::medium)
	{
		countStates = 6;
		period = 500;
		periodForConsole = 0.5;
	}
	else
	{
		countStates = 8;
		period = 250;
		periodForConsole = 0.25;
	}

	std::cout << "Starting  \"" << EnumToString(difficultyID) << "\" mode. You will have " << countStates << " states (";

	for (int i = 0; i < countStates; i++)
	{
		std::cout << states[i];
		if (i < countStates - 1) std::cout << ", ";
	}

	std::cout << " ) and a period of " << periodForConsole << "sec to look at the answers." << std::endl;
	std::cin.ignore();
	std::cout << "Press any key to start playing...";
	std::cin.ignore();
	clear();

	for (int i = 0; i < countStates; i++)
	{
		int randomIndex = rand() % countStates + 0;
		std::cout << "Simon says " << states[randomIndex];
		statesToCheck[i] = states[randomIndex];
		Sleep(period);
		clear();
	}

	std::cout << "Now it's your turn!" << std::endl;

	std::string currentState;
	bool areEqual = false;

	for (int i = 0; i < countStates; i++)
	{
		std::cin >> currentState;

		if (currentState == statesToCheck[i])
		{
			areEqual = true;
		}
		else
		{
			areEqual = false;
			break;
		}
	}

	if (areEqual)
	{
		points++;
		std::cout << "Congrats! That's correct! You have" << points << " point up to now. Continue? (Yes/No)" << std::endl;
		std::string answer;
		std::cin >> answer;

		if (answer == "Yes")
		{
			std::string newDifficulty;
			std::cin >> newDifficulty;

			GameStart(newDifficulty);
		}
	}
	else
	{
		std::cout << "Sorry, you lost! You had " << points << " before you lost.";
	}
}

int main()
{
	std::string difficulty;
	std::cin >> difficulty;

	GameStart(difficulty);

	return 0;
}
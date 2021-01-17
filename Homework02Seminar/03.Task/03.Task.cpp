#include <iostream>

struct Player
{
private:
	char* name;
	int health;
	int strength;
	int level;
	int bicepsSize;
public:
	char* GetName()
	{
		return name;
	}

	int GetHealth()
	{
		return health;
	}

	int GetStrength()
	{
		return strength;
	}

	int GetLevel()
	{
		return level;
	}

	int GetBicepsSize()
	{
		return bicepsSize;
	}

	void SetName(char* _name)
	{
		name = _name;
	}

	void SetHealth(int _health)
	{
		health = _health;
	}

	void SetStrength(int _strength)
	{
		strength = _strength;
	}

	void SetLevel(int _level)
	{
		level = _level;
	}

	void SetBicepsSize(int _bicepsSize)
	{
		bicepsSize = _bicepsSize;
	}

	void TakeDamake(int damage)
	{
		health -= damage;
	}
};

void Fight(Player firstPlayer, Player secondPlayer, int firstPunch)
{
	int order = firstPunch;

	while (true)
	{
		int damage = 0;

		if (order % 2 == 0)//is second player's move
		{
			damage = secondPlayer.GetLevel() * secondPlayer.GetBicepsSize() + secondPlayer.GetStrength();
			firstPlayer.TakeDamake(damage);
			order++;
		}
		else//is first player's move
		{
			damage = firstPlayer.GetLevel() * firstPlayer.GetBicepsSize() + firstPlayer.GetStrength();
			secondPlayer.TakeDamake(damage);
			order++;
		}
		if (firstPlayer.GetHealth() < 0 || secondPlayer.GetHealth() < 0)
		{
			break;
		}
	}

	if (order % 2 != 0)
	{
		std::cout << "The fight won -> " << secondPlayer.GetName() << " with " << secondPlayer.GetHealth() << " health points left.";
	}
	else
	{
		std::cout << "The fight won -> " << firstPlayer.GetName() << " with " << firstPlayer.GetHealth() << " health points left.";
	}
}

int main()
{
	Player firstPlayer, secondPlayer;
	int currentHealth = 0, currentStrength = 0, currentLevel = 0, currentBicepsSize = 0;
	char* currentName = new char[8];

	//first player input
	std::cout << "Enter first player's name: ";
	std::cin >> currentName;
	firstPlayer.SetName(currentName);
	std::cout << "Enter first player's health points: ";
	std::cin >> currentHealth;
	firstPlayer.SetHealth(currentHealth);
	std::cout << "Enter first player's strength: ";
	std::cin >> currentStrength;
	firstPlayer.SetStrength(currentStrength);
	std::cout << "Enter first player's level: ";
	std::cin >> currentLevel;
	firstPlayer.SetLevel(currentLevel);
	std::cout << "Enter first player's biceps size: ";
	std::cin >> currentBicepsSize;
	firstPlayer.SetBicepsSize(currentBicepsSize);


	//second player input
	std::cout << "Enter second player's name: ";
	std::cin >> currentName;
	secondPlayer.SetName(currentName);
	std::cout << "Enter second player's health points: ";
	std::cin >> currentHealth;
	secondPlayer.SetHealth(currentHealth);
	std::cout << "Enter second player's strength: ";
	std::cin >> currentStrength;
	secondPlayer.SetStrength(currentStrength);
	std::cout << "Enter second player's level: ";
	std::cin >> currentLevel;
	secondPlayer.SetLevel(currentLevel);
	std::cout << "Enter second player's biceps size: ";
	std::cin >> currentBicepsSize;
	secondPlayer.SetBicepsSize(currentBicepsSize);

	int firstPunch = 0;
	std::cout << "Enter which will be the first punch. Enter 1 for the first player and 2 for the second: ";
	std::cin >> firstPunch;


	Fight(firstPlayer, secondPlayer, firstPunch);

	return 0;
}
#include <iostream>

#define cout(x) std::cout << x << std::endl
#define cin(x) std::cin >> x

char* ReplaceWithAsterisk(char* arr, char symbol)
{
	int i = 0;

	while (arr[i] != '\0')
	{
		if (arr[i] == symbol)
		{
			arr[i] = '*';
		}

		i++;
	}

	return arr;
}

bool CheckAsterisk(char arr[])
{
	int i = 0;

	while (arr[i] != '\0')
	{
		if (arr[i] != '*')
		{
			return false;
		}

		i++;
	}

	return true;
}


//This funcion will find if all elements on the first text contain on the second one. When it's find a common elemen, this element will
//be replaced with asterisk in the first texts, even if it occurs more than once.
bool CompareSymbols(char firstText[], char* secondText, int i)
{
	int j = 0;
	int count = 0;
	bool exist = false;

	if (firstText[i] == '*')
	{
		i++;
		return CompareSymbols(firstText, secondText, i++);
	}

	while (secondText[j] != '\0')
	{
		if (secondText[j] != '*')
		{
			if (firstText[i] == secondText[j])
			{
				firstText = ReplaceWithAsterisk(firstText, firstText[i]);
				i++;
				return CompareSymbols(firstText, secondText, i++);
			}
		}
		j++;
	}

	if (CheckAsterisk(firstText))
	{
		return true;
	}

	return false;
}

int main()
{
	char firstText[64];
	cin(firstText);
	char secondText[64]{ '*' };
	cin(secondText);

	if (CompareSymbols(firstText, secondText, 0))
	{
		cout("YES");
	}
	else
	{
		cout("NO");
	}

	return 0;
}

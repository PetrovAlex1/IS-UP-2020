#include <iostream>

int main()
{
	int n, array[32];
	std::string sortType;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}

	std::cin >> sortType;

	if (sortType == "ascending")
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					int temp = array[j + 1];
					array[j + 1] = array[j];
					array[j] = temp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (array[j] < array[j + 1])
				{
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}

	return 0;
}
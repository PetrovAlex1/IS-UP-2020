#include <iostream>

int* MergeArr(int* leftArr, int* rightArr)
{
	int leftCounter = 0;
	int rightCounter = 0;
	int* arr = new int[sizeof(leftArr) + sizeof(rightArr)];

	for (int i = 0; i < sizeof(arr); i++)
	{
		if (rightCounter == sizeof(rightCounter) || ((leftCounter < sizeof(leftArr)) && (leftArr[leftCounter] <= rightArr[rightCounter])))
		{
			arr[i] = leftArr[leftCounter];
			leftCounter++;
		}
		else if (leftCounter == sizeof(leftArr) || ((rightCounter < sizeof(rightCounter)) && (leftArr[leftCounter] >= rightArr[rightCounter])))
		{
			arr[i] = rightArr[rightCounter];
			rightCounter++;
		}
	}

	return arr;
}


int* MergeSort(int* arr)
{
	if (sizeof(arr) == 1)
	{
		return arr;
	}
	int size = sizeof(arr) / sizeof(arr[0]);
	int middle = size / 2;
	int* leftArr = new int[middle];
	int* rightArr = new int[sizeof(arr) - middle];

	for (int i = 0; i < middle; i++)
	{
		leftArr[i] = arr[i];
	}

	int j = 0;

	for (int i = middle; i < sizeof(arr); i++)
	{
		rightArr[j] = arr[i];
		j++;
	}

	leftArr = MergeSort(leftArr);
	rightArr = MergeSort(rightArr);

	int* newArr = MergeArr(leftArr, rightArr);

	return newArr;
}

int main() //Not Done 
{
	int* arr = new int[6]{ 6, 1, 11, 9, 3, 21 };

	arr = MergeSort(arr);

	for (int i = 0; i < sizeof(arr); i++)
	{
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}


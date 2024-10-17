#include <iostream>
#include <cassert>
#include <span>
#include <array>

void product(std::span<int> inputOutput, std::span<int> coefficients)
{
	assert(inputOutput.size() == coefficients.size());
	int i = 0;
	/*while (true)
	{
		if (i == inputOutput.size())
			break;

		inputOutput[i] *= coefficients[i];
		i++;
	}*/
	/*while (i < inputOutput.size())
	{
		inputOutput[i] *= coefficients[i];
		i++;
	}*/
	for (int k = 0; k < inputOutput.size(); k++)
	{
		inputOutput[k] *= coefficients[k];
	}
}

void PrintArray(std::span<int> arr) 
{
	for (int i = 0; i < arr.size(); i++) 
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	std::array arr1{ 1, 6, 13, 35, 8, 9 };
	std::array arr2{ 5, 34, 21, 7, 44, 1 };
	product(arr1, arr2);
	PrintArray(arr1);
}
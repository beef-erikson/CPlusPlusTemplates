// Assignment1.cpp
//
// Convert the following functions into templates
// 1. int Add(int x, int y)
// 2. int ArraySum(int* pArr, int arrSize)
// 3. int Max(int* pArr, int arrSize)
//

#include <iostream>


template<typename T>
T Add(T x, T y)
{
	return x + y;
}

template<typename T>
T ArraySum(T* pArr, T arrSize)
{
	auto sum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum += pArr[i];
	}
	return sum;
}

template<typename T>
T ArrayMax(T* pArr, T arrSize)
{
	auto max = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (pArr[i] > max)
		{
			max = pArr[i];
		}
	}
	return max;
}

int main()
{
	auto numAdd = Add(12, 24);
	std::cout << numAdd << std::endl;

	int numArray[] = { 12, 234, 235, 22 };
	auto arraySum = ArraySum(numArray, 4);
	std::cout << arraySum << std::endl;

	auto arrayMax = ArrayMax(numArray, 4);
	std::cout << arrayMax << std::endl;
}
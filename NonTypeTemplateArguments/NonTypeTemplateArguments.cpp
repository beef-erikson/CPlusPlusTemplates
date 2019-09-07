#include <iostream>

// Primary Template (note this would normally go in header file)
template<typename T>
T Max(T x, T y)
{
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

// Explicit Instantiation - normally would go in header
template char Max(char x, char y);

// Explicit Specialization - note this MUST go in .cpp, not header file
template<> const char* Max<const char*>(const char* x, const char* y)
{
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

// Non-type Template Arguments
template<int size>
void Print()
{
	std::cout << size << std::endl;
}
// These are typically used in arrays:
//template<typename T>
//T Sum(T* parr, int size)
//{
//	T sum{};
//	for (int i = 0; i < size; i++)
//	{
//		sum += parr[i];
//	}
//	return sum;
//}
// Another example using the reference of array without supplying size
template<typename T, int size>
T Sum(T (&parr)[size])
{
	T sum{};
	for (int i = 0; i < size; i++)
	{
		sum += parr[i];
	}
	return sum;
}




int main()
{
	int i = 3;
	//Print<i>(); -- this will not compile. must be a constant
	Print<3>();

	int arr[]{ 2, 1, 8, 5 };

	// grabs first entry in arr (std::begin and std::end is a function that uses a Nontype Template)
	auto it = std::begin(arr);
	std::cout << *it << std::endl;

	// reference to array with the array size
	//int(&ref)[4] = arr;

	// reference to array without array size
	int sum = Sum(arr);
	std::cout << sum << std::endl;

	return 0;
}
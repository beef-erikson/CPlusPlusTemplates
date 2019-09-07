#include <iostream>

// Note this would normally go in header file
template<typename T>
T Max(T x, T y)
{
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

// instatiate Max function for char types - can verify in assembly source
template char Max(char x, char y);

int main()
{
	// all arguments must be of same type.
	// Max(3, 5.2) <-- would throw compiler error

	// ways around this:
	Max(static_cast<float>(3), 4.4f);
	Max<double>(3, 6.4);

	std::cout << std::endl;

	// normal calls
	Max(3, 5);
	Max(3.1, 5.3);

	// can also instantiate by taking address
	int (*pfn)(int, int) = Max;
	std::cout << std::endl << pfn << std::endl;

	return 0;
}
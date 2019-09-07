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

int main()
{
	// Instantiation Examples
	const char* b{ "B" };
	const char* a{ "A" };

	// returns wrong answer if Explicit Specialization is not present since the address of "A" is larger
	auto s = Max(a, b);
	std::cout << s << std::endl;

	return 0;
}
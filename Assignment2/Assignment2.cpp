#include <iostream>
#include "Templates.h"

// Assignment 2:
// 1. Modify the function templates created in Assignment 1 to accept array by reference
// 2. Create specialization of the function templates created in Assignment 1. Specialize for const char*
// 3. Define the specialized functions in a .h file and include it in multiple source files. Observe what happens.



// Template specialization
template<> const char* Templates::Max<const char*>(const char* x, const char* y)
{
	return strcmp(x, y) > 0 ? x : y;
}

int main()
{
	Templates templates;

	int numAdd[]{ 12, 24, 36 };
	int sum = templates.Add(numAdd);
	std::cout << sum << std::endl;

	int max = templates.ArrayMax(numAdd);
	std::cout << max << std::endl;

	const char* f{ "F" };
	const char* g{ "G" };
	std::cout << templates.Max(f, g) << std::endl;
	

	// This erros out when the Template Specialization isn't defined in .cpp (commenting the definition out above)
	//auto Max = templates.Max2(f, g);
	//std::cout << templates.Max2(f, g) << std::endl;
}
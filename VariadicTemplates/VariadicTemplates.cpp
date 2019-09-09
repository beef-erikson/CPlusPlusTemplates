#include <iostream>

// Variadic Templates - functions and templates that accept any number of arguments / types


/*
// Arguments must be of same type in this example:
template<typename T>
void Print(std::initializer_list<T> args)
{
	for (const auto& x : args)
	{
		std::cout << x << " ";
	}
}
*/


// Base case function - for when recursion is completed
void Print()
{
	std::cout << std::endl;
}


// Variadic Template
template<typename T, typename...Params>					// Template parameter pack
void Print(const T&& a, Params&& ... args)				// Function parameter pack
{
	//std::cout << sizeof...(args) << std::endl;		// Used to find sizeof args and params
	//std::cout << sizeof...(Params) << std::endl;

	std::cout << a;
	if (sizeof...(args) != 0)
	{
		std::cout << ", ";
	}
	Print(std::forward<Params>(args)...);				// Invokes print function recursively
}


int main()
{
	// Note this will NOT work with the first template as a double and string are thrown in here:
	Print(1, 2.5, 3, "4", 5);

	/*
	Works like this:
	1. Print(1, 2.5, 3, "4", 5);
	2. Print(2.5, 3, "4", 5);
	3. Print(3, "4", 5);
	4. Print("4", 5);
	5. Print(5);
	6. Print();
	*/

	return 0;
}
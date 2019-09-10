#include <iostream>
#include <vector>
#include <list>

// typedef
// - Introduces a name for an existing type
// - This name becomes a synonym of that type
// - Useful for shorter or more meaningful names for existing types
// - Simplifies declaration of some types (i.e. function pointers and templates)
// - Implementation details that may change can be encapsulated
// - Does NOT introduce a new type; only introduces a new name for existing type

// Example:
//
// typedef std::vector<std::list<Employee>> Teams;
// Teams testingTeams;
// Teams::iterator it = testingTeams.begin();


// Type Alias
// - Creates a name that is a synonym of existing type
// - Does not introduce a new type
// - Same as typedef declaration
// - Created through the using keyword:
// using identifier = type;

// Example:
//
// using Teams = std::vector<std::list<Employee>>;
// Teams testingTeams;
// Teams::iterator it = testingTeams.begin();


const char* GetErrorMessage(int errorNo)
{
	return "Empty";
}

// typedef example
//typedef const char* (*PFN)(int);

// type alias example
using PFN = const char* (*)(int);
void ShowError(PFN pfn)
{

}

// anoter typedef example - note typedefs cannot use templates
//typedef std::vector<std::list<std::string>> Names;

// using type alias for templates
template<typename T>
using Names = std::vector<std::list<T>>;
// or to use a specific type:
//using Names = std::vector<std::list<std::string>>;
int main()
{
	Names<std::string> names;
	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
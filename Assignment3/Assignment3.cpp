#include <iostream>
#include <vector>

// Assignment 3
// Specialize the PrettyPrinter class for std::vector<std::vector<int>>
// It should print the vector data as follows:
// 
//Main vector (vector<vector<int>>)
//{
//	{1,2,3},		// first element vector<int> 
//	{4,5,6}			// second element vector<int>

// Regular template
template<typename T>
class PrettyPrinter
{
	T* m_pData;
public:
	PrettyPrinter(T* data) :m_pData(data)
	{
	}
	void Print()
	{
		std::cout << "{" << *m_pData << "}" << std::endl;
	}
	T* GetData()
	{
		return m_pData;
	}
};

// Specialized template for Print member function only, accepts type vector<vector<int>>
template<typename T>
using vec = std::vector<std::vector<T>>;
void PrettyPrinter<vec<int>>::Print()
{
	std::cout << "{";
	for (const auto& x : *m_pData)
	{
		std::cout << x << ",";
	}
	std::cout << "}" << std::endl;

}

int main()
{
	std::vector<std::vector<int>> vect{ { 1, 2, 3 }, { 4, 5, 6 } };

	vec p1 = PrettyPrinter({ { 1, 2, 3 }, { 4, 5, 6 } });

	return 0;
}
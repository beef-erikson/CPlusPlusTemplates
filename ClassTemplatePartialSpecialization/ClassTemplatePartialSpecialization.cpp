#include <iostream>
#include <vector>

template<typename T>
class PrettyPrinter
{
	T* m_pData;
public:
	PrettyPrinter(T* data) : m_pData(data)
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

int main()
{


	return 0;
}
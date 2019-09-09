#include <iostream>

template<typename T, int size>
class Stack
{
	T m_Buffer[512];
	int m_Top{ -1 };
public:
	// Constructor
	Stack() = default;
	// Copy Constructor for class - perform copy of attributes manually
	Stack(const Stack& obj)
	{
		m_Top = obj.m_Top;
		for (int i = 0; i <= m_Top; ++i)
		{
			m_Buffer[i] = obj.m_Buffer[i];
		}
	}

	// Class Functions
	void Push(const T& elem)
	{
		m_Buffer[++m_Top] = elem;
	}
	void Pop();
	const T& Top() const
	{
		return m_Buffer[m_Top];
	}
	bool IsEmpty()
	{
		return m_Top == -1;
	}
	// Factory method, creates instance of class
	static Stack Create();
};

// If defining function outside class, definition must be preceeded with definition of template and template paramaters as type
template<typename T, int size>
void Stack<T, size>::Pop()
{
	--m_Top;
}

// We would also create factory method outside of class, note that shorthand can't be used and full type must be written out
template<typename T, int size>
Stack<T, size> Stack<T, size>::Create()
{
	return Stack<T, size>();
}

int main()
{
	Stack<int, 10> intStack = Stack<int, 10>::Create();
	intStack.Push(3);
	intStack.Push(1);
	intStack.Push(6);
	intStack.Push(9);
	
	// Using the copy constructor
	auto intStack2(intStack);

	while (!intStack2.IsEmpty())
	{
		std::cout << intStack2.Top() << " ";
		intStack2.Pop();
	}
	std::cout << std::endl;

	Stack<float, 5> floatStack = Stack<float, 5>::Create();
	floatStack.Push(2.5);
	floatStack.Push(4.33);
	floatStack.Push(323.223);

	while (!floatStack.IsEmpty())
	{
		std::cout << floatStack.Top() << " ";
		floatStack.Pop();
	}
	std::cout << std::endl;

	return 0;
}
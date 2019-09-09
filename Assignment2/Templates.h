#pragma once
class Templates
{
public:
	// Note that templates should be declared and initialized in header, unless it's a specialized template.
	template<typename T, int size>
	T Add(T(&parr)[size])
	{
		T sum{};
		for (int i = 0; i < size; i++)
		{
			sum += parr[i];
		}
		return sum;
	}

	template<typename T, int size>
	T ArrayMax(T(&parr)[size])
	{
		T max = 0;
		for (int i = 0; i < size; i++)
		{
			if (parr[i] > max)
			{
				max = parr[i];
			}
		}
		return max;
	}

	template<typename T>
	T Max(T x, T y)
	{
		return x > y ? x : y;
	}

	//// Specialized template - MUST go in .cpp but here for assignment - Errors out when compiling
	//template<> const char* Templates::Max<const char*>(const char* x, const char* y)
	//{
	//	return strcmp(x, y) > 0 ? x : y;
	//}

	//auto Max2(const char* a, const char* b);
};


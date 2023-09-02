#include "Noise.h"

Noise::Noise(std::vector<_CRT_DOUBLE>data)
{
	input.resize(data.size());
	for (size_t i = 0; i < data.size(); i++)
	{
		input[i].x = data[i].x;
	}
}


_CRT_DOUBLE Noise::getMax()
{
	_CRT_DOUBLE result{};
	result.x = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (result.x < input[i].x)
		{
			result.x = input[i].x;
		}
	}
	return result;
}

_CRT_DOUBLE Noise::getMin()
{
	_CRT_DOUBLE result{};
	result.x = DBL_MAX;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (result.x > input[i].x)
		{
			result.x = input[i].x;
		}
	}
	return result;
}

_CRT_DOUBLE Noise::getAverage()
{
	FastAverage av();
	return _CRT_DOUBLE();
}

_CRT_DOUBLE Noise::maxDifference()	//use correct vectors pls
{
	std::vector<_CRT_DOUBLE> diff;
	diff.resize(input.size() + 1);
	for (size_t i = 0; i < input.size() - 1; i++)
	{
		output[i].x = input[i + 1].x - input[i].x;
	}
	getMax();
	return _CRT_DOUBLE();
}

size_t Noise::getIndexAtTime(_CRT_DOUBLE time)
{
	size_t i = 0;
	while (i < input.size())
	{
		if (time.x < input[i].x)
		{
			i++;
		}
		if (time.x > input[i].x)
		{
			break;
		}
	}
	return i;
}

_CRT_DOUBLE Noise::getTimeAtIndex(size_t index)
{
	if (index < input.size())
	{
		input[index].x;
	}
	return _CRT_DOUBLE();
}

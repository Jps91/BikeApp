#include "VectorEditor.h"

size_t indexAtTime(std::vector<_CRT_DOUBLE>timeVector, double timestamp)
{
	std::vector<_CRT_DOUBLE> time = timeVector;
	for (size_t i = 0; i < time.size(); i++)
	{
		if (time[i].x > timestamp)
		{
			return i;
		}
	}
	return time.size();
}


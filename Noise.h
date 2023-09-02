#pragma once
#include <vector>

#include "FastAverage.h"
#include "MeanFilter.h"

class Noise
{
	std::vector<_CRT_DOUBLE> input{};
	std::vector<_CRT_DOUBLE> output{};

	Noise(std::vector<_CRT_DOUBLE> data);
	
	_CRT_DOUBLE getMax();
	_CRT_DOUBLE getMin();
	_CRT_DOUBLE getAverage();
	_CRT_DOUBLE getMedian();
	_CRT_DOUBLE averageDifferenc();
	_CRT_DOUBLE maxDifference();
	_CRT_DOUBLE minDifference();
	size_t getIndexAtTime(_CRT_DOUBLE time);
	_CRT_DOUBLE getTimeAtIndex(size_t index);

public:

};


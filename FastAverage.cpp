#include "FastAverage.h"

FastAverage::FastAverage(const int filterSize) :size_(filterSize)
{
	list.resize(size_);
	list.assign(size_, 0);

}
float FastAverage::additionalValue(float inputValue)
{
	sum_m -= list[lastPointer];
	sum_m += inputValue;
	list[lastPointer] = inputValue;
	pointerIncrement();
	return sum_m / size_;

}
void FastAverage::pointerIncrement()
{
	lastPointer++;
	pointer++;
	if (lastPointer == size_)
	{
		lastPointer = 0;
	}
	else if (pointer == size_)
	{
		pointer = 0;
	}

}
FastAverage::~FastAverage()
{
	;
}
#include "FastAverageDouble.h"

FastAverageDouble::FastAverageDouble(const int filterSize) :size_(filterSize)
{
	list.resize(size_);
	list.assign(size_, 0);

}
float FastAverageDouble::additionalValue(double inputValue)
{
	sum_m -= list[lastPointer];
	sum_m += inputValue;
	list[lastPointer] = inputValue;
	pointerIncrement();
	return sum_m / size_;

}
void FastAverageDouble::pointerIncrement()
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
FastAverageDouble::~FastAverageDouble()
{
	;
}
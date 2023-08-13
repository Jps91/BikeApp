#pragma once
#ifndef FastAverage_H
#include <vector>

class FastAverageDouble
{
public:
	FastAverageDouble(const int filterSize = 3);
	float additionalValue(double inputValue);

	~FastAverageDouble();
private:
	std::vector<double> list;
	int pointer = 0;
	int lastPointer = 0;
	void pointerIncrement();
	int size_ = 0;
	double sum_m = 0;
	double last_m = 0;
};





#endif // !FastAverage_H


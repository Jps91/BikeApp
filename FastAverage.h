#pragma once
#ifndef FastAverage_H
#include <vector>

class FastAverage
{
public:
	FastAverage(const int filterSize=3);
	float additionalValue(float inputValue);

	~FastAverage();
private:
	std::vector<float> list;
	int pointer = 0;
	int lastPointer = 0;
	void pointerIncrement();
	int size_ = 0;
	float sum_m = 0;
	float last_m = 0;
};





#endif // !FastAverage_H


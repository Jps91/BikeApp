#pragma once
#ifndef MeanFilter_H


#include <vector>
class MeanFilter
{
public:
	MeanFilter(const int filterSize);
	void resetCache();
	void nextValue(float newValue);
	float result();
	~MeanFilter();
private:
	int size_ = 5;
	int pointer_ = 0;
	int middle_ = 0;
	std::vector<float> list = { 0 };
	std::vector<float> sorted = { 0 };
	void insertion_sort(std::vector<float>& vec);
	void pointerIncrement();
};



#endif // !MeanFilter_H

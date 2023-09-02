#pragma once
#ifndef MeanFilterDouble_H


#include <vector>
class MeanFilterDouble
{
public:
	MeanFilterDouble(const int filterSize);
	void resetCache();
	void nextValue(double newValue);
	float result();
	~MeanFilterDouble();
private:
	int size_ = 5;
	int pointer_ = 0;
	int middle_ = 0;
	std::vector<double> list = { 0 };
	std::vector<double> sorted = { 0 };
	void insertion_sort(std::vector<double>& vec);
	void pointerIncrement();
};



#endif // !MeanFilter_H

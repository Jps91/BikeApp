#include "MeanFilterDouble.h"

MeanFilterDouble::MeanFilterDouble(const int filterSize)
{
	list.resize(size_);
	sorted.resize(size_);
	list.assign(size_, 0);
	middle_ = size_ / 2;
}

void MeanFilterDouble::resetCache()
{
	list.assign(size_, 0);
}

void MeanFilterDouble::nextValue(double newValue)
{
	list[pointer_] = newValue;
	pointerIncrement();
}

float MeanFilterDouble::result()
{
	insertion_sort(list);
	return list[middle_];
}


void MeanFilterDouble::insertion_sort(std::vector<double>& vec)
{
	size_t vectorSize = vec.size();
	for (int j = 1; j < vectorSize; j++)
	{
		float key = vec[j];
		int i = j - 1;

		while (i >= 0 && vec[i] > key)
		{
			vec[i + 1] = vec[i];
			i--;
		}
		vec[i + 1] = key;
	}
}

void MeanFilterDouble::pointerIncrement()
{
	pointer_++;
	if (pointer_ == size_)
	{
		pointer_ = 0;
	}
}

MeanFilterDouble::~MeanFilterDouble()
{
}

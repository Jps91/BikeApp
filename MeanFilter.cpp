#include "MeanFilter.h"

MeanFilter::MeanFilter(const int filterSize)
{
	list.resize(size_);
	sorted.resize(size_);
	list.assign(size_, 0);
	middle_ = size_ / 2;
}

void MeanFilter::resetCache()
{
	list.assign(size_, 0);
}

void MeanFilter::nextValue(float newValue)
{
	list[pointer_] = newValue;
	pointerIncrement();
}

float MeanFilter::result()
{
	insertion_sort(list);
	return list[middle_];
}


void MeanFilter::insertion_sort(std::vector<float>& vec)
{
	int vectorSize = vec.size();
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

void MeanFilter::pointerIncrement()
{
	pointer_++;
	if (pointer_ == size_)
	{
		pointer_ = 0;
	}
}

MeanFilter::~MeanFilter()
{
}

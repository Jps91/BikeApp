#pragma once
#include <vector>
#include <fstream>
#include <istream>
#include <fstream>
#include <math.h>  
#include <iostream>

class GYRO
{
public:
	std::vector<long long> time;

	std::vector<_CRT_DOUBLE>x;
	std::vector<_CRT_DOUBLE>y;
	std::vector<_CRT_DOUBLE>z;
	long long entries = 0;
	GYRO();

private:
	std::string fileName_m = "GRYO.csv";
	bool status = true;
};


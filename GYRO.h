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
	std::vector<_CRT_DOUBLE> time;

	std::vector<_CRT_DOUBLE>x;
	std::vector<_CRT_DOUBLE>y;
	std::vector<_CRT_DOUBLE>z;
	size_t entries = 0;
	GYRO(std::string);

private:
	std::string fileName_m = "Gyroscope.csv";
	bool status = true;
};


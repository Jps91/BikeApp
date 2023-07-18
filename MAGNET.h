#pragma once
#include <vector>
#include <fstream>
#include <istream>
#include <fstream>
#include <math.h>  
#include <iostream>
class MAGNET
{
public:
	std::vector<long long> time;

	std::vector<_CRT_DOUBLE>x;
	std::vector<_CRT_DOUBLE>y;
	std::vector<_CRT_DOUBLE>z;
	MAGNET();

	long long entries = 0;
private:
	std::string fileName_m = "MAGNET.csv";
	bool status = true;
};


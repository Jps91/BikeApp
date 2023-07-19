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
	std::vector<_CRT_DOUBLE> time;

	std::vector<_CRT_DOUBLE>x;
	std::vector<_CRT_DOUBLE>y;
	std::vector<_CRT_DOUBLE>z;

	std::vector<_CRT_DOUBLE>xAngle;
	std::vector<_CRT_DOUBLE>zAngle;
	std::vector<_CRT_DOUBLE>zAngle;

	MAGNET(std::string);
	void store();
	unsigned long long entries = 0;
private:
	std::string fileName_m = "Magnetometer.csv";
	bool status = true;
};


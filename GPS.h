#pragma once
#include <vector>
#include <fstream>
#include <istream>
#include <fstream>
#include <math.h>  
#include <iostream>


class GPS
{
public:
	std::vector<long long> time;
	std::vector<float> latitude;
	std::vector<float> longitude;
	std::vector<_CRT_DOUBLE> altitude;
	std::vector<float> accuracy;
	std::vector<float> speed;
	std::vector<float> bearing;
	long long entries = 0;
	GPS();
	~GPS();
private:
	std::string fileName_m = "GPS.csv";
	bool status = true;
};


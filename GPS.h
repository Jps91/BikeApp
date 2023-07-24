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
	std::vector<_CRT_DOUBLE> time;
	std::vector<_CRT_DOUBLE> latitude;
	std::vector<_CRT_DOUBLE> longitude;
	std::vector<_CRT_DOUBLE> altitude;
	std::vector<_CRT_DOUBLE> speed;
	std::vector<_CRT_DOUBLE> bearing;
	std::vector<_CRT_DOUBLE> horizontalAccuracy;
	std::vector<_CRT_DOUBLE> verticalAccuracy;
	size_t entries = 0;
	GPS(std::string);
	void terrain();
	~GPS();
private:
	std::string fileName_m = "Location.csv";
	bool status = true;
};


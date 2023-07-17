#pragma once
#include <vector>
#include <fstream>
#include <istream>
#include <fstream>
#include <math.h>  



class ACC
{
public:
	std::vector<long long> time;

	//With Gravity;
	std::vector<_CRT_DOUBLE>ag;
	std::vector<_CRT_DOUBLE>agx;
	std::vector<_CRT_DOUBLE>agy;
	std::vector<_CRT_DOUBLE>agz;

	std::vector<_CRT_DOUBLE>vg;
	std::vector<_CRT_DOUBLE>vgx;
	std::vector<_CRT_DOUBLE>vgy;
	std::vector<_CRT_DOUBLE>vgz;


	ACC(std::string filePath);
	bool isGood();
	int getLine(long long* time_nano_seconds, double* x, double* y, double* z);

	//bool setByTime(long long time_nano_seconds);
	long long entries = 0;
	~ACC();
private:
	std::string fileName_m = "ACC.csv";
	long long currentTime;
	bool status = true;
	void speed();

};


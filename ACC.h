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

	std::vector<_CRT_DOUBLE>a;
	std::vector<_CRT_DOUBLE>ax;
	std::vector<_CRT_DOUBLE>ay;
	std::vector<_CRT_DOUBLE>az;

	std::vector<_CRT_DOUBLE>v;
	std::vector<_CRT_DOUBLE>vx;
	std::vector<_CRT_DOUBLE>vy;
	std::vector<_CRT_DOUBLE>vz;

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


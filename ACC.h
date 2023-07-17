#pragma once
#include <vector>
#include <fstream>
#include <istream>
#include <fstream>



class ACC
{
public:
	std::vector<long long> time;
	std::vector<_CRT_DOUBLE>x;
	std::vector<_CRT_DOUBLE>y;
	std::vector<_CRT_DOUBLE>z;
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
};


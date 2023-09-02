#pragma once
#include <vector>
#include <fstream>
#include <istream>
#include <fstream>
#include <math.h>  
#include <iostream>


class ACG
{
public:
	std::vector<_CRT_DOUBLE> time;

	//With Gravity;
	std::vector<_CRT_DOUBLE>a;
	std::vector<_CRT_DOUBLE>ax;
	std::vector<_CRT_DOUBLE>ay;
	std::vector<_CRT_DOUBLE>az;

	std::vector<_CRT_DOUBLE>awg;
	std::vector<_CRT_DOUBLE>axwg;
	std::vector<_CRT_DOUBLE>aywg;
	std::vector<_CRT_DOUBLE>azwg;

	std::vector<_CRT_DOUBLE>axNorthg;
	std::vector<_CRT_DOUBLE>ayEastg;
	std::vector<_CRT_DOUBLE>azDowng;

	std::vector<_CRT_DOUBLE>v;
	std::vector<_CRT_DOUBLE>vx;
	std::vector<_CRT_DOUBLE>vy;
	std::vector<_CRT_DOUBLE>vz;

	std::vector<_CRT_DOUBLE>p;
	std::vector<_CRT_DOUBLE>px;
	std::vector<_CRT_DOUBLE>py;
	std::vector<_CRT_DOUBLE>pz;


	ACG(std::string filePath);
	bool isGood();
	int getLine(long long* time_nano_seconds, double* x, double* y, double* z);
	void store();
	//bool setByTime(long long time_nano_seconds);
	unsigned long long entries = 0;
	void betterspeed();
	void gravityFix( std::vector<_CRT_DOUBLE>&yaw, std::vector<_CRT_DOUBLE>&pitch, std::vector<_CRT_DOUBLE>&roll);
	void speed();
	void position();
	~ACG();
private:
	std::string fileName_m = "Accelerometer.csv";
	long long currentTime;
	bool status = true;
};


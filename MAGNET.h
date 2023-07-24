#pragma once
#include <vector>
#include <fstream>
#include <istream>
#include <fstream>
#include <cmath>
#include <iostream>
#include "lib/eigen-3.4.0/Eigen/Dense"

class MAGNET
{
public:
	std::vector<_CRT_DOUBLE> time;

	std::vector<_CRT_DOUBLE>x;
	std::vector<_CRT_DOUBLE>y;
	std::vector<_CRT_DOUBLE>z;

	std::vector<_CRT_DOUBLE>xc;		//c= correceted;
	std::vector<_CRT_DOUBLE>yc;
	std::vector<_CRT_DOUBLE>zc;


	std::vector<_CRT_DOUBLE>xAngle;
	std::vector<_CRT_DOUBLE>yAngle;
	std::vector<_CRT_DOUBLE>zAngle;

	std::vector<_CRT_DOUBLE>elipsoidDistance;
	_CRT_DOUBLE avergaeDistance{};

	std::vector<_CRT_DOUBLE>a;
	std::vector<_CRT_DOUBLE>b;
	std::vector<_CRT_DOUBLE>c;

	_CRT_DOUBLE xlow{};
	_CRT_DOUBLE ylow{};
	_CRT_DOUBLE zlow{};

	_CRT_DOUBLE xhigh{};
	_CRT_DOUBLE yhigh{};
	_CRT_DOUBLE zhigh{};

	_CRT_DOUBLE xhio{};
	_CRT_DOUBLE yhio{};
	_CRT_DOUBLE zhio{};


	MAGNET(std::string);
	void rotationToNoth();
	void store();
	void calibrate();
	unsigned long long entries = 0;
private:
	std::string fileName_m = "Magnetometer.csv";
	bool status = true;
	_CRT_DOUBLE sqrtOf3WithPower(_CRT_DOUBLE X, _CRT_DOUBLE Y, _CRT_DOUBLE Z);
};


#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "ACG.h"
#include "GPS.h"
#include "GYRO.h"
#include "MAGNET.h"
#include "FastAverage.h"
#include "VectorEditor.h"
#include "MeanFilterDouble.h"

class Rotaion
{
public:
	size_t entries;
	std::vector<_CRT_DOUBLE>roll;
	std::vector<_CRT_DOUBLE>pitch;
	std::vector<_CRT_DOUBLE>yaw;

	std::vector<_CRT_DOUBLE>time;
	std::vector<_CRT_DOUBLE>magx;
	std::vector<_CRT_DOUBLE>magy;
	std::vector<_CRT_DOUBLE>magz;
	std::vector<_CRT_DOUBLE>gyroP;
	std::vector<_CRT_DOUBLE>gyroR;
	std::vector<_CRT_DOUBLE>gyroY;
	std::vector<_CRT_DOUBLE>gyroSpeed;

	Rotaion(std::string path);

	~Rotaion();
private:
};


#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "ACG.h"
#include "GPS.h"
#include "Rotaion.h"

class Position
{
public:
	std::vector<_CRT_DOUBLE> xPosition;
	std::vector<_CRT_DOUBLE> yPosition;
	std::vector<_CRT_DOUBLE> zPosition;
	std::vector<_CRT_DOUBLE> time;
	Position(std::string filepath);
	//give pos recive distance of closest point
	~Position();
private:

};


#include "Position.h"

Position::Position(std::string filepath)
{
	std::vector<_CRT_DOUBLE> xCachePos;
	std::vector<_CRT_DOUBLE> yCachePos;
	std::vector<_CRT_DOUBLE> zCachePos;

	GPS gps(filepath);
	xCachePos.resize(gps.entries + 1);
	yCachePos.resize(gps.entries + 1);
	zCachePos.resize(gps.entries + 1);

	xPosition.resize(gps.entries + 1);
	yPosition.resize(gps.entries + 1);
	zPosition.resize(gps.entries + 1);

	for (size_t i = 0; i < gps.entries; i++)
	{
		xCachePos[i].x = gps.latitude[i].x;
		yCachePos[i].x = gps.longitude[i].x;
		zCachePos[i].x = gps.altitude[i].x;
	}

	for (size_t i = 0; i < gps.entries; i++)
	{
		
	}


	for (size_t i = 0; i < xPosition.size(); i++)
	{
		;
	}
}

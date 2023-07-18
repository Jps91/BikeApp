#include "GPS.h"

GPS::GPS(std::string filePath)
{
	//std::fstream inputFile{filePathNameCombined(&filePath, &fileName_m), std::ios::in};
	std::fstream inputFile{filePath + fileName_m, std::ios::in};
	if (!inputFile)
	{
		status = false;
	}
	char someData[256]{};
	while (inputFile.getline(someData, sizeof(someData)))
	{
		entries++;
	}
	inputFile.close();

	time.resize(entries + 1);
	latitude.resize(entries + 1);
	longitude.resize(entries + 1);
	altitude.resize(entries + 1);
	speed.resize(entries + 1);
	bearing.resize(entries + 1);
	horizontalAccuracy.resize(entries + 1);
	verticalAccuracy.resize(entries + 1);

	//inputFile.open(filePathNameCombined(&filePath, &fileName_m), std::ios::in);
	inputFile.open(filePath + fileName_m, std::ios::in);
	if (!inputFile)
	{
		status = false;
	}
	char value_time[64];
	char lat[64];
	char lon[64];
	char alt[64];
	char acc[64];
	char spee[64];
	char bear[64];
	char hacc[64];
	char vacc[64];
	char nothing[64];
	size_t i = 0;
	int retValue = 0;
	while (inputFile.getline(value_time, sizeof(value_time), ';')
		&& inputFile.getline(lat, sizeof(lat), ';')
		&& inputFile.getline(lon, sizeof(lon), ';')
		&& inputFile.getline(alt, sizeof(alt), ';')
		&& inputFile.getline(spee, sizeof(spee), ';')
		&& inputFile.getline(bear, sizeof(bear), ';')
		&& inputFile.getline(hacc, sizeof(hacc), ';')
		&& inputFile.getline(vacc, sizeof(vacc)))
	{
		if (i < entries)
		{
			retValue = _atodbl(&time[i], value_time);
			retValue = _atodbl(&latitude[i], lat);
			retValue = _atodbl(&longitude[i],lon);
			retValue = _atodbl(&altitude[i], alt);
			retValue = _atodbl(&speed[i],spee);
			retValue = _atodbl(&bearing[i],bear);
			retValue = _atodbl(&horizontalAccuracy[i], hacc);
			retValue = _atodbl(&verticalAccuracy[i], vacc);
		}
		i++;
	}
	inputFile.close();

}

GPS::~GPS()
{
}

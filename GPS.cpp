#include "GPS.h"

GPS::GPS()
{
	//std::fstream inputFile{filePathNameCombined(&filePath, &fileName_m), std::ios::in};
	std::fstream inputFile{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\GPS.csv", std::ios::in};
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
	accuracy.resize(entries + 1);
	speed.resize(entries + 1);
	bearing.resize(entries + 1);

	//inputFile.open(filePathNameCombined(&filePath, &fileName_m), std::ios::in);
	inputFile.open("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\GPS.csv", std::ios::in);
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
	char nothing[64];
	size_t i = 0;
	int retValue = 0;
	while (inputFile.getline(value_time, sizeof(value_time), ';')
		&& inputFile.getline(lat, sizeof(lat), ';')
		&& inputFile.getline(lon, sizeof(lon), ';')
		&& inputFile.getline(alt, sizeof(alt), ';')
		&& inputFile.getline(acc, sizeof(acc), ';')
		&& inputFile.getline(spee, sizeof(spee), ';')
		&& inputFile.getline(bear, sizeof(bear),';')
		&&inputFile.getline(nothing,sizeof(nothing)))
	{
		if (i < entries)
		{
			time[i] = atoll(value_time)*pow(10,6);
			latitude[i] = atof(lat);
			longitude[i] = atof(lon);
			retValue = _atodbl(&altitude[i],alt);
			accuracy[i] = atof(acc);
			speed[i] = atof(spee);
			bearing[i] = atof(bear);
		}
		i++;
	}
	inputFile.close();

}

GPS::~GPS()
{
}

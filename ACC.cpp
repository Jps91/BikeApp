#include "ACC.h"

ACC::ACC(std::string filePath)
{
	//std::fstream inputFile{filePathNameCombined(&filePath, &fileName_m), std::ios::in};
	std::fstream inputFile{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC.csv", std::ios::in};
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

	time.resize(entries+1);
	x.resize(entries+1);
	y.resize(entries+1);
	z.resize(entries+1);

	//inputFile.open(filePathNameCombined(&filePath, &fileName_m), std::ios::in);
	inputFile.open("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC.csv", std::ios::in);
	if (!inputFile)
	{
		status = false;
	}
	char value_time[64];
	char value_x[64];
	char value_y[64];
	char value_z[64];
	char nothing[64];
	size_t i = 0;
	int retValue = 0;
	while (inputFile.getline(value_time, sizeof(value_time), ';')
		&&inputFile.getline(nothing, sizeof(nothing), ';')
		&& inputFile.getline(value_x, sizeof(value_x), ';')
		&& inputFile.getline(value_y, sizeof(value_y), ';')
		&& inputFile.getline(value_z, sizeof(value_z),';')
		&& inputFile.getline(nothing, sizeof(nothing)))
	{
		if (i < entries)
		{
			time[i] = atoll(value_time);
			retValue = _atodbl(&x[i], value_x);
			retValue = _atodbl(&y[i], value_y);
			retValue = _atodbl(&y[i], value_z);
		}
		i++;
	}
	inputFile.close();


}

bool ACC::isGood()
{
	return status;
}

int ACC::getLine(long long* time_nano_seconds, double* x, double* y, double* z)
{
	//currentTime = time_nano;
	return 0;
}

ACC::~ACC()
{
}

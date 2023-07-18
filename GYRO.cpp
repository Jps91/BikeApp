#include "GYRO.h"

GYRO::GYRO(std::string filePath)
{
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
	x.resize(entries + 1);
	y.resize(entries + 1);
	z.resize(entries + 1);

	//inputFile.open(filePathNameCombined(&filePath, &fileName_m), std::ios::in);
	inputFile.open(filePath + fileName_m, std::ios::in);
	if (!inputFile)
	{
		status = false;
	}
	char value_time[64];
	char value_x[64];
	char value_y[64];
	char value_z[64];
	size_t i = 0;
	int retValue = 0;
	while (inputFile.getline(value_time, sizeof(value_time), ';')
		&& inputFile.getline(value_x, sizeof(value_x), ';')
		&& inputFile.getline(value_y, sizeof(value_y), ';')
		&& inputFile.getline(value_z, sizeof(value_z)))
	{
		if (i < entries)
		{
			retValue = _atodbl(&time[i], value_time);
			retValue = _atodbl(&x[i], value_x);
			retValue = _atodbl(&y[i], value_y);
			retValue = _atodbl(&z[i], value_z);
		}
		i++;
	}
	inputFile.close();
}

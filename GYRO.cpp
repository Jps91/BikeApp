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
	while (inputFile.getline(value_time, sizeof(value_time), '	')
		&& inputFile.getline(value_x, sizeof(value_x), '	')
		&& inputFile.getline(value_y, sizeof(value_y), '	')
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

void GYRO::positon()
{
	xp.resize(entries + 1);
	yp.resize(entries + 1);
	zp.resize(entries + 1);

	for (size_t i = 0; i < entries - 1; i++)
	{
		xp[i].x = (((x[i + 1].x * 180) / 3.14159265358979323846264338327950288419716939937510)) * (time[i + 1].x - time[i].x) + xp[i].x;
		if (xp[i].x < 0)
		{
			xp[i].x += 360;
		}
		yp[i].x = (((y[i + 1].x * 180) / 3.14159265358979323846264338327950288419716939937510)) * (time[i + 1].x - time[i].x) + yp[i].x;
		if (yp[i].x < 0)
		{
			yp[i].x += 360;
		}
		zp[i].x = (((z[i + 1].x * 180) / 3.14159265358979323846264338327950288419716939937510)) * (time[i + 1].x - time[i].x) + z[i].x;
		if (zp[i].x < 0)
		{
			zp[i].x += 360;
		}
	}

}

void GYRO::store()
{
	std::fstream file{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\GYRO_Log.csv", std::ios::trunc | std::ios::out};
	int loadingbar = round(static_cast<float>(entries) / 100);
	for (size_t i = 0; i < entries - 1; i++)
	{
		file << time[i].x << "	" << xp[i].x << " " << yp[i].x << " " << zp[i].x << std::endl;


		if (i % loadingbar == 0)
		{
			system("CLS");
			std::cout << "Saving GYRO_log.csv File: " << 100 * static_cast<float>(i) / entries << "%";
		}
	}
	file.close();
}

GYRO::~GYRO()
{
}

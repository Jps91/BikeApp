#include "GYRO.h"

GYRO::GYRO(std::string filePath, double xAngle, double yAngle, double zAngel)
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

void GYRO::rotation()
{
	yaw.resize(entries + 1);
	pitch.resize(entries + 1);
	roll.resize(entries + 1);

	for (size_t i = 1; i < entries ; i++)
	{
		pitch[i].x = x[i ].x * (time[i ].x - time[i-1].x) + pitch[i-1].x;
		if (pitch[i].x < 0)
		{
			pitch[i].x += (2 * pi);
		}
		if (pitch[i].x > 2 * pi)
		{
			pitch[i].x = pitch[i].x - (2 * pi);
		}

		roll[i].x = y[i].x * (time[i].x - time[i-1].x) + roll[i-1].x;
		if (roll[i].x < 0)
		{
			roll[i].x += (2 * pi);
		}
		if (roll[i].x > (2 * pi))
		{
			roll[i].x = roll[i].x - (2 * pi);
		}

		yaw[i].x = z[i].x * (time[i].x - time[i-1].x) + yaw[i-1].x;
		if (yaw[i].x < 0)
		{
			yaw[i].x += (2 * pi);
		}
		if (yaw[i].x > (2 * pi))
		{
			yaw[i].x = yaw[i].x - (2 * pi);
		}
	}

}

void GYRO::store()
{
	std::fstream file{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\GYRO_Log.csv", std::ios::trunc | std::ios::out};
	int loadingbar = round(static_cast<float>(entries) / 100);
	for (size_t i = 0; i < entries - 1; i++)
	{
		file << time[i].x << "	" << pitch[i].x << " " << roll[i].x << " " << yaw[i].x << std::endl;


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

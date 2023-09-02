#include "Rotaion.h"

Rotaion::Rotaion(std::string path)
{
	/*	Do it simple:
	* 1:Mount device paralell to refplane and postion north
	* 2:wait a few sec
	*/
	MAGNET mag(path);
	GYRO gyro(path, 0, 0, 0);

	size_t maxSize = mag.entries + gyro.entries;
	time.resize(maxSize + 1);
	if (mag.time[0].x < gyro.time[0].x)
	{
		time[0].x = mag.time[0].x;
	}
	else
	{
		time[0].x = gyro.time[0].x;
	}
	size_t magPointer = 0;
	size_t gyroPointer = 0;
	size_t finaleI = 0;
	for (size_t i = 1; i < time.size() - 1; i++)
	{
		if (mag.time[magPointer].x < gyro.time[gyroPointer].x)
		{
			time[i].x = mag.time[magPointer].x;
			magPointer++;
			if (magPointer >= mag.entries - 1)
			{
				finaleI = i;
				break;
			}
		}
		else
		{
			time[i].x = gyro.time[gyroPointer].x;
			gyroPointer++;
			if (gyroPointer >= gyro.entries - 1)
			{
				finaleI = i;
				break;
			}
		}
	}
	magx.resize(mag.entries + gyro.entries);
	magy.resize(mag.entries + gyro.entries);
	magz.resize(mag.entries + gyro.entries);
	gyroP.resize(mag.entries + gyro.entries);
	gyroR.resize(mag.entries + gyro.entries);
	gyroY.resize(mag.entries + gyro.entries);
	gyroSpeed.resize(mag.entries + gyro.entries);
	for (size_t j = 0; j < time.size(); j++);
	{
		magx[j].x = mag.x[indexAtTime(mag.time, time[j].x)].x;
		magy[j].x = mag.y[indexAtTime(mag.time, time[j].x)].x;
		magz[j].x = mag.z[indexAtTime(mag.time, time[j].x)].x;

		gyroR[j].x = gyro.roll[indexAtTime(gyro.time, time[j].x)].x;
		gyroP[j].x = gyro.pitch[indexAtTime(gyro.time, time[j].x)].x;
		gyroY[j].x = gyro.yaw[indexAtTime(gyro.time, time[j].x)].x;
	}


	std::fstream file{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\Rotation.csv", std::ios::trunc | std::ios::trunc | std::ios::out};
	int loadingbar = round(static_cast<float>(time.size()) / 100);
	for (size_t i = 0; i < time.size() - 1; i++)
	{
		file << time[i].x << magx[i].x << gyroP[i].x << std::endl;


		if (i % loadingbar == 0)
		{
			system("CLS");
			std::cout << "Saving Rotation.csv File: " << 100 * static_cast<float>(i) / entries << "%";
		}
	}
	file.close();


}

Rotaion::~Rotaion()
{
}

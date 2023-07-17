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

	time.resize(entries + 1);
	ax.resize(entries + 1);
	ay.resize(entries + 1);
	az.resize(entries + 1);
	a.resize(entries + 1);

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
		&& inputFile.getline(nothing, sizeof(nothing), ';')
		&& inputFile.getline(value_x, sizeof(value_x), ';')
		&& inputFile.getline(value_y, sizeof(value_y), ';')
		&& inputFile.getline(value_z, sizeof(value_z), ';')
		&& inputFile.getline(nothing, sizeof(nothing)))
	{
		if (i < entries)
		{
			time[i] = atoll(value_time);
			retValue = _atodbl(&ax[i], value_x);
			retValue = _atodbl(&ay[i], value_y);
			retValue = _atodbl(&ay[i], value_z);
			a[i].x = ax[i].x + ay[i].x + az[i].x;
		}
		i++;
	}
	inputFile.close();


	speed();

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

void ACC::speed()
{
	vx.resize(time.size() + 1);
	vy.resize(time.size() + 1);
	vz.resize(time.size() + 1);
	v.resize(time.size() + 1);

	for (size_t i = 0; i < time.size() - 1; i++)
	{
		vx[i + 1].x = vx[i].x + ((ax[i].x + ax[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vy[i + 1].x = vy[i].x + ((ay[i].x + ay[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vz[i + 1].x = vz[i].x + ((az[i].x + az[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		v[i + 1].x = vx[i + 1].x + vy[i + 1].x + vz[i + 1].x;
	}
}




ACC::~ACC()
{
}

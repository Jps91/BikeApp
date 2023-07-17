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
	agx.resize(entries + 1);
	agy.resize(entries + 1);
	agz.resize(entries + 1);
	ag.resize(entries + 1);

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
			retValue = _atodbl(&agx[i], value_x);
			retValue = _atodbl(&agy[i], value_y);
			retValue = _atodbl(&agy[i], value_z);
			ag[i].x = agx[i].x + agy[i].x + agz[i].x;
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
	vgx.resize(time.size() + 1);
	vgy.resize(time.size() + 1);
	vgz.resize(time.size() + 1);
	vg.resize(time.size() + 1);

	for (size_t i = 0; i < time.size() - 1; i++)
	{
		vgx[i + 1].x = vgx[i].x + ((agx[i].x + agx[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vgy[i + 1].x = vgy[i].x + ((agy[i].x + agy[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vgz[i + 1].x = vgz[i].x + ((agz[i].x + agz[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vg[i + 1].x = vgx[i + 1].x + vgy[i + 1].x + vgz[i + 1].x;
	}
}



ACC::~ACC()
{
}

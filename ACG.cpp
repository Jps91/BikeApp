#include "ACG.h"

ACG::ACG(std::string filePath)
{
	//std::fstream inputFile{filePathNameCombined(&filePath, &fileName_m), std::ios::in};
	std::fstream inputFile{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG.csv", std::ios::in};
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
	inputFile.open("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG.csv", std::ios::in);
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
			retValue = _atodbl(&az[i], value_z);
			a[i].x = ax[i].x + ay[i].x + az[i].x;
		}
		i++;
	}
	inputFile.close();


	betterspeed();
	position();
}

bool ACG::isGood()
{
	return status;
}

int ACG::getLine(long long* time_nano_seconds, double* x, double* y, double* z)
{
	//currentTime = time_nano;
	return 0;
}

void ACG::betterspeed()
{
	//To Do fix Gravity


	vx.resize(entries + 1);
	vy.resize(entries + 1);
	vz.resize(entries + 1);
	v.resize(entries + 1);

	for (size_t i = 0; i < entries - 1; i++)
	{
		vx[i + 1].x = vx[i].x + ((ax[i].x + ax[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vy[i + 1].x = vy[i].x + ((ay[i].x + ay[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vz[i + 1].x = vz[i].x + ((az[i].x + az[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		v[i + 1].x = sqrt(pow(vx[i + 1].x, 2) + pow(vy[i + 1].x, 2) + pow(vz[i + 1].x, 2));
	}
}

void ACG::speed()
{
	vx.resize(entries + 1);
	vy.resize(entries + 1);
	vz.resize(entries + 1);
	v.resize(entries + 1);

	for (size_t i = 0; i < entries - 1; i++)
	{
		vx[i + 1].x = vx[i].x + ((ax[i].x + ax[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vy[i + 1].x = vy[i].x + ((ay[i].x + ay[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		vz[i + 1].x = vz[i].x + ((az[i].x + az[i + 1].x) / 2) * ((time[i + 1] - time[i]) / (pow(10, 9)));
		v[i + 1].x = sqrt(pow(vx[i + 1].x, 2) + pow(vy[i + 1].x, 2) + pow(vz[i + 1].x, 2));
	}
}

void ACG::position()
{
	px.resize(time.size() + 1);
	py.resize(time.size() + 1);
	pz.resize(time.size() + 1);
	p.resize(time.size() + 1);

	for (size_t i = 0; i < time.size() - 1; i++)
	{
		px[i + 1].x = px[i].x + (static_cast<double>(1) / 4) * (ax[i + 1].x - ax[i].x) * pow((time[i + 1] - time[i]) / (pow(10, 9)), 2);
		py[i + 1].x = py[i].x + (static_cast<double>(1) / 4) * (ay[i + 1].x - ax[i].x) * pow((time[i + 1] - time[i]) / (pow(10, 9)), 2);
		pz[i + 1].x = pz[i].x + (static_cast<double>(1) / 4) * (az[i + 1].x - ax[i].x) * pow((time[i + 1] - time[i]) / (pow(10, 9)), 2);
		p[i + 1].x = abs(px[i + 1].x) + abs(py[i + 1].x) + abs(pz[i + 1].x);


		/*
		px[i + 1].x = px[i].x + (static_cast<double>(1) / 4) * (ax[i + 1].x - ax[i].x) * pow((time[i + 1] - time[i]) / (pow(10, 9)), 2);
		py[i + 1].x = py[i].x + (static_cast<double>(1) / 4) * (ay[i + 1].x - ax[i].x) * pow((time[i + 1] - time[i]) / (pow(10, 9)), 2);
		pz[i + 1].x = pz[i].x + (static_cast<double>(1) / 4) * (az[i + 1].x - ax[i].x) * pow((time[i + 1] - time[i]) / (pow(10, 9)), 2);
		p[i + 1].x = px[i + 1].x + py[i + 1].x + pz[i + 1].x;
		*/
	}
}



ACG::~ACG()
{
	std::fstream file{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG_Log.csv", std::ios::trunc | std::ios::out};
	int loadingbar = round(static_cast<float>(entries) / 100);
	for (size_t i = 0; i < entries; i++)
	{
		file << time[i] << " " << vx[i].x << " " << vy[i].x << " " << vz[i].x << std::endl;
		if (i % loadingbar == 0)
		{
			system("CLS");
			std::cout << "Saving ACG_log.csv File: " << 100 * static_cast<float>(i) / entries << "%";
		}
		/*
		file << vx[i].x <<"," << vy[i].x << "," << vz[i].x << "," << v[i].x << ","
			<< px[i].x << "," << py[i].x << "," << pz[i].x << "," << p[i].x << std::endl;*/
	}
	file.close();
}

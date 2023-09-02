#include "ACG.h"

ACG::ACG(std::string filePath)
{
	//std::fstream inputFile{filePathNameCombined(&filePath, &fileName_m), std::ios::in};
	std::fstream inputFile{filePath + fileName_m, std::ios::in};
	if (!inputFile)
	{
		std::cout << "Could not open File:" << filePath + fileName_m << std::endl;
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
			retValue = _atodbl(&ax[i], value_x);
			retValue = _atodbl(&ay[i], value_y);
			retValue = _atodbl(&az[i], value_z);
			a[i].x = ax[i].x + ay[i].x + az[i].x;
		}
		i++;
	}
	inputFile.close();

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

void ACG::store()
{
	std::fstream file{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG_Log.csv", std::ios::trunc | std::ios::out};
	int loadingbar = round(static_cast<float>(entries) / 100);
	for (size_t i = 0; i < entries; i++)
	{
		file << time[i].x << " " << axNorthg[i].x << " " << ayEastg[i].x << " " << azDowng[i].x<<" ";
		file << time[i].x << " " << ax[i].x << " " << ay[i].x << " " << az[i].x << std::endl;
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

void ACG::betterspeed()
{
	//To Do fix Gravity


	vx.resize(entries + 1);
	vy.resize(entries + 1);
	vz.resize(entries + 1);
	v.resize(entries + 1);

	for (size_t i = 0; i < entries - 1; i++)
	{
		vx[i + 1].x = vx[i].x + ((ax[i].x + ax[i + 1].x) / 2) * ((time[i + 1].x - time[i].x));
		vy[i + 1].x = vy[i].x + ((ay[i].x + ay[i + 1].x) / 2) * ((time[i + 1].x - time[i].x));
		vz[i + 1].x = vz[i].x + ((az[i].x + az[i + 1].x) / 2) * ((time[i + 1].x - time[i].x));
		v[i + 1].x = sqrt(pow(vx[i + 1].x, 2) + pow(vy[i + 1].x, 2) + pow(vz[i + 1].x, 2));
	}
}


void ACG::gravityFix(std::vector<_CRT_DOUBLE>& yaw, std::vector<_CRT_DOUBLE>& pitch, std::vector<_CRT_DOUBLE>& roll)
{
	axNorthg.resize(entries + 1);
	ayEastg.resize(entries + 1);
	azDowng.resize(entries + 1);
	for (size_t i = 0; i < entries; i++)
	{
		double cosa = std::cos((yaw[i * (yaw.size() / entries)].x * 0.01745));	//0.01745 = deg to rad const
		double sina = std::sin((yaw[i * (yaw.size() / entries)].x * 0.01745));
		double cosb = std::cos((pitch[i * (yaw.size() / entries)].x * 0.01745));
		double sinb = std::sin((pitch[i * (yaw.size() / entries)].x * 0.01745));
		double cosc = std::cos((roll[i * (yaw.size() / entries)].x * 0.01745));
		double sinc = std::sin((roll[i * (yaw.size() / entries)].x * 0.01745));
		double Axx = cosa * cosb;
		double Axy = cosa * sinb * sinc - sina * cosc;
		double Axz = cosa * sinb * cosc + sina * sinc;
		double Ayx = sina * cosb;
		double Ayy = sina * sinb * sinc + cosa * cosc;
		double Ayz = sina * sinb * cosc - cosa * sinc;
		double Azx = -sinb;
		double Azy = cosb * sinc;
		double Azz = cosb * cosc;
		double px = 0;
		double py = 0;
		double pz = 9.81;
		/*axNorthg[i].x = ax[i].x - abs(Axx * px + Axy * py + Axz * pz);
		ayEastg[i].x = ay[i].x - abs(Ayx * px + Ayy * py + Ayz * pz);
		azDowng[i].x = az[i].x - abs(Azx * px + Azy * py + Azz * pz);
		*/
		/*
		const double g = 9.81;
		axNorthg[i].x = g * -sin((yaw[i].x * 0.01745));
		ayEastg[i].x = g * cos((yaw[i].x * 0.01745)) * sin((pitch[i].x * 0.01745));
		az[i].x=g*
		*/
		//g:
		double g[3];
		//g[0] = sin((yaw[i * (yaw.size() / entries)].x * 0.01745)) * cos((pitch[i * (yaw.size() / entries)].x * 0.01745)) * 9.81;
		g[0] = sin((yaw[i * (yaw.size() / entries)].x * 0.01745)) * cos((pitch[i * (yaw.size() / entries)].x * 0.01745)) * 9.81;
		//g[1] = sin((yaw[i * (yaw.size() / entries)].x * 0.01745)) * sin((pitch[i * (yaw.size() / entries)].x * 0.01745)) * 9.81;
		g[1] = sin((yaw[i * (yaw.size() / entries)].x * 0.01745)) * sin((pitch[i * (yaw.size() / entries)].x * 0.01745)) * 9.81;
		//g[2] = cos((yaw[i * (yaw.size() / entries)].x * 0.01745)) * 9.81;
		g[2] = cos((yaw[i * (yaw.size() / entries)].x * 0.01745)) * 9.81;
		axNorthg[i].x = ax[i].x - g[0];
		ayEastg[i].x = ay[i].x - g[1];
		azDowng[i].x = az[i].x - g[2];
		
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
		vx[i + 1].x = vx[i].x + ((ax[i].x + ax[i + 1].x) / 2) * ((time[i + 1].x - time[i].x) / (pow(10, 9)));
		vy[i + 1].x = vy[i].x + ((ay[i].x + ay[i + 1].x) / 2) * ((time[i + 1].x - time[i].x) / (pow(10, 9)));
		vz[i + 1].x = vz[i].x + ((az[i].x + az[i + 1].x) / 2) * ((time[i + 1].x - time[i].x) / (pow(10, 9)));
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
		px[i + 1].x = px[i].x + (static_cast<double>(1) / 4) * (ax[i + 1].x - ax[i].x) * pow((time[i + 1].x - time[i].x) / (pow(10, 9)), 2);
		py[i + 1].x = py[i].x + (static_cast<double>(1) / 4) * (ay[i + 1].x - ax[i].x) * pow((time[i + 1].x - time[i].x) / (pow(10, 9)), 2);
		pz[i + 1].x = pz[i].x + (static_cast<double>(1) / 4) * (az[i + 1].x - ax[i].x) * pow((time[i + 1].x - time[i].x) / (pow(10, 9)), 2);
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
	;
}

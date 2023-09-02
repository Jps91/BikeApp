#include "MAGNET.h"

MAGNET::MAGNET(std::string filePath)
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

void MAGNET::rotationToNoth()
{

	xAngle_Roll.resize(entries + 1);
	yAngle_Pitch.resize(entries + 1);
	zAngle_Yaw.resize(entries + 1);
	/*
	for (size_t i = 0; i < entries; i++)
	{
		xAngle[i].x = pow(sin((1 + x[i].x) / sqrtOf3WithPower(x[i],y[i],z[i]).x), -1);
		yAngle[i].x = pow(sin((1 + y[i].x) / sqrtOf3WithPower(x[i],y[i],z[i]).x), -1);
		zAngle[i].x = pow(sin((1 + z[i].x) / sqrtOf3WithPower(x[i],y[i],z[i]).x), -1);
	}*/

	//second Take:
	/*
	for (size_t i = 0; i < entries; i++)
	{
		xAngle[i].x = atan(x[i].x / (sqrt(pow(y[i].x, 2) + pow(z[i].x, 2))));
		yAngle[i].x = atan(y[i].x / (sqrt(pow(x[i].x, 2) + pow(z[i].x, 2))));
		zAngle[i].x = atan((sqrt(pow(x[i].x, 2) + pow(y[i].x, 2))) / z[i].x);

	}
	*/


	//third Take:
	for (size_t i = 0; i < entries; i++)
	{
		zAngle_Yaw[i].x = -1 * (atan2(yc[i].x, xc[i].x));
		/*if (zAngle_Yaw[i].x >(2 * pi))
		{
			zAngle_Yaw[i].x -= (2 * pi);
		}*/
		yAngle_Pitch[i].x = -1 * (atan2(zc[i].x, xc[i].x));
		/*if (yAngle_Pitch[i].x > (2 * pi))
		{
			yAngle_Pitch[i].x -= (2 * pi);
		}*/
		xAngle_Roll[i].x = -1 * (atan2(zc[i].x, yc[i].x));
		/*if (xAngle_Roll[i].x > (2 * pi))
		{
			xAngle_Roll[i].x -= (2 * pi);
		}*/
		//x=Roll
		//y=Pitch
		//	z=yaw
		//yAngle[i].x = atan2(y[i].x, z[i].x) * 180 / 3.14159265358979323846264338327950288419716939937510;
		//zAngle[i].x = atan2(z[i].x, x[i].x) * 180 / 3.14159265358979323846264338327950288419716939937510;

	}
}

void MAGNET::store()
{
	std::fstream file{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\MAGNET_Log.csv", std::ios::trunc | std::ios::out};
	int loadingbar = round(static_cast<float>(entries) / 100);
	//double a = 1;
	//double b = 1;
	//double c = 1;
	for (size_t i = 0; i < entries - 1; i++)
	{
		file << time[i].x << " " << x[i].x << " " << y[i].x << " " << z[i].x << " "
			<< xc[i].x << " " << yc[i].x << " " << zc[i].x << " "
			<< xAngle_Roll[i].x << " " << yAngle_Pitch[i].x << " " << zAngle_Yaw[i].x << std::endl;
		//file << time[i + 1].x << " " << xc[i + 1].x << " " << yc[i + 1].x << " " << zc[i + 1].x  << std::endl;


		if (i % loadingbar == 0)
		{
			system("CLS");
			std::cout << "Saving MAGNET_log.csv File: " << 100 * static_cast<float>(i) / entries << "%";
		}
		/*
		file << vx[i].x <<"," << vy[i].x << "," << vz[i].x << "," << v[i].x << ","
			<< px[i].x << "," << py[i].x << "," << pz[i].x << "," << p[i].x << std::endl;*/
	}
	file.close();
}



void MAGNET::calibrate()
{
	//Rotate in all posible direct



	//Hard Iron correction:y

	for (size_t i = 0; i < entries - 1; i++)
	{
		if (xlow.x > x[i + 1].x)
		{
			xlow.x = x[i + 1].x;
		}
		if (xhigh.x < x[i + 1].x)
		{
			xhigh.x = x[i + 1].x;
		}

		if (ylow.x > y[i + 1].x)
		{
			ylow.x = y[i + 1].x;
		}
		if (yhigh.x < y[i + 1].x)
		{
			yhigh.x = y[i + 1].x;
		}

		if (zlow.x > z[i + 1].x)
		{
			zlow.x = z[i + 1].x;
		}
		if (zhigh.x < z[i + 1].x)
		{
			zhigh.x = z[i + 1].x;
		}
	}

	xhio.x = (xlow.x + xhigh.x) / 2;
	yhio.x = (ylow.x + yhigh.x) / 2;
	zhio.x = (zlow.x + zhigh.x) / 2;

	for (size_t i = 0; i < entries; i++)
	{
		x[i].x -= xhio.x;
		y[i].x -= yhio.x;
		z[i].x -= zhio.x;
	}


	//Soft Iron Calib:
	elipsoidDistance.resize(entries + 1);
	for (size_t i = 0; i < entries - 1; i++)
	{
		elipsoidDistance[i] = sqrtOf3WithPower(x[i], y[i], z[i]);
	}
	_CRT_DOUBLE sum{};
	for (size_t i = 0; i < entries - 1; i++)
	{
		sum.x += elipsoidDistance[i].x;
	}
	avergaeDistance.x = sum.x / entries;

	xc.resize(entries + 1);
	yc.resize(entries + 1);
	zc.resize(entries + 1);
	for (size_t i = 0; i < entries - 1; i++)
	{
		xc[i].x = avergaeDistance.x * (1 / elipsoidDistance[i].x) * x[i].x;
		yc[i].x = avergaeDistance.x * (1 / elipsoidDistance[i].x) * y[i].x;
		zc[i].x = avergaeDistance.x * (1 / elipsoidDistance[i].x) * z[i].x;
	}
}





_CRT_DOUBLE MAGNET::sqrtOf3WithPower(_CRT_DOUBLE X, _CRT_DOUBLE Y, _CRT_DOUBLE Z)
{
	_CRT_DOUBLE result{};
	result.x = sqrt((pow(X.x, 2) + pow(Y.x, 2) + pow(Z.x, 2)));
	return result;
}

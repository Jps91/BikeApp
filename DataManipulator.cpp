#include "DataManipulator.h"

enum Sensor		////Order Depends on Vector dataSensorFileNames
{
	lineraAccelerometer,
	accelerometer,
	gravity,
	gyrometer,
	rotationVector,
	gps
};

DataManipulator::DataManipulator()
{
	//smth like: for each Sensor open corresponding File
	//never did for ech befor and enums
	lineraAccelerometer.open(lineraAccelerometerFileName);
	if (!lineraAccelerometer)
	{
		std::cout << "Could not open" << lineraAccelerometerFileName << std::endl;
	}
	accelerometer.open(accelerometerFileName);
	if (!accelerometer)
	{
		std::cout << "Could not open" << accelerometerFileName << std::endl;
	}
	gravity.open(gravityFileName);
	if (!gravity)
	{
		std::cout << "Could not open" << gravityFileName << std::endl;
	}
	gyrometer.open(gyrometerFileName);
	if (!gyrometer)
	{
		std::cout << "Could not open" << gyrometerFileName << std::endl;
	}
	rotationVector.open(rotationVectorFileName);
	if (!rotationVector)
	{
		std::cout << "Could not open" << rotationVectorFileName << std::endl;
	}
	gps.open(gpsFileName);
	if (!gps)
	{
		std::cout << "Could not open" << gpsFileName << std::endl;
	}

}

void DataManipulator::compress()
{

}


DataManipulator::~DataManipulator()
{
}

std::string DataManipulator::dirFilePathMerge(std::string FileName)
{
	return std::string(inputFolderName + FileName);
}

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class DataManipulator
{
public:
	DataManipulator();
	std::string inputFolderName;
	void compress();
	~DataManipulator();

private:



	std::fstream lineraAccelerometer{};
	std::string lineraAccelerometerFileName = "ACC.csv";

	std::fstream accelerometer{};
	std::string accelerometerFileName = "ACG.csv";

	std::fstream gravity{};
	std::string gravityFileName = "AGG.csv";

	std::fstream gyrometer{};
	std::string gyrometerFileName = "GYRO.csv";

	std::fstream rotationVector{};
	std::string rotationVectorFileName = "ROTATION.csv";

	std::fstream gps{};
	std::string gpsFileName = "GPS.csv";

	std::string dirFilePathMerge(std::string);
	std::string filePath;
};



/*
	* std::vector<std::string> dataSensorFileNames{ "ACC.csv", "ACG.csv", "AGG.csv", "AGG.csv", "GYRO.csv", "ROTATION.csv", "GPS.csv" };  //Order Depends on Enum Sensor
	std::vector<std::fstream> SensorList{lineraAccelerometer,}
	*/
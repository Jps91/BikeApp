// BikeApp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>>

#include <stdlib.h>
#include <stdio.h>

#include "ACC.h"
#include "ACG.h"

void extract()
{
	std::fstream inputFile{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC.csv", std::ios::in };
	if (!inputFile)
	{
		std::cerr << "could not open ACC.csv";
	}
	std::fstream outputFile{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC_OUT.csv", std::ios::trunc | std::ios::out};
	if (!outputFile)
	{
		std::cerr << "could not open OutputFile";
	}
	unsigned long t_Android = 0;
	unsigned long t_unix = 0;
	float x = 0;
	float y = 0;
	float z = 0;
	int a = 0;
	char notANumber[1] = {};
	while (inputFile.get(notANumber[0]))
	{
		if (notANumber[0] == ';')
		{
			outputFile << " ";
		}
		else if (notANumber[0] == '3')
		{
			;
		}
		else
		{

			outputFile << notANumber[0];
		}
	}
	outputFile.close();
	outputFile.open("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC_OUT.csv", std::ios::in);
	std::fstream result("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC_RESULT.csv", std::ios::trunc | std::ios::out);
	if (!outputFile)
	{
		std::cerr << "could not open OutputFile";
	}
	char part1[64] = {};
	char part2[64] = {};
	char values[64] = {};
	char lastValues[64] = {};
	outputFile.getline(part1, sizeof(part1));
	bool check = true;
	while (check)
	{
		if (outputFile.get(part1, ';'))
		{
			check = false;
		}
		if (outputFile.get(part2, ';'))
		{
			check = false;
		}
		if (outputFile.get(values, '\n'))
		{
			check = false;
		}
		if (values != lastValues)
		{
			result << part1 << " " << part2 << " " << values << "\n";
			for (size_t i = 0; i < sizeof(values); i++)
			{
				lastValues[i] = values[i];
				values[i] = { 0 };
			}
		}
	}
	result.close();
};

void stage2()
{
	std::fstream outputFile;
	outputFile.open("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG.csv", std::ios::in | std::ios::out);
	std::fstream result("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG_RESULT.csv", std::ios::trunc | std::ios::out | std::ios::in);
	if (!outputFile)
	{
		std::cerr << "could not open OutputFile";
	}
	long long nano = 0;
	long long timeSec = 0;
	_CRT_DOUBLE x;
	_CRT_DOUBLE y;
	_CRT_DOUBLE z;
	int mode = 0;


	char inputVlaue[32] = {};
	int returnValue = 0;
	while (!outputFile.eof())
	{
		outputFile.getline(inputVlaue, sizeof(inputVlaue), ';');
		nano = atoll(inputVlaue);
		outputFile.getline(inputVlaue, sizeof(inputVlaue), ';');
		timeSec = atoll(inputVlaue);
		outputFile.getline(inputVlaue, sizeof(inputVlaue), ';');
		returnValue = _atodbl(&x, inputVlaue);
		outputFile.getline(inputVlaue, sizeof(inputVlaue), ';');
		returnValue = _atodbl(&y, inputVlaue);
		outputFile.getline(inputVlaue, sizeof(inputVlaue), ';');
		returnValue = _atodbl(&z, inputVlaue);
		outputFile.getline(inputVlaue, sizeof(inputVlaue));
		mode = atoi(inputVlaue);
		result << nano << " " << x.x << " " << y.x << " " << z.x << std::endl;

	}
	result.close();
}

void gettimediff()
{
	std::ifstream  inputFile{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG_RESULT.csv", std::ios::in};
	if (!inputFile)
	{
		std::cerr << "Error" << std::endl;
	}
	std::ofstream outputFile{"C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACG_RESULT_TIMEDIFF.csv", std::ios::out | std::ios::trunc};
	long long nano = 0;
	long long nanoOld = 0;
	long long timeSec = 0;
	_CRT_DOUBLE x{};
	_CRT_DOUBLE xOld{};
	_CRT_DOUBLE y{};
	_CRT_DOUBLE yOld{};
	_CRT_DOUBLE z{};
	_CRT_DOUBLE zOld{};
	int mode = 0;


	char inputVlaue[32] = {};
	int returnValue = 0;
	while (!inputFile.eof())
	{
		inputFile.getline(inputVlaue, sizeof(inputVlaue), ' ');
		nano = atoll(inputVlaue);
		/*inputFile.getline(inputVlaue, sizeof(inputVlaue), ' ');
		timeSec = atoll(inputVlaue);*/
		inputFile.getline(inputVlaue, sizeof(inputVlaue), ' ');
		returnValue = _atodbl(&x, inputVlaue);
		inputFile.getline(inputVlaue, sizeof(inputVlaue), ' ');
		returnValue = _atodbl(&y, inputVlaue);
		inputFile.getline(inputVlaue, sizeof(inputVlaue), ' ');
		returnValue = _atodbl(&z, inputVlaue);
		inputFile.getline(inputVlaue, sizeof(inputVlaue));
		mode = atoi(inputVlaue);

		if (x.x != xOld.x || y.x != yOld.x || z.x != zOld.x)
		{
			outputFile << nanoOld << " " << xOld.x << " " << yOld.x << " " << zOld.x << std::endl;
			outputFile << nano << " " << x.x << " " << y.x << " " << z.x << std::endl;
			xOld = x;
			yOld = y;
			zOld = z;
		}
		nanoOld = nano;
	}
	outputFile.close();

}


int main()
{
	//extract();
	//stage2();
	//gettimediff();
	ACC acc("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\");
	ACG acg("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\");
	if (!acg.isGood())
	{
		std::cerr << "AUA";
	}
	std::cout << acg.entries << std::endl;
	int loadingbaracg = round(static_cast<float>(acg.entries) / 100);
	for (size_t i = 0; i < acg.entries; i++)
	{
		if (i % loadingbaracg == 0)
		{
			system("CLS");
			std::cout << "Loading ACG: " << 100 * static_cast<float>(i) / acg.entries << "%";
		}
		//std::cout << ac.p[i].x << std::endl;		
		//std::cout << acg.v[i].x << std::endl;		
	}
	/*
	if (!acc.isGood())
	{
		std::cerr << "AUA";
	}
	std::cout << acc.entries << std::endl;
	int loadingbaracc = round(static_cast<float>(acc.entries) / 100);
	for (size_t i = 0; i < acc.entries; i++)
	{
		if (i % loadingbaracc == 0)
		{
			system("CLS");
			std::cout << "Loading ACC: " << 100 * static_cast<float>(i) / acc.entries << "%";
		}
		//std::cout << ac.p[i].x << std::endl;		
		//std::cout << acg.v[i].x << std::endl;		
	}
	*/
}


// BikeApp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>>

#include <stdlib.h>
#include <stdio.h>




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
	outputFile.open("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC_OUT.csv", std::ios::in|std::ios::out);
	std::fstream result("C:\\1_Jan\\DataServerClient\\Projekte\\BikeApp\\SensorBox\\ENDLESS_23_06_2023_16_27_03\\ACC_RESULT.csv", std::ios::trunc | std::ios::out| std::ios::in);
	if (!outputFile)
	{
		std::cerr << "could not open OutputFile";
	}
	long long nano = 0;
	 long long timeSec = 0;
	_CRT_DOUBLE x;
	_CRT_DOUBLE y ;
	_CRT_DOUBLE z ;
	int mode = 0;
	char nothing1[1]={};
	char nothing2[2]={};
	char nothing3[2]={};
	char nothing4[2]={};
	char nothing5[2]={};
	char nothing6[2] = {};

	char inputVlaue[32] = {};
	int returnValue = 0;
	while (!outputFile.eof())
	{
		outputFile.getline(inputVlaue,sizeof(inputVlaue),' ');
		nano = atoll(inputVlaue);
		outputFile.getline(inputVlaue,sizeof(inputVlaue),' ');
		timeSec= atoll(inputVlaue);
		outputFile.getline(inputVlaue,sizeof(inputVlaue),' ');
		returnValue = _atodbl(&x,inputVlaue);
		outputFile.getline(inputVlaue,sizeof(inputVlaue),' ');
		returnValue = _atodbl(&y, inputVlaue);
		outputFile.getline(inputVlaue,sizeof(inputVlaue),' ');
		returnValue = _atodbl(&z, inputVlaue);
		outputFile.getline(inputVlaue, sizeof(inputVlaue));
		mode = atoi(inputVlaue);
		result << nano << " " << timeSec << " " << x.x << " " << y.x << " " << z.x << std::endl;

	}
	result.close();
}




int main()
{
	//extract();
	stage2();
}


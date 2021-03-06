/**
* Name: Algorytm
* Purpose: Problem plecakowy
*
* @author Kamil Krzysztof Lipski
* @version 2.2
*/

#include "pch.h"
#include <chrono>

std::vector <int> Interface::processOptions(char* argVal[])
{	
	std::vector <int> options;

	if (charToInt(argVal[1], 2) == 1)
	{
		options.push_back(1);
	}

	else if (charToInt(argVal[1], 2) == 2)
	{
		options.push_back(2);
		options.push_back(charToInt(argVal[2], 2));
		options.push_back(charToInt(argVal[3], 3));
		options.push_back(charToInt(argVal[4], 2));
	}

	else if (charToInt(argVal[1], 2) == 3)
	{
		options.push_back(3);
		options.push_back(charToInt(argVal[2], 2));
		options.push_back(charToInt(argVal[3], 3));
		options.push_back(charToInt(argVal[4], 2));
		options.push_back(charToInt(argVal[5], 2));
		options.push_back(charToInt(argVal[6], 5));
		options.push_back(charToInt(argVal[7], 2));
	}

	else if (charToInt(argVal[1], 2) == 5964)
	{
		options.push_back(0);
	}

	else
	{
		puts("Wrong command! Check readme for help.\n");
		options.push_back(-1);
	}

	return options;
}

void Interface::selectMode(std::vector <int> startOptions)
{

	if (startOptions[0] == 1)
	{
		dataCollection fileData(1);
		Algorithm::bucketCounting(fileData);
		auto m = Algorithm::knapsackProblem(fileData);
		Algorithm::printSolution(fileData, m);
	}

	else if (startOptions[0] == 2)
	{
		dataCollection genData = Generator::generateData(startOptions[1], startOptions[2], startOptions[3]);
		genData.showGenData();
		Algorithm::bucketCounting(genData);
		auto m = Algorithm::knapsackProblem(genData);
		Algorithm::printSolution(genData, m);
	}

	else if (startOptions[0] == 3)
	{
		std::cout << " Algorytm z asymptota O(T(n)) " << std::endl;
		std::cout << "     n    " << " t(n)[ms] " << "   q(n)   " << std::endl;
		double complexity, complexityMedian;
		int counterForMedian = 0, median = 0;
		int count = startOptions[1];
		int maxVol = startOptions[2];
		int bound = startOptions[3];
		int numOfProblems = startOptions[4];
		int step = startOptions[5];
		int numOfInstances = startOptions[6];

		std::vector <dataCollection> genData;

		// median

		median = ((2 * count) + ((numOfProblems - 1) * step)) / 2;
		
		for (int i = 0; i < numOfInstances; i++) genData.push_back(Generator::generateData(median, maxVol, bound));

		auto timeStart = std::chrono::steady_clock::now();

		for (int j = 0; j < numOfInstances; j++)
		{
			Algorithm::bucketCounting(genData[j]);
			Algorithm::knapsackProblem(genData[j]);
		}

		auto timeEnd = std::chrono::steady_clock::now();
		auto measuredTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
		auto timeMedian = measuredTime;

		complexityMedian = median * maxVol;

		// /median

		for (int i = 1; i <= (numOfProblems / 2); i++)
		{
			for (int j = 0; j < numOfInstances; j++) genData[j] = Generator::generateData(count, maxVol, bound);

			timeStart = std::chrono::steady_clock::now();

			for (int k = 0; k < numOfInstances; k++)
			{
				Algorithm::bucketCounting(genData[k]);
				Algorithm::knapsackProblem(genData[k]);
			}

			timeEnd = std::chrono::steady_clock::now();
			auto measuredTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();

			complexity = count * maxVol;
			std::cout.width(9);
			std::cout << count << " "; 
			std::cout.width(9);
			std::cout << (measuredTime / numOfInstances) << " ";
			std::cout.width(9);
			std::cout << ((measuredTime * complexityMedian) / (complexity * timeMedian)) << " " << std::endl;
			count += step;
		}

		// median

		std::cout.width(9);
		std::cout << median << " ";
		std::cout.width(9);
		std::cout << (timeMedian / numOfInstances) << " ";
		std::cout.width(9);
		std::cout << 1.0 << " " << std::endl;

		if (numOfProblems % 1 == 1) count += step;

		// /median

		for (int i = 1; i <= (numOfProblems / 2); i++)
		{
			for (int j = 0; j < numOfInstances; j++) genData[j] = Generator::generateData(count, maxVol, bound);

			timeStart = std::chrono::steady_clock::now();

			for (int k = 0; k < numOfInstances; k++)
			{
				Algorithm::bucketCounting(genData[k]);
				Algorithm::knapsackProblem(genData[k]);
			}

			timeEnd = std::chrono::steady_clock::now();
			auto measuredTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();

			complexity = count * maxVol;
			std::cout.width(9);
			std::cout << count << " ";
			std::cout.width(9);
			std::cout << (measuredTime / numOfInstances) << " ";
			std::cout.width(9);
			std::cout << ((measuredTime * complexityMedian) / (complexity * timeMedian)) << " " << std::endl;
			count += step;
		}
	}

	else if (startOptions[0] == 0)
	{
		puts("If you need help with using the programme, please consider reading the attached readme file.\n");
	}

	else
	{
		return;
	}
}

int Interface::charToInt(char stringToConvert[], int charsToSkip)
{
	int digitsNum = 0, retVal = 0, pos = charsToSkip, digit = 0;

	while (stringToConvert[pos])
	{
		pos++;
		digitsNum++;
	}

	pos--;

	for (int i = digitsNum; i > 0; i--)
	{
		digit = (int)(stringToConvert[pos] - '0');
		for (int j = digitsNum - i; j > 0; j--)
		{
			digit *= 10;
		}
		retVal += digit;
		pos--;
	}

	return retVal;
}
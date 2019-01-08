/**
* Name: Algorytm
* Purpose: Problem plecakowy
*
* @author Kamil Krzysztof Lipski
* @version 2.2
*/

#include "pch.h"
#include <algorithm>

dataCollection::dataCollection(int mode)
{
	values.push_back(0);
	volumes.push_back(0);

	if (mode == 1)
	{
		std::cin >> count;
		std::cin >> maxVol;
		std::cin >> bound;

		int tmp = 0;

		for (int i = 1; i <= count; i++)
		{
			std::cin >> tmp;
			volumes.push_back(tmp);
			std::cin >> tmp;
			values.push_back(tmp);
		}
	}
}

dataCollection & dataCollection::operator=(const dataCollection & copiedData)
{
	bound = copiedData.bound;
	count = copiedData.count;
	maxVol = copiedData.maxVol;
	volumes.clear();
	values.clear();
	volumes = copiedData.volumes;
	values = copiedData.values;
	return *this;
}

void dataCollection::showGenData()
{
	std::cout << "Generated objects:" << std::endl;
	for (int i = 1; i <= count; i++)
	{
		std::cout << i << ".: volume: " << volumes[i] << ", value: " << values[i] << std::endl;
	}
}

void Algorithm::bucketCounting(dataCollection & dataToProcess)
{
	std::vector < std::vector < int > > valVol((*(std::max_element(dataToProcess.values.begin(), dataToProcess.values.end())) + 1), std::vector <int>((*(std::max_element(dataToProcess.volumes.begin(), dataToProcess.volumes.end()))) + 1));
	for (int i = 1; i <= dataToProcess.count; i++)
	{
		valVol[dataToProcess.values[i]][dataToProcess.volumes[i]] += 1;
		if (valVol[dataToProcess.values[i]][dataToProcess.volumes[i]] > dataToProcess.bound)
		{
			dataToProcess.volumes.erase(dataToProcess.volumes.begin() + i);
			dataToProcess.values.erase(dataToProcess.values.begin() + i);
			dataToProcess.count -= 1;
			i -= 1;
		}
	}
}

std::vector < std::vector < int > > Algorithm::knapsackProblem(dataCollection dataToProcess)
{
	// NOTE: Vectors "values" and "volumes" are assumed to store all relevant values starting at index 1.

	std::vector < std::vector < int > > m(dataToProcess.count + 1, std::vector <int>(dataToProcess.maxVol + 1));

	// Define m[i, w] to be the maximum value that can be attained with weight less than or equal to w using items up to i (first i items)

	for (int i = 1; i <= dataToProcess.count; i++)
	{
		for (int j = 0; j <= dataToProcess.maxVol; j++)
		{
			if (dataToProcess.volumes[i] > j) m[i][j] = m[i - 1][j];

			else m[i][j] = std::max(m[i - 1][j], m[i - 1][j - dataToProcess.volumes[i]] + dataToProcess.values[i]);
		}
	}

	return m;
}

void Algorithm::printSolution(dataCollection processedData, std::vector<std::vector<int>> m)
{
	std::cout << "Maximum possible summary value of items packed in a suitcase: " << m[processedData.count][processedData.maxVol] << std::endl;

	int i = processedData.count, j = processedData.maxVol, k = 1;

	while (m[i][j] != 0)
	{
		while (m[i - 1][j] == m[i][j]) i--;

		std::cout << "Item no. " << k << ": volume: " << processedData.volumes[i] << ", value: " << processedData.values[i] << std::endl;
		j = j - processedData.volumes[i];
		i--;
		k++;
	}
}

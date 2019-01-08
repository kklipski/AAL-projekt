/**
* Name: Algorytm
* Purpose: Problem plecakowy
*
* @author Kamil Krzysztof Lipski
* @version 2.2
*/

#include "pch.h"

dataCollection Generator::generateData(int insCount, int insMaxVol, int insBound)
{
	dataCollection genData;
	genData.count = insCount;
	genData.bound = insBound;
	genData.maxVol = insMaxVol;

	for (int i = 1; i <= insCount; i++)
	{
		genData.volumes.push_back((rand() % (insMaxVol-1)) + 1);
		genData.values.push_back(rand() % MAX_VALUE);
	}

	return genData;
}
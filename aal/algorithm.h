#ifndef ALGORITHM_H
#define ALGORITHM_H

class dataCollection
{
private:
	int bound = 0;
	int count = 0;
	int maxVol = 0;
	std::vector <int> values;
	std::vector <int> volumes;
	friend class Algorithm;
	friend class Generator;
public:
	dataCollection(int mode = 0);
	dataCollection& operator= (const dataCollection & copiedData);
	void showGenData();
};

class Algorithm
{
public:
	static void bucketCounting(dataCollection & dataToProcess);
	static std::vector < std::vector < int > > knapsackProblem(dataCollection dataToProcess);
	static void printSolution(dataCollection processedData, std::vector<std::vector<int>> m);
};

#endif //ALGORITHM_H
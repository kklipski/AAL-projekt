/**
* Name: Algorytm
* Purpose: Problem plecakowy
*
* @author Kamil Krzysztof Lipski
* @version 2.2
*/

#include "pch.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));
	std::vector <int> options = Interface::processOptions(argv);
	Interface::selectMode(options);
	return 0;
}
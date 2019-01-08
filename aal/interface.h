#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{	
public:
	static std::vector <int> processOptions(char* argVal[]);
	static void selectMode(std::vector <int> startOptions);
private:
	static int charToInt(char stringToConvert[], int charsToSkip);
};

#endif //INTERFACE_H
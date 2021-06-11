#pragma once
#include"Cell.h"

class Line
{
private:
	Cell data[26];
	size_t lineInd;

	//Helpers
	int calculateIndexOfCellByColumName(char columName) const;

public:
	//constructors
	Line(size_t lineInd);

	//geters
	size_t getLineInd() const;

	//Methods
	void addCell(char columName, Type* value);
	void deleteCell(char columName);
	void printLine() const;
	//void readLineFromFile();
	//void saveLineToFile();

};

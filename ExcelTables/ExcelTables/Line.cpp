#include"Line.h"


Line::Line(size_t lineInd)
{
	//data is initialized with the default constructor of Cell
	this->lineInd = lineInd;
}

size_t Line::getLineInd() const {
	return lineInd;
}

int Line::calculateIndexOfCellByColumName(char columName) const {
	//for convenience, the logic of the program will work with capital letters

	return (int)columName - 65;
}

void Line::addCell(char columName, Type* value) {

	int indexToAdd = calculateIndexOfCellByColumName(columName);
	data[indexToAdd] = Cell(columName, lineInd, value);

}

void Line::deleteCell(char columName) {
	int indexToDelete = calculateIndexOfCellByColumName(columName);
	data[indexToDelete].deleteValue();
}

void Line::printLine() const {

	for (int i = 0; i < 26; i++) {
			data[i].printCell();
	}
	std::cout << std::endl;
}
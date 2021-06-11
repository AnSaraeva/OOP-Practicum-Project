#pragma once
#include"Line.h"

class Table {
private:
	Line** content;
	size_t rowCount; // we assume that the table has 26 columns
	//size_t capacity;

	//helpers
	void copy(const Table& other);
	void free();
	void resize(size_t newCapacity);
public:
	//Big 5
	Table();
	Table(const Table& other);
	Table& operator=(const Table& other);
	Table(Table&& other);
	Table& operator=(Table&& other);
	~Table();

	//Methods
	//void readTableFromFile();
	//void writeTableToFile();
	//void addLine(size_t lineInd); XXXX
	void editCell(char columName, size_t rowInd, Type* value);
	void printTable() const;
	void printDimensions() const;

};
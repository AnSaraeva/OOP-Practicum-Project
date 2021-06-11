#include "Table.h"
#include<iostream>
#include<iomanip>
using namespace std;

//define Big5
Table::Table() {
	this->rowCount = 2;
	//this->capacity = 8;
	content = new Line * [rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		content[i] = new Line(i+1);//create array of lines with empty cells
	}
	
}

Table::Table(const Table& other) {
	copy(other);
}

Table& Table::operator=(const Table& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Table::Table(Table&& other) {
	rowCount = other.rowCount;
	//capacity = other.capacity;
	content = other.content;

	other.rowCount = 0;
	//other.capacity = 0;
	other.content = nullptr;

	cout << "Move constructor!" << endl;
}
Table& Table::operator=(Table&& other)
{
	if (this != &other)
	{
		free();

		rowCount = other.rowCount;
		//capacity = other.capacity;
		content = other.content;

		other.rowCount = 0;
		//other.capacity = 0;
		other.content = nullptr;
	}
	return*this;
}
Table::~Table() {
	free();
}

//define helpers
void Table::copy(const Table& other) {
	rowCount = other.rowCount;
	//capacity = other.capacity;
	content = new Line * [other.rowCount];
	for (int i = 0; i < other.rowCount; i++)
	{
		content[i] = new Line(*other.content[i]);
	}
}
void Table::free() {
	for (int i = 0; i < rowCount; i++)
		delete content[i];
	
	delete[] content;
}
void Table::resize(size_t newRowCount) {
	Line** tmp = new Line * [newRowCount];
	for (int i = 0; i < rowCount; i++)
	{
		tmp[i] = content[i];
	}

	for (int i = rowCount; i < newRowCount; i++)
	{
		tmp[i] = new Line(i + 1);
	}

	delete[] content;
	content = tmp;
	rowCount = newRowCount;

}

//define Methods

void Table::editCell(char columName, size_t rowInd, Type* value) {
	if (rowInd >= rowCount)
				resize(rowInd);

	content[rowInd - 1]->addCell(columName, value);


}

void Table::printTable() const {

	char c = 'A';
	for (int i = 0; i < 3; i++) {
		cout << "|" << c << setw(10);
		c++;
	}
	cout << setw(0)<< endl;
	for (int i = 0; i < rowCount; i++)
	{
		cout << "Line " << i+1 << endl;
		content[i]->printLine();
		cout << setw(0)<< endl;
	}
	cout << setw(0) << endl;
}

void Table::printDimensions() const {
	cout << "Lines: " << rowCount << ", Columns: 26\n";
}
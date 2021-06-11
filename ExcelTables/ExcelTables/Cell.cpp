#include "Cell.h"
#include<iomanip>
using namespace std;

Cell::Cell()
{ 
	value = nullptr;
}

Cell::Cell(char columName, size_t rowInd, Type* value)
{
	setColumName(columName);
	setRowInd(rowInd);
	setValue(value);
}


void Cell::copy(const Cell& other) {
	if (other.isEmpty())
		value = nullptr;
	else
	    value = other.value->clone();

	rowInd = other.rowInd;
	columName = other.columName;
}
void Cell::free() {
	delete value;
}


Cell::Cell(const Cell& other) {
	copy(other);
}
Cell& Cell::operator=(const Cell& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}
Cell::Cell(Cell&& other) {
	if (other.isEmpty())
		value = nullptr;
	else
		value = other.value->move_clone();

	other.value = nullptr;

	rowInd = other.rowInd;
	other.rowInd = 0;
	columName = other.columName;
	other.columName = '0';

	
}
Cell& Cell::operator=(Cell&& other) {
	if (this != &other) {
		free();

		value = other.value->move_clone();
		other.value = nullptr;

		rowInd = other.rowInd;
		other.rowInd = 0;
		columName = other.columName;
		other.columName = '0';
	}
	return *this;
}
Cell::~Cell() {
	free();
}

void Cell::setValue(Type* value){
	this->value = value->clone();
}

void Cell::setRowInd(size_t rowInd){
	this->rowInd = rowInd;
}

void Cell::setColumName(char columName) {
	//if ((columName < 'A' || columName>'Z') && (columName < 'a' || columName>'z'))
	//	throw("Columname must be a letter!");
	this->columName = columName;
}

void Cell::deleteValue() {
	delete value;
	value = nullptr;

}

const char* Cell::getValue() const {
	return this->value->getValue();
}

size_t Cell::getRowInd() const {
	return rowInd;
}

char Cell::getColumName() const {
	return columName;
}
bool Cell::isEmpty() const {
	return value == nullptr;
}

void Cell::printCell() const
{
	if (isEmpty())
		cout << "|" << setw(10);
	else {
		cout << "|";
		value->printValue();
		cout << setw(10);
	}
	//cout << "Value: " << getValue() << endl;
	//cout << "Columname: " << getColumName() << endl;
	//cout << "rowInd: " <<getRowInd()<< endl;
	//cout << "Empty: " <<isEmpty() << endl;
}
#pragma once
#include"Type.h"

class Cell
{
private:
	Type* value;
	size_t rowInd;
	char columName;
	//bool empty;

	//Helpers
	void copy(const Cell& other);
	void free();

public:
	//Constructors
	Cell();
	Cell(char columName,size_t rowInd, Type* value);
	Cell(const Cell& other);
	Cell& operator=(const Cell& other);
	Cell(Cell&& other);
	Cell& operator=(Cell&& other);
	~Cell();

	//Setters
	void setValue(Type* value);
	void setRowInd(size_t rowInd);
	void setColumName(char columName);
	void deleteValue();

	//Getters
	const char* getValue() const;
	size_t getRowInd() const;
	char getColumName() const;
	bool isEmpty() const;

	//Methods
	void printCell() const;
	//Cell readCellFromFile();
	//void saveCellToFile();
};


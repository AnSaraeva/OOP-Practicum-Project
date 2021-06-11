#pragma once
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<utility>
#include <charconv>
#include<string>


class Type{
private:
	//Helpers
	void copy(const Type& other);
	void free();

protected:
	char* value;

public:
	//Big 5
	Type(const char* value);
	Type(const Type& other);
	Type& operator=(const Type& other);
	Type(Type&& other);
	Type& operator=(Type&& other);
	virtual ~Type();

	virtual Type* clone() const = 0;
	virtual Type* move_clone() = 0;
	

	virtual void printValue() const = 0;
	virtual char returnType() const = 0;
	virtual const char* getValue() const = 0;

	virtual  Type* operator+(Type& rs) const =0;
	virtual  Type* operator-(Type& rs) const = 0;
	virtual  Type* operator*(Type& rs) const = 0;
	virtual  Type* operator/(Type& rs) const = 0;
	virtual  Type* operator^(Type& rs) const = 0;

};
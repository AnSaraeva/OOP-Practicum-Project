#pragma once
#include"Type.h"

class Error :public Type {
public:
	 Error();

	Type* clone() const override;
	Type* move_clone();
	void printValue() const override;
	const char* getValue() const;
	char returnType() const override;

	//operators
	Type* operator+(Type& rs) const override;
	Type* operator-(Type& rs) const override;
	Type* operator*(Type& rs) const override;
	Type* operator/(Type& rs) const override;
	Type* operator^(Type& rs) const override;
};

#pragma once
#include"Type.h"

class Double :public Type {
public:
	Double(const char* value);


	void printValue()const;
	Type* clone() const;
	Type* move_clone();

    char returnType() const override;
    const char* getValue() const ;

	Type* operator+(Type& rs) const override;
	Type* operator-(Type& rs) const override;
	Type* operator*(Type& rs) const override;
	Type* operator/(Type& rs) const override;
	Type* operator^(Type& rs) const override;
};
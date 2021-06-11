#pragma once
#include "Type.h"

class String :public Type {
private:
	char* convertedValue;

	void convertValue();
	void copy(const String& other);
	void free();
public:
	String(const char* value);
	String(const String& other);
	String& operator=(const String& other);
	String(String&& other);
	String& operator=(String&& other);
	~String();

	void printValue() const;
	Type* clone()const;
	Type* move_clone();

	char returnType() const override;
	const char* getValue() const;
	bool isContentInteger(const char* content) const;
	bool isContentDouble(const char* content) const;

	Type* operator+(Type& rs) const override;
	Type* operator-(Type& rs) const override;
	Type* operator*(Type& rs) const override;
	Type* operator/(Type& rs) const override;
	Type* operator^(Type& rs) const override;

	friend std::ostream& operator<<(std::ostream& os, String str);

};

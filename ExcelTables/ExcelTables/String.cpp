#include "String.h"
#include"Integer.h"
#include"Double.h"
#include"Error.h"

String::String(const char* value):Type(value) {
	convertValue();
}

void String:: copy(const String& other) {
	convertedValue = new char[strlen(other.convertedValue) + 1];
	strcpy(convertedValue, other.convertedValue);
}

void String::free() {
	delete[] convertedValue;
}


String::String(const String& other):Type(other) {
	copy(other);
}
String& String::operator=(const String& other) {

	if (this != &other)
	{
		Type::operator=(other);
		free();
		copy(other);
	}
	return *this;
}
String::String(String&& other):Type(other) {
	convertedValue = other.convertedValue;
	other.convertedValue = nullptr;

}
String& String::operator=(String&& other) {
	
	if (this != &other) {
		Type::operator=(other);
		free();
		convertedValue = other.convertedValue;
		other.convertedValue = nullptr;
	}
	return *this;
}
String::~String() {
	free();
}


void String::convertValue() {

	int len = strlen(value);
	char* tmp = new char[len-2 + 1];
	
	int j = 0;
	for (int i = 1; i < len - 1; i++)//mahame "" 
	{
		if (value[i] == '\\' && (value[i + 1] == '\\' || value[i + 1] == '\"'))
			tmp[j++] = value[++i];

		else
			tmp[j++] = value[i];
	}

	tmp[j] = '\0';
	
	convertedValue = new char[strlen(tmp) + 1];
	strcpy(convertedValue, tmp);
	delete[] tmp;

}

void String:: printValue() const {
	std::cout << convertedValue;
}

std::ostream& operator<<(std::ostream& os, String str) {
	os << str.convertedValue << std::endl;
   return os;
}

Type* String::clone() const {
	return new String(*this);
}

Type* String::move_clone() {
	return new String(std::move(*this));
}

char String:: returnType() const {
	return 's';
}

const char* String::getValue() const {
	return convertedValue;
}

bool String::isContentInteger(const char* content) const {
	for (int i = 0; i < strlen(content); i++) {
		if (content[i] < '0' || content[i] >'9')
			return false;
	}
	return true;
}

bool String::isContentDouble(const char* content) const {
	bool meetPoint = false;
	for (int i = 0; i < strlen(content); i++) {
		if (content[i] < '0' || content[i]>'9') {
			if (content[i] == '.') {
				if (meetPoint == true || i == 0)
					return false;
				else
					meetPoint = true;
			}
			else
				return false;
		}
		
	}
	return true;
}


Type* String::operator+(Type& rs) const {
	Type& leftSide = rs;
	Type& rightSide = *(new String(*this));
	Type* result = leftSide + rightSide;
	return result;
}

Type* String::operator-(Type& rs) const {
	Type& leftSide = rs;
	Type& rightSide = *(new String(*this));
	Type* result = leftSide - rightSide;
	return result;
}

Type* String::operator*(Type& rs) const {
	Type& leftSide = rs;
	Type& rightSide = *(new String(*this));
	Type* result = leftSide * rightSide;
	return result;
}

Type* String::operator/(Type& rs) const {
	
	if (this->isContentInteger(this->convertedValue)) {
		Integer leftSide(convertedValue);
		return leftSide / rs;
	}
	else if (this->isContentDouble(this->convertedValue)) {
		Double leftSide(convertedValue);
		return leftSide / rs;
	}
	else
	{
		Integer leftSide("0");
		return leftSide / rs;
	}
	
}

Type* String::operator^(Type& rs) const {
	if (this->isContentDouble(this->convertedValue) || rs.returnType() == 'd' || rs.returnType() == 'e')
		return new Error();
	
	if (this->isContentInteger(this->convertedValue)) {
		Integer leftSide(convertedValue);
		return leftSide ^ rs;
	}
		
	return new Error();
}
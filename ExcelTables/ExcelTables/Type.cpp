#include "Type.h"

//Big 5
Type::Type(const char* value) {
	this->value = new char[strlen(value) + 1];
	strcpy(this->value, value);
}

Type::Type(const Type& other) {
	copy(other);
}

Type& Type::operator=(const Type& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}
Type::~Type() {
	free();
}

Type::Type(Type&& other) {
	value = other.value;
	other.value = nullptr;
}
Type& Type::operator=(Type&& other) {
	if (this != &other)
	{
		free();
		value = other.value;
		other.value = nullptr;

	}
	return *this;
}

//Helpers
void Type::copy(const Type& other) {
	this->value = new char[strlen(other.value) + 1];
	strcpy(this->value, other.value);
}
void Type::free() {
	delete[] value;
}


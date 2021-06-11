#include"Error.h"

Error::Error() :Type("#ERROR") {};

Type* Error::clone() const {
	return new Error(*this);
}

Type* Error::move_clone() {
	return new Error(std::move(*this));
}

void Error::printValue() const {
	std::cout << value;
}
const char* Error::getValue() const {
	return value;
}
char Error::returnType() const{
	return'e';
}

//operators
Type* Error::operator+(Type& rs) const {
	return new Error();
}
Type* Error::operator-(Type& rs) const {
	return new Error();
}
Type* Error::operator*(Type& rs) const {
	return new Error();
}
Type* Error::operator/(Type& rs) const {
	return new Error();
}
Type* Error::operator^(Type& rs) const {
	return new Error();
}
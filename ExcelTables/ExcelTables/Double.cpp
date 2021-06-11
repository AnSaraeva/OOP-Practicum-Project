#include "Double.h"
#include"Integer.h"
#include"String.h"
#include"Error.h"

Double::Double(const char* value) :Type(value) {};


void Double::printValue()const {
	std::cout << value;
}

Type* Double:: clone() const {
	return new Double(*this);
}

Type* Double::move_clone() {
	return new Double(std::move(*this));
}

char Double::returnType() const {
	return 'd';
}

const char* Double::getValue() const {
	return value;
}

Type* Double::operator+(Type& rs) const {
	double leftSideConvertedValue = atof(this->value);
	double resultDouble;
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		 resultDouble = leftSideConvertedValue + rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		resultDouble = leftSideConvertedValue + rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			resultDouble = leftSideConvertedValue + rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			resultDouble = leftSideConvertedValue + rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else {
			int rightSideConvertedValue = 0;
			return new Double(*this);
		}


	}
	else if (rs.returnType() == 'e') {
		return new Error();
	}
}

Type* Double::operator-(Type& rs) const {
	double leftSideConvertedValue = atof(this->value);
	double resultDouble;
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		resultDouble = leftSideConvertedValue - rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		resultDouble = leftSideConvertedValue - rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			resultDouble = leftSideConvertedValue - rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			resultDouble = leftSideConvertedValue - rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else {
			int rightSideConvertedValue = 0;
			return new Double(*this);
		}


	}
	else if (rs.returnType() == 'e') {
		return new Error();
	}
}

Type* Double::operator*(Type& rs) const {
	double leftSideConvertedValue = atof(this->value);
	double resultDouble;
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		resultDouble = leftSideConvertedValue * rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		resultDouble = leftSideConvertedValue * rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			resultDouble = leftSideConvertedValue * rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			resultDouble = leftSideConvertedValue * rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else {
			int rightSideConvertedValue = 0;
			return new Double("0");
		}


	}
	else if (rs.returnType() == 'e') {
		return new Error();
	}
}

Type* Double::operator/(Type& rs) const {
	double leftSideConvertedValue = atof(this->value);
	double resultDouble;
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		if (rightSideConvertedValue == 0)
			return new Error();
		resultDouble = leftSideConvertedValue / rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		if (rightSideConvertedValue == 0)
			return new Error();
		resultDouble = leftSideConvertedValue / rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			if (rightSideConvertedValue == 0)
				return new Error();
			resultDouble = leftSideConvertedValue / rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			if (rightSideConvertedValue == 0)
				return new Error();
			resultDouble = leftSideConvertedValue / rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else {
			int rightSideConvertedValue = 0;
			return new Error();
		}


	}
	else if (rs.returnType() == 'e') {
		return new Error();
	}
}

Type* Double::operator^(Type& rs) const {
	return new Error();
}
#include "Integer.h"
#include "Double.h"
#include"String.h"
#include"Error.h"

Integer::Integer(const char* value) :Type(value) {};

Type* Integer::clone() const {
	return  new Integer(*this);
}

Type* Integer::move_clone() {
	return new Integer(std::move(*this));
}
void Integer::printValue() const {
	std::cout << value;
}

const char* Integer::getValue() const {
	return value;
}

char Integer::returnType() const{
	return 'i';
}

Type* Integer::operator+(Type& rs) const {

	int leftSideConvertedValue = atoi(this->value);
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		int resultInt = leftSideConvertedValue + rightSideConvertedValue;
		std::string s = std::to_string(resultInt);//convert int to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Integer(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		double resultDouble = leftSideConvertedValue + rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);//convert double to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			int resultInt = leftSideConvertedValue + rightSideConvertedValue;
			std::string s = std::to_string(resultInt);//convert int to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Integer(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			double resultDouble = leftSideConvertedValue + rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);//convert double to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else {
			int rightSideConvertedValue = 0;
			return new Integer(*this);
		}

		
	}
	else if (rs.returnType() == 'e') {
		return new Error();
	}
}



Type* Integer::operator-(Type& rs) const {
	int leftSideConvertedValue = atoi(this->value);
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		int resultInt = leftSideConvertedValue - rightSideConvertedValue;
		std::string s = std::to_string(resultInt);//convert int to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Integer(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		double resultDouble = leftSideConvertedValue - rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);//convert double to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			int resultInt = leftSideConvertedValue - rightSideConvertedValue;
			std::string s = std::to_string(resultInt);//convert int to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Integer(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			double resultDouble = leftSideConvertedValue - rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);//convert double to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else {
			int rightSideConvertedValue = 0;
			return new Integer(*this);
		}
    }
	else if (rs.returnType() == 'e') {
		return new Error();
	}
}


Type* Integer::operator*(Type& rs) const {
	int leftSideConvertedValue = atoi(this->value);
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		int resultInt = leftSideConvertedValue * rightSideConvertedValue;
		std::string s = std::to_string(resultInt);//convert int to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Integer(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		double resultDouble = leftSideConvertedValue * rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);//convert double to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			int resultInt = leftSideConvertedValue * rightSideConvertedValue;
			std::string s = std::to_string(resultInt);//convert int to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Integer(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			double resultDouble = leftSideConvertedValue * rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);//convert double to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Double(resultStr);
		}
		else {
			int rightSideConvertedValue = 0;
			return new Integer("0");
		}
    }

	else if (rs.returnType() == 'e') {
		return new Error();
	}
}


Type* Integer::operator/(Type& rs) const {

	int leftSideConvertedValue = atoi(this->value);
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());	
		if(rightSideConvertedValue==0)
			return new Error();

		int resultInt = leftSideConvertedValue / rightSideConvertedValue;
		std::string s = std::to_string(resultInt);//convert int to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Integer(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		double rightSideConvertedValue = atof(rs.getValue());
		if (rightSideConvertedValue == 0)
			return new Error();

		double resultDouble = leftSideConvertedValue / rightSideConvertedValue;
		std::string s = std::to_string(resultDouble);//convert double to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Double(resultStr);
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			if (rightSideConvertedValue == 0)
				return new Error();
			int resultInt = leftSideConvertedValue / rightSideConvertedValue;
			std::string s = std::to_string(resultInt);//convert int to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Integer(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			double rightSideConvertedValue = atof(rs.getValue());
			if (rightSideConvertedValue == 0)
				return new Error();
			double resultDouble = leftSideConvertedValue / rightSideConvertedValue;
			std::string s = std::to_string(resultDouble);//convert double to string
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

Type* Integer::operator^(Type& rs) const {

	int leftSideConvertedValue = atoi(this->value);
	if (rs.returnType() == 'i') {
		int rightSideConvertedValue = atoi(rs.getValue());
		int resultInt = leftSideConvertedValue ^ rightSideConvertedValue;
		std::string s = std::to_string(resultInt);//convert int to string
		const char* resultStr = s.c_str();  //use char const* as target type

		return new Integer(resultStr);
	}
	else if (rs.returnType() == 'd')
	{
		return new Error();
	}
	else if (rs.returnType() == 's') {
		if (((String&)rs).isContentInteger(rs.getValue())) {
			int rightSideConvertedValue = atoi(rs.getValue());
			int resultInt = leftSideConvertedValue ^ rightSideConvertedValue;
			std::string s = std::to_string(resultInt);//convert int to string
			const char* resultStr = s.c_str();  //use char const* as target type

			return new Integer(resultStr);
		}
		else if (((String&)rs).isContentDouble(rs.getValue())) {
			return new Error();
		}
		else {
			int rightSideConvertedValue = 0;
			return new Integer("1"); //x^0=1
		}
    }
	else if (rs.returnType() == 'e') {
		return new Error();
	}
}
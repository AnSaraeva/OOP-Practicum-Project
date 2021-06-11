#include<fstream>
#include "Cell.h"
#include"Table.h"
#include"String.h"
#include"Double.h"
#include"Integer.h"
using namespace std;


const int BUFF_SIZE = 100;
 
//void setValue(const char*value) {
//	if (value[0] != '+' && value[0] != '-' && (value[0] < '0' || value[0]>'9'))
//		throw("Trying to assign non double value to cell of type double!");
//
//	int i = 1;
//	bool meetPoint = false;
//	while (i < strlen(value))
//	{
//		if (value[i] == '.' && !meetPoint)
//			meetPoint = true;
//
//		else if ((value[i] < '0' || value[i]>'9') || (value[i] == '.' && meetPoint))
//			throw("Trying to assign non double value to cell of type double!");
//
//		i++;
//	}
//	double convertedValue = atof(value);
//	cout << convertedValue << endl;
//}





int main()
{/*
	Cell c1;
	c1.print();

	Cell c2(5, 'A',1);
	c2.print();*/
	

	/*Table t1;
	t1.printTable();
	t1.editCell('B', 1, 5);
	t1.printTable();*/
	

	/*String c1("\"This is a quotation\"");
	cout << c1;*/

	/*char buff[1000];*/



	//cin.getline(buff, 1000);
	//cout << buff;
	//cout << endl;

	//String s1(buff);
	//cout << s1;

	Integer*i1=new Integer("3");
	Cell c1('A', 1, i1);
	//c1.printCell();

	//Type* test = s1/(*i1);
	//Cell c2('B', 1, test);
	//c2.printCell();

	
	/*Double* s1 = new Double("0.5");
	Cell c2('B', 2, s1);
	c2.printCell();
	Integer* i2 = new Integer("4");
	Cell c3('C', 1, i2);
	c3.printCell();
	Type* test = *i1 * *s1;
	Cell c4('D', 1, test);
	c4.printCell();
	test->printValue();
	cout << test->returnType();*/


	Double* s1 = new Double("0.5");
	Integer* i2 = new Integer("4");

	/*Line l1(1);
	l1.addCell('A', i1);
	l1.addCell('B', s1);
	l1.addCell('C', i2);
	l1.printLine();
	l1.addCell('A', *s1+*i2);
	l1.printLine();*/

	Table t1;
	t1.editCell('A', 1, i1);
	t1.printTable();
	t1.printDimensions();
	t1.editCell('C', 4, s1);
	t1.printTable();
	t1.printDimensions();

	return 0;
}
//============================================================================
// Name        : test1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Sommet.hpp"
#include "Coloration.hpp"
#include "Model.hpp"
#include "Parser.hpp"
//#include "IntegerVector.hpp"
#include <time.h>
#include <sys/time.h>
#include <string>
//#include <boost/spirit/include/classic.hpp>

using namespace std;


/*
		1	[]
		3	[1]
		4	[1,3]
		2	[1,3]
		6	[2,3][4]
		5	[4,6][1]
		7	[1,5][2]
*/

/*
		1	[]
		2	[1]
		3	[1,2]
		4	[1,2,3]
		5	[1,2,3,4][]
		6 	[3,2][]
		7	[2,3,6][]
		8	[4,5][]
		9	[4,5,8]
		10	[6,7][8,9]
		11	[7,10][9]
*/
/*
bool
parse_numbers(char const* str, vector<IntegerVector<vector<int> > > int_v)
{
    return parse(str,
    		(
    				real_p[push_back_a(v)] >> *(',' >> real_p[push_back_a(v)])
    		) ,
    		space_p).full;
}
//*/

int main() {
	cout<<"##Start"<<endl;

	/*
	Coloration int3(1);
		Sommet s1(1);
		Sommet s2(2);
		Sommet s3(3);
		Sommet s4(4);
		Sommet s5(5);
		Sommet s6(6);
		Sommet s7(7);
		Sommet s8(8);
		Sommet s9(9);
		s2.addSommetAt(&s1,1);

		s3.addSommetAt(&s1,1);
		s3.addSommetAt(&s2,1);

		s4.addSommetAt(&s1,1);
		s4.addSommetAt(&s2,1);

		s5.addSommetAt(&s1,1);
		s5.addSommetAt(&s2,1);

		s6.addSommetAt(&s1,1);
		s6.addSommetAt(&s7,1);
		s6.createNewEt();
		s6.addSommetAt(&s3,2);
		s6.addSommetAt(&s5,2);

		s6.addSommetAt(&s1,1);
				s6.addSommetAt(&s7,1);
				s6.createNewEt();
				s6.addSommetAt(&s3,2);
				s6.addSommetAt(&s5,2);

			int3.push_back(&s1);
			int3.push_back(&s2);
			int3.push_back(&s3);
			int3.push_back(&s4);
			int3.push_back(&s5);
			int3.push_back(&s6);
			int3.push_back(&s7);
			int3.push_back(&s8);
			int3.push_back(&s9);
			int3.displayInConsole();
		Model m;

		m.addColoration(int3);
		//*/
	/*
	Coloration int2(1);
	Sommet s1(1);
	Sommet s2(2);
		s2.addSommetAt(&s1,1);
	Sommet s3(3);
		s3.addSommetAt(&s1,1);
		s3.addSommetAt(&s2,1);
	Sommet s4(4);
		s4.addSommetAt(&s1,1);
		s4.addSommetAt(&s2,1);
		s4.addSommetAt(&s3,1);
	Sommet s5(5);
		s5.addSommetAt(&s1,1);
		s5.addSommetAt(&s2,1);
		s5.addSommetAt(&s3,1);
		s5.addSommetAt(&s4,1);
	Sommet s6(6);
		s6.addSommetAt(&s3,1);
		s6.addSommetAt(&s2,1);
	Sommet s7(7);
		s7.addSommetAt(&s2,1);
		s7.addSommetAt(&s3,1);
		s7.addSommetAt(&s6,1);
	Sommet s8(8);
		s8.addSommetAt(&s4,1);
		s8.addSommetAt(&s5,1);
	Sommet s9(9);
		s9.addSommetAt(&s4,1);
		s9.addSommetAt(&s5,1);
		s9.addSommetAt(&s8,1);
	Sommet s10(10);
		s10.addSommetAt(&s6,1);
		s10.addSommetAt(&s7,1);
		s10.createNewEt();
		s10.addSommetAt(&s8,2);
		s10.addSommetAt(&s9,2);
	Sommet s11(11);
		s11.addSommetAt(&s7,1);
		s11.addSommetAt(&s10,1);
		s11.createNewEt();
		s11.addSommetAt(&s9,2);
	int2.push_back(&s1);
	int2.push_back(&s2);
	int2.push_back(&s3);
	int2.push_back(&s4);
	int2.push_back(&s5);
	int2.push_back(&s6);
	int2.push_back(&s7);
	int2.push_back(&s8);
	int2.push_back(&s9);
	int2.push_back(&s10);
	int2.push_back(&s11);
	int2.displayInConsole();
	Model m;

	m.addColoration(int2);
	//*/
	/*
	Coloration int1(1);
	Sommet s1(1);
	Sommet s3(3);
		s3.addSommetAt(&s1,1);
	Sommet s4(4);
		s4.addSommetAt(&s1,1);
		s4.addSommetAt(&s3,1);
	Sommet s2(2);
		s2.addSommetAt(&s1,1);
		s2.addSommetAt(&s3,1);
	Sommet s6(6);
		s6.addSommetAt(&s2,1);
		s6.addSommetAt(&s3,1);
		s6.createNewEt();
		s6.addSommetAt(&s4,2);
	Sommet s5(5);
		s5.addSommetAt(&s4,1);
		s5.addSommetAt(&s6,1);
		s5.createNewEt();
		s5.addSommetAt(&s1,2);
	Sommet s7(7);
		s7.addSommetAt(&s1,1);
		s7.addSommetAt(&s5,1);
		s7.createNewEt();
		s7.addSommetAt(&s2,2);
	int1.push_back(&s1);
	int1.push_back(&s3);
	int1.push_back(&s4);
	int1.push_back(&s2);
	int1.push_back(&s6);
	int1.push_back(&s5);
	int1.push_back(&s7);
	int1.displayInConsole();
	Model m;

	m.addColoration(int1);
	//*/
	//*

timeval start, end;
		gettimeofday(&start, NULL);
	Parser p;
	string s("./charpente7.txt");
	p.setFilepath(s);
	if (p.parseFile())
	{
		Model m;
		Coloration col = p.getCol();


		//time_t t1, t2;
		//t1 = time(NULL);
		
		vector<Coloration> vect_col = m.generer(col);
		
		gettimeofday(&end, NULL);
		double tps = (end.tv_usec - start.tv_usec);
		//t2 = time(NULL);
		//double tps=difftime(t2,t1);


		for(unsigned int i=0; i<vect_col.size();++i)
		{
			vect_col.at(i).displayInConsole();
		}

		cout<<"Execution time : "<<tps<<endl;
	}
	else
	{
		cout << "syntax error in the charpente file..."<<endl;
	}
	/*
	Parser p;
	string s("./charpente11.txt");
	p.setFilepath(s);
	cout << "Parser\nbool:"<<p.parseFile()<<endl;
	cout << "Col du parser ::"<<endl;
	p.getCol().displayInConsole();
	//*/
	cout<<"##Quit"<<endl;
	return 0;
}

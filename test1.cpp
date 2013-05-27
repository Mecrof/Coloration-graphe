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

int main() {
	cout<<"##Start"<<endl;
	//*
	Coloration int1(1);
	Sommet s1(1);
	Sommet s3(3);
		s3.addSommetAt(s1,1);
	Sommet s4(4);
		s4.addSommetAt(s1,1);
		s4.addSommetAt(s3,1);
	Sommet s2(2);
		s2.addSommetAt(s1,1);
		s2.addSommetAt(s3,1);
	Sommet s6(6);
		s6.addSommetAt(s2,1);
		s6.addSommetAt(s3,1);
		s6.createNewEt();
		s6.addSommetAt(s4,2);
	Sommet s5(5);
		s5.addSommetAt(s4,1);
		s5.addSommetAt(s6,1);
		s5.createNewEt();
		s5.addSommetAt(s1,2);
	Sommet s7(7);
		s7.addSommetAt(s1,1);
		s7.addSommetAt(s5,1);
		s7.createNewEt();
		s7.addSommetAt(s2,2);
	int1.push_back(s1);
	int1.push_back(s3);
	int1.push_back(s4);
	int1.push_back(s2);
	int1.push_back(s6);
	int1.push_back(s5);
	int1.push_back(s7);
	int1.displayInConsole();
	Coloration::iterator itCol;
	for (itCol=int1.begin();itCol!=int1.end();)
	{
		while ( !(*itCol).hasMultipleEt() )
		{
			itCol++;
		};

		Sommet * s = &(*itCol);
		cout<<"Sommet"<<s->getNum()<<endl;
		Sommet * sEt2 = &(s->getSommetAt(2,0)); // a modifier
		vector<Sommet*>::iterator itSEt2;
		vector<Sommet*>::iterator itSEt1;
		for(itSEt2=sEt2->getEt(1).begin();itSEt2!=sEt2->getEt(1).end();)
		{
			for (itSEt1=s->getEt(1).begin();itSEt1!=s->getEt(1).end();itSEt1++)
			{
				if( (*itSEt2)!=(*itSEt1) )
				{
					cout << "found : et2->"<< sEt2->getNum() <<" ; et1->"<<(*itSEt2)->getNum()<<endl;
				}
			}

			itSEt2++;
		}
		itCol = int1.end();
	}
	//*/

	/*
	Sommet s1(1);
	cout << "sommet"<<s1.getNum()<<".hasInterdit : "<<s1.hasInterdit()<<endl;
	Sommet s2(2);
	s1.addSommetAt(s2,1);
	cout << "sommet"<<s1.getNum()<<" : "<<s1.getSommetAt(1,0).getNum()<<endl;
	cout << "sommet"<<s1.getNum()<<".hasInterdit : "<<s1.hasInterdit()<<endl;
	cout<<"---HasNext::\n";
	cout << "sommet"<<s1.getNum()<<".hasEt2 : "<<s1.hasMultipleEt()<<endl;
	s1.createNewEt();
	cout << "sommet"<<s1.getNum()<<".hasEt2 : "<<s1.hasMultipleEt()<<endl;

	cout<<"---RemoveSommetAt\n";
	cout<<"size:"<<s1.getEt(1).size()<<endl;
	s1.removeSommetAt(s2,1);
	cout<<"size:"<<s1.getEt(1).size()<<endl;
	//*/
	cout<<"##Quit"<<endl;
	return 0;
}

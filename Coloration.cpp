/*
 * Coloration.cpp
 *
 *  Created on: 26 mai 2013
 *      Author: Antoine
 */
#include "Coloration.hpp"

Coloration::Coloration(int n)
{
	this->num = n;
}

int Coloration::getNumvoid(void)
{
	return this->num;
}

void Coloration::displayInConsole(void)
{
	cout<<"----Classe de coloration "<<this->num<<"----"<<endl;
	Coloration::iterator it;
	vector<Sommet*>::iterator it2;
	cout<<"- S(i)\tint(i)"<<endl;
	for (it=this->begin();it!=this->end();it++)
	{
		cout<<"- "<<it->getNum()<<"\t[";
		for (it2=it->getEt(1).begin();it2!=it->getEt(1).end();it2++)
		{
			cout<< (*it2)->getNum()<<",";
		}
		cout<<"]"<<endl;
		if(it->hasMultipleEt())
		{
			//a modifier
			cout<<"   \t[";
			for (it2=it->getEt(2).begin();it2!=it->getEt(2).end();it2++)
			{
				cout<<(*it2)->getNum()<<",";
			}
			cout<<"]"<<endl;
		}
	}
	cout<<"-------------------------"<<endl;
}


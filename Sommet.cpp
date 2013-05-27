/*
 * Sommet.cpp
 *
 *  Created on: 26 mai 2013
 *      Author: Antoine
 */
#include "Sommet.hpp"

/////////////////////////////////////////////
/////////// CONSTRUCTOR-DESTRUCTOR ////////////
/////////////////////////////////////////////

Sommet::Sommet(int n)
{
	this->num = n;
	vector<Sommet*> v1;
	this->v.push_back(v1);
}

/////////////////////////////////////////////
///////////////// SETTERS ////////////////////
/////////////////////////////////////////////

vector<Sommet*> & Sommet::createNewEt(void)
{
	vector<Sommet*> nv;
	this->v.push_back(nv);
	return (*v.end());
}

int Sommet::removeEt(int et)
{
	return removeEt(this->getEt(et));
}

int Sommet::removeEt(vector<Sommet*> & et)
{
	vector<vector<Sommet*> >::iterator it;
	for(it=this->v.begin();it!=this->v.end();)
	{
		if( (*it)==et )
		{
			v.erase(it);
			return 0;
		}
		it++;
	}
	return -1;
}

Sommet & Sommet::addSommetAt(Sommet & s, const int et)
{
	this->v.at(et-1).push_back(&s);
	return (*(this->v.at(et-1).back()));
}

int Sommet::removeSommetAt(Sommet & s, const int et)
{
	vector<Sommet*> * vect = &(this->v.at(et-1));
	vector<Sommet*>::iterator it;
	for (it=vect->begin();it!=vect->end();)
	{
		if( (*it)==&s )
		{
			vect->erase(it);
			return 0;
		}
		it++;
	}
	return -1;
}

/////////////////////////////////////////////
///////////////// GETTERS ////////////////////
/////////////////////////////////////////////


Sommet & Sommet::getSommetAt(const int et, const int pos) const
{
	return (*(this->v.at(et-1).at(pos)));
}

vector<Sommet*>& Sommet::getEt(const int et)
{
	return this->v.at(et-1);
}

int Sommet::getNumberOfEt(void)
{
	return this->v.size();
}

int Sommet::getNum(void)
{
	return this->num;
}

/////////////////////////////////////////////
///////////////// HASER ////////////////////
/////////////////////////////////////////////

bool Sommet::hasMultipleEt(void)
{
	return v.size()>1;
}

bool Sommet::hasInterdit(void)
{
	return v.at(0).size()>0;
}


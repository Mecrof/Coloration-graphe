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

Sommet::Sommet(int n):sign(1)
{
	this->num = n;
	vector<Sommet*> v1;
	this->v.push_back(v1);
}

Sommet::Sommet(Sommet const & s):v(s.v)
{
	this->num = s.num;
	this->sign = s.sign;
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

Sommet & Sommet::addSommetAt(Sommet * s, const int et)
{
	this->v.at(et-1).push_back(s);
	return (*(this->v.at(et-1).back()));
}

int Sommet::removeSommetAt(Sommet & s, const int et)
{
	vector<Sommet*> * vect = &(this->v.at(et-1));
	vector<Sommet*>::iterator it=vect->begin();
	while (it<vect->end())
	{
		if( (*it)==&s )
		{
			vect->erase(it);
			if (vect->size()==0)
			{
				this->removeEt(2);
			}
			return 0;
		}
		it++;
	};

	return -1;
}

int Sommet::removeSommetAt(int pos, const int et)
{
	return this->removeSommetAt((*this->getEt(et).at(pos)), et);
}

void Sommet::replace(Sommet const & sAnc, Sommet & sNouv)
{
	vector<vector<Sommet*> >::iterator it;
	vector<Sommet*>::iterator it2;
	for (it=v.begin();it<v.end();++it)
	{
		for(it2=it->begin();it2<it->end();++it2)
		{
			if ( (*it2)->getNum() == sAnc.getNum() )
			{
				it2 = it->erase(it2);
				it2 = it->insert(it2, &sNouv);
			}
		}
	}
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

int Sommet::getNum(void) const
{
	return this->num;//*this->sign;
}

int Sommet::getNumSigned(void)
{
	return this->num*this->sign;
}

int Sommet::getSign()
{
	return this->sign;
}

void Sommet::setSign(int s)
{
	if (s>=0) this->sign = 1;
	else this->sign = -1;
}

/////////////////////////////////////////////
///////////////// HASER ////////////////////
/////////////////////////////////////////////

bool Sommet::isEtContains(int et, int num)
{
	vector<Sommet*> v_et = this->getEt(et);
	for (unsigned int i=0; i<v_et.size();++i)
	{
		if (v_et.at(i)->num == num) return true;
	}
	return false;
}

bool Sommet::hasMultipleEt(void) const
{
	return v.size()>1;
}

bool Sommet::hasInterdit(void)
{
	return v.at(0).size()>0;
}

bool operator==(Sommet const & s1, Sommet const & s2)
{
  return s1.num == s2.num && (s1.sign==s2.sign);
}

bool operator!=(Sommet const & s1, Sommet const & s2)
{
  return !(s1==s2);
}

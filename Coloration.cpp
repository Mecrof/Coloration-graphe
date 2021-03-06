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

Coloration::Coloration(Coloration const & c)//:vector<Sommet*>(c)
{
	int i = 0, nbEt, k, j, nbSommet = c.size();
	vector<Sommet*>::iterator itDsEt;
	Sommet * newS;
	//recopier les sommets avec des nouvelles adresses.
	this->num = c.num;
	this->reserve(nbSommet);
	while(i<nbSommet)
	{
		newS = new Sommet(c.at(i)->getNum());
		this->push_back(newS);
		++i;
	};
	i = 0;
	while(i<nbSommet)
	{
		nbEt = c.at(i)->getNumberOfEt();
		j = 0;
		while(j<nbEt)
		{
			if (j>0) this->at(i)->createNewEt(); //car un premier etage est deja crée par defaut.
			for(itDsEt = c.at(i)->getEt(j+1).begin(); itDsEt < c.at(i)->getEt(j+1).end(); ++itDsEt)
			{
				if ((*itDsEt)->getSign()<0)
				{
					newS = new Sommet((*itDsEt)->getNum());
					newS->setSign(-1);
					this->at(i)->getEt(j+1).push_back(newS);
				}
				else
				{
					k = 0;
					while(c.at(k)->getNum()!=(*itDsEt)->getNum() && k<nbSommet)
					{
						k++;
					};
					if (k>=nbSommet)
					{
						cout<<"error:: sommet not found in Coloration cloning ."<<endl;
					}
					else
					{
						newS = this->at(k);
						this->at(i)->getEt(j+1).push_back(newS);
					}
				}
			}
			++j;
		}
		++i;
	};
}

int Coloration::nextSommetWithEt2(unsigned int pos) const
{
	while ( !this->at(pos)->hasMultipleEt() )
	{
		pos++;
		if (pos>=this->size())
		{
			return -1;
		}
	};
	return pos;
}

int Coloration::getNum(void)
{
	return this->num;
}

void Coloration::setNum(int n)
{
	this->num = n;
}

void Coloration::replace(Sommet const & sAnc, Sommet & sNouv)
{
	for (Coloration::iterator it=this->begin();it<this->end();++it)
	{
		(*it)->replace(sAnc, sNouv);
	}
}

void Coloration::displayInConsole(void)
{
	cout<<"----Classe de coloration "<<this->num<<"----"<<endl;
	Coloration::iterator it;
	vector<Sommet*>::iterator it2;
	cout<<"- S(i)\tint(i)"<<endl;
	for (it=this->begin();it!=this->end();it++)
	{
		cout<<"- "<<(*it)->getNum()<<"\t[";
		for (it2=(*it)->getEt(1).begin();it2!=(*it)->getEt(1).end();it2++)
		{
			cout<< (*it2)->getNum()*(*it2)->getSign()<<",";
		}
		cout<<"]"<<endl;
		if((*it)->hasMultipleEt())
		{
			cout<<"   \t[";
			for (it2=(*it)->getEt(2).begin();it2!=(*it)->getEt(2).end();it2++)
			{
				cout<<(*it2)->getNum()<<",";
			}
			cout<<"]"<<endl;
		}
	}
	cout<<"-------------------------"<<endl;
}

void Coloration::displayAddressesInConsole(void)
{
	cout<<"----Classe de coloration ADDR "<<this->num<<"----"<<endl;
	Coloration::iterator it;
	vector<Sommet*>::iterator it2;
	cout<<"- S(i)\tint(i)"<<endl;
	for (it=this->begin();it!=this->end();it++)
	{
		cout<<"- "<<(*it)<<"\t[";
		for (it2=(*it)->getEt(1).begin();it2!=(*it)->getEt(1).end();it2++)
		{
			cout<< (*it2) <<",";
			//cout<< (*it2)->getNum()<<",";
		}
		cout<<"]"<<endl;
		if((*it)->hasMultipleEt())
		{
			//a modifier
			cout<<"   \t[";
			for (it2=(*it)->getEt(2).begin();it2!=(*it)->getEt(2).end();it2++)
			{
				cout<<(*it2)<<",";
			}
			cout<<"]"<<endl;
		}
	}
	cout<<"-------------------------"<<endl;
}

int Coloration::getAmbigousColor(int posSommet)
{
	Sommet * currentSommet = this->at(posSommet);
	vector<Sommet*>::iterator it_SommetDansEt2;
	vector<Sommet*>::iterator it_SommetDansEt1;

	for(it_SommetDansEt1=currentSommet->getEt(1).begin();
			it_SommetDansEt1<currentSommet->getEt(1).end();
			++it_SommetDansEt1)
	{
		if ( (*it_SommetDansEt1)->getNum()==currentSommet->getSommetAt(2,0).getNum())
		{
			return -2;
		}
	}
	bool found = false;
	//boucle sur le premier etage du sommet courant
	for(unsigned int i=0; i<currentSommet->getEt(1).size(); ++i)
	{
		found = false;
		Sommet * sommetDansEt1 = currentSommet->getEt(1).at(i);
		//boucle sur le premiet etage du sommet de l'etage 2 du sommet courant
		for (it_SommetDansEt2=currentSommet->getSommetAt(2,0).getEt(1).begin(); it_SommetDansEt2<currentSommet->getSommetAt(2,0).getEt(1).end();++it_SommetDansEt2)
		{
			if ( (*(*it_SommetDansEt2))==(*(sommetDansEt1)) )
			{
				found = true;
				it_SommetDansEt2 = currentSommet->getSommetAt(2,0).getEt(1).end();
			}
		}
		if (!found)
		{
			Sommet * sommetDansEt2 = &currentSommet->getSommetAt(2,0);
			for(it_SommetDansEt1=sommetDansEt1->getEt(1).begin();it_SommetDansEt1<sommetDansEt1->getEt(1).end();++it_SommetDansEt1)
			{
				if ( (*sommetDansEt2) == (*(*it_SommetDansEt1)) )
				{
					found = true;
					it_SommetDansEt1 = sommetDansEt1->getEt(1).end();
				}
			}
			if(!found)
			{
				return i;
			}
		}
	}
	//si aucune ambiguite est trouvee
	return -1;
}

Sommet * Coloration::getSommetByNum(int n)
{
	Coloration::iterator it_col;
	for (it_col=this->begin(); it_col<this->end(); ++it_col)
	{
		if ( (*it_col)->getNum() == n ) return (*it_col);
	}
	return NULL;
}


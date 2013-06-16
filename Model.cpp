/*
 * Model.cpp
 *
 *  Created on: 2 juin 2013
 *      Author: Mecrof
 */

#include "Model.hpp"

Model::Model():nbClass(0) {
	// TODO Auto-generated constructor stub
}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

void Model::addColoration(const Coloration & c)
{
	this->nbClass++;
	this->vect_col.push_back(c);
}

vector<Coloration> Model::generer(Coloration & col1)
{
	Coloration * newCol;
	//Sleep(1000);
	int tmp;
	Sommet * sTmp;
	unsigned int i = 0;
		//boucle sur le vecteur de sommet d'une classe de coloration
		while(i<col1.size())
		{
			//recupere le premier sommet avec un etage 2
			tmp = col1.nextSommetWithEt2(i);
			// si la classe de coloration contient un sommet avec un etage 2
			if (tmp>=0)
			{
				i=tmp;
				Sommet * sommetAvecEt2 = col1.at(i);
				Sommet * sommetDansEt2 = &sommetAvecEt2->getSommetAt(2,0);
				//recupere l'index du sommet de l'etage 1 qui a une couleur ambigue
				// avec le sommet de l'etage 2.
				int indexEt1 = col1.getAmbigousColor(i);
				if (indexEt1>=0	)
				{
					//creation d'une nouvelle classe de coloration clone de la precedente
					Sommet * sommetDansEt1 = sommetAvecEt2->getEt(1).at(indexEt1);
					newCol = new Coloration(col1);
					this->nbClass++;
					newCol->setNum(this->nbClass);
					// remplace tous les sommets a l'index "indexEt1" par le sommet de l'etage 2 dans la nouvelle classe.
					newCol->replace( (*sommetDansEt1), (*sommetDansEt2));
					Sommet * sommetDansEt2newCol = newCol->at(i)->getEt(2).at(0);
					// si la suppression du sommet de l'etage 2 a bien fonctionnee
					if (newCol->at(i)->removeSommetAt(0, 2)>=0)
					{
						sTmp = newCol->getSommetByNum( sommetDansEt1->getNum() );
						sTmp->getEt(1).clear();
						Sommet tmp((*sommetDansEt2newCol));
						tmp.setSign(-1);
						sTmp->addSommetAt(&tmp,1);
					}
					else
					{
						cout <<"error erasing"<<endl;
					}
					sTmp = col1.getSommetByNum( sommetDansEt1->getNum() );
					sTmp->createNewEt();
					sTmp->addSommetAt(sommetDansEt2,2);

					vector<Coloration> vect1;
					vect1 = generer(col1);
					vector<Coloration> vect2;
					vect2 = generer((*newCol));
					vect1.reserve(vect1.size()+vect2.size());
					vect1.insert(vect1.end(), vect2.begin(), vect2.end());
					return vect1;
				}
				else if (indexEt1==-2)
				{
					col1.at(i)->removeSommetAt(0,2);
				}
				else
				{
					sommetAvecEt2->removeSommetAt(0, 2);
					sommetAvecEt2->addSommetAt(sommetDansEt2, 1);
				}
			}
			else
			{
				i=col1.size();
			}
		};
	vector<Coloration> vect;
	vect.push_back(col1);
	return vect;
}

void Model::displayAll()
{
	vector<Coloration>::iterator it;
	for (it=vect_col.begin();it<vect_col.end();++it)
	{
		it->displayInConsole();
	}
}

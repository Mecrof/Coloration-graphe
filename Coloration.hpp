/*
 * Coloration.hpp
 *
 *  Created on: 26 mai 2013
 *      Author: Antoine
 */

#ifndef COLORATION_HPP_
#define COLORATION_HPP_
#include <iostream>
#include <vector>
#include "Sommet.hpp"
using std::vector;
using namespace std;

class Coloration:public vector<Sommet*>
{
private:
	int num;
public:
	Coloration(int);
	Coloration(Coloration const &);
	int nextSommetWithEt2(unsigned int) const;
	int getNum(void);
	void setNum(int);
	void replace(Sommet const &, Sommet &);
	void displayInConsole(void);
	void displayAddressesInConsole(void);
	int getAmbigousColor(int);
	Sommet * getSommetByNum(int);
};


#endif /* COLORATION_HPP_ */

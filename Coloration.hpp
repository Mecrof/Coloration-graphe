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

class Coloration:public vector<Sommet>
{
private:
	int num;
public:
	Coloration(int);

	int getNumvoid(void);
	void displayInConsole(void);
};


#endif /* COLORATION_HPP_ */

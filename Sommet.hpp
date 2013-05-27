/*
 * Sommet.hpp
 *
 *  Created on: 26 mai 2013
 *      Author: Antoine
 */

#ifndef SOMMET_HPP_
#define SOMMET_HPP_
#include <iostream>
#include <vector>
using std::vector;

class Sommet
{
private:
	int num;
	vector<vector<Sommet*> > v;
public:
	Sommet(int n);
	~Sommet(){};

	vector<Sommet*> & createNewEt(void);
	int removeEt(int);
	int removeEt(vector<Sommet*> &);
	Sommet & addSommetAt(Sommet &, const int);
	int removeSommetAt(Sommet &, const int);

	Sommet & getSommetAt(const int, const int) const;
	vector<Sommet*>& getEt(const int);
	int getNumberOfEt(void);
	int getNum(void);

	bool hasMultipleEt(void);
	bool hasInterdit(void);
};



#endif /* SOMMET_HPP_ */

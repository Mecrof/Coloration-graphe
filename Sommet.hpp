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
	int sign;
	vector<vector<Sommet*> > v;
public:
	Sommet(int n);
	Sommet(Sommet const &);
	~Sommet(){};

	vector<Sommet*> & createNewEt(void);
	int removeEt(int);
	int removeEt(vector<Sommet*> &);
	Sommet & addSommetAt(Sommet *, const int);
	int removeSommetAt(Sommet &, const int);
	int removeSommetAt(int, const int);
	void replace(Sommet const &, Sommet &);

	Sommet & getSommetAt(const int, const int) const;
	vector<Sommet*>& getEt(const int);
	int getNumberOfEt(void);
	int getNum(void) const;
	int getNumSigned(void);

	int getSign(void);
	void setSign(int);

	bool isEtContains(int, int);
	bool hasMultipleEt(void) const;
	bool hasInterdit(void);
	friend bool operator==(Sommet const & s1, Sommet const & s2);
	friend bool operator!=(Sommet const & s1, Sommet const & s2);
};



#endif /* SOMMET_HPP_ */

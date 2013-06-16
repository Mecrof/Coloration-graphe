/*
 * Model.hpp
 *
 *  Created on: 2 juin 2013
 *      Author: Mecrof
 */

#ifndef MODEL_HPP_
#define MODEL_HPP_
#include <iostream>
#include <vector>
#include "Coloration.hpp"
#include "Sommet.hpp"
using std::vector;

class Model {
private:
int nbClass;
vector<Coloration> vect_col;
public:
	Model();
	virtual ~Model();
	void addColoration(const Coloration&);
	vector<Coloration> generer(Coloration &);
	void displayAll();
};

#endif /* MODEL_HPP_ */

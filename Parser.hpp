/*
 * Parser.hpp
 *
 *  Created on: 12 juin 2013
 *      Author: Antoine
 */

#ifndef PARSER_HPP_
#define PARSER_HPP_
#include <iostream>
#include <string>
#include <boost/spirit/include/classic_core.hpp>
//#include <boost/spirit/include/qi.hpp>
#include <boost/bind.hpp>
#include <boost/spirit/include/classic_push_back_actor.hpp>
#include <boost/spirit/include/classic_file_iterator.hpp>
using namespace std;
using namespace boost::spirit;
using namespace BOOST_SPIRIT_CLASSIC_NS;

#include "Coloration.hpp"

class Parser {
private:
	Coloration col;
	string filepath;
public:
	Parser();
	virtual ~Parser();
	void newColoration(int);
	void newSommet(int const&);
	void addSommetEt1(int);
	void addSommetEt2(int);
	bool parseFile();
	void setFilepath(string&);
	string getFilepath();
	Coloration getCol();
};

#endif /* PARSER_HPP_ */

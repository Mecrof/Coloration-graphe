/*
 * Parser.cpp
 *
 *  Created on: 12 juin 2013
 *      Author: Antoine
 */

#include "Parser.hpp"

Parser::Parser():col(0) {
	// TODO Auto-generated constructor stub

}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

void Parser::newColoration(int i)
{
	this->col = (*(new Coloration(i)));
}

void Parser::newSommet(int const& i)
{
	this->col.push_back(new Sommet(i));
}

void Parser::addSommetEt1(int i)
{
	Coloration::iterator vect = this->col.begin();
	while (vect < this->col.end())
	{
		if ((*vect)->getNum()==i)
		{
			this->col.back()->getEt(1).push_back((*vect));
			vect = this->col.end();
		}
		else
		{
			++vect;
		}
	};
}

void Parser::addSommetEt2(int i)
{
	Coloration::iterator vect = this->col.begin();
	while (vect < this->col.end())
	{
		if ((*vect)->getNum()==i)
		{
			if(!this->col.back()->hasMultipleEt())
			{
				this->col.back()->createNewEt();
			}
			this->col.back()->getEt(2).push_back((*vect));
			vect = this->col.end();
		}
		else
		{
				++vect;
		}
	};
}

//*
bool Parser::parseFile()
{
	file_iterator<char> fileStart(filepath);
	if (!fileStart)
	{
		cout << "Impossible d'ouvrir " << filepath << " !" << endl;
		return false;
	}
	file_iterator<char> fileEnd = fileStart.make_end();
	cout<<endl;
	return parse(fileStart, fileEnd,
			str_p("Ordre")>>int_p>>
			*(
					int_p[boost::bind(&Parser::newSommet, &(*this), _1)] >>
					*('['>>
							*(int_p[boost::bind(&Parser::addSommetEt1, &(*this), _1)]
							 >>*ch_p(','))>>
							//*int_p[boost::bind(&Parser::addSommetEt1, &(*this), _1)]>>
					  ']'>>
					  *('['>>
							  *(int_p[boost::bind(&Parser::addSommetEt2, &(*this), _1)]
							   >>*ch_p(','))>>
							   //*int_p[boost::bind(&Parser::addSommetEt2, &(*this), _1)]>>
					   ']')
					 )
			),space_p).full;
	//return parse(fileStart, fileEnd, *(int_p>>ch_p('[')>>*(int_p)>>ch_p(']')>>*(ch_p('[')>>*(int_p)>>ch_p(']'))), space_p).full;
	/*
    *(int_p[&newSommet]>>*space_p>>'['>>*(int_p[&addSommetEt1])>>']'>>*('['>>*(int_p[&addSommetEt2])>>']')>>*space_p)
    return parse(str,
    		(
    				real_p[push_back_a(v)] >> *(',' >> real_p[push_back_a(v)])
    		) ,
    		space_p).full;
    //*/
}
//*/

void Parser::setFilepath(string & str)
{
	this->filepath = str;
}

string Parser::getFilepath()
{
	return this->filepath;
}

Coloration Parser::getCol()
{
	return this->col;
}

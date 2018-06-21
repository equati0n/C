/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

#ifndef PLUSTAB_H
#define	PLUSTAB_H

#include "Table.h"

class PlusTab :public Table {
public:
	PlusTab(unsigned int r, unsigned int c) :Table(r, c) {};
	PlusTab operator+(const PlusTab &);
};

#endif	/* PLUSTAB_H */

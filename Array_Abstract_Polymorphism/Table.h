/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

#ifndef TABLE_H
#define	TABLE_H

#include "AbsTabl.h"

class Table :public AbsTabl {
public:
	Table(unsigned int, unsigned int);
	Table(const Table &);
	virtual ~Table();
	int getSzRow()const { return szRow; }
	int getSzCol()const { return szCol; }
	int getData(int, int)const;
	void setData(int, int, int);
};

#endif	/* TABLE_H */

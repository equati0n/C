/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

#ifndef ABSTABL_H
#define	ABSTABL_H

#include "RowAray.h"

class AbsTabl {
protected:
	int szRow;
	int szCol;
	RowAray **columns;
public:
	virtual int getSzRow()const = 0;
	virtual int getSzCol()const = 0;
	virtual int getData(int, int)const = 0;
};

#endif	/* ABSTABL_H */

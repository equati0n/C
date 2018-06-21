/* 
* Author: Jonathan Baird
* Created on September 20, 2016, 2:51 AM
* Purpose: Make review 2 into a template.                      
*/

#ifndef ABSTABL_H
#define	ABSTABL_H

#include "RowAray.h"
template <class T>
class AbsTabl{
protected:
	int szRow;
	int szCol;
	RowAray<T> **columns;
public:
	virtual int getSzRow()const = 0;
	virtual int getSzCol()const = 0;
	virtual int getData(int,int)const = 0;
};

#endif	/* ABSTABL_H */
/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

#ifndef ABSROW_H
#define	ABSROW_H

class AbsRow {
protected:
	int size;
	int *rowData;
public:
	virtual int getSize()const = 0;
	virtual int getData(int)const = 0;
};

#endif	/* ABSROW_H */

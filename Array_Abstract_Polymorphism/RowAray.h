/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

#ifndef ROWARAY_H
#define	ROWARAY_H

#include "AbsRow.h"

class RowAray :public AbsRow {
public:
	RowAray(unsigned int);
	virtual ~RowAray();
	int getSize()const { return size; }
	int getData(int i)const {
		if (i >= 0 && i < size)return rowData[i];
		else return 0;
	}
	void setData(int, int);
};

#endif	/* ROWARAY_H */

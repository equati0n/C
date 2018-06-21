/* 
* Author: Jonathan Baird
* Created on September 20, 2016, 2:51 AM
* Purpose: Make review 2 into a template.                      
*/

#ifndef PLUSTAB_H
#define	PLUSTAB_H

#include "Table.h"
template <class T>
class PlusTab:public Table<T>{
public:
	PlusTab(unsigned int r,unsigned int c):Table<T>(r,c){};
	PlusTab operator+(const PlusTab &);
};

template <class T>
PlusTab<T> PlusTab<T>::operator+(const PlusTab<T> &a){
	//Initialize a new Table
	PlusTab sum(this->getSzRow(),this->getSzCol());
	for(int row=0;row<szRow;row++){
		for(int col=0;col<szCol;col++){
			sum.columns[col]->setData(row,
				this->columns[col]->getData(row)+a.columns[col]->getData(row));
		}
	}
	return sum;
}

#endif	/* PLUSTAB_H */
/* 
* Author: Jonathan Baird
* Created on September 20, 2016, 2:51 AM
* Purpose: Make review 2 into a template.                      
*/

#ifndef TABLE_H
#define	TABLE_H

#include "AbsTabl.h"
template <class T>
class Table:public AbsTabl<T>{
public:
	Table(unsigned int,unsigned int);
	Table(const Table<T> &);
	virtual ~Table();
	int getSzRow()const {return szRow;}
	int getSzCol()const {return szCol;}
	T getData(int,int)const;
	void setData(int,int,T);
};
template <class T>
Table<T>::Table(unsigned int rows,unsigned int cols){
	szRow=rows;
	szCol=cols;
	columns=new RowAray<T>*[cols];
	for(int col=0;col<cols;col++){
		columns[col]=new RowAray<T>(rows);
	}
}
template <class T>
Table<T>::Table(const Table<T> &a){
	//Create like before
	szRow=a.getSzRow();
	szCol=a.getSzCol();
	columns=new RowAray<T>*[szCol];
	for(int col=0;col<szCol;col++){
		columns[col]=new RowAray<T>(szRow);
	}
	//Copy the data
	for(int row=0;row<szRow;row++){
		for(int col=0;col<szCol;col++){
			int val=a.getData(row,col);
			this->setData(row,col,val);
		}
	}
}

template <class T>
Table<T>::~Table(){
	for(int col=0;col<szCol;col++){
		delete columns[col];
	}
	delete []columns;
}

template <class T>
T Table<T>::getData(int row,int col)const{
	int val=0;
	if(row>=0&&row<szRow&&col>=0&&col<szCol)
		val=columns[col]->getData(row);
	return val;
}
template <class T>
void Table<T>::setData(int row,int col,T val){
	if(row>=0&&row<szRow&&col>=0&&col<szCol)
		columns[col]->setData(row,val);
}


#endif	/* TABLE_H */
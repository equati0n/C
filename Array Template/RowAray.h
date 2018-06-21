/* 
* Author: Jonathan Baird
* Created on September 20, 2016, 2:51 AM
* Purpose: Make review 2 into a template.                      
*/

#ifndef ROWARAY_H
#define	ROWARAY_H
//User Libraries
#include <cstdlib>
#include "AbsRow.h"
template <class T>
class RowAray:public AbsRow<T>{
public:
	RowAray(unsigned int);
	virtual ~RowAray();
	int getSize()const{return size;}
	T getData(int i)const{
		if(i>=0&&i<size)return rowData[i];
		else return 0;}
	void  setData(int,T);
};
template <class T>
RowAray<T>::RowAray(unsigned int n){
	size=n;
	rowData=new T[size];
	for(int i=0;i<size;i++){
		rowData[i]=rand()%90+10;
	}
}
template <class T>
RowAray<T>::~RowAray(){
	delete []rowData;
}

template <class T>
void RowAray<T>::setData(int row,T val){
	if(row>=0&&row<size)rowData[row]=val;
	else rowData[row]=0;
}

#endif	/* ROWARAY_H */
/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

#include "PlusTab.h"

PlusTab PlusTab::operator+(const PlusTab &a) {
	
	PlusTab sum(this->getSzRow(), this->getSzCol());
	for (int row = 0; row < szRow; row++) {
		for (int col = 0; col < szCol; col++) {
			sum.columns[col]->setData(row,
				this->columns[col]->getData(row) + a.columns[col]->getData(row));
		}
	}
	return sum;
}
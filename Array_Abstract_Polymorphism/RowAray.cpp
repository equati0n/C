/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

//User Libraries
#include <cstdlib>

//System Libraries
#include "RowAray.h"

RowAray::RowAray(unsigned int n) {
	size = n;
	rowData = new int[size];
	for (int i = 0; i < size; i++) {
		rowData[i] = rand() % 90 + 10;
	}
}

RowAray::~RowAray() {
	delete[]rowData;
}

void RowAray::setData(int row, int val) {
	if (row >= 0 && row < size)rowData[row] = val;
	else rowData[row] = 0;
}
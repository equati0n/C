/*
* Author: Jonathan Baird
* Created on September 15, 2016, 1:41 AM
*/

#include "Table.h"

Table::Table(unsigned int rows, unsigned int cols) {
	szRow = rows;
	szCol = cols;
	columns = new RowAray*[cols];
	for (int col = 0; col < cols; col++) {
		columns[col] = new RowAray(rows);
	}
}

Table::Table(const Table &a) {

	szRow = a.getSzRow();
	szCol = a.getSzCol();
	columns = new RowAray*[szCol];
	for (int col = 0; col < szCol; col++) {
		columns[col] = new RowAray(szRow);
	}
	
	for (int row = 0; row < szRow; row++) {
		for (int col = 0; col < szCol; col++) {
			int val = a.getData(row, col);
			this->setData(row, col, val);
		}
	}
}

Table::~Table() {
	for (int col = 0; col < szCol; col++) {
		delete columns[col];
	}
	delete[]columns;
}

int Table::getData(int row, int col)const {
	int val = 0;
	if (row >= 0 && row < szRow&&col >= 0 && col < szCol)
		val = columns[col]->getData(row);
	return val;
}

void Table::setData(int row, int col, int val) {
	if (row >= 0 && row < szRow&&col >= 0 && col < szCol)
		columns[col]->setData(row, val);
}
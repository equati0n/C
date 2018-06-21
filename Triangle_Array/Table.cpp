#include "Table.h"

Table::Table(int rows, int cols) {
	szRow = rows;
	szCol = cols;
	records = new RowAray*[cols];
	for (int col = 0; col < cols; col++) {
		records[col] = new RowAray(rows);
	}
}

Table::~Table() {
	for (int col = 0; col < szCol; col++) {
		delete records[col];
	}
	delete[]records;
}

int Table::getData(int row, int col) {
	return records[col]->getData(row);
}
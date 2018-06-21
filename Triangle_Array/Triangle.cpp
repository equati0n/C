#include "Triangle.h"

Triangle::Triangle(int rows) {
	szRow = rows;

	records = new RowAray*[rows];
	for (int col = 0; col < rows; col++) {
		records[col] = new RowAray(rows);
	}
}

Triangle::~Triangle() {
	for (int col = 0; col < szRow; col++) {
		delete records[col];
	}
	delete[]records;
}

int Triangle::getData(int row, int col) {
	return records[col]->getData(row);
}
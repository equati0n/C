/* 
 * Author: Jonathan Baird
 * Created on September 20, 2016, 1:24 AM
 * Purpose: Create Push_back, pop_off functions. 
 *          Then double and 1/2 the size to reduce 
 *          the amount of copying necessary            
 */

#include <cstdlib>
#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main(int argc, char** argv) {
    
	// Mimick a vector with size of 8
	cout << "Here is the initial vector using the default constructor" << endl;
    SimpleVector<int> a(8);
	a.print();

	// Use push_back
	cout << "Using the push_back function I created to add a value" <<endl;
	a.push_back(3);
	a.print();

	// Use pop_off
	cout << "Using the pop_off function I created to subtract a value" <<endl;
	a.pop_off();
	a.print();

	//Double the size
	cout<< "Using my resize function to Double the size of the vector" <<endl;
	a.resizeUp();
	a.print();

	// 1/2 the size
	cout<< "Using my resize function to 1/2 the size of the vector" <<endl;
	a.resizeDwn();
	a.print();
     
	//exit
    return 0;
}

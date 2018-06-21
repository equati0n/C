/* 
 * Author: Jonathan Baird
 * Created on September 20, 2016, 1:24 AM
 * Purpose: Create Push_back, pop_off functions. 
 *          Then double and 1/2 the size to reduce 
 *          the amount of copying necessary            
 */

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
	T *aptr;          // To point to the allocated array
	int arraySize;    // Number of elements in the array
	void memError();  // Handles memory allocation errors
	void subError();  // Handles subscripts out of range

public:
	// Default constructor
	SimpleVector()
	{ aptr = 0; arraySize = 0;}

	// Constructor declaration
	SimpleVector(int);

	// Copy constructor declaration
	SimpleVector(const SimpleVector &);

	// Destructor declaration
	~SimpleVector();

	// Accessor to return the array size
	int size() const
	{ return arraySize; }

	// Accessor to return a specific element
	T getElementAt(int position);

	// Overloaded [] operator declaration
	T &operator[](const int &);

	//adds value to end of array and increases arraySize by one
	T push_back(T);

	//removes value from top and decreases arraySize by one
	T pop_off();

	//prints array to screen
	void print();

	//copies an array
	T *copyArray();   

	// Doubles the array size
	T resizeUp();

	// Half the array size
	T resizeDwn();

};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	// Allocate memory for the array.
	try
	{
		aptr = new T [s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
	//copy array size
	arraySize = obj.arraySize;
	//allocate memory fort the array
	aptr = new T[arraySize];
	if(aptr == 0){
		memError();
	}
	//copy the elements of objt's array
	for(int count = 0; count <arraySize; count++){
		*(aptr + count) = *(obj.aptr + count);
	} 
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//1/2 the array size
template <class T>
T SimpleVector<T>::resizeDwn( ){

	// decrease the size
	arraySize /= 2;

	// Allocate memory for the array.
	aptr = new T [arraySize];

	// Set the elements to zero
	for (int count = 0; count < arraySize; count++){
		aptr[count] = 0; 
	}
	// Return the array
	return *aptr;
}

//Double the array size
template <class T>
T SimpleVector<T>::resizeUp( ){

	// Increase the size
	arraySize *= 2;

	// Allocate memory for the array.
	aptr = new T [arraySize];

	// Set the elements to zero
	for (int count = 0; count < arraySize; count++){
		aptr[count] = 0; 
	}  
	return *aptr;
}

//adds a value to the end of an array
template <class T>
T SimpleVector<T>::push_back(T newNum){

	//copy of previous array
	T *prevArray = copyArray();

	//increases arraySize by one to add new value.
	arraySize = arraySize + 1;

	// Allocate memory for the array.
	aptr = new T [arraySize];

	// Copy the elements of the previous  array.
	for(int i = 0; i < arraySize - 1; i++){
		aptr[i] = prevArray[i];   
	}
	// new value is added to the end of the array
	aptr[arraySize - 1] = newNum; 
	return *aptr;

	delete[] prevArray;
}

//removes value from top of the array
template <class T>
T SimpleVector<T>::pop_off(){

	//copy of previous array
	T *prevArray = copyArray();

	//decrease arraySize by one 
	arraySize = arraySize - 1;

	// Allocate memory for the array.
	aptr = new T [arraySize];

	// Copy the elements of the previous  array.
	//prevArray subscript increased by one to remove top value in copied array
	for(int i = 0; i < arraySize; i++){
		aptr[i] = prevArray[i+1];  	 
	} 
	return *aptr;
	delete[] prevArray;
}

template <class T>
void SimpleVector<T>::print(){
	cout << "The size of the vector is: " << arraySize <<endl;
	cout << "The values are:" << endl;
	for(int i = 0; i < arraySize; i++){
		cout << aptr[i] << " ";
	}
	cout << endl << endl;
}

//copies an array 
template <class T>
T *SimpleVector<T>::copyArray(){
	T *array = new T[arraySize]; 
	for(int i = 0; i < arraySize; i++){
		array[i] = aptr[i];
	}
	return array;
}




#endif
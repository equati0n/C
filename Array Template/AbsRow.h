/* 
 * Author: Jonathan Baird
 * Created on September 20, 2016, 2:51 AM
 * Purpose: Make review 2 into a template.                      
 */

/* 
* Author: Jonathan Baird
* Created on September 20, 2016, 2:51 AM
* Purpose: Make review 2 into a template.                      
*/

#ifndef ABSROW_H
#define	ABSROW_H

template <class T>
class AbsRow{
protected:
	int size;
	T *rowData;
public:
	virtual int getSize()const = 0;
	virtual int getData(int)const = 0;
};

#endif	/* ABSROW_H */
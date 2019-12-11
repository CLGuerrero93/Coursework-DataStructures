/****************************************************************************************
FILE: bag.h
Purpose: Header file for the Bag ADT. 
Author:Dr. Greg Schaper

Invarient properties of bag:
A bag is a container that stores data values of the same type.
The set of data values a bag can store must support the following operations:
   pass-by-value, pass-by-reference, assignment operator =, relational operators
The data values in a bag are not stored in any order.
A bag can contain multiple copies of the same data value.
The capacity of a bag should change as needed to store the data inserted into it.

Data Structures:
Currently supports implementation using linked list or dynamic array data structures.
Data structure is selected using compiler directives.

Date Last Modified:
Created: 10/1/2013


***********************************************************************************/


#include<iostream>

// These two defines are used to select the data structure to use.
#define XXXX_BAG_LINKLIST_XXXX
//#define XXXX_BAG_DYNAMICARRAY_XXXX

// Based on the data structure selected above, include the appropriate file and set the 
// data structure type.
#ifdef XXXX_BAG_LINKLIST_XXXX
   #include "/export/home/student/cguer715/237/p2/linklist.h"
   #define XXXX_BAG_DATASTRUCTURE linklist
#else
 #include "/export/home/student/cguer715/237/CodeBase/DataStructures/DArrayClass/darraylist.h"
 #define XXXX_BAG_DATASTRUCTURE darraylist
#endif


#ifndef XXXXX_BAG_XXXXX
#define XXXXX_BAG_XXXXX


template <class dT>
class bag
{ 
  public:
	// standard value semantics
      bag();
      bag(const bag<dT>& b);
      ~bag();		
      bag<dT> operator =(bag<dT> b);

	 // remove all target members from *this bag. return true if success, false otherwise
      bool removeAllOccurrences(dT target);
	 
	 // remove one target member from *this bag. return true if success, false otherwise.
      bool removeOne(dT target);

	 // return a random item from *this bag. return true if success, false otherwise
      bool peekRandom(dT& item) const;

      bool isMember(dT item) const;








	 // insert item into *this bag
      void insert(dT item);
	 
	 // Union of 2 bags. *this += b or *this + b
      void operator +=(bag b);
      bag operator +(bag b);

	 // Difference of 2 bags. *this -= b or *this - b
      void operator -=(bag b);
      bag operator -(bag b);

	 // return true if *this bag equal to b, false otherwise
      bool operator ==(bag b) const;

	 // return true if *this bag not equal to b, false otherwise
      bool operator !=(bag b) const;

	 // return number of items in *this bag.
      size_t size() const;

	 // return number of taget items currently in *this bag
      size_t count(dT target) const;

	 // return true if *this bag is empty, false otherwise
      bool isEmpty();

	 // print *this bag contents in any order.
      void print(std::ostream& bout, char separator = '\n') const;
   
    private:

	    // container data structure for *this bag.
	    XXXX_BAG_DATASTRUCTURE<dT> data;

	    // remove all items from *this bag.
	    void removeAll();

	    // return true if *this bag is a subset of b.
         bool subsetOf(bag b) const;


    };


template <class dT>
std::ostream& operator << (std::ostream& bout, bag<dT> b);

#include"bag.cxx"


#endif

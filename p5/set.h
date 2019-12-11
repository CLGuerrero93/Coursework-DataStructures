/****************************************************************************************
FILE: set.h
Purpose: Header file for the Set ADT. 
Author:Dr. Greg Schaper

Invarient properties of bag:
A set is a container that stores data values of the same type.
The data values a set can store must support the following operations:
   pass-by-value, pass-by-reference, assignment operator =, relational operators
The data values in a set are not stored in any order.
A set cannot contain multiple copies of the same data value.
The capacity of a set should change as needed to store the data inserted into it.

Data Structures:
Currently supports implementation using linked list or dynamic array data structures.
Data structure is selected using compiler directives.

Date Last Modified:
Created: 10/1/2013


***********************************************************************************/


#include<iostream>
#include "/export/home/student/cguer715/237/p4/bag.h"
#ifndef XXXXX_SET_XXXXX
#define XXXXX_SET_XXXXX

template <class dT>
class set: public bag<dT>
{ 
  public:
	// standard value semantics
      set();
      set(const set<dT>& b);
      ~set();		
      set<dT> operator =(set<dT> b);

	 // remove target from *this set. return true if success, false otherwise
      bool remove(dT target);

	 // return a random item from *this set. return true if success, false otherwise
      bool peekRandom(dT& item) const;

        // return true if item is in *this set, false otherwise.
      //      bool isMember(dT item) const;

	 // insert item into *this set
      void insert(dT item);
	 
	 // Union of 2 sets. *this += b or *this + b
      void operator +=(set b);
      set operator +(set b);

	 // Difference of 2 set. *this -= b or *this - b
      void operator -=(set b);
      set operator -(set b);

        // Intersection of 2 sets 
      void operator *=(set b);
      set operator *(set b);

	 // return true if *this set equal to b, false otherwise
      bool operator ==(set b) const;

	 // return true if *this set not equal to b, false otherwise
      bool operator !=(set b) const;

	 // return number of items in *this set.
      // size_t size( ) const;

	 // return true if *this set is empty, false otherwise
      bool isEmpty();

        // return true if *this set is a subset of b.
      bool isSubsetOf(set b);

	 // print *this set contents in any order.
      //void print(std::ostream& bout, char separator = '\n') const;
   
    private:
      //remove all values in set
      void removeAll();

};


template <class dT>
std::ostream& operator << (std::ostream& bout, bag<dT> b);

#include"set.cxx"


#endif

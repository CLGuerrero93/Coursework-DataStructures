/*********************************************************
Filename: stack.h
PURPOSE: Header file Stack ADT
Author: DR. Greg Schaper

INVARIENT PROPERTIES:
Stack ADT is a container that organizes data temporally in a
Last-In-First-Out fashion. 
A stack conatainer object stores data of a single type.
Stack class supports creation of stack objects capable of 
storing any data type that supports the following operations:
- pass-by-value (copy constructor for objects)
- copy assignment: operator =
- stream insertion: operator <<
- new and delete memory management (destructor for objects)


Modification History:
Created: 10/14/2012

 ********************************************************/
#include "/export/home/student/cguer715/237/p2/linklist.h"
#ifndef XXXXX_STACK_XXXXX
#define XXXXX_STACK_XXXXX

typedef int dT;
template <class dT>
class stack:public linklist<dT>
{
 public:
  /***************
   Standard Value Semantic Methods
   ***************/
  stack();
  stack(const stack& original);
  stack operator = (stack original);
  ~stack();

  // insert anItem on top of the stack
  void push(dT anItem);

  // remove the top item from the stack
  void pop();

  // return the value of the top item on the stack
  dT peek() const;

  // return true if stack is empty, otherwise return false
  bool isEmpty() const;

  // print the contents of the stack to outStream in Last-In-First-Out order
  //void print(std::ostream& outStream, char separator = '\n') const;

};



// overloaded stream insertion for printing a stack.
//std::ostream& operator <<(std::ostream& outstream, stack<dT> S);


#include "stack.cxx"
#endif

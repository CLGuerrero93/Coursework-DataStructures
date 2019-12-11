/*********************************************************
Filename: queue.h
PURPOSE: Header file Queue ADT
Author: DR. Greg Schaper

INVARIENT PROPERTIES:
Queue ADT is a container that organizes data temporally in a
First-In-First-Out fashion. 
A queue container object stores data of a single type.
Queue class supports creation of queue objects capable of 
storing any data type that supports the following operations:
- pass-by-value (copy constructor for objects)
- copy assignment: operator =
- stream insertion: operator <<
- new and delete memory management (destructor for objects)


Modification History:
Created: 10/14/2012

 ********************************************************/
#include "/export/home/student/cguer715/237/p2/linklist.h"
#ifndef XXXXX_QUEUE_XXXXX
#define XXXXX_QUEUE_XXXXX

typedef int dT;
template <class dT>
class queue:public linklist<dT>
{
 public:
  /***************
   Standard Value Semantic Methods
   ***************/
  queue();
  queue(const queue& original);
  queue operator = (queue original);
  ~queue();

  // insert anItem at the end of the queue
  void push(dT anItem);

  // remove the oldest item in the queue from the queue
  void pop();

  // return the value of the oldest item in the queue
  dT peek() const;

  // return true if queue is empty, otherwise return false
  bool isEmpty() const;

  // print the contents of the queue to outStream in First-In-First-Out order
  //void print(std::ostream& outStream, char separator = '\n') const;

};



// overloaded stream insertion for printing a queue.
//std::ostream& operator <<(std::ostream& outstream, queue<dT> S);


#include "queue.cxx"
#endif

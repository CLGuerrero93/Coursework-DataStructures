// Author:          Cassandra Guerrero adapted from Dr. Spiegel
// Creation Date:   2 September 2014
// Due Date:        4 September 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #1
// Filename:        LinkedList.h
// Purpose:         LinkedList class declaration. Contains Default 
//                  Constructor, Copy Constructor, Destructor, a 
//                  function to append a node to the end of the list, 
//                  a function to determine if the LinkedList is empty,
//                  and a function to output the list using << operator.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

class node
{
  friend class LinkedList;

 public:
  // Function Name:  node (CONSTRUCTOR)
  // Description:    Constructs an empty node pointing to NULL.
  // Parameters:     None
  // Return Value:   None
  node(void):next(NULL){ }

  // Function Name:  node (CONSTRUCTOR)
  // Description:    Constructs a node containing int value and
  //                 pointing to NULL.
  // Parameters:     int value (IMPORT) - the integer to be held
  // Return Value:   None
  node(int value):data(value), next(NULL){ }

  // Function Name:  node (CONSTRUCTOR)
  // Description:    Constructs a node containing int value and
  //                 pointing to the next node.
  // Parameters:     int value (IMPORT) - the integer to be held.
  //                 node *after (IMPORT) - the pointer at the next node.
  // Return Value:   None
  node(int value, node *after):data(value), next(after){ }

  // Function Name:  getData
  // Description:    Returns the value within the node.
  // Parameters:     None
  // Return Value:   int data (EXPORT) - the value within the node.
  //  int getData(void){return data;}

  // Function Name:  getNext
  // Description:    Returns the pointer at the next node.
  // Parameters:     None
  // Return Value:   node *next (EXPORT) - the pointer at the next node.
  //  node *getNext(void){return next;}

 private:
  int data; // The value within the node.
  node *next; // The pointer which points at the next node in the list.
};

class LinkedList
{
  friend class node;

 public:
  // Function Name:  LinkedList (CONSTRUCTOR)
  // Description:    Constructs an empty LinkedList.
  // Parameters:     None
  // Return Value:   None
  LinkedList();

  // Function Name:  LinkedList (COPY CONSTRUCTOR)
  // Description:    Constructs a copy of another LinkedList.
  // Parameters:     LinkedList &l (IMPORT)
  // Return Value:   None
  LinkedList(LinkedList &l);

  // Function Name:  ~LinkedList (DESTRUCTOR)
  // Description:    Destructs a LinkedList.
  // Parameters:     None
  // Return Value:   None
  ~LinkedList();

  // Function Name:  append
  // Description:    Appends another node to the end of a LinkedList.
  // Parameters:     int value (IMPORT) - the value to be held.
  // Return Value:   None
  void append(int value);

  // Function Name:  output
  // Description:    Outputs all the values in the LinkedList.
  // Parameters:     ostream &os (IMPORT) - output stream
  // Return Value:   None
  void output(ostream &os);

  // Function Name:  empty
  // Description:    Determines if the LinkedList is empty by checking 
  //                 if the head pointer is pointing at NULL.
  // Parameters:     None
  // Return Value:   bool (EXPORT) - 1 if the list is empty, 0 if it isn't.
  bool empty();

  // Function Name:  getHead
  // Description:    Returns the head pointer of a LinkedList
  // Parameters:     None
  // Return Value:   node* (EXPORT) - head pointer of the LinkedList
  //  node *getHead();

  // Function Name:  getLast
  // Description:    Returns the pointer at last node in a LinkedList
  // Parameters:     None
  // Return Value:   node* (EXPORT) - pointer at last node of LinkedList
  //  node *getLast();

  // Function Name:  getFirst
  // Description:    Returns the pointer named first in a LinkedList
  // Parameters:     None
  // Return Value:   node* (EXPORT) - pointer named first in LinkedList
  //  node *getFirst();

  void writeFile();//LinkedList &L);

 private:
  node *head; //Head pointer of the list.
  node *first; // Holds the last node added (one before the last in the list)
  node *last;  // Holds the new node (the last node in the list)
};

// Function Name:  <<
// Description:    Outputs the values in a LinkedList
// Parameters:     ostream &os (IMPORT/EXPORT) - output stream
//                 LinkedList &l (IMPORT)- LinkedList to be output
// Return Value:   ostream (IMPORT/EXPORT) - output stream
ostream& operator<<(ostream& os, LinkedList& l);

#endif

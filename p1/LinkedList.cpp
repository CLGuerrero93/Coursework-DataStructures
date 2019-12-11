// Author:          Cassandra Guerrero adapted from Dr. Spiegel
// Creation Date:   2 September 2014
// Due Date:        4 September 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #1
// Filename:        LinkedList.cpp
// Purpose:         LinkedList class definition.

#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(void):head(NULL), first(NULL), last(NULL){ }

LinkedList::LinkedList(LinkedList &l)
{
  node *p = l.head;       // p will iterate through the list to be copied
  while(p != NULL)
    {
      append(p -> data);  // Add the copy of the node to the end
      p = p -> next;      // Move p
    }
}

LinkedList::~LinkedList()
{
  while(!empty())
    {
      node *p = head;       // Point p to the head of the list
      head = head -> next;  // Move the head of the list
      delete p;
    }
}

void LinkedList::append(int value)
{
  last = new node (value, NULL);   // Create a new node to append to end
  if (empty())
    head = first = last;           // Only one node in the list
  else
    first = first -> next = last;  // Point previous node to new node,
                                   // move first pointer
}

void LinkedList::output(ostream &os)
{  
  node *p = head;
  while(p != NULL)
    {  
      os << p -> data << " ";
      p = p -> next;
    }
}

inline bool LinkedList::empty(){return (head == NULL);}

void LinkedList::writeFile()
{
  ofstream outfile;
  outfile.open("largest.dat");
  node *p = head;
  node *lp = last;
  while (p != NULL)
    {
      if ((p -> data) > (lp -> data))
	outfile<<(p -> data)<<endl;
      p = p -> next;
    }
  outfile.close();
}

//node* LinkedList::getLast(){return last;}

//node* LinkedList::getFirst(){return first;}

ostream& operator<<(ostream& os, LinkedList& l)
{
  l.output(os);
  return os;
}

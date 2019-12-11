// Author:          Cassandra Guerrero 
// Creation Date:   22 September 2014
// Due Date:        23 September 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #3
// Filename:        p2.cpp
// Purpose:         Assignment #2 test file.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "rational.h"
#include "linklist.h"

typedef rational T;

int main()
{
  std::cout<<"This is a test.\n";
  linklist<T> L1;
  std::cout<<"L1 created.\n";
  L1.insertEnd(5);
  std::cout<<"L1 "<<L1<<'\n';
  L1.insertFront(7);
  std::cout<<"L1 "<<L1<<'\n';
  L1.insertEnd(9);
  std::cout<<"L1 "<<L1<<'\n'; 
  L1.insertByPosition(2,4);
  std::cout<<"L1 "<<L1<<'\n';
  linklist<T> L2(L1);
  std::cout<<"L2 created.\n"<<"L2 "<<L2<<'\n';
  linklist<T> L3;
  std::cout<<"L3 created.\n";
  L3.insertFront(5);
  std::cout<<"L3 "<<L3<<'\n';
  L3 = L1;
  std::cout<<"L3 "<<L3<<'\n';
  L2.insertByValue(3);
  std::cout<<"L2 "<<L2<<'\n';
  L2.insertByValue(6);
  std::cout<<"L2 "<<L2<<'\n';
  T a = L1[3];
  T b = L1[4];
  L1.swapDataItem(a, b);
  std::cout<<"L1 "<<L1<<'\n';
  L3.removeFront();
  std::cout<<"L3 "<<L3<<'\n';
  L2.removeEnd();
  std::cout<<"L2 "<<L2<<'\n';
  L1.removeByPosition(2);
  std::cout<<"L1 "<<L1<<'\n';
  L2.insertFront(6);
  std::cout<<"L2 "<<L2<<'\n';
  L2.removeByValue(6);
  std::cout<<"L2 "<<L2<<'\n';
  L2.removeByValue(6);
  std::cout<<"L2 "<<L2<<'\n';
  std::cout<<"L1 "<<L1.peekEnd()<<"\n";
  L1.removeAll();
  std::cout<<"L1 All Removed.\n";
  std::cout<<L3.peekFront()<<'\n';
  std::cout<<L3.peekByPosition(3)<<'\n';
  std::cout<<L2.peekByValue(4)<<'\n';
  std::cout<<L2.peekByValue(2)<<'\n';
  
  return 0;
}

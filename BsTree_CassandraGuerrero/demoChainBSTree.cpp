//Author:          Cassandra Guerrero
//Creation Date:   27 October 2015
//Due Date:        28 October 2015
//Course:          CSC 402
//Professor Name:  Dr. Wang
//Assignment:      6
//Filename:        bsTree.h
//Purpose:         Definition of ADT Binary Search Tree               

#include <iostream>
#include "chainBSTree.cxx"

using namespace std;

int main()
{
  chainBSTree Redwood;

  Redwood.insert(pair<int, int>(6, 1));
  Redwood.insert(pair<int, int>(4, 2));
  Redwood.insert(pair<int, int>(8, 3));
  Redwood.insert(pair<int, int>(3, 4));
  Redwood.insert(pair<int, int>(5, 5));
  Redwood.insert(pair<int, int>(7, 6));
  Redwood.insert(pair<int, int>(9, 7));
  Redwood.insert(pair<int, int>(9, 10));

  cout<<"Value "<<Redwood.find(9)<<" is stored at key 9."<<endl;
  cout<<"Value "<<Redwood.find(1)<<" is stored at key 1."<<endl;
  cout<<"Redwood Tree:  ";
  Redwood.ascend();

  cout<<"Erasing node with key 9.\n";
  Redwood.erase(9);
  cout<<"Redwood Tree:  ";
  Redwood.ascend();

  return 0;
}

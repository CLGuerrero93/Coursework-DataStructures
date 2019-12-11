//Author:          Cassandra Guerrero
//Creation Date:   27 October 2015
//Due Date:        28 October 2015
//Course:          CSC 402
//Professor Name:  Dr. Wang
//Assignment:      6
//Filename:        bsTree.h
//Purpose:         Definition of ADT Binary Search Tree

#include <utility>

using namespace std;

class bsTree
{
 public:

  virtual ~bsTree() {}

  //Find value from key
  virtual int find(int key) = 0;

  //Insert pair(key, value)
  virtual void insert(pair<int, int> p) = 0;

  //Remove value from key
  virtual void erase(int key) = 0;

  //In-order Tree Traversal
  virtual void ascend() = 0;

};

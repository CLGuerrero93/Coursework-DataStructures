//Author:          Cassandra Guerrero
//Creation Date:   27 October 2015
//Due Date:        28 October 2015
//Course:          CSC 402
//Professor Name:  Dr. Wang
//Assignment:      6
//Filename:        chainBSTree.h
//Purpose:         Definition of Binary Search Tree using a linked list

#include <utility>
#include <set>
#include "bsTree.h"
#include "nodeBST.h"

using namespace std;

class chainBSTree : public bsTree
{
 private:
  nodeBST *root;

 public:

  //constructor
  chainBSTree(): root(NULL) {};

  //destructor
  ~chainBSTree(){}

  //Find value from key
  int find(int key);

  //Insert pair(key, value)
  void insert(pair<int, int> p);

  //Remove value from key
  void erase(int key);

  //In-order Tree Traversal
  void ascend();

  //print helper for ascend
  void print(nodeBST *parent);
};

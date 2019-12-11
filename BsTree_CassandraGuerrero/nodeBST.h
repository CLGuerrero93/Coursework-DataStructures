//Author:          Cassandra Guerrero
//Creation Date:   28 October 2015
//Due Date:        28 October 2015
//Course:          CSC 402
//Professor Name:  Dr. Wang
//Assignment:      6
//Filename:        nodeBST.h
//Purpose:         Definition of node for Binary Search Tree

#include <utility>

using namespace std;

//template <typename T>
struct nodeBST
{
  pair<int, int> P;
  //nodeBST< pair<int, int> > *leftChild, *rightChild;
  nodeBST *leftChild, *rightChild;

  nodeBST() {}
 
  nodeBST(const pair<int, int> &P)
  {
    this->P = P;
    leftChild = NULL;
    rightChild = NULL;
  }

  //nodeBST(const pair<int, int> &P, nodeBST< pair<int, int> > *leftChild)
  nodeBST(const pair<int, int> &P, nodeBST *leftChild)
  {
    this->P = P;
    this->leftChild = leftChild;
  }

  //nodeBST(const pair<int, int> &P, nodeBST< pair<int, int> > *leftChild, nodeBST< pair<int, int> > *rightChild)
  nodeBST(const pair<int, int> &P, nodeBST *leftChild, nodeBST *rightChild)
  {
    this->P = P;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }
 
};

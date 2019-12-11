//Author:          Cassandra Guerrero
//Creation Date:   27 October 2015
//Due Date:        28 October 2015
//Course:          CSC 402
//Professor Name:  Dr. Wang
//Assignment:      6
//Filename:        chainBSTree.cxx
//Purpose:         Implementation of Binary Search Tree using a linked list

#include <utility>
#include <iostream>
#include <set>
#include "chainBSTree.h"

using namespace std;

int chainBSTree::find(int key)
{
  nodeBST *parent = root;

  while(parent->P.first != key)
    {
      if(key < parent->P.first && parent->leftChild != NULL)
	parent = parent->leftChild;

      else if(key > parent->P.first && parent->rightChild != NULL)
	parent = parent->rightChild;

      else 
	{
	  cout<<"A node with key "<<key<<" does not exist.  Returning value -1."<<endl;
	  return -1;
	}
    }

  return parent->P.second;
}

void chainBSTree::insert(pair<int, int> p)
{
  nodeBST *parent, *child, *newNode;
  newNode = new nodeBST(p);
  parent = root;
  child = root;
  bool valid = true; //turns false if key is in use

  if(parent == NULL) //if newNode will be root
    root = newNode;

  else //if newNode is not in use
    {
      while(child != NULL && valid) //search for insertion point
	{
	  if(p.first < child->P.first) //move to leftChild
	    {
	      parent = child;
	      child = child->leftChild;
	    }
	  else if(p.first > child->P.first)//move to rightChild
	    {
	      parent = child;
	      child = child->rightChild;
	    }
	  else //key already exists
	    {
	      cout<<"Insertion attempted at key "<<p.first<<".  This value is already in use."
		  <<"\nPlease erase the node with key "<<p.first<<" before attempting insertion.\n";
	      valid = false;
	    }
	}
      if(valid)
	{
	  if(child == parent->leftChild)
	    parent->leftChild = newNode;
	  else
	    parent->rightChild = newNode;
	}
    }
}

void chainBSTree::erase(int key)
{
  nodeBST *parent, *child, *largest, *largestParent;
  parent = root;
  child = root;
  bool valid = true;

  if(root == NULL) //do not try to erase from an empty tree!
    valid = false;

  while(child->P.first != key && valid) //search for key
    {
      if(key < child->P.first) //move to leftChild
	{
	  parent = child;
	  child = child->leftChild;
	}
      else if(key > child->P.first)//move to rightChild
	{
	  parent = child;
	  child = child->rightChild;
	}
      else //key does not exist
	{
	  cout<<"Cannot delete node with key "<<key<<" because it does not exist."<<endl;
	  valid = false;
	}
    }

  if(valid)
    {
      if(child->leftChild == NULL && child->rightChild == NULL) //leaf
	{
	  if(child == parent->leftChild)
	    {
	      parent->leftChild = child->leftChild;
	      delete child;
	    }
	  else
	    {
	      parent->rightChild = child->rightChild;
	      delete child;
	    }
	}
      else if(child->leftChild != NULL && child->rightChild == NULL) //one child on left
	{
	  if(child == parent->leftChild)
	    {
	      parent->leftChild = child->leftChild;
	      delete child;
	    }
	  else
	    {
	      parent->rightChild = child->leftChild;
	      delete child;
	    }
	}
      else if(child->leftChild == NULL && child->rightChild != NULL) // one child on right
	{
	  if(child == parent->leftChild)
	    {
	      parent->leftChild = child->rightChild;
	      delete child;
	    }
	  else
	    {
	      parent->rightChild = child->rightChild;
	      delete child;
	    }
	}
      else //2 children
	{
	  largest = child->leftChild;
	  largestParent = child->leftChild;
	  while(largest->rightChild != NULL)
	    {
	      largestParent = largest;
	      largest = largest->rightChild;
	    }
	  largestParent->rightChild = largest->leftChild;
	  largest->leftChild = child->leftChild;
	  largest->rightChild = child->rightChild;
	  if(child == parent->leftChild)
	    {
	      parent->leftChild = largest;
	      delete child;
	    }
	  else
	    {
	      parent->rightChild = largest;
	      delete child;
	    }
	}
    }
}

void chainBSTree::ascend()
{
  nodeBST *parent = root;
  if(parent != NULL)
    {
      parent = root;
      print(parent);
      cout<<endl;
    }
}

void chainBSTree::print(nodeBST *parent)
{
  if(parent->leftChild != NULL)
    print(parent->leftChild);

  cout<<parent->P.first<<" ";

  if(parent->rightChild != NULL)
    print(parent->rightChild);
}


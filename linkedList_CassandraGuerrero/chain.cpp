#include <iostream>
#include "chain.h"

template<typename T> chain<T>::chain()
{
  listSize = 0;
  firstNode = NULL;
}

template<typename T> chain<T>::chain(const chain<T>& theList)
{
  listSize = 0;
  firstNode = NULL;
  if(!theList.empty())
    {
      for(int i = 0; i < theList.size(); i++)
	  insert(i, theList.get(i));
    }
}

template<typename T> chain<T>::~chain()
{
  chainNode<T>* p = firstNode;
  for(int i = 0; i < listSize; i++)
    {
      firstNode = firstNode->next;
      delete p;
      p = firstNode;
    }
}

template<typename T> bool chain<T>::empty() const {return(firstNode == NULL);}

template<typename T> int chain<T>::size() const {return listSize;}

template<typename T> T& chain<T>::get(int theIndex) const
{
  chainNode<T>* p = firstNode;
  if(theIndex != 0)
    {
      for(int i = 0; i < theIndex; i++)
	p = p -> next;
    }
  return p->element;
}

template<typename T> int chain<T>::indexOf(const T& theElement) const
{
  int index = -1;
  chainNode<T>* currentNode = firstNode;
  for(int i = 0; i < listSize; i++)
    {
      if(currentNode->element == theElement)
	return i;
      currentNode = currentNode->next;
    }
  return index;
}

template<typename T> void chain<T>::erase(int theIndex)
{
  checkIndex(theIndex);
  chainNode<T>* p = firstNode;
  if(theIndex == 0)
    {
      firstNode = firstNode->next;
      delete p;
    }
  else
    {
      chainNode<T>* beforeNode = firstNode;
      p = p->next;
      for(int i = 0; i < theIndex-1; i++)
	{
	  beforeNode = beforeNode->next;
	  p = p->next;
	}
      beforeNode->next = p->next;
      delete p;
    }
  listSize--;
}

template<typename T> void chain<T>::insert(int theIndex, const T& theElement)
{
  checkIndex(theIndex);
  chainNode<T>* newNode = new chainNode<T>(theElement);
  chainNode<T>* beforeNode = firstNode;
    
  if(theIndex == 0)
    {
      newNode->next = firstNode;
      firstNode = newNode;
    }
  else 
    {
      for(int i = 0; i < theIndex-1; i++)
	beforeNode = beforeNode->next;
      newNode->next = beforeNode->next;
      beforeNode->next = newNode;
    }
  listSize++;
}

template<typename T> void chain<T>::output(ostream& out) const
{
  chainNode<T>* p = firstNode;
  for(int i = 0; i < listSize; i++)
    {
      out<<p->element<<" ";
      p = p->next;
    }
  out<<endl;
}

template<typename T> void chain<T>::checkIndex(int theIndex)
{
  if(theIndex < 0 || theIndex > listSize)
    {
      cout<<"Invalid index\n";
      return;
    }
}

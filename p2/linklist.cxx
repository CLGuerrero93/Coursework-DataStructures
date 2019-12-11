// Author:          Cassandra Guerrero 
// Creation Date:   13 September 2014
// Due Date:        23 September 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #2
// Filename:        linklist.cxx
// Purpose:         template class linklist class definition.

#include<iostream>
#include<fstream>
#include<cstdlib>

template <class T>
linklist<T>::linklist(void):headPointer(NULL)
{}//std::cout<<"linklist constructor\n"; }

template <class T>
linklist<T>::linklist(const linklist<T>& original)
{
  headPointer = NULL;
  node* p = original.headPointer;
  while (p != NULL)
    {
      insertEnd(p -> dataItem);
      p = p -> linkPointer;
    }
}

template <class T>
linklist<T> linklist<T>::operator =(linklist<T> rhs)
{
  node *p = rhs.headPointer;
  removeAll();
  while (p != NULL)
    {
      insertEnd(p -> dataItem);
      p = p -> linkPointer;
    }
  return (*this);
}

template <class T>
linklist<T>::~linklist(){removeAll();}

template <class T> 
inline bool linklist<T>::isEmpty() const {return (headPointer == NULL);}

template <class T> 
std::size_t linklist<T>::NumberOfItems() const 
{
  size_t numItems = 0;
  node *p = headPointer;
  while (p != NULL)
    {
      numItems++;
      p = p -> linkPointer;
    }
  return numItems;
}

template <class T> 
void linklist<T>::insertFront(T anItem)
{headPointer = new node(anItem, headPointer);}

template <class T> 
void linklist<T>::insertEnd(T anItem)
{
  node *p = headPointer;
  if (p == NULL)
    insertFront(anItem);
  else
    {
      while (p -> linkPointer != NULL)
	p = p -> linkPointer;
      p -> linkPointer = new node(anItem, p -> linkPointer);
    }
}

template <class T> 
void linklist<T>::insertByPosition(std::size_t index, T anItem)
{
  if (index <= NumberOfItems() && index > 0)
    {
      size_t position = 1;
      node *p = headPointer;
      while (position < index-1)
	{
	  p = p -> linkPointer;
	  position++;
	}
      p -> linkPointer = new node(anItem, p -> linkPointer);
    }
}

template <class T>
void linklist<T>::swapDataItem(T& x, T& y)
{
  size_t xindex = peekByValue(x);
  size_t yindex = peekByValue(y);

  if (NumberOfItems() > 1 && xindex != 0 && yindex != 0)
    {
      node *px = headPointer;
      node *py = headPointer;
      size_t pospx = 1;
      size_t pospy = 1;

      while (pospx < xindex)
	{
	  px = px -> linkPointer;
	  pospx++;
	}

      T hold = px -> dataItem;

      while (pospy < yindex)
	{
	  py = py -> linkPointer;
	  pospy++;
	}

      px -> dataItem = py -> dataItem;
      py -> dataItem = hold;

      }
}

template <class T>
void linklist<T>::insertByValue(T anItem)
{
  node *p = headPointer;
  if (isEmpty() || anItem < p -> dataItem)
    insertFront(anItem);
  else
    {
      while (p -> linkPointer != NULL && anItem > 
	     p -> linkPointer -> dataItem)
	p = p -> linkPointer;
      p -> linkPointer = new node(anItem, p -> linkPointer);
    }
}

template <class T>
T linklist<T>::peekFront() const 
{
  if(!isEmpty())
    return (headPointer -> dataItem);
}

template <class T>
T linklist<T>::peekEnd() const 
{
  if(!isEmpty())
    {
      node *p = headPointer;
      while (p -> linkPointer != NULL)
	p = p -> linkPointer;
      return (p -> dataItem);
    }
}

template <class T>
T linklist<T>::peekByPosition(std::size_t index) const 
{
  if(index <= NumberOfItems() && index > 0)
    {
      node* p = headPointer;
      size_t position = 1;
      while (position < index)
	{
	  p = p -> linkPointer;
	  position++;
	}
      return (p -> dataItem);
    }
}

template <class T>
std::size_t linklist<T>::peekByValue(T anItem) const
{
  if (!isEmpty())
    {
      node *p = headPointer;
      size_t index = 0, position = 1;
      while (p != NULL)
	{
	  if (p -> dataItem != anItem)
	    {
	      p = p -> linkPointer;
	      position++;
	    }
	  else
	    {
	      index = position;
	      return index;
	    }
	}
    }
  return 0;
}

template <class T>
void linklist<T>::removeFront()
{
  if (!isEmpty())
    {
      node *p = headPointer;
      headPointer = headPointer -> linkPointer;
      delete p;
    }
}

template <class T>
void linklist<T>::removeEnd()
{
  if (!isEmpty())
    {
      node *p = headPointer;
      node *tp = headPointer;
      p = p -> linkPointer;      
      while (p -> linkPointer != NULL)
	{
	  p = p -> linkPointer;
	  tp = tp -> linkPointer;
	}
      tp -> linkPointer = p -> linkPointer;
      delete p;
    }
}

template <class T>
void linklist<T>::removeByPosition(size_t index)
{
  if (index <= NumberOfItems() && index > 0)
    {
      node *p = headPointer;
      size_t position = 1;
      while (position < index-1)
	{
	  p = p -> linkPointer;
	  position++;
	}
      node *doomed = p -> linkPointer;
      p -> linkPointer = doomed -> linkPointer;
      delete doomed;
    }
}

template <class T>
void linklist<T>::removeByValue(T anItem)
{ 
  if (!isEmpty())
    {
      node *p = headPointer;
      if (anItem == p -> dataItem)
	removeFront();
      else
	{
	  while (p -> linkPointer != NULL && anItem != 
		 p -> linkPointer -> dataItem)
	    p = p -> linkPointer;
	  if (p -> linkPointer != NULL)
	    {
	      node *doomed = p -> linkPointer;
	      p -> linkPointer = doomed -> linkPointer;
	      delete doomed;
	    }
	}
    }
}

template <class T>
void linklist<T>::removeAll()
{
  while (!isEmpty())
    removeFront();
}

template <class T>
void linklist<T>::print(std::ostream& outStream, char separator) const
{
  separator = ' ';
  node *p = headPointer;
  while (p != NULL)
    {
      outStream << p -> dataItem << separator;
      p = p -> linkPointer;
    }
}

template <class T>
T const& linklist<T>::operator[](size_t position) const
{
  if (position <= NumberOfItems() && position > 0)
    {
      node *p = headPointer;
      size_t index = 1;
      while (index < position)
	{
	  p = p -> linkPointer;
	  index++;
	}
      return (p -> dataItem);
    }
}

template <class T>
T& linklist<T>::operator[](size_t position)
{
  if (position <= NumberOfItems() && position > 0)
    {
      node *p = headPointer;
      size_t index = 1;
      while (index < position)
	{
	  p = p -> linkPointer;
	  index++;
	}
      return (p -> dataItem);
    }
}

template <class T>
std::ostream& operator <<(std::ostream& outStream, linklist<T> list)
{ 
  list.print(outStream);
  return outStream;
}

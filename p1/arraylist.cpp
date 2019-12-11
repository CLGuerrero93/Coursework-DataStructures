//Author:          Cassandra Guerrero
//Creation Date:   04 September 2015
//Due Date:        13 September 2015
//Course:          CSC 402
//Professor Name:  Dr. Wang
//Assignment:      #1
//Filename:        arrayList.cpp
//Purpose:         arrayList class definition and implementation

#include <iostream>
#include <string>

using namespace std;

class arrayList{

private:

  int *element; // all items are int type
  int listSize; // number of elements in array
  int arrayLength; // capacity of the 1D array
	
public:

  //constructor
  arrayList();
  arrayList(int n);
  arrayList(arrayList &A);
  ~arrayList(){delete [] element;}
	
  int size() const{return listSize;}
  int length() const {return arrayLength;}
  bool empty() const {return listSize==0;}
		
  //add new item at end of the arrayList
  void add(const int n);

  //insert new item at index
  void insert(int index, const int n);

  //remove the item at index
  void erase(int index);

  //return the index of the element
  int indexOf(int n) const;

  //return the item at the index
  int get(int index) const;

  void output(ostream &out) const;
		
private:

  //change 1D array length
  void changeArrayLength(int l);

  bool checkIndex(int b) const;
};

arrayList::arrayList()
{
  element = new int [10];
  arrayLength = 10;
  listSize = 0;
}

arrayList::arrayList(int n)
{
  element = new int [n];
  arrayLength = n;
  listSize = 0;
}

arrayList::arrayList(arrayList &A)
{
  element = new int [A.length()];
  arrayLength = A.length();
  listSize = 0;
  for(int i = 0; i < A.size(); i++)
    insert(i, A.get(i));
}
	
void arrayList::add(const int n)
{
  if (listSize == arrayLength)
    changeArrayLength(arrayLength*2);
  element[listSize] = n;
  listSize++;

}

void arrayList::insert(int index, const int n)
{
  if (checkIndex(index))
    {
      if (listSize == arrayLength)
	changeArrayLength(arrayLength*2);
      for (int i = listSize; i > index; i--)
	element[i] = element[i-1];
      element[index] = n;
      listSize++;
    }
}

void arrayList::erase(int index)
{
  if (checkIndex(index))
    {
      for (int i = index; i < listSize-1; i++)
	element[i] = element[i+1];
      listSize--;
      if (listSize == arrayLength/4)
	changeArrayLength(arrayLength/2);
    }
}

//returns -1 if element not found
int arrayList::indexOf(int n) const
{
  int index = -1;
  for (int i = 0; i < listSize; i++)
    {
      if(element[i] == n)
	index = i;
    }
  return index;
}

int arrayList::get(int index) const
{
  if(checkIndex(index))
    return element[index];
}

void arrayList::output(ostream &out) const
{
  for (int i = 0; i < listSize; i++)
    out<<element[i]<<" ";
  out<<endl;
}

void arrayList::changeArrayLength(int l)
{
  int *A = new int [l];
  for (int i = 0; i < listSize; i++)
    A[i] = element[i];
  delete [] element;
  element = A;
}

bool arrayList::checkIndex(int index) const
{
  if(index >= 0 && index < arrayLength)
      return true;
  else
      return false;
}


int main()
{
  arrayList A(3);
  A.insert(0,1);
  A.insert(1,2);
  A.insert(2,3);
  A.output(cout);

  arrayList B(A);
  B.add(4);
  B.erase(0);
  B.output(cout);

  cout<<A.get(0)<<endl;
  cout<<B.indexOf(2)<<endl;
  cout<<A.indexOf(4)<<endl;

  return 0;
}

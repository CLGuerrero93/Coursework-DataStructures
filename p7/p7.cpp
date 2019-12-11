// Author:         Cassandra Guerrero
// Creation Date:  04 December 2014
// Due Date:       04 December 2014
// Course:         CSC 237
// Professor:      Dr. Schaper
// Assignment:     #7
// Filename:       p7.cpp
// Purpose:        Reads four different input files of 1000 random rationals
//                 into four arrays and sorts them using recursive merge,
//                 quick, and heap sorts.

#include <iostream>
#include <fstream>
#include <string> 
#include "/export/home/student/cguer715/237/CodeBase/DataTypes/Rational/rational.h"
#include "/export/home/student/cguer715/237/CodeBase/RandomData/randomData.h"
#include "/export/home/student/cguer715/237/CodeBase/DataStructures/Heap/heap.h"

using namespace std;

typedef int dT;

void readFile(dT A[], int size, const string& filename);
void writeFile(dT A[], int size, const string& filename);
void quickSort(dT A[], int size, int first, int last);
void mergeSort(dT A[], int size);
void merge(dT A1[], int A1size, dT A2[], int A2size, dT temp[]);
void copy(dT A[], int index, dT newA[], int nIndex, int size);
void heapSort(heap<dT> H, dT A[], int size);

int main()
{
  const int SIZE = 15;
  const size_t tSIZE = 15;
  dT mergeArray[SIZE];
  dT quickArray[SIZE];
  dT h1Array[SIZE];
  dT h2Array[SIZE];

  ifstream fp;

  readFile(mergeArray, SIZE, "d1.dat");
  readFile(quickArray, SIZE, "d2.dat");
  readFile(h1Array, SIZE, "d3.dat");
  readFile(h2Array, SIZE, "d4.dat");

  dT* ptrH2 = h2Array;

  heap<dT> H1(tSIZE); //needs to be sorted
  heap<dT> H2(ptrH2, tSIZE); //will be sorted at creation 

  mergeSort(mergeArray, SIZE);
  quickSort(quickArray, SIZE, 0, SIZE-1);
  heapSort(H1, h1Array, SIZE);

  writeFile(mergeArray, SIZE, "r1.dat");
  writeFile(quickArray, SIZE, "r2.dat");
  writeFile(h1Array, SIZE, "r3.dat");
  writeFile(h2Array, SIZE, "r4.dat");

  return 0;
}

void readFile(dT A[], int size, const string& filename)
{
  ifstream fp;

  fp.open(filename.c_str());

  if (fp.is_open())
    {
      for (int i = 0; i < size; i++)
	fp>>A[i];
    }
  else
    cout<<"File read error. No input taken.\n";

  fp.close();
}

void writeFile(dT A[], int size, const string& filename)
{
  ofstream outfile;
  size_t index = 0;
  outfile.open(filename.c_str());

  while (index < size)
    {
      if (index == 0)
	outfile<<A[index]<<' ';
      else if (index % 9 == 0)
	outfile<<A[index]<<'\n';
      else
	outfile<<A[index]<<' ';
      index++;
    }

  outfile<<endl;
  outfile.close();
}

void mergeSort(dT A[], int size)
{
  if (size > 1)
    {
      //first half
      dT *first = new dT[size/2];
      copy(A, 0, first, 0, size/2);
      mergeSort(first, size/2);
      
      //second half
      int nsize = size - size/2;
      dT *last = new dT[nsize];
      copy(A, size/2, last, 0, nsize);
      mergeSort(last, nsize);
      
      //merge halves
      dT *temp = new dT[size];
      merge(first, size/2, last, nsize, temp);
      copy(temp, 0, A, 0, size);
      delete [] temp;
      delete [] first;
      delete [] last;
    }
}

void merge(dT A1[], int A1size, dT A2[], int A2size, dT temp[])
{
  //indices
  int iA1 = 0;
  int iA2 = 0;
  int iT = 0; 
  
  //merge in order
  while (iA1 < A1size && iA2 < A2size)
    {
      if (A1[iA1] < A2[iA2])
	temp[iT++] = A1[iA1++];
      else
	temp[iT++] = A2[iA2++];
    }
  
  //build A1
  while (iA1 < A1size)
    temp[iT++] = A1[iA1++];
  
  //build A2
  while (iA2 < A2size)
    temp[iT++] = A2[iA2++];
}

void copy(dT A[], int index, dT newA[], int nIndex, int size)
{
  for (int i = 0; i < size; i++)
    newA[i + nIndex] = A[i + index];
}

void quickSort(dT A[], int size, int first, int last)
{
  int left = first;  
  int right = last;
  int index = (first+last)/2;
  dT pivot = A[index];
  dT swap;

  while (first <= last)
    {
      while (A[first] < pivot)
	first++;
      while (A[last] > pivot)
	last--;
      if (first <= last)
	{
	  swap = A[last];
	  A[last] = A[first];
	  A[first] = swap;
	  first++;
	  last--;
	}
    }

  //quicksort array from first index to right
  if (last > 0 && last > left)
    quickSort(A, size, left, last);
  if (first < size && first < right) // fail safe
    quickSort(A, size, first, right);
  //quicksort array from left to last index
}

void heapSort(heap<dT> H, dT A[], int size)
{
  for (int i = 0; i < size; i++)
    H.push(A[i]);
  for (int e = size - 1; e >= 0; e--)
    {    
      A[e] = H.peek();
      H.pop();
    }
}

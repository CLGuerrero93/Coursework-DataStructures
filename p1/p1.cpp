// Author:          Cassandra Guerrero
// Creation Date:   3 September 2014
// Due Date:        4 September 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #1
// Filename:        p1.cpp
// Purpose:         LinkedList Class implementation.  The program
//		    opens a file, reads the contents into a LinkedList
//		    object, and outputs all the values in the LinkedList
//		    larger than the last value in the LinkedList to a file.

#include <iostream>
#include "LinkedList.h"
#include <fstream>
#include <string>
using namespace std;

// Function Name:  readFile
// Description:    Reads values from the file into the LinkedList.
// Parameters:     LinkedList &L (IMPORT) - values will go in here
// Returns:        None
void readFile(LinkedList& L);

// Function Name:  writeFile
// Description:    Writes values from the LinkedList into the file.
// Parameters:     LinkedList &L (IMPORT) - values will come from here.
// Returns:        None
void writeFile(LinkedList& L);

int main()
{
  LinkedList L1;
  readFile(L1);
  L1.writeFile();
  return 0;
}

void readFile(LinkedList& L)
{
  ifstream fp;
  string filename;
  int value;

  cout<<"Please enter the filename:  ";
  cin>>filename;
  cout<<endl;

  fp.open(filename.c_str());

  if(fp.is_open())
    {
      while(!fp.eof())
	{
	  fp>>value;
	  L.append(value);
	}
    }

  else
    {
      cout<<"File read error.  Please try again.\n";
      readFile(L);
    }
}

/*void writeFile(LinkedList& L)
{
  ofstream outfile;
  outfile.open("largest.dat");
  node *p = L.getHead();
  node *lp = L.getLast();
  while(p != NULL)
    {
      if(p -> getData() > lp -> getData())
	outfile<<p -> getData()<<endl;
      p = p -> getNext();
    }
  outfile.close();
  }*/


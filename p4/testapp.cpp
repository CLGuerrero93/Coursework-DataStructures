// Author:          Cassandra Guerrero
// Creation Date:   15 October 2014
// Due Date:        16 October 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #4
// Filename:        testapp.cpp
// Purpose:         test app for template class bag.
//                  Can be used with linklist or dynamic array class.

#include <iostream>
#include "bag.h"
#include "/export/home/student/cguer715/237/CodeBase/DataTypes/Rational/rational.h"
using namespace std;

typedef int T;

int main()
{
  T item;
  bool success;

  cout<<"This is a test.\n";

  bag<T> B1;
  cout<<"B1 instantiated.\n";

  B1.insert(6);
  B1.insert(7);
  B1.insert(6);
  B1.insert(6);
  B1.insert(7);

  cout<<"Finished inserting B1: "<<B1<<endl;
  cout<<"Now peeking inside B1...\n";

  success = B1.peekRandom(item);
  cout<<"Successful Peek?  "<<success<<endl;
  if (success == 1)
    cout<<"The item seen was "<<item<<".\n";

  bag<T> B2(B1);
  cout<<"B2 instantiated as copy B1.\n"<<"B2: "<<B2<<endl;

  cout<<"Now removing one "<<item<<" from B2...\n";
  success = B2.removeOne(item);
  cout<<"Success?  "<<success<<endl;
  cout<<"B2: "<<B2<<endl;

  success = B2.isMember(item);
  cout<<"Is "<<item<<" still a member of B2?  "<<success;
  cout<<"\nNow removing all occurrences of "<<item<<" from B1...\n";
  success = B2.removeAllOccurrences(item);
  cout<<"Success?  "<<success<<endl;
  cout<<"B2: "<<B2<<endl;
  
  bag<T> B3;
  cout<<"B3 instantiated.\nNow peeking inside...\n";

  B3 = B1 + B2;
  cout<<"B3: "<<B3<<endl;

  success = B3.peekRandom(item);
  cout<<"Successful Peek?  "<<success<<endl;
  if (success == 1)
    cout<<"The item seen was "<<item<<endl;  

  B3.insert(8);
  cout<<"Finished inserting B3: "<<B3<<endl;
  cout<<"B3 will now be B1...\n";
  B3 = B1;
  cout<<"B3: "<<B3<<endl;

  if (B3 == B1)
    success = 1;
  else
    success = 0;

  cout<<"Is B3 == B1 true?  "<<success<<endl;

  if (B3 != B2)
    success = 1;
  else 
    success = 0;

  cout<<"Is B3 != B2 true?  "<<success<<endl;
  cout<<"B1: "<<B1<<"\nB2: "<<B2<<"\nB3: "<<B3<<endl;

  cout<<"How many items in B1?  "<<B1.size()<<endl;
  B3.peekRandom(item);
  cout<<"How many values of "<<item<<" in B3?  "
      <<B3.count(item)<<endl;

  cout<<"Test complete.\n";

  return 0;
}


// Author:          Cassandra Guerrero
// Creation Date:   29 October 2014
// Due Date:        30 October 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #5
// Filename:        test.cpp
// Purpose:         test app for template class set inheriting from bag.
//                  Can be used with linklist or dynamic array class.

#include <iostream>
#include "set.h"
#include "/export/home/student/cguer715/237/CodeBase/DataTypes/Rational/rational.h"
using namespace std;

typedef rational T;

int main()
{
  T item;
  bool success;
  cout<<"This is a test.\n";

  set<T> S1;
  cout<<"S1 instantiated.\n";

  S1.insert(1);
  S1.insert(2);
  S1.insert(3);
  S1.insert(4);
  S1.insert(5);
  cout<<"Finished inserting S1: "<<S1<<endl;
  S1.insert(5);
  cout<<"Insert duplicate attempt S1: "<<S1<<endl;
  cout<<"Now peeking inside S1...\n";

  success = S1.peekRandom(item);
  cout<<"Successful Peek?  "<<success<<endl;
  if (success == 1)
    cout<<"The item seen was "<<item<<".\n";

  set<T> S2(S1);
  cout<<"S2 instantiated as copy S1.\nS2: "<<S2<<endl;

  cout<<"Now removing one "<<item<<" from S2...\n";
  success = S2.remove(item);
  cout<<"Success?  "<<success<<endl;
  cout<<"S2: "<<S2<<endl;
  success = S2.isMember(item);
  cout<<"Is "<<item<<" still a member of S2?  "<<success<<endl;

  set<T> S4;
  S4.insert(0);
  S4.insert(9);
  S4.insert(8);
  S4.insert(7);
  cout<<"S4 instantiated."<<endl<<"S4: "<<S4<<endl;
  
  set<T> S3;
  cout<<"S3 instantiated.\nAdding S3 = S1 + S4...\n";
  S3 = S1 + S4;
  cout<<"S3: "<<S3<<endl;
  cout<<"Intersection of S3 and S2 into S4"<<endl;
  S4 = S3 * S2;
  cout<<"S4: "<<S4<<endl;
  cout<<"S3: "<<S3<<endl;
  cout<<"S2: "<<S2<<endl;
  cout<<"Subtracting S4 = S3 - S1"<<endl;
  S4 = S3 - S1;
  cout<<"S4: "<<S4<<endl;
  cout<<"S3: "<<S3<<endl;
  cout<<"S1: "<<S1<<endl;

  cout<<"S3 will now be S1...\n";
  S3 = S1;
  cout<<"S3: "<<S3<<endl;

  if (S3 == S1)
    success = 1;
  else
    success = 0;

  cout<<"Is S3 == S1 true?  "<<success<<endl;

  if (S3 != S2)
    success = 1;
  else 
    success = 0;

  cout<<"Is S3 != S2 true?  "<<success<<endl;
  cout<<"S1: "<<S1<<"\nS2: "<<S2<<"\nS3: "<<S3<<endl;
  cout<<"How many items in S1?  "<<S1.size()<<endl;

  cout<<"Test complete.\n";

  return 0;
}


// Author:         Cassandra Guerrero
// Creation Date:  12 November 2014
// Due Date:       13 November 2014
// Course:         CSC 237
// Professor:      Dr. Schaper
// Assignment:     #6
// Filename:       test.cpp
// Purpose:        test file for queue and stack

#include "/export/home/student/cguer715/237/p6/stack.h"
#include "/export/home/student/cguer715/237/p6/queue.h"
#include <iostream>
using namespace std;

typedef int dT;

int main()
{
  queue<dT> Q1;
  cout<<"Q1 created.\n";
  Q1.push(10);
  cout<<"pushing 10\n";
  Q1.push(15);
  cout<<"pushing 15\n";
  cout<<"peeking   "<<Q1.peek()<<endl;
  Q1.pop();
  cout<<"pop\n";
  cout<<"peeking   "<<Q1.peek()<<endl;
  queue<dT> Q2(Q1);
  cout<<"Q2 created as copy of Q1\n";
  cout<<"peeking   "<<Q2.peek()<<endl;

  stack<dT> S1;
  cout<<"S1 created.\n";
  S1.push(14);
  cout<<"pushing 14\n";
  S1.push(18);
  cout<<"pushing 18\n";
  cout<<"peeking   "<<S1.peek()<<endl;
  S1.pop();
  cout<<"pop\n";
  cout<<"peeking   "<<S1.peek()<<endl;
  cout<<"Q2 created as copy of Q1\n";
  stack<dT> S2(S1);
  cout<<"peeking   "<<S2.peek()<<endl;
}

#include <iostream>
#include "chain.cpp"

using namespace std;

int main()
{
  chain<int> C1;
  C1.insert(0, 6);
  C1.insert(0, 5);
  C1.insert(1, 2);
  cout<<"C1 is ";
  C1.output(cout);

  chain<int> C2(C1);
  C2.insert(0,9);
  cout<<"C2 is ";
  C2.output(cout);

  C1.erase(C1.indexOf(2));
  cout<<"C1 is ";
  C1.output(cout);
  cout<<C2.get(0)<<endl;

  return 0;
}

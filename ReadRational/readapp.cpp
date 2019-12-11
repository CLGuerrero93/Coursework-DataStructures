/*****************************************************************
Example program for producing an execution trace showing the
instantiation of rational numbers and execution of value
semantics.

Trace should show all output written to the monitor during
the exeuction of the program.
*****************************************************************/
#include<iostream>
#include"rational.h"

int main()
{
  rational r1;
  rational r2(3);
  rational r3(4,5);
  rational r4 (r2);

  std::cout << "\n\n Done with constructors \n\n";
  r1 = r3;
  std::cout << "\n\n Done with assignment operator \n\n";
  r1 = r2 + r3;
  std::cout << "\n\n Done with r1 = r2 + r3 \n\n";

  return 0;
}

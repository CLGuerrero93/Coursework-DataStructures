/*************************************************************
FILENAME: expression.h
PURPOSE: Define expression ADT for storing arithmetic expressions.
AUTHOR: Dr. Greg Schaper
Modification History:
11/12/2012: Created
 ***********************************************************/

#ifndef XXXX_EXPRESSION_XXXX
#define XXXX_EXPRESSION_XXXX
#include "token.h"

class Expression:public queue<Token>
{
 public:
  Expression();
  Expression(const Expression& original);
  Expression operator =(Expression rhs);
  ~Expression();

  // remove all tokens from an Expression
  void clean();
  
  // insert Expression to outstream with each token separated by 1 blank character
  void print(std::ostream& outstream, char delimiter = '\n');

  // read a sequence of tokens delimited by a single semicolon. Eat the semicolon
  void read(std::istream& instream);

 private:

};


std::ostream& operator <<(std::ostream& outstream, Expression E);

std::istream& operator >>(std::istream& instream, Expression& E);

#include "expression.cxx"
#endif

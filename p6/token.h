/*************************************************************
FILENAME: token.h
PURPOSE: Define Token ADT for storing lexemes used in arithmetic expressions.
AUTHOR: Dr. Greg Schaper
Modification History:
11/12/2012: Created
 ***********************************************************/

#ifndef XXXXX_TOKEN_XXXXX
#define XXXXX_TOKEN_XXXXX
#include<iostream>
#include<fstream>
#include<string>

// enumeration types used to identify the type of token and type of operator.
enum TokenType {NOTYPE, OPERAND, OPERATOR};
enum OperatorType {NOOP,PLUSMINUS, MULTDIV};


class Token
{
 public:
  Token();
  Token(const Token& original);
  Token operator = (Token rhs);
  ~Token();
  
  // set token to NOTYPE, OPERAND, or OPERATOR type.
  void setTokenType(TokenType tt);

  // set operator token to indicate the operation: NOOP,PLUSMINUS, MULTDIV
  void setOperatorType(OperatorType ot);

  // set the symbol field to the character string for the actual token
  // as it was read from the input expression.
  void setSymbol(std::string s);

  // return the token type of *this token
  TokenType getTokenType();

  // return the operator type of *this token
  OperatorType getOperatorType();

  // return the character string of the *this token
  std::string getSymbol();

  // set a token to its initial state. 
  // typeOfToken is set to NOTYPE;
  // typeOfOperator is set to NOOP;
  // symbol is set to empty string.
  void clean();

  // insert all attributes of a token to outstream. Mainly used for logic testing. 
  void print(std::ostream& outstream, char delimiter = ' ');

  // insert only the symbol attribute for a token to outstream.
  void printSymbol(std::ostream& outstream, char delimiter = ' ');
 
  // read a token. skips any leading white space. does not read character after the token.
  void read(std::istream& instream);

 private:

  TokenType typeOfToken;
  OperatorType typeOfOperator;
  std::string symbol;

  // eats white space in instream until next non-white space character encountered.
  void skipWhiteSpace(std::istream& instream);

  // read token of type operand from instream.
  void readOperand(std::istream& instream);

  // read token of type operator from instream.
  void readOperator(std::istream& instream);


   
};


std::ostream& operator <<(std::ostream& outstream, Token t);

std::istream& operator >>(std::istream& instream, Token& t);

#include "token.cxx"
#endif



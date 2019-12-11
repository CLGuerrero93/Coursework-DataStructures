/**************************************************************************************
Rational class interface
FILENAME: rational.h

The rational class implements rational numbers as a ratio of a numerator and a
denominator. The data type of the numerator and denominator is defined using
a typedef so that more accurate rational numbers can be achieved using new classes
that implement large integers. Current implementation will use long integers which
are assumed to be 32 bit values. Current implementation allows for arithmetic and logic
operations for rational expressions. Future modifications will be made to allow
mixed int, long, and rational expressions. 

Invariant Properties:
1. The denominator of a rational number is never negative. The sign of a rational number
is always represented by the sign of the numerator.
2. rational numbers are always represented in simplest terms. That is the numerator
and denominator have not common factors.
3. Positive and negative infinity are represented by a denominator with value 0. 
For positive infinity the numerator has value 1. For negative infinity the numerator
has value -1. 


Author: Dr. Greg Schaper 

Modification History:
Created 2/1/2010 for use in CSC136
Modified 9/10/2010 to include features covered in CSC237
Modified 9/15/2012 to include standard I/O libraries containing defintions
    of istream and ostream classes used by << and >>. 
Modified 9/20/2012 to include type casting from rational to char data type
 *************************************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>
#include<fstream>

typedef long int IntegerType;

class rational
{

 public:
  // Basic Constructors
  // explicit rational(IntegerType n = 0);
  // explicit rational(IntegerType n, IntegerType d);
  rational(IntegerType n = 0);
  rational(IntegerType n, IntegerType d);
  rational(const rational& r);
  rational(const int& r);
  

  // Value Semantics
  ~rational();
  rational operator =(rational r);
  //  int operator = (rational r);
  // Basic Accessor and Mutators - are these necessary?????
  IntegerType getNumerator() const;
  IntegerType getDenominator() const;
  void setRational(IntegerType n, IntegerType d);

  // Type Conversion
  operator double();
  operator int();
  operator char();

  // Basic Binary Arithmetic Operators
  rational operator +(rational rhs) const;
  rational operator -(rational rhs) const;
  rational operator *(rational rhs) const;
  rational operator /(rational rhs) const;

  // Assignment Operations
  rational operator +=(rational rhs);
  rational operator -=(rational rhs);
  rational operator *=(rational rhs);
  rational operator /=(rational rhs);

  // Relational Operators
  bool operator ==(rational rhs) const;
  bool operator !=(rational rhs) const;
  bool operator <(rational rhs) const;
  bool operator >(rational rhs) const;
  bool operator >=(rational rhs) const;
  bool operator <=(rational rhs) const;

  // Unary Operators
  rational operator++();
  rational operator++(int);
  rational operator--();
  rational operator--(int);
  rational operator+() const;
  rational operator-() const;
  bool operator!() const;

 private:
  IntegerType numerator;
  IntegerType denominator;

  void normalize();
  void setSign();
  void reduce();
  IntegerType greatestCommonDivisor(IntegerType a, IntegerType b);
};


std::ostream& operator <<(std::ostream& outstream, rational r);
std::istream& operator >>(std::istream& instream, rational &r);


#include"rational.cxx"


#endif

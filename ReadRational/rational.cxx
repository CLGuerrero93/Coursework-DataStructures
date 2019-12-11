/*************************************************************************************
Implemention file for the rational class.
FILENAME: rational.cpp

See rational.h for documentation.

Author: Dr. Greg Schaper
Date last modified: 9/10/2010
 *************************************************************************************/

rational::rational(IntegerType n, IntegerType d):numerator(n), denominator(d)
{
  std::cout << 'A';
  normalize();
}


rational::rational(const rational &r)
{
  std::cout << 'B';

  numerator = r.numerator;
  denominator = r.denominator;
}


rational::~rational()
{
  std::cout << 'C';

  /* nothing to do */
}


rational rational::operator =(rational r)
{
  std::cout << 'D';

  numerator = r.numerator;
  denominator = r.denominator;
  return(*this);
}


IntegerType rational::getNumerator() const
{
  std::cout << 'E';

  return(numerator);
}


IntegerType rational::getDenominator() const
{
  std::cout << 'F';

  return(denominator);
}


void rational::setRational(IntegerType n, IntegerType d)
{
  std::cout << 'G';

  numerator = n;
  denominator = d;
  normalize();
}


rational::operator double() const
{
  std::cout << 'H';

  double d;
  d = static_cast<double>(numerator) / static_cast<double>(denominator);
  return d;
}


rational::operator int() const
{
  std::cout << 'I';

  return(numerator/denominator);
}


rational rational::operator +(rational rhs) const
{
  std::cout << 'J';

  rational temp;
  temp.numerator = numerator*rhs.denominator + rhs.numerator*denominator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator -(rational rhs) const
{
  std::cout << 'K';

  rational temp;
  temp.numerator = numerator*rhs.denominator - rhs.numerator*denominator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator *(rational rhs) const
{
  std::cout << 'L';

  rational temp;
  temp.numerator = numerator*rhs.numerator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator /(rational rhs) const
{
  std::cout << 'M';

  rational temp;
  temp.numerator = numerator*rhs.denominator;
  temp.denominator = denominator*rhs.numerator;
  temp.normalize();
  return temp;
}


rational rational::operator +=(rational rhs)
{
  std::cout << 'N';

  *this = *this + rhs;
  return(*this);
}



rational rational::operator -=(rational rhs)
{
  std::cout << 'O';

  *this = *this - rhs;
  return(*this);
}


rational rational::operator *=(rational rhs)
{
  std::cout << 'P';

  *this = *this * rhs;
  return(*this);
}


rational rational::operator /=(rational rhs)
{
  std::cout << 'Q';

  *this = *this / rhs;
  return(*this);
}


bool rational::operator ==(rational rhs) const
{
  std::cout << 'R';

  return (numerator*rhs.denominator == rhs.numerator*denominator);
}


bool rational::operator !=(rational rhs) const
{
  std::cout << 'S';

  return (numerator*rhs.denominator != rhs.numerator*denominator);
}


bool rational::operator <(rational rhs) const
{
  std::cout << 'T';

  return (numerator*rhs.denominator < rhs.numerator*denominator);
}


bool rational::operator >(rational rhs) const
{
  std::cout << 'U';

  return (numerator*rhs.denominator > rhs.numerator*denominator);
}


bool rational::operator >=(rational rhs) const
{
  std::cout << 'V';

  return(!(*this < rhs));
}


bool rational::operator <=(rational rhs) const
{
  std::cout << 'W';

  return(!(*this > rhs));
}


// Unary Operators
rational rational::operator++() // prefix form
{
  std::cout << 'X';

  numerator += denominator;

  return (*this);
};


rational rational::operator++(int) // postfix form
{
  std::cout << 'Y';

  rational result = *this;
  numerator += denominator;
  return result;
};


rational rational::operator--() // prefix form
{
  std::cout << 'Z';

  numerator -= denominator;
  return (*this);
};


rational rational::operator--(int) // postfix form
{
  std::cout << 'a';

  rational result = *this;
  numerator -= denominator;
  return result;
};


rational rational::operator+() const
{
  std::cout << 'b';

  return(*this);
};


rational rational::operator-() const
{
  std::cout << 'c';

  rational result(-numerator, denominator);
  return (result);
};


bool rational::operator!() const
{
  std::cout << 'd';

  // return true if the this rational is zero.

  return(numerator==0);
};



/**************************************************************************
PRIVATE MEMBER FUNCTIONS
 *************************************************************************/

void rational::normalize()
{
  std::cout << 'e';

  if(denominator == 0) // rational represents infinity
    {
      if(numerator >= 0)
	{
	  numerator = 1; // represents positive infinity
	}
      else
	{
	  numerator = -1; // represents negative infinity
	}
    }
  else
    {
      // set the sign of the numerator
      setSign();
      // reduce fraction to lowest terms
      if((numerator != 0) && (denominator !=0))
	  reduce();
    }

};


void rational::setSign()
{
  if(denominator < 0)
    {
      denominator = -denominator;
      numerator = -numerator;
    }
}


void rational::reduce()
{
  IntegerType gcd;
  IntegerType small, large;
  bool positiveRational;
  
  positiveRational = (numerator >=0);

  if(!positiveRational)
      numerator = -1*numerator;

  if(numerator <= denominator)
    {
      small = numerator;
      large = denominator;
    }
  else
    {
      small = denominator;
      large = numerator;
    }
  
  gcd = greatestCommonDivisor(large, small);

  numerator = numerator / gcd;
  denominator = denominator / gcd;
  
  if(!positiveRational)
    numerator = -1*numerator;
}


IntegerType rational::greatestCommonDivisor(IntegerType a, IntegerType b)
{
  IntegerType r, x, y;
  x = a;
  y = b;
  while(y!=0)
    {
      r = x % y;
      x = y;
      y = r;
    }
  return x;
}



/***********************************************************************
NON MEMBER FUNCTIONS
 **********************************************************************/

std::ostream& operator <<(std::ostream& outstream, rational r)
{
  std::cout << 'f';

  IntegerType n, d;
  n = r.getNumerator();
  d = r.getDenominator();
  if(d != 0)
    {
      outstream << n << '/' << d;
    }
  else
    {
      if(n < 0)
	{
	  outstream << '-';
	}
      outstream << "infinity";
    }
  return outstream;
}


std::istream& operator >>(std::istream& instream, rational &r)
{
  IntegerType temp1, temp2;
  char ch;
  
  instream >> temp1;
  instream >> ch;
  instream >> temp2;
  r.setRational(temp1, temp2);

  return instream;
}

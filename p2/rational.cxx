/*************************************************************************************
Implemention file for the rational class.
FILENAME: rational.cpp

See rational.h for documentation.

Author: Dr. Greg Schaper
Modification History:
Created on 9/10/2010
Modified on 9/20/2012 to include type cast for rational to char conversion.
 *************************************************************************************/
#include<cmath>  // need for abs() function

rational::rational(IntegerType n):numerator(n), denominator(1)
{
  normalize();
}


rational::rational(IntegerType n, IntegerType d):numerator(n), denominator(d)
{
  normalize();
}




rational::rational(const rational &r)
{
  numerator = r.numerator;
  denominator = r.denominator;
}


rational::rational(const int& r)
{
  numerator = r;
  denominator = 1;
}


rational::~rational()
{
  /* nothing to do */
}


rational rational::operator =(rational r)
{
  numerator = r.numerator;
  denominator = r.denominator;
  return(*this);
}


IntegerType rational::getNumerator() const
{
  return(numerator);
}


IntegerType rational::getDenominator() const
{
  return(denominator);
}


void rational::setRational(IntegerType n, IntegerType d)
{
  numerator = n;
  denominator = d;
  normalize();
}


rational::operator double()
{
  double d;
  d = static_cast<double>(numerator) / static_cast<double>(denominator);
  return d;
}


rational::operator int()
{
  return(numerator/denominator);
}


rational::operator char()
{
  const char asciiA = 'A';
  return(static_cast<char>((abs(numerator/denominator) % 26) + asciiA));
}



rational rational::operator +(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.denominator + rhs.numerator*denominator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator -(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.denominator - rhs.numerator*denominator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator *(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.numerator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator /(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.denominator;
  temp.denominator = denominator*rhs.numerator;
  temp.normalize();
  return temp;
}


rational rational::operator +=(rational rhs)
{
  *this = *this + rhs;
  return(*this);
}



rational rational::operator -=(rational rhs)
{
  *this = *this - rhs;
  return(*this);
}


rational rational::operator *=(rational rhs)
{
  *this = *this * rhs;
  return(*this);
}


rational rational::operator /=(rational rhs)
{
  *this = *this / rhs;
  return(*this);
}


bool rational::operator ==(rational rhs) const
{
  return (numerator*rhs.denominator == rhs.numerator*denominator);
}


bool rational::operator !=(rational rhs) const
{
  return (numerator*rhs.denominator != rhs.numerator*denominator);
}


bool rational::operator <(rational rhs) const
{
  return (numerator*rhs.denominator < rhs.numerator*denominator);
}


bool rational::operator >(rational rhs) const
{
  return (numerator*rhs.denominator > rhs.numerator*denominator);
}


bool rational::operator >=(rational rhs) const
{
  return(!(*this < rhs));
}


bool rational::operator <=(rational rhs) const
{
  return(!(*this > rhs));
}


// Unary Operators
rational rational::operator++() // prefix form
{
  numerator += denominator;

  return (*this);
};


rational rational::operator++(int) // postfix form
{
  rational result = *this;
  numerator += denominator;
  return result;
};


rational rational::operator--() // prefix form
{
  numerator -= denominator;
  return (*this);
};


rational rational::operator--(int) // postfix form
{
  rational result = *this;
  numerator -= denominator;
  return result;
};


rational rational::operator+() const
{
  return(*this);
};


rational rational::operator-() const
{
  rational result(-numerator, denominator);
  return (result);
};


bool rational::operator!() const
{
  // return true if the this rational is zero.

  return(numerator==0);
};



/**************************************************************************
PRIVATE MEMBER FUNCTIONS
 *************************************************************************/

void rational::normalize()
{
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

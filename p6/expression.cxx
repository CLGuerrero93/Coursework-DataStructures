/*************************************************************
FILENAME: expression.cxx
PURPOSE: Implmentation of expression ADT for storing arithmetic expressions.
AUTHOR: Dr. Greg Schaper
Modification History:
11/12/2012: Created
 ***********************************************************/

Expression::Expression():queue<Token>::queue()
{
}

Expression::Expression(const Expression& original):queue<Token>::queue(original)
{
}

Expression Expression::operator =(Expression rhs)
{
  this->queue<Token>::operator =(rhs);
  return(*this);
}

Expression::~Expression()
{
  // base class will handle dynamic memory
}

void Expression::clean()
{
  while(!(this->queue<Token>::isEmpty()))
    {
      this->queue<Token>::pop();
    }
}

void Expression::print(std::ostream& outstream, char delimiter)
{ 
  Expression temp(*this);
  /*while(!(this->queue<Token>::isEmpty()))
  {
  	this->queue<Token>::peek().printSymbol(outstream);
  	this->queue<Token>::pop();
  } */
  
  while(!temp.queue<Token>::isEmpty())
    {
      temp.queue<Token>::peek().printSymbol(outstream);
      temp.queue<Token>::pop();
    }

  outstream << delimiter;
}

void Expression::read(std::istream& instream)
{
  Token newToken;
  char nextChar;

  nextChar = instream.peek();
  while(nextChar != ';')
    {
      newToken.clean();
      instream >> newToken;
      push(newToken);
      nextChar = instream.peek();
    }
  nextChar = instream.get(); // get the semicolon
}

std::ostream& operator <<(std::ostream& outstream, Expression E)
{
  E.print(outstream, '\n');
  return(outstream);
}

std::istream& operator >>(std::istream& instream, Expression& E)
{
  E.read(instream);
  return(instream);
}




/*************************************************************
FILENAME: token.cxx
PURPOSE: Implementation of Token ADT for storing lexemes used in arithmetic expressions.
AUTHOR: Dr. Greg Schaper
Modification History:
11/12/2012: Created
 ***********************************************************/

//enum TokenType {NOTYPE, OPERAND, OPERATOR};
//enum OperatorType {NOOP,PLUSMINUS, MULTDIV};


Token::Token()
{
  typeOfToken = NOTYPE;
  typeOfOperator = NOOP;
  symbol = "";
}


Token::Token(const Token& original)
{
  typeOfToken = original.typeOfToken;
  typeOfOperator = original.typeOfOperator;
  symbol = original.symbol;
}


Token Token::operator = (Token rhs)
{
  typeOfToken = rhs.typeOfToken;
  typeOfOperator = rhs.typeOfOperator;
  symbol = rhs.symbol;
  return(*this);
}



Token::~Token()
{
  // no dynamic memory
}


  
void Token::setTokenType(TokenType tt)
{
  typeOfToken = tt;
}



void Token::setOperatorType(OperatorType ot)
{
  typeOfOperator = ot;
}



void Token::setSymbol(std::string s)
{
  symbol = s;
}



TokenType Token::getTokenType()
{
  return(typeOfToken);
}



OperatorType Token::getOperatorType()
{
  return(typeOfOperator);
}



std::string Token::getSymbol()
{
  return(symbol);
}


void Token::clean()
{
  typeOfToken = NOTYPE;
  typeOfOperator = NOOP;
  symbol = "";
}



void Token::print(std::ostream& outstream, char delimiter)
{
  outstream << typeOfToken << ", " << typeOfOperator << ", " << symbol << '\n';
}


void Token::printSymbol(std::ostream& outstream, char delimiter)
{
  outstream << symbol << delimiter;
}


void Token::skipWhiteSpace(std::istream& instream)
{
  char nextChar;
  do
    {
      nextChar = instream.peek();
      if(std::isspace(nextChar))
        {
          nextChar = instream.get();
        }
    }
  while(std::isspace(nextChar));
}


void Token::readOperand(std::istream& instream)
{
  char nextChar;
  typeOfToken = OPERAND;
  typeOfOperator = NOOP;
  while(isalpha(nextChar))
    {
      nextChar = instream.get();
      symbol = symbol + nextChar;
      nextChar = instream.peek();
    }
}



void Token::readOperator(std::istream& instream)
{
  char nextChar;
  typeOfToken = OPERATOR;
  nextChar = instream.get();
  symbol = symbol + nextChar;
  if((symbol == "*") || (symbol == "/"))
    {
      typeOfOperator = MULTDIV;
    }
  else
    {
      typeOfOperator = PLUSMINUS;
    }
}


void Token::read(std::istream& instream)
{
  char nextChar;
  //  std::cout << "Reading Next Token\n";

  this->clean();
  this->skipWhiteSpace(instream);
  nextChar = instream.peek();
  if(std::isalpha(nextChar))
    {
      this->readOperand(instream);
    }
  else
    {
      this->readOperator(instream);
    }
 
  //  std::cout << "Done Reading Next Token\n";

}




std::ostream& operator <<(std::ostream& outstream, Token t)
{
  t.print(outstream, ' ');
  return(outstream);
}



std::istream& operator >>(std::istream& instream, Token& t)
{
  t.read(instream);
  return(instream);
}




#include<iostream>
#include<fstream>
#include "/export/home/student/cguer715/237/p6/stack.h"
#include "/export/home/student/cguer715/237/p6/queue.h"
#include "expression.h"

void openFile(std::fstream& fileStream, char *fileName, const std::_Ios_Openmode& inOutApp);
void convertToPostfix(Expression infix, Expression& postfix);
void evaluatePostfix(Expression postfix, std::string& evaluation);
void movePastEndOfLine(std::fstream& instream);

int main()
{
  std::fstream expressions;
  std::fstream results;
  Expression infix;
  Expression postfix;
  std::string evaluatedExpression;

  openFile(expressions, "TestExpressions.txt", std::fstream::in);
  openFile(results, "result.txt", std::fstream::out);
 
  do
    {
      infix.clean();
      expressions >> infix;
      results << infix;
      postfix.clean();
      convertToPostfix(infix, postfix);
      results << postfix;
      evaluatedExpression = "";
      evaluatePostfix(postfix, evaluatedExpression);
      results << evaluatedExpression;
      results << "\n\n";
      movePastEndOfLine(expressions);
    }while(expressions.good());

  expressions.close();
  results.close();
  return 0;
}



void openFile(std::fstream& fileStream, char *fileName, const std::_Ios_Openmode& inOutApp)
{
  fileStream.open(fileName, inOutApp);
  if (!fileStream.is_open())
    {
      std::cout << "\n\nError opening file: " << fileName << ".\n\n";
      exit(1); // exit program if input file not opened
    }
}



void movePastEndOfLine(std::fstream& instream)
{
  char newline[80];
  char nextChar;
  instream.getline(newline, 79, '\n'); // move past end of line
  nextChar = instream.peek(); // peek next character to check if at end of file
}




void convertToPostfix(Expression infix, Expression& postfix)
{
  stack<Token> conversionStack;
  Token currentToken;
  //infix.print(std::cout);
  Token noopToken;
  noopToken.setTokenType(OPERATOR);
  noopToken.setOperatorType(NOOP);
  noopToken.setSymbol("");
  conversionStack.push(noopToken);  
  while(!infix.isEmpty())
    {
      //      postfix.print(std::cout);
      currentToken = infix.peek(); //change infix.front() to .peek()
      infix.pop();
      // currentToken.print(std::cout);
          
      if(currentToken.getTokenType() == OPERAND)
	{
	  postfix.push(currentToken);
	}      
      else
	{
	   while(currentToken.getOperatorType() <= conversionStack.peek().getOperatorType())
	     {
	       postfix.push(conversionStack.peek());
             conversionStack.pop();
	     }
	   conversionStack.push(currentToken);
	}
    }

  while(!conversionStack.isEmpty())
    {
      if(conversionStack.peek().getOperatorType() != NOOP)
	{
	  postfix.push(conversionStack.peek());
	}
      conversionStack.pop();
    }
 
}



void evaluatePostfix(Expression postfix, std::string& evaluation)
{
  stack< std::string > evaluationStack;
  Token currentToken;
  std::string temp1;
  std::string temp2;
  std::string temp3;
  while(!postfix.isEmpty())
    {
      currentToken = postfix.peek(); //from .front to .peeek
      postfix.pop();
      if(currentToken.getTokenType() == OPERAND)
	{
          evaluationStack.push(currentToken.getSymbol());
	}
      else
	{
	  temp1 = evaluationStack.peek();
	  evaluationStack.pop();
          temp2 = evaluationStack.peek();
          evaluationStack.pop();
          temp3 = "(" + temp2 + currentToken.getSymbol() + temp1 + ")";
          evaluationStack.push(temp3);
	}
    }
  evaluation = evaluationStack.peek();
}


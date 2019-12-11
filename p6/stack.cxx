// Author:          Cassandra Guerrero
// Creation Date:   12 November 2014
// Due Date:        13 November 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #6
// Filename:        stack.cxx
// Purpose:         template class stack implementation. 
//                  Inheritance from linklist.

//Value Semantics
template <class dT>
stack<dT>::stack():linklist<dT>::linklist(){}

template <class dT>
stack<dT>::stack(const stack<dT>& original):linklist<dT>::linklist(original){}

template <class dT>  
stack<dT> stack<dT>::operator = (stack<dT> original)
{
  this->linklist<dT>::operator = (original);
  return(*this);
}

template <class dT>
stack<dT>::~stack(){}

template <class dT>  
void stack<dT>::push(dT anItem){this->linklist<dT>::insertFront(anItem);}

template <class dT>
void stack<dT>::pop(){this->linklist<dT>::removeFront();}

template <class dT>
dT stack<dT>::peek() const{return(this->linklist<dT>::peekFront());}

template <class dT>
bool stack<dT>::isEmpty() const{return(this->linklist<dT>::isEmpty());}
  
/*
template <class dT>
void stack<dT>::print(std::ostream& outStream, char separator = '\n') const
{linklist::print(std::ostream& outStream, char separator) const;}

template <class dT>
std::ostream& operator <<(std::ostream& outstream, stack<dT> S)
{
	S.print(outstream);
	return outstream;
}
*/

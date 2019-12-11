// Author:         Cassandra Guerrero
// Creation Date:  12 November 2014
// Due Date:       13 November 2014
// Course:         CSC 237
// Professor:      Dr. Schaper
// Assignment:     #6
// Filename:       queue.cxx
// Purpose:        template class queue implementation.
//		   Inheritance from linklist.

//Value Semantics
template <class dT>
queue<dT>::queue():linklist<dT>::linklist(){}

template <class dT>
queue<dT>::queue(const queue<dT>& original):linklist<dT>::linklist(original)
{} 

template <class dT> 
queue<dT> queue<dT>::operator = (queue<dT> original)
{
	this->linklist<dT>::operator = (original);
	return(*this);
}

template <class dT>  
queue<dT>::~queue(){}

template <class dT>
void queue<dT>::push(dT anItem){linklist<dT>::insertEnd(anItem);}

template <class dT>
void queue<dT>::pop(){this->linklist<dT>::removeFront();}

template <class dT>
dT queue<dT>::peek() const{return(this->linklist<dT>::peekFront());}

template <class dT>
bool queue<dT>::isEmpty() const{return(this->linklist<dT>::isEmpty());}  

/* 
template <class dT>
void queue<dT>::print(std::ostream& outStream, char separator = '\n') const
{linklist<dT>::print(std::ostream& outStream, char separator) const;}

template <class dT>
std::ostream& operator <<(std::ostream& outstream, queue<dT> S)
{
	S.print(outstream);
	return outstream;
}
*/

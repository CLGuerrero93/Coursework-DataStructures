// Author:          Cassandra Guerrero
// Creation Date:   27 October 2014
// Due Date:        30 October 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #5
// Filename:        set.cxx
// Purpose:         template class set definition. Inheritance from bag.
//                  Can be used with linklist or dynamic array class.

// Constructors and Value Semantics
template <class dT>
set<dT>::set():bag<dT>::bag(){}

template <class dT>
set<dT>::set(const set<dT>& b):bag<dT>(b){}

template <class dT>
set<dT>::~set(){}

template <class dT>	
set<dT> set<dT>::operator =(set<dT> b)
{
  this -> bag<dT>::operator =(b);
  return (*this);
}

//Public methods
template <class dT>
bool set<dT>::remove(dT target)
{return (this -> bag<dT>::removeOne(target));}

template <class dT>
bool set<dT>::peekRandom(dT& item) const
{return (this -> bag<dT>::peekRandom(item));}

//template <class dT>
//bool set<dT>::isMember(dT item) const{  }

template <class dT>
void set<dT>::insert(dT item)
{
  if (!isMember(item))
    this -> bag<dT>::insert(item);
}

template <class dT>
void set<dT>::operator +=(set<dT> b)
{
  set<dT> temp = (*this);
  *this -> temp + b;
}

template <class dT>
set<dT> set<dT>::operator+(set<dT> b)
{
  dT item;
  set<dT> temp (*this);

  while (b.peekRandom(item))
      {
	temp.insert(item);
	b.removeOne(item);
      }
  return temp;
}

template <class dT>
void set<dT>::operator -=(set<dT> b)
{
  set<dT> temp = (*this);
  *this -> temp - b;
}

template <class dT>
set<dT>::set<dT> set<dT>::operator-(set<dT> b)
{
  dT item;
  set<dT> temp (*this);

  while (b.peekRandom(item))
      {
	temp.remove(item);
	b.remove(item);
      }
  return temp;
}

template <class dT>
void set<dT>::operator *=(set<dT> b)
{
  set<dT> temp (*this);
  this -> temp * b;
}

template <class dT>
set<dT>::set<dT> set<dT>::operator*(set<dT> b)
{
  dT item;
  set<dT> temp;
  while (b.peekRandom(item))
    { 
      if (isMember(item))
	{
	  b.remove(item);
	  temp.insert(item);
	}
    }
  return temp;
}

template <class dT>
bool set<dT>::operator ==(set<dT> b) const
{
  return (this -> bag<dT>::operator ==(b));
}

template <class dT>
bool set<dT>::operator !=(set<dT> b) const {return !(*this == b);}

//template <class dT>
//size_t set<dT>::size() const {}

template <class dT>
bool set<dT>::isEmpty()
{return (this -> bag<dT>::isEmpty());}

//template <class dT>
//void set<dT>::print(std::ostream& bout, char separator) const {}

template <class dT>
bool set<dT>::isSubsetOf(set<dT> b)
{ 
  set<dT> temp = (*this);
  dT item;
  while (!b.isEmpty())
    {
      b.peekRandom(item);
      b.remove(item);
      if (!temp.remove(item))
	return false;
    }
  return true;
}

//private functions
template <class dT>
void set<dT>::removeAll()
{
  dT item;
  while (peekRandom(item))
    remove(item);
}

// non-member functions
template <class dT>
std::ostream& operator << (std::ostream& bout, set<dT> b)
{
  b.print(bout, ',');
  return bout;
}
 

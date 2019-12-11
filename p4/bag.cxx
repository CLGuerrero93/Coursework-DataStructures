// Author:          Cassandra Guerrero
// Creation Date:   10 October 2014
// Due Date:        16 October 2014
// Course:          CSC 237
// Professor Name:  Dr. Schaper
// Assignment:      #4
// Filename:        bag.cxx
// Purpose:         template class bag definition.
//                  Can be used with linklist or dynamic array class.


// Constructors and Value Semantics
template <class dT>
bag<dT>::bag():data(){ }

template <class dT>
bag<dT>::bag(const bag<dT>& b):data(b.data){ }

template <class dT>
bag<dT>::~bag(){}

template <class dT>	
bag<dT> bag<dT>::operator =(bag<dT> b)
{
  data = b.data;
  return *this;
}

//public functions
template <class dT>
bool bag<dT>::removeAllOccurrences(dT target)
{
  bool flag = false;

  while (removeOne(target))
      flag = true;

  return flag;
}

template <class dT>
bool bag<dT>::removeOne(dT target)
{
  if (data.peekByValue(target) != 0)
    {
      data.removeByValue(target);
      return true;
    }
  return false;
}

template <class dT>
bool bag<dT>::peekRandom(dT& item) const
{
  if (!data.isEmpty())
    item = data.peekFront();

  return !(data.isEmpty());
}

template <class dT>
bool bag<dT>::isMember(dT item) const
{
  if (!data.isEmpty())
    return (data.peekByValue(item) != 0);

  return false;
}

template <class dT>
void bag<dT>::insert(dT item){data.insertFront(item);}

template <class dT>
void bag<dT>::operator +=(bag<dT> b)
{
  bag<dT> temp = (*this);
  temp = temp + b;
  data = temp.data;
}

template <class dT>
bag<dT> bag<dT>::operator+(bag<dT> b)
{
  dT item;
  bag<dT> temp (*this);

  while (b.peekRandom(item))
      {
	temp.insert(item);
	b.removeOne(item);
      }
  return temp;
}

template <class dT>
void bag<dT>::operator -=(bag<dT> b)
{
  bag<dT> temp = (*this);
  temp = temp - b;
  data = temp.data;
}

template <class dT>
bag<dT>::bag<dT> bag<dT>::operator-(bag<dT> b)
{
  dT item;
  bag<dT> temp (*this);
  while (b.peekRandom(item))
    {
      temp.removeOne(item);
      b.removeOne(item);
    }
  return temp;
}

template <class dT>
bool bag<dT>::operator ==(bag<dT> b) const
{
  dT item;
  bag<dT> temp (*this);
  bool flag = true;
  while (b.peekRandom(item))
    {
      b.removeOne(item);
      if (!temp.removeOne(item))
	flag = false;
    }
  return (flag && temp.isEmpty());
}

template <class dT>
bool bag<dT>::operator !=(bag<dT> b) const {return !(*this == b);}

template <class dT>
size_t bag<dT>::size() const {return data.NumberOfItems();}

template <class dT>
size_t bag<dT>::count(dT target) const
{
  size_t count = 0;
  bag<dT> temp (*this);
  while (temp.removeOne(target))
    count++;
  return count;
}

template <class dT>
bool bag<dT>::isEmpty(){return (data.NumberOfItems() == 0);}

template <class dT>
void bag<dT>::print(std::ostream& bout, char separator) const
{data.print(bout, separator);}

// private functions
template <class dT>
void bag<dT>::removeAll()
{
  dT item;
  while (peekRandom(item))
      removeAllOccurrences(item);
}

template <class dT>
bool bag<dT>::subsetOf(bag b) const
{ 
  bag<dT> temp = (*this);
  dT item;
  while (!b.isEmpty())
    {
      b.peekRandom(item);
      b.removeOne(item);
      if (!temp.removeOne(item))
	return false;
    }
  return true;
}

// non-member functions
template <class dT>
std::ostream& operator << (std::ostream& bout, bag<dT> b)
{
  b.print(bout, ',');
  return bout;
}
 

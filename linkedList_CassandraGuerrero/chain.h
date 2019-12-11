#include <iostream>
#include "linearList.h"
#include "chainNode.h"

template <typename T>
class chain : public linearList<T>
{
protected:
  chainNode<T>* firstNode;
  int listSize;

public:
  //constructors                                                                                                                            
  chain();
  chain(const chain<T>& theList);

  //destructors                                                                                                                                 
  ~chain();

  //ADT methods                                                                                            
  bool empty() const;
  int size() const;
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(ostream& out) const;
  void checkIndex(int theIndex);
};

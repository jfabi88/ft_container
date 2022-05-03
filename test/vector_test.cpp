#include <iostream>
#include <vector>
#include "utils.hpp"

int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third

  std::vector<int> sixth(0, -1);
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::vector<int>::iterator  it;
  it = third.begin();
  it = third.end();
  int h = it[-123];
  it+= 6;
  std::cout << "Il valore di h: " << h << std::endl;
  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
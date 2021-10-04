#include <iostream>
#include <list>

int main ()
{
  int myints[]= {3,2,2,3};
  std::list<int> mylist (myints,myints+4);

  mylist.remove(2);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

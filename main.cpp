#include <iostream>
#include "rational.h"
using namespace std;

int main()
{
  Rational x = Rational(6, 5);
  cout << "x= " << x << endl;
  Rational y = Rational (4, 5);
  cout << "y= " << y << endl;
  cout << "x++ = " << x++ << endl;
  cout << "x= " << x << endl;
  cout << "++x= " << ++x << endl;
  cout << "x= " << x << endl;
  Rational minus = x-y;
  Rational plus = x+y;
  Rational div = x/y;
  Rational mult = x*y;
  cout << "x-y = " << minus << endl;
  cout << "x+y = " << plus << endl;
  cout << "x/y = " << div << endl;
  cout << "x*y = " << mult << endl;
  std::cout << std::boolalpha;
  cout << "x<y = " << (x<y) << endl;
  cout << "x>y = " << (x>y) << endl;
  cout << "x<=y = " << (x<=y) << endl;
  cout << "x>=y = " << (x>=y) << endl;
  cout << "x==y = " << (x==y) << endl;
  cout << "x!=y = " << (x!=y) << endl;



  return 0;
}

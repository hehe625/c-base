#include <iostream>
#include "complex.h"
#include "complex.cpp"

int main()
{
  using std::cout;
  complex c1(2,1);
  complex c2(4, 0);

  std::cout << c1 << std::endl;
  std::cout << c2 << std::endl;
  
  std::cout << c1+c2 << std::endl;
  
  std::cout << conj(c1) << std::endl;
  
  std::cout << (c1 += c2) << std::endl;
  
  std::cout << (c1 == c2) <<std:: endl;
  std::cout << +c2 << std::endl;
  std::cout << -c2 << std::endl;

  std::cout << (5 + c2) << std::endl;
  
  return 0;
}

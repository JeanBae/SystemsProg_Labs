#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
int main() {
  int x = 44;
  int y = 22;
  // part (a)
  int * p1 = &x;
  *p1 = 11;
  // part (b)
  const int * p2 = &x;
  *p2 = 11;
  p2 = &y;
  // part (c)
  const int * const p3 = &x;
  *p3 = 11;
  p3 = &y;
  return EXIT_SUCCESS;
} // main

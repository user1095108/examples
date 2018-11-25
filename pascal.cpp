#include <cassert>

#include <iostream>

unsigned pascal1(unsigned n, unsigned k)
{
  if (!k || (n == k))
  {
    return 1;
  }
  else
  {
    return pascal1(n - 1, k - 1) + pascal1(n - 1, k);
  }
}

int main()
{
  for (unsigned i{}; i != 10; ++i)
  {
    for (unsigned j{}; j != i + 1; ++j)
    {
      std::cout << pascal1(i, j) << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}

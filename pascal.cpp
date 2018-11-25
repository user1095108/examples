#include <cassert>

#include <iostream>

unsigned pascal1(unsigned i, unsigned N)
{
  if (!i || (i == N - 1))
  {
    return 1;
  }
  else
  {
    return pascal1(i - 1, N - 1) + pascal1(i, N - 1);
  }
}

int main()
{
  for (unsigned i{}; i != 10; ++i)
  {
    for (unsigned j{}; j != i; ++j)
    {
      std::cout << pascal1(j, i) << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}

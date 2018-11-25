#include <cassert>

#include <iostream>

unsigned binom1(unsigned n, unsigned k)
{
  if (!k || (n == k))
  {
    return 1;
  }
  else
  {
    return binom1(n - 1, k - 1) + binom1(n - 1, k);
  }
}

unsigned binom2(unsigned n, unsigned k)
{
  unsigned r{1};

  for (unsigned i{1}; i != k + 1; ++i)
  {
    r = (r * (n - i + 1)) / i;
  }

  return r;
}

int main()
{
  for (unsigned i{}; i != 10; ++i)
  {
    for (unsigned j{}; j != i + 1; ++j)
    {
      std::cout << binom2(i, j) << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}

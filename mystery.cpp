#include <cassert>

#include <iostream>

using index_t = __uint128_t;

std::string mystery(index_t const i, unsigned n)
{
  assert(n);

  if (1 == n)
  {
    return i ? "1" : "0";
  }
  else
  {
    auto const size{index_t{1} << n};

    return i < (size / 2) ?
      "0" + mystery(i, n - 1) :
      "1" + mystery(size - i - 1, n - 1);
  }
}

std::string mystery2(index_t i, unsigned n)
{
  char r[n]{};

  auto size{index_t{1} << n};

  while (n--)
  {
    if (i < (size >> 1))
    {
      r[sizeof(r) - n - 1] = '0';
    }
    else
    {
      r[sizeof(r) - n - 1] = '1';
      i = size - i - 1;
    }

    size >>= 1;
  }

  return {r, sizeof(r)};
}

int main()
{
  unsigned n{2};

  //std::cin >> n;

  auto const size{index_t{1} << n};

  for (index_t i{}; i != size; ++i)
  {
    std::cout << mystery2(i, n) << std::endl;
  }

/*
  for (index_t i{size - n}, end(size); i != end; ++i)
  {
    std::cout << mystery(i, n) << std::endl;
  }
*/

  return 0;
}

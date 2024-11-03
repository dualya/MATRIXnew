#include <iostream>
#include <stdexpect>

int main()
{
  size_t m = 0, n = 0;
  std::cin >> m >> n;
  if (!(std::cin >> m >> n))
  {
    std::cerr << "Invalid matrix dimensions\n";
    return 1;
  }
  try
  {
    Matrix mat(m, n);
    mat.input(std::cin)
    mat.print(std::cout);
    mat.resize(m + 1, n + 1);
    mat.fill(0);
    mat.print(std::cout);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}

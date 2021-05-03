#include <iostream> //std::cout, std::cin, etc.
#include <cstdlib>  //C++ version of stdlib.h
#include <cstring>  //C++ version of string.h
#include <string>
#include <typeinfo>

void f(int &y, int z)
{
  y = z * y;
}

void f(int &x)
{
  f(x, x);
  std::cout << x << " "
            << "\n";
}

int main(int argc, char *argv[])
{

  char False;
  // std::cout << "Test review\n";

  int n[3] = {3, 7, 9};
  f(n[1]);

  int y = n[1];

  std::cout << y << "\n";

  // int tracker[] = {88, 21, 9, 7, 119, 22, 11};
  // tracker[7] = 50;

  // std::cout << "tracker is " << tracker[9] << "\n";

  auto just = 2.5;

  int num = 5;

  // std::cout << typeid(just).name() << "\n";
  // std::cout << typeid(num).name() << "\n";

  // char ch = "b";

  // int n[] = {2, 5, 8, 3, 6, 9, 0, 10};
  // char a[] = {'z', 'x', 'y', 'q', 'u', 'o', 'g', 'c', 'w', 'e', 't'};

  // for (auto i : n)
  // {
  //   if (n[i] % 2 == 0)
  //   {
  //     std::cout << a[i] << " "
  //               << "\n";
  //   }
  // };

  // 2, 8, 6, 0, 10

  enum class Days
  {
    SUN = 97,
    MON = 66,
    TUE = 99,
    WED,
    THUR = 102,
    FRI,
    SAT
  };

  Days days[] = {Days::SUN, Days::MON, Days::TUE};

  int count = 0;

  while (count < 3)
  {
    std::cout << static_cast<char>(days[count]) << " what"
              << "\n";
    count++;
  }

  return 0;
}
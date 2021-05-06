#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>

void g(int a[], int s)
{
    std::cout << "g(a) =" << a << "\n";

    for (int i = 0; i < s; i++)
    {
        a[i] = i * i;
    }
}

int main()
{

    int a[5] = {1, 2, 3, 4, 5};
    std::cout << "a = " << a << std::endl;
    g(a, 5);
    for (auto e : a)
    {
        std::cout << e << " ";
    }

    // std::ofstream ofs("data.dat");
    // ofs << 10 << " " << 20 << " " << 30 << "\n";
    // ofs << 40 << " " << 50 << " " << 60 << "\n";
    // ofs.close();

    // std::ifstream ifs("data.dat");
    // int n = 0;
    // >> is the extraction operator
    // while (ifs >> n)
    // {
    //     std::cout << n << " ";
    // }

    // char stop;
    // std::cin >> stop;

    return 0;
}
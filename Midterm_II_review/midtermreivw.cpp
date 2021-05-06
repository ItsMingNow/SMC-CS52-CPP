#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void swap(string[]);

int string_length(char s[]);

void reverse_an_array(int n[], int size);

int main()
{
    // cout << "test" << endl;

    // int b = 100;
    // int *c = &b;
    // int &a = b;
    // cout << b << " " << c << " " << a;

    // string str;
    // char c;
    // int x;

    // cin >> str;
    // cin >> c;
    // cin >> str;
    // cin >> c;
    // cin >> x;
    // cin >> c;
    // cout << str << " " << x;

    // vector<int> nums;
    // nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    string ibiza[2] = {"beaches", "music"};
    swap(ibiza);

    // cout << ibiza[0] << " and " << ibiza[1] << endl;

    int size = 0;
    int index1, index2;
    int array[4][4];

    for (int index1 = 0; index1 < 4; index1++)
    {
        for (int index2 = 0; index2 < 4; index2++)
        {
            array[index1][index2] = index1 + index2;
        }
    }

    // for (int index1 = 0; index1 < 4; index1++)
    // {
    //     for (int index2 = 0; index2 < 4; index2++)
    //     {
    //         cout << array[index1][index2] << " ";
    //     }
    //     cout << endl;
    // }

    int arr[] = {1, 2, 3};

    // for (int &element : arr)
    // {
    //     element *= 10;
    // }

    // for (int &element : arr)
    // {
    //     cout << element << endl;
    // }

    // int i = 0;
    // int j = 0;
    // for (i = 0; i < 4; i++)
    // {
    //     for (j = 0; j < 3; j++)
    //     {
    //         if (i == 2)
    //         {
    //             cout << "value of i in loop = " << i << endl;
    //             break;
    //         }
    //     }
    // }

    // cout << "value of i = " << i << endl;

    // int n;
    // char c;
    // n = -128;
    // c = n;

    // cout << "size of c " << (sizeof c) << endl;

    char c[] = "sunny days are here again";

    // cout << "length of c = " << string_length(c);
    // string_length(c);

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};

    reverse_an_array(a, 8);

    for (auto e : a)
    {
        cout << "New array Value " << e << " ";
    }
}

void reverse_an_array(int n[], int size)
{
    int newArray[size];

    for (int i = 0; i < (size); i++)
    {
        newArray[i] = n[size - i - 1];
    }

    for (int k = 0; k < (size); k++)
    {
        n[k] = newArray[k];
    }
}

int string_length(char s[])
{
    int index = 0;

    while (s[index] != '\0')
    {
        index += 1;
    }

    return index;
}

void swap(string items[])
{
    string elem = items[0];

    items[0] = items[1];
    items[1] = elem;
}

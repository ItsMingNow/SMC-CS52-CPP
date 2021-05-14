// Name: Yanming Yu
// SSID: 1748671
// Assignment #: 4
// Submission Date: 4/13/2021
//
// Description: Vector
//

#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

struct Vector
{
    int size = 0;
    int capacity = 0;
    int *data = nullptr;
};

void construct_vector(Vector &v, int size = 0, int initVal = 0);

void destroy_vector(Vector &v);

int *data(const Vector &v);

int size(const Vector &v);

int capacity(const Vector &v);

int &at(Vector &v, int index);

void clear(Vector &v);

bool empty(const Vector &v);

int &front(const Vector &v);

int &back(const Vector &v);

void pop_back(Vector &v);

void push_back(Vector &v, int element);

int find(Vector &v, int key);

void printArray(Vector &v);

int main()
{
    Vector a, b;

    cout << "construct_vector(a, 5, 0)" << endl;
    construct_vector(a, 5, 0);

    cout << "a = ";
    printArray(a);
    cout << "size(a) is " << size(a) << "; ";
    cout << "capacity(a) is " << capacity(a) << endl;
    cout << "\n";

    at(a, 0) = 10;
    at(a, 3) = 5;
    cout << "at(a , 0) = " << at(a, 0) << endl;
    cout << "at(a , 3) = " << at(a, 3) << endl;
    cout << "a = ";
    printArray(a);
    cout << "\n";

    cout << "front(a) = " << front(a) << endl;
    cout << "back(a) = " << back(a) << endl;
    cout << "\n";

    cout << "destroy_vector(a)" << endl;
    destroy_vector(a);
    cout << "\n";

    /*
    ------------------------------------------------------------------------------------------------------------------------
    */

    //Vector b

    cout << "construct_vector(b)" << endl;
    construct_vector(b);
    cout << "size(b) is " << size(b) << "; ";
    cout << "capacity(b) is " << capacity(b) << endl;
    cout << "\n";

    //Add elements to b
    cout << "push_back(b, 0); push_back(b, 1); push_back(b, 2); push_back(b, 3);" << endl;
    push_back(b, 0);
    push_back(b, 1);
    push_back(b, 2);
    push_back(b, 3);
    cout << "\n";

    cout << "b = ";
    printArray(b);
    cout << "size(b) is " << size(b) << "; ";
    cout << "capacity(b) is " << capacity(b) << endl;

    cout << "at(b,1) = " << at(b, 1) << endl;
    cout << "\n";

    //use at to assign new value to 2nd element
    at(b, 1) = 88;
    cout << "at(b,1) = " << at(b, 1) << endl;
    printArray(b);
    cout << "\n";

    //Remove last element
    cout << "pop_back(b)" << endl;
    pop_back(b);
    cout << "b = ";
    printArray(b);
    cout << "\n";

    //add two more elements
    cout << "push_back(b, 55); push_back(b, 75);" << endl;
    push_back(b, 55);
    push_back(b, 75);
    cout << "b = ";
    printArray(b);
    cout << "\n";

    //clear the vector
    cout << "clear the vector" << endl;
    clear(b);
    cout << "size(b) is " << size(b) << "; ";
    cout << "capacity(b) is " << capacity(b) << endl;
    cout << "\n";

    cout << "empty(b) is ";
    if (empty(b))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    cout << "\n";

    cout << "push_back(b, 10); push_back(b, 20); push_back(b, 30); push_back(b, 40); push_back(b, 50); push_back(b, 60);" << endl;
    push_back(b, 10);
    push_back(b, 20);
    push_back(b, 30);
    push_back(b, 40);
    push_back(b, 50);
    push_back(b, 60);
    cout << "\n";

    cout << "size(b) is " << size(b) << "; ";
    cout << "capacity(b) is " << capacity(b) << endl;
    cout << "\n";

    //find function that returns
    cout << "int i = find(b, 30), ";
    int i = find(b, 30);
    cout << "i = " << i << endl;
    cout << "int i = find(b, 999), ";
    i = find(b, 999);
    cout << "i = " << i << endl;
    cout << "\n";

    //traverse data with pointer
    cout << "int* ptr = data(b)" << endl;
    int *ptr = data(b);
    cout << "b = ";
    for (int j = 0; j < b.size; j++)
    {
        cout << *(ptr + j) << " ";
    }
    cout << endl;

    //destroy the vector
    destroy_vector(b);
    cout << "size(b) is " << size(b) << "; ";
    cout << "capacity(b) is " << capacity(b) << endl;

    return 0;
}

void construct_vector(Vector &v, int size, int initVal)
{
    v.size = v.capacity = size;

    v.data = new int[size];

    for (int i = 0; i < size; i++)
    {
        v.data[i] = initVal;
    }
}

void destroy_vector(Vector &v)
{
    v.size = v.capacity = 0;

    delete[] v.data;
}

int *data(const Vector &v)
{
    //returns pointer to the first element in vector

    int *ptr = &v.data[0];

    return ptr;
}

int size(const Vector &v)
{
    return v.size;
}

int capacity(const Vector &v)
{
    return v.capacity;
}

int &at(Vector &v, int index)
{
    //returns a reference to the element at location i

    int &ref = v.data[index];

    return ref;
}

void clear(Vector &v)
{
    //erase the elements of vector but does not change capacity

    v.size = 0;

    delete[] v.data;
}

bool empty(const Vector &v)
{
    //returns true if vector is empty
    if (v.size == 0)
    {
        return true;
    }

    return false;
}

int &front(const Vector &v)
{
    int &ref = v.data[0];

    return ref;
}

int &back(const Vector &v)
{
    int &ref = v.data[v.size - 1];

    return ref;
}

void pop_back(Vector &v)
{
    if (v.size == 0)
    {
        cout << "No elements to remove" << endl;
    }
    else
    {
        int newSize = (v.size - 1);

        int newArray[newSize];

        for (int i = 0; i < newSize; i++)
        {
            newArray[i] = v.data[i];
        }

        delete[] v.data;

        v.data = new int[newSize];

        for (int j = 0; j < newSize; j++)
        {
            v.data[j] = newArray[j];
        }

        v.size = v.capacity = newSize;
    }
}

void push_back(Vector &v, int element)
{
    if (v.size == 0)
    {
        v.size = v.capacity = 1;

        v.data = new int[1];

        v.data[0] = element;
    }
    else
    {
        int newSize = (v.size + 1);

        int oldArray[v.size];

        for (int i = 0; i < v.size; i++)
        {
            oldArray[i] = v.data[i];
        }

        delete[] v.data;

        v.data = new int[newSize];

        for (int j = 0; j < v.size; j++)
        {
            v.data[j] = oldArray[j];
        }

        v.data[newSize - 1] = element;

        v.size = v.capacity = newSize;
    }
}

int find(Vector &v, int key)
{
    for (int i = 0; i < v.size; i++)
    {
        if (v.data[i] == key)
        {
            return i;
        }
    }

    return -1;
}

void printArray(Vector &v)
{
    for (int i = 0; i < v.size; i++)
    {
        cout << v.data[i] << " ";
    }

    cout << endl;
}
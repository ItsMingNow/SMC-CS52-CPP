// Name: Yanming Yu
// SSID: 1748671
// Assignment #: 5
// Submission Date: 5/17/2021
//
// Description: Arraylist
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

namespace CS52
{
    class ArrayList
    {
        // access specififer
    public:
        ArrayList()
        {
            _data = new int[_size];
        }

        ArrayList(int size, int initial_value)
        {
            _size = _capacity = size;

            _data = new int[_size];

            for (int i = 0; i < size; i++)
            {
                _data[i] = initial_value;
            }
        }

        ArrayList(const ArrayList &al)
        {
            _data = new int[al.size()];
            _size = al.size();
            _capacity = al.capacity();
            for (int i = 0; i < al.size(); i++)
            {
                _data[i] = al.at(i);
            }
        }
        // ~ArrayList();

        //Resize an ArrayList
        void resize(int new_size, int initial_value);

        //Increase capacity of an ArrayList
        void reserve(int capacity);

        //Returns a reference to the element at location i in an ArrayList.
        int &at(int i) const
        {
            int &ref = _data[i];
            return ref;
        } // throws an std::string exception

        // Returns the allocated storage for an ArrayList.
        int capacity() const { return _capacity; }

        //Erases the elements of an ArrayList but does not change capacity.
        void clear();

        //Returns pointer to the first element in an ArrayList.
        int *data() const
        {
            int *ptr = &_data[0];

            return ptr;
        }

        //If ArrayList is empty return true, else false.
        bool empty() const
        {
            if (_size == 0)
            {
                return true;
            }

            return false;
        }

        //Deletes the element at the end of an ArrayList.
        void pop_back();

        //Add an element to the end of the ArrayList.
        void push_back(int element);

        //Returns a reference to the first element in an ArrayList.
        int &front() const
        {
            int &ref = _data[0];

            return ref;
        } //throws and std::out_of_range exception

        //Returns a reference to the last element in an ArrayList.
        int &back() const
        {
            int &ref = _data[_size - 1];

            return ref;
        }
        // throw(...); //std::out_of_range

        //Returns the number of elements in the ArrayList.
        int size() const { return _size; }

        //Search for a key in ArrayList, return index of key or -1 if not found
        int find(int key);

        //Overloaded operators
        int &operator[](int i) { return _data[i]; }
        ArrayList &operator=(const ArrayList &object)
        {
            delete[] _data;
            _size = object.size();
            _data = new int[_size];

            _capacity = object.capacity();
            for (int i = 0; i < object.size(); i++)
            {
                _data[i] = object.at(i);
            }
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &ostream, ArrayList &object)
        {

            return ostream << *object._data;
        }

    private:
        int _size = 0;
        int _capacity = 0;
        int *_data = nullptr;
    };

}

void CS52::ArrayList::resize(int new_size, int initial_value)
{

    for (int i = (_size); i < new_size; i++)
    {
        _data[i] = initial_value;
    }

    _size = new_size;

    int newArray[new_size];

    for (int j = 0; j < new_size; j++)
    {
        newArray[j] = _data[j];
    }

    delete[] _data;

    _data = new int[new_size];

    for (int k = 0; k < new_size; k++)
    {
        _data[k] = newArray[k];
    }
}

void CS52::ArrayList::reserve(int capacity)
{
    if (capacity > _capacity)
    {
        _capacity = capacity;
    }
}

void CS52::ArrayList::clear()
{
    _size = 0;

    delete[] _data;

    _data = new int[_size];
}

int CS52::ArrayList::find(int key)
{
    for (int i = 0; i < size(); i++)
    {
        if (_data[i] == key)
        {
            return i;
        }
    }

    return -1;
}

void CS52::ArrayList::push_back(int element)
{
    int newSize = (_size + 1);

    int oldArray[_size];

    for (int i = 0; i < _size; i++)
    {
        oldArray[i] = _data[i];
    }

    delete[] _data;

    _data = new int[newSize];

    for (int j = 0; j < _size; j++)
    {
        _data[j] = oldArray[j];
    }

    _data[newSize - 1] = element;

    _size = _capacity = newSize;
}

void info(CS52::ArrayList &arrlist)
{
    cout << "Size is: " << arrlist.size() << endl;
    cout << "Capacity is: " << arrlist.capacity() << endl;
    cout << "Contents : ";
    for (int i = 0; i < arrlist.size(); i++)
    {
        cout << arrlist[i] << " ";
    }
    cout << endl;
}

void CS52::ArrayList::pop_back()
{
    if (_size == 0)
    {
        cout << "No elements to remove" << endl;
    }
    else
    {
        int newSize = (_size - 1);

        int newArray[newSize];

        for (int i = 0; i < newSize; i++)
        {
            newArray[i] = _data[i];
        }

        delete[] _data;

        _data = new int[newSize];

        for (int j = 0; j < newSize; j++)
        {
            _data[j] = newArray[j];
        }

        _size = _capacity = newSize;
    }
}
int main()
{
    // Default constructor, push_back, at and creating arraylist object
    CS52::ArrayList a;
    a.push_back(10);
    a.push_back(88);
    a.at(0) = 99;
    info(a);

    // b
    cout << "\n//overloaded constructor, [] op, at, find, empty, clear, \ exception handling: front, at \nCS52::ArrayList b(2,5);\n";

    CS52::ArrayList b(2, 5);
    cout << "b is " << b << "\n";

    cout << "\n//Add more elements to b\n";
    cout << "b.push_back(10); b.push_back(2);\n";
    cout << "b.push_back(99); b.push_back(-5);\n";
    b.push_back(10);
    b.push_back(2);
    b.push_back(99);
    b.push_back(-5);

    cout << "\n//array index [] and at()\n";
    cout << "b[0] = 25; b[1] = 1;\n";
    b[0] = 25;
    b[1] = 1;
    cout << "b.at(0) ; b.at(1) ;\n";
    cout << b.at(0) << " " << b.at(1) << "\n";

    cout << "\n//find method\n int i = b.find(25) , ";
    cout << "i = " << b.find(25);
    cout << "\n int i = b.find(999), ";
    cout << "i = " << b.find(999);

    cout << "\n\n//empty method, size, and capacity\n";
    cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";
    cout << "b.clear()\n";
    b.clear();
    info(b);
    cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";

    cout << "\n\n//Exception handling:";
    try
    {
        cout << "\nb.front() = ";
        cout << b.front();
    }
    catch (std::out_of_range e)
    {
        cerr << e.what();
    }
    try
    {
        cout << "\nb.at(9) = ";
        cout << b.at(9);
    }
    catch (std::string msg)
    {
        cerr << "\n"
             << msg << std::endl;
    }

    //c

    cout << "\n//copy constructor , copy assignment , pop_back ,reserve ,\ \n//resize, capacity, size\nCS52::ArrayList c(b);\n";
    cout << "\n//Add more elements to b\n";
    cout << "b.push_back(11); b.push_back(7);\n";
    cout << "b.push_back(3); b.push_back(23);\n";
    b.push_back(11);
    b.push_back(7);
    b.push_back(3);
    b.push_back(23);
    CS52::ArrayList c(b);
    info(c);

    //d

    cout << "\n//copy assignment\n";
    CS52::ArrayList d;
    d = c;
    cout << "CS52::ArrayList d = c; \n";
    cout << "d is " << d << "\n";

    cout << "\n//size vs capacity()\n";
    cout << "d.size() is " << d.size() << "\n";
    cout << "d.capacity() is " << d.capacity() << "\n";

    cout << "\n//pop_back()\n";
    cout << "d.pop_back();d.pop_back();\n";
    d.pop_back();
    d.pop_back();

    cout << "\n//size vs capacity()\n";
    cout << "d.size() is " << d.size() << "\n";
    cout << "d.capacity() is " << d.capacity() << "\n";

    cout << "\n//Resize-Reserve Testing \n";
    d.resize(10, -1);
    cout << "d.resize(10, -1); \n";
    info(d);

    d.resize(5, 0);
    cout << "\nd.resize(5, 0); \n";
    info(d);

    d.reserve(15);
    cout << "\nd.reserve(15); \n";
    info(d);

    d.reserve(1);
    cout << "\nd.reserve(1); \n";
    info(d);

    return 0;
}
#include "pgm.h"

#include <iostream>
#include <string.h>

using namespace std;

// function to read image
SImage readPGM(const std::string filename)
{
    SImage image;

    fstream in;
    in.open(filename, ios::in);

    if (!in.is_open())
    {
        cout << "File couldn't be opened" << endl;
        return image;
    }

    getline(in, image.format);

    // getline(in, image.comment);

    in >> image.cols; // read image colums
    in >> image.rows; // read image rows
    cout << "number of pixels: " << image.cols * image.rows << endl;

    in >> image.maxVal;

    // set size of gray value vector
    image.grayvalues.resize(image.cols * image.rows);

    // read grayvalue over loop
    for (unsigned int i = 0; i < (image.cols * image.rows); i++)
    {
        in >> image.grayvalues[i];
    }

    if (image.cols * image.rows != image.grayvalues.size())
    {
        cout << "Could not read all pixels" << endl;
    }
    else
    {
        cout << "All pixels read" << endl;
    }

    return image;
}
// ask for gray values
short getGrayval(const SImage &img, unsigned int r, unsigned int c)
{
    short g = 0;

    if ((r * c) > img.grayvalues.size())
    {
        cout << r << ", " << c << "is not a element of the image" << endl;

        return g;
    }

    g = img.grayvalues[r * img.cols + c];

    return g;
}
// manipulate the image
void setGrayVal(SImage &img, unsigned int r, unsigned int c, short val)
{
    if ((r * c) > img.grayvalues.size())
    {
        cout << r << ", " << c << "is not a element of the image" << endl;

        return;
    }

    img.grayvalues[r * img.cols + c] = val;
}
// save the image
// int writePGM(const SImage, const std::string filename)
// {
//     fstream file;
//     file.open(filename, ios::out);

//     if (!file.is_open())
//     {
//         cout << "Could not file " << filename << endl;

//         return -1;
//     }

//     file << "P2" << endl;
//     file << image.cols << " " << image.rows << endl;
//     file << image.maVal << endl;

//     for (unsigned int i = 0, j = 0; i < image.rows * image.cols; i++, j++)
//     {
//         file << image.grayvalues[i] << " ";

//         if (j == 27)
//         {
//             file << endl;
//             j = -1;
//         }
//     }

//     return 0;
// }

int main()
{
    SImage img;
    img = readPGM("digit_00.pgm");

    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            // cout << getGrayval(img, i, j);
            if (getGrayval(img, i, j) == 0)
            {
                cout << "   ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}

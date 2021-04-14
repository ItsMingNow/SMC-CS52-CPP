// Name: Yanming Yu
// SSID: 1748671
// Assignment #: 3
// Submission Date: 4/13/2021
//
// Description: read and write images
//

// #include "pgm.h"

#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Image data
struct SImage
{
    unsigned int rows;
    unsigned int cols;
    unsigned int maxVal;
    std::string format;
    std::string comment;
    std::vector<short> grayvalues; //save gray values
};

// Color Struct
struct Color
{
    unsigned char bgR;
    unsigned char bgG;
    unsigned char bgB;
    unsigned char fontR;
    unsigned char fontG;
    unsigned char fontB;
};

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
    // cout << "number of pixels: " << image.cols * image.rows << endl;

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
        // cout << "All pixels read" << endl;
    }

    return image;
}

void draw(SImage array[], int digit)
{

    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            // cout << getGrayval(img, i, j);
            if (array[digit].grayvalues[i * array[digit].cols + j] == 0)
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
}

void writeToColorPGMImages(SImage array[], int digit, Color fontAndBG)
{
    int r, g, b, fR, fG, fB;

    cout << "Enter background color: " << endl;

    cin >> r >> g >> b;

    while (r > array[digit].maxVal || g > array[digit].maxVal || b > array[digit].maxVal || r < 0 || g < 0 || b < 0)
    {
        cout << "number entered must be between 0 and " << array[digit].maxVal << endl;
        cin >> r >> g >> b;
    }

    fontAndBG.bgR = r;

    fontAndBG.bgG = g;

    fontAndBG.bgB = b;

    cout << "Enter font color: " << endl;

    cin >> fR >> fG >> fB;

    while (fR > array[digit].maxVal || fG > array[digit].maxVal || fB > array[digit].maxVal || fR < 0 || fG < 0 || fB < 0)
    {
        cout << "number entered must be between 0 and " << array[digit].maxVal << endl;
        cin >> fR >> fG >> fB;
    }

    fontAndBG.fontR = fR;

    fontAndBG.fontG = fG;

    fontAndBG.fontB = fB;

    // formats file name
    string filename = "digit_0" + to_string(digit) + ".ppm";

    // Creates new image file
    ofstream NewImage;
    NewImage.open(filename);

    NewImage << "P3" << endl;
    NewImage << array[digit].rows << " " << array[digit].cols << endl;
    NewImage << array[digit].maxVal << endl;

    for (int i = 0; i < array[digit].rows; i++)
    {
        for (int j = 0; j < array[digit].cols; j++)
        {
            if (array[digit].grayvalues[i * array[digit].cols + j] > 0)
            {
                NewImage << int(fontAndBG.fontR) << " " << int(fontAndBG.fontG) << " " << int(fontAndBG.fontB) << " ";
            }
            else
            {

                NewImage << int(fontAndBG.bgR) << " " << int(fontAndBG.bgG) << " " << int(fontAndBG.bgB) << " ";
            }
        }
        NewImage << endl;
    }

    cout << "Image has been saved to " << filename << endl;

    NewImage.close();
}

int main()
{
    SImage img0, img1, img2, img3, img4, img5, img6, img7, img8, img9;
    img0 = readPGM("digit_00.pgm");
    img1 = readPGM("digit_01.pgm");
    img2 = readPGM("digit_02.pgm");
    img3 = readPGM("digit_03.pgm");
    img4 = readPGM("digit_04.pgm");
    img5 = readPGM("digit_05.pgm");
    img6 = readPGM("digit_06.pgm");
    img7 = readPGM("digit_07.pgm");
    img8 = readPGM("digit_08.pgm");
    img9 = readPGM("digit_09.pgm");

    SImage imageObjects[10] = {img0, img1, img2, img3, img4, img5, img6, img7, img8, img9};

    Color fontAndBG;

    int imgNum;

    string yesOrNo;

    bool runProgram = true;

    while (runProgram == true)
    {
        // ask user which digit
        cout << "Which MNIST handwritten digit do you want to display from 0 to 9? " << endl;

        cin >> imgNum;

        draw(imageObjects, imgNum);

        cout << "Do you want to change the background color and font (yes or no)? ";

        cin >> yesOrNo;

        // yesOrNo = "yes";

        if (yesOrNo == "yes")
        {
            writeToColorPGMImages(imageObjects, imgNum, fontAndBG);
        }

        cout << "Do you want to see another digit (yes or no)? " << endl;

        cin >> yesOrNo;

        if (yesOrNo == "no")
        {
            cout << "Goodbye" << endl;
            runProgram = false;
        }
    }

    return 0;
}

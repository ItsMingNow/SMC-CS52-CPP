
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct SImage
{
    unsigned int rows;
    unsigned int cols;
    unsigned int maxVal;
    std::string format;
    std::string comment;
    std::vector<short> grayvalues; //save gray values
};

// function to read image
SImage readPGM(const std::string dateiname);
// ask for gray values
short getGrayval(const SImage &img, unsigned int r, unsigned int c);
// manipulate the image
void setGrayVal(SImage &img, unsigned int r, unsigned int c, short val);
// save the image
int writePGM(const SImage, const std::string filename);
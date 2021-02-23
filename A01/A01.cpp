//
// Name: Yanming Yu
// SSID: Student ID Number
// Assignment #: 1
// Submission Date: 3/2/21 //
// Program Description: This program prints the
// average of five numbers input by a user. //

#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    // declare five variables and a average varable
    double one, two, three, four, five, average;
    // ask user for 5 numbers separated by space
    std::cout << "Enter five space separated numbers to compute their average:\n";
    std::cin >> one >> two >> three >> four >> five;
    // calculate average of the five numbers
    average = (one + two + three + four + five) / 5;
    // display the value of the five numbers
    std::cout << "The average of {";
    std::cout << one << " " << two << " " << three << " " << four << " " << five;
    std::cout << "} is ";
    std::cout << std::setprecision(2) << std::fixed << average << "\n";
    // ask user to press any key to leave
    std::cout << "Enter any key to exit:"
              << "\n";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
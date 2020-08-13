// Lesson8OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
#include <cstdint>//for std::uint_fast8
#include <string>
#include <iostream>


class Ball85aquiz
{
private:
    std::string m_color{ "black" };
    // The radius always gets initialized by the constructors.
    double m_radius;
public:
    // Constructor with only radius parameter (color will use default value)
    Ball85aquiz(double radius) : m_radius{ radius }
    {}
    // Constructor with both color and radius parameters
    Ball85aquiz(const std::string &color = "black", double radius = 1): m_color{ color }, m_radius{ radius }
    {}

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

void lesson85aquiz()
{
    Ball85aquiz defdd{};
    defdd.print();

    Ball85aquiz blueaaa{ "blue" };
    blueaaa.print();

    Ball85aquiz twentyaaa{ 20.0 };
    twentyaaa.print();

    Ball85aquiz blueTwentyaaa{ "blue", 20.0 };
    blueTwentyaaa.print();

    /*
    Why do we not need to declare a default constructor in the program above,
    even though we’re constructing def without arguments?

    “Ball def{};” uses the second Ball constructor which has a default argument 
    for every parameter.
    
    */
}


int main()
{
    lesson85aquiz();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project 
// > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > 
// Project and select the .sln file

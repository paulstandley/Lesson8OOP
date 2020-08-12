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
#include <iostream>


class RGBA
{
public:
    // A type alias saves us some typing and makes the class easier to maintain
    using uif8 = std::uint8_t;
private:
    uif8 m_red;
    uif8 m_green;
    uif8 m_blue;
    uif8 m_alpha;
public:
    RGBA(uif8 red = 1, uif8 green = 1, uif8 blue = 1, uif8 alpha = 255)
        : m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
    {}
    void print()
    {
        std::cout << "Red = " << static_cast<int>(m_red) << " Green = " << static_cast<int>(m_green)
            << " Blue = " << static_cast<int>(m_blue) << " Alpha = " << static_cast<int>(m_alpha) << ".\n";
    };
};

void lesson85aquiz()//std::uint8_t 
{
    /*Write a class named RGBA that contains 4 member variables of type 
    std::uint_fast8_t named m_red, m_green, m_blue, and m_alpha 
    (#include cstdint to access type std::uint_fast8_t). 
    Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha. 
    Create a constructor that uses a member initializer list that allows the user
    to initialize values for m_red, m_blue, m_green, and m_alpha. 
    Include a print() function that outputs the value of the member variables.
    
    */

    RGBA teal{ 0, 127, 127 };
    teal.print();

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

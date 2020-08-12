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


class Rectanglensmi
{
private:
    double m_length{ 1.0 };
    double m_width{ 1.0 };

public:

    Rectanglensmi(double length, double width)
        : m_length{ length },
        m_width{ width }
    {
        // m_length and m_width are initialized by the constructor (the default values aren't used)
    }

    Rectanglensmi(double length)
        : m_length{ length }
    {
        // m_length is initialized by the constructor.
        // m_width's default value (1.0) is used.
    }

    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }

};


void class_cpp_oop_85a()
{
    /*Non-static member initialization

    When writing a class that has multiple constructors (which is most of them), 
    having to specify default values for all members in each constructor 
    results in redundant code.
    If you update the default value for a member, 
    you need to touch each constructor.

    Starting with C++11,
    it’s possible to give normal class member variables 
    (those that don’t use the static keyword)
    a default initialization value directly

    Non-static member initialization 
    (also called in-class member initializers)
    provides default values for your member variables that your
    constructors will use if the constructors do not provide initialization
    values for the members themselves (via the member initialization list).

    However, note that constructors still determine what 
    kind of objects may be created. 

    If a default initialization value is provided and the constructor initializes
    the member via the member initializer list, 
    the member initializer list will take precedence.
    
    */

    Rectanglensmi xxxxx{ 2.0, 3.0 };
    xxxxx.print();

    Rectanglensmi yyyyy{ 4.0 };
    yyyyy.print();
    
    /*Note that initializing members 
    using non-static member initialization requires using either an equals sign, 
    or a brace (uniform) initializer -- the direct initialization
    form doesn’t work here.

    Rule

    Favor use of non-static member initialization to give default values 
    for your member variables.
    
    */
}


int main()
{
    


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

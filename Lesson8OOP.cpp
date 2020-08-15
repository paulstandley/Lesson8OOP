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
#include <cstddef>
#include <iostream>


class Datemfocd
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Datemfocd(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay() { return m_day; }
};

// Date constructor
Datemfocd::Datemfocd(int year, int month, int day)
{
    SetDate(year, month, day);
}

// Date member function
void Datemfocd::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

class Calcmfocd
{
private:
    int m_value = 0;

public:
    Calcmfocd(int value = 0);

    Calcmfocd& add(int value);
    Calcmfocd& sub(int value);
    Calcmfocd& mult(int value);

    int getValue() { return m_value; }
};

Calcmfocd::Calcmfocd(int value) : m_value(value)
{
}

Calcmfocd& Calcmfocd::add(int value)
{
    m_value += value;
    return *this;
}

Calcmfocd& Calcmfocd::sub(int value)
{
    m_value -= value;
    return *this;
}

Calcmfocd& Calcmfocd::mult(int value)
{
    m_value *= value;
    return *this;
}

void class_cpp_oop_89()
{
    /*Defining member functions outside the class definition

    All of the classes that we have written so far have been 
    simple enough that we have been able to implement the member 
    functions directly inside the class definition itself.

    However, as classes get longer and more complicated, 
    having all the member function definitions inside the class 
    can make the class harder to manage and work with. 
    
    Using an already-written class only requires understanding 
    its public interface (the public member functions), 
    not how the class works underneath the hood.
    The member function implementation details just get in the way.

    Fortunately,
    C++ provides a way to separate the “declaration” portion of the class
    from the “implementation” portion.
    This is done by defining the class member functions
    outside of the class definition. 
    To do so, simply define the member functions 
    of the class as if they were normal functions, 
    but prefix the class name to the function using the 
    scope resolution operator (::) (same as for a namespace).

Here is our Date class with the Date constructor and setDate() function defined outside of the class definition. Note that the prototypes for these functions still exist inside the class definition, but the actual implementation has been moved outside:

    */
}


int main()
{
    class_cpp_oop_89();


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

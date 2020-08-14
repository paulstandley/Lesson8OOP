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


void class_cpp_oop_88()
{
    /* The hidden “this” pointer
    
    One of the questions about classes that new object-oriented programmers
    often ask is, “When a member function is called,
    how does C++ keep track of which object it was called on?”. 
    The answer is that C++ utilizes a hidden pointer named “this”!
    Let’s take a look at “this” in more detail.

    The following is a simple class that holds an integer and provides a
    constructor and access functions. 
    Note that no destructor is needed because C++ can clean up integer
    member variables for us.

    class Simple
    {
    private:
        int m_id;
    public:
        Simple(int id)
        {
            setID(id);
        }
        void setID(int id) { m_id = id; }
        int getID() { return m_id; }
    };

    int main()
    {
        Simple simple(1);
        simple.setID(2);
        std::cout << simple.getID() << '\n';

        return 0;
    }

    As you would expect, this program produces the result: 2

    Somehow, when we call simple.setID(2);,
    C++ knows that function setID() should operate on object simple,
    and that m_id actually refers to simple.m_id.
    Let’s examine the mechanics behind how this works.

    The hidden *this pointer

    */
}


int main()
{
    class_cpp_oop_88();


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

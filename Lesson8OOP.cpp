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


void class_cpp_oop_812()
{
    std::cout << "Static member functions\n";
    
    /*Static member functions

    In the previous lesson on 8.11 -- Static member variables,
    you learned that static member variables are member variables that belong 
    to the class rather than objects of the class. 
    
    If the static member variables are public,
    we can access them directly using the class name and the scope resolution operator.
    But what if the static member variables are private?

    class Something
    {
    private:
        static int s_value;
    };
    int Something::s_value{ 1 }; 
    // initializer, this is okay even though s_value is private since it's a definition
    int main()
    {
        // how do we access Something::s_value since it is private?
    }

    In this case, 
    we can’t access Something::s_value directly from main(),
    because it is private. 
    Normally we access private members through public member functions. 
    While we could create a normal public member function to access s_value, 
    we’d then need to instantiate an object of the class type to use the function!
    We can do better. 
    It turns out that we can also make functions static.

    Like static member variables, 
    static member functions are not attached to any particular object.
    Here is the above example with a static member function accessor:

    class Something
    {
    private:
        static int s_value;
    public:
        static int getValue() { return s_value; } // static member function
    };
    int Something::s_value{ 1 }; // initializer
    int main()
    {
        std::cout << Something::getValue() << '\n';
    }

    Because static member functions are not attached to a particular object, 
    they can be called directly by using the class name 
    and the scope resolution operator. 
    Like static member variables, 
    they can also be called through objects of the class type, 
    though this is not recommended.

    /////////////////////////////////////////////////////////////////////////////

    Static member functions have no *this pointer

    Static member functions have two interesting quirks worth noting.
    First, because static member functions are not attached to an object, 
    they have no this pointer!
    This makes sense when you think about it -- 
    the this pointer always points to the object 
    that the member function is working on. 
    Static member functions do not work on an object,
    so the this pointer is not needed.

    Second, static member functions can directly access other static members 
    (variables or functions), but not non-static members.
    This is because non-static members must belong to a class object,
    and static member functions have no class object to work with!

    */
}

int main()
{
    class_cpp_oop_812();


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

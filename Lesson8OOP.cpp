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
#include "Date.h"
#include <iostream>


void class_cpp_oop_810()
{
    /*Const class objects and member functions
    
    Const, constexpr, and symbolic constants, you learned that fundamental data types
    (int, double, char, etc…) can be made const via the const keyword, 
    and that all const variables must be initialized at time of creation.

    In the case of const fundamental data types,
    initialization can be done through copy, direct,
    or uniform initialization:
    
    */

    const int value11 = 5; // copy initialization
    const int value21(7); // direct initialization
    const int value31{ 9 }; // uniform initialization (C++11)

    /*Const classes

    Similarly, 
    instantiated class objects can also be made const by using the const keyword.
    Initialization is done via class constructors:
    
    */

    //const Date date11; 
    // initialize using default constructor
    const Date date21(2020, 10, 16); 
    // initialize using parameterized constructor
    const Date date31{ 2020, 10, 16 }; 
    // initialize using parameterized constructor (C++11)

    /*Once a const class object has been initialized via constructor,
    any attempt to modify the member variables of the object is disallowed, 
    as it would violate the const-ness of the object.
    This includes both changing member variables directly (if they are public),
    or calling member functions that set the value of member variables. 
    Consider the following class:

    class Something
    {
    public:
        int m_value;

        Something(): m_value{0} { }

        void setValue(int value) { m_value = value; }
        int getValue() { return m_value ; }
    };

    int main()
    {
        const Something something{}; // calls default constructor

        something.m_value = 5; // compiler error: violates const
        something.setValue(5); // compiler error: violates const

        return 0;
    }

    Both of the above lines involving variable something are illegal
    because they violate the constness of something by either attempting
    to change a member variable directly, 
    or by calling a member function that attempts to change a member variable.

    Just like with normal variables,
    you’ll generally want to make your class objects const
    when you need to ensure they aren’t modified after creation.

    ////////////////////////////////////////////////////////////////////////////

    Const member functions

    Now, consider the following line of code:

    std::cout << something.getValue();

    Perhaps surprisingly, this will also cause a compile error, 
    even though getValue() doesn’t do anything to change a member variable!
    It turns out that const class objects can only explicitly call
    const member functions, 
    and getValue() has not been marked as a const member function.

    A const member function is a member function that guarantees 
    it will not modify the object or call any non-const member functions 
    (as they may modify the object).

    To make getValue() a const member function,
    we simply append the const keyword to the function prototype,
    after the parameter list, but before the function body:
    
    int getValue() const { return m_value; }
    // note addition of const keyword after parameter list, but before function body

    Now getValue() has been made a const member function, 
    which means we can call it on any const objects.

    For member functions defined outside of the class definition,
    the const keyword must be used on both the function prototype
    in the class definition and on the function definition:

    class Something
    {
    public:
        int m_value;
        Something(): m_value{0} { }
        void resetValue() { m_value = 0; }
        void setValue(int value) { m_value = value; }

        int getValue() const; // note addition of const keyword here
    };

    int Something::getValue() const // and here
    {
        return m_value;
    }

    Futhermore, 
    any const member function that attempts to change a member variable
    or call a non-const member function will cause a compiler error to occur.
    For example:
    
    class Something
    {
    public:
        int m_value ;

        void resetValue() const { m_value = 0; } // compile error, const functions can't change member variables.
    };

    In this example, resetValue() has been marked as a const member function, 
    but it attempts to change m_value. This will cause a compiler error.

    Note that constructors cannot be marked as const. 
    This is because constructors need to be able to initialize their member variables,
    and a const constructor would not be able to do so. 
    Consequently, the language disallows const constructors.

    Rule

    Make any member function that does not modify the state of the class object const, 
    so that it can be called by const objects.

    //////////////////////////////////////////////////////////////////////////////////

    Const member functions

    Now, consider the following line of code:

    std::cout << something.getValue();

    Perhaps surprisingly,
    this will also cause a compile error, even though getValue()
    doesn’t do anything to change a member variable!
    It turns out that const class objects can only explicitly 
    call const member functions, 
    and getValue() has not been marked as a const member function.

    A const member function is a member function that guarantees 
    it will not modify the object or call any non-const member functions
    (as they may modify the object).

    To make getValue() a const member function,
    we simply append the const keyword to the function prototype,
    after the parameter list, but before the function body:

    class Something
    {
    public:
        int m_value;
        Something(): m_value{0} { }
        void resetValue() { m_value = 0; }
        void setValue(int value) { m_value = value; }
        int getValue() const { return m_value; }
        // note addition of const keyword after parameter list, but before function body
    };

    Now getValue() has been made a const member function, 
    which means we can call it on any const objects.

    For member functions defined outside of the class definition, 
    the const keyword must be used on both the function 
    prototype in the class definition and on the function definition:

    class Something
    {
    public:
        int m_value;

        Something(): m_value{0} { }

        void resetValue() { m_value = 0; }
        void setValue(int value) { m_value = value; }

        int getValue() const; // note addition of const keyword here
    };

    int Something::getValue() const // and here
    {
        return m_value;
    }

    Futhermore, 
    any const member function that attempts to change a member variable
    or call a non-const member function will cause a compiler error to occur. 
    For example:

    class Something
    {
    public:
        int m_value ;

        void resetValue() const { m_value = 0; } // compile error, const functions can't change member variables.
    };

    In this example, resetValue() has been marked as a const member function,
    but it attempts to change m_value. This will cause a compiler error.

    Note that constructors cannot be marked as const. 
    This is because constructors need to be able to initialize their member variables,
    and a const constructor would not be able to do so. 
    Consequently, the language disallows const constructors.

    Rule

    Make any member function that does not modify the state of the class object const,
    so that it can be called by const objects.

    /////////////////////////////////////////////////////////////////////////////////////

    */

    

}


int main()
{
    class_cpp_oop_810();


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

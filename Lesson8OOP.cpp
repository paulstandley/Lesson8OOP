// Lesson8OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
#include <iostream>


class Something11
{
private:
    int m_value1;
    double m_value2;
    char m_value3;

public:
    Something11(int value1, double value2, char value3 = 'c')
        : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 } // directly initialize our member variables
    {
        // No need for assignment here
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }

};

void class_cpp_oop_85a()
{
    /*
    In the previous lesson, for simplicity,
    we initialized our class member data in the constructor 
    using the assignment operator.

    When the class’s constructor is executed, m_value1, m_value2,
    and m_value3 are created.
    Then the body of the constructor is run,
    where the member data variables are assigned values. 
    This is similar to the flow of the following code in non-object-oriented C++

     as you have learned in previous lessons, some types of data 
     (e.g. const and reference variables)
     must be initialized on the line they are declared

     Assigning values to const or reference member variables 
     in the body of the constructor is clearly not possible in some cases.

     ////////////////////////////////////////////////////////////////////////////

     Member initializer lists

    To solve this problem, C++ provides a method for initializing class 
    member variables (rather than assigning values to them after they are created)
    via a member initializer list (often called a “member initialization list”). 
    Do not confuse these with the similarly named initializer list
    that we can use to assign values to arrays.

    int value1 = 1; // copy initialization
    double value2(2.2); // direct initialization
    char value3 {'c'}; // uniform initialization

    Using an initialization list is almost identical to doing direct initialization 
    or uniform initialization.

    This is something that is best learned by example.
    Revisiting our code that does assignments in the constructor body:

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;

    public:
        Something()
        {
            // These are all assignments, not initializations
            m_value1 = 1;
            m_value2 = 2.2;
            m_value3 = 'c';
        }
    };

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;

    public:
        Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' } // Initialize our member variables
        {
        // No need for assignment here
        }

        void print()
        {
            std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
        }
    };

    int main()
    {
        Something something{};
        something.print();
        return 0;
    }

    The member initializer list is inserted after the constructor parameters.
    It begins with a colon (:), and then lists each variable to initialize 
    along with the value for that variable separated by a comma.

    Note that we no longer need to do the assignments in the constructor body,
    since the initializer list replaces that functionality. 
    Also note that the initializer list does not end in a semicolon.

    */

    Something11 something11{ 1, 2.2 };
    // value1 = 1, value2=2.2, value3 gets default value 'c'
    something11.print();

    /*
    class Something
    {
    private:
        const int m_value;
 
    public:
        Something(): m_value{ 5 } // directly initialize our const member variable
        {
        } 
    };

    This works because 
    we’re allowed to initialize const variables
    (but not assign to them!).

    Rule

    Use member initializer lists to initialize your class member variables 
    instead of assignment.

    Initializing array members with member initializer lists

    class Something
    {
    private:
        const int m_array[5];

    public:
        Something(): m_array {} // zero the member array
        {
        }
    };

    However, since C++11, 
    you can fully initialize a member array using uniform initialization:

    class Something
    {
    private:
        const int m_array[5];
    public:
        Something(): m_array { 1, 2, 3, 4, 5 } // use uniform initialization to initialize our member array
        {
        }
    };

    /////////////////////////////////////////////////////////////////////////////

    Initializing member variables that are classes

    A member initialization list can also be used to initialize 
    members that are classes.

    #include <iostream>

    class A
    {
    public:
        A(int x) { std::cout << "A " << x << '\n'; }
    };

    class B
    {
    private:
        A m_a;
    public:
        B(int y)
             : m_a{ y-1 } // call A(int) constructor to initialize member m_a
        {
            std::cout << "B " << y << '\n';
        }
    };

    int main()
    {
        B b{ 5 };
        return 0;
    }

    When variable b is constructed, 
    the B(int) constructor is called with value 5. 
    Before the body of the constructor executes,
    m_a is initialized, calling the A(int) constructor with value 4. 
    This prints “A 4”. 
    Then control returns back to the B constructor, 
    and the body of the B constructor executes,
    printing “B 5”.

    /////////////////////////////////////////////////////////////////////

    Formatting your initializer lists

    C++ gives you a lot of flexibility in how to format your initializer lists,
    and it’s really up to you how you’d like to proceed.
    But here are some recommendations:

    If the initializer list fits on the same line as the function name,
    then it’s fine to put everything on one line

    If the initializer list doesn’t fit on the same line as the function name,
    then it should go indented on the next line.

    If all of the initializers don’t fit on a single line 
    (or the initializers are non-trivial),
    then you can space them out, one per line:

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;
        float m_value4;

    public:
        Something(int value1, double value2, char value3='c', float value4=34.6f) // this line already has a lot of stuff on it
            : m_value1{ value1 }, // one per line, commas at end of each line
            m_value2{ value2 },
            m_value3{ value3 },
            m_value4{ value4 }
        {
        }
    };

    ////////////////////////////////////////////////////////////////////////////////

    Initializer list order

    Perhaps surprisingly, 
    variables in the initializer list are not initialized in the
    order that they are specified in the initializer list. 
    Instead, they are initialized in the order in which they are
    declared in the class.

    For best results, the following recommendations should be observed:

    1) Don’t initialize member variables in such a way that they are dependent
    upon other member variables being initialized first 
    (in other words, ensure your member variables will properly initialize
    even if the initialization ordering is different).

    2) Initialize variables in the initializer list in the same order in which they
    are declared in your class. 
    This isn’t strictly required so long as the prior
    recommendation has been followed, 
    but your compiler may give you a warning if you don’t 
    do so and you have all warnings turned on.

    Summary

    Member initializer lists allow us to initialize our members rather 
    than assign values to them. 
    This is the only way to initialize members that require values upon initialization,
    such as const or reference members, 
    and it can be more performant than assigning values in the body of the constructor.
    Member initializer lists work both with fundamental types and members that are 
    classes themselves.

    */
}


int main()
{
    class_cpp_oop_85a();


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

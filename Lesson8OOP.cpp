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

    ////////////////////////////////////////////////////////////

    The hidden *this pointer

    Take a look at the following line of code from the example above:

    simple.setID(2);

    Although the call to function setID() looks like it only has one argument, 
    it actually has two! When compiled, 
    the compiler converts simple.setID(2);
    into the following:

    setID(&simple, 2); 
    
    note that simple has been changed from an object prefix to a function argument!

    Note that this is now just a standard function call,
    and the object simple (which was formerly an object prefix)
    is now passed by address as an argument to the function.

    But that’s only half of the answer. 
    Since the function call now has an added argument, 
    the member function definition needs to be modified to accept (and use)
    this argument as a parameter. 

    Consequently, the following member function:

    void setID(int id) { m_id = id; }

    is converted by the compiler into:

    void setID(Simple* const this, int id) { this->m_id = id; }

    When the compiler compiles a normal member function,
    it implicitly adds a new parameter to the function named “this”. 
    The this pointer is a hidden const pointer that holds the 
    address of the object the member function was called on.

    There’s just one more detail to take care of. 
    Inside the member function, any class members (functions and variables) 
    also need to be updated so they refer to the object the member function
    was called on. 
    This is easily done by adding a “this->” prefix to each of them.
    Thus, in the body of function setID(), m_id (which is a class member variable)
    has been converted to this->m_id. Thus, 
    when “this” points to the address of simple, 
    this->m_id will resolve to simple.m_id.

    Putting it all together:

    1) When we call simple.setID(2), the compiler actually calls setID(&simple, 2).

    2) Inside setID(), the “this” pointer holds the address of object simple.

    3) Any member variables inside setID() are prefixed with “this->”.
    So when we say m_id = id, the compiler is actually executing this->m_id = id, 
    which in this case updates simple.m_id to id.

    The good news is that all of this happens automatically, 
    and it doesn’t really matter whether you remember how it works or not. 
    All you need to remember is that all normal member functions have a “this” pointer
    that refers to the object the function was called on.

    /////////////////////////////////////////////////////////////////////////////////

    “this” always points to the object being operated on

    New programmers are sometimes confused about how many “this” pointers exist. 
    Each member function has a “this” pointer parameter that is set to the address
    of the object being operated on. 
    Consider:

    Simple A(1); // this = &A inside the Simple constructor
    Simple B(2); // this = &B inside the Simple constructor
    A.setID(3); // this = &A inside member function setID
    B.setID(4); // this = &B inside member function setID

    Note that the “this” pointer alternately holds the address of object A or B
    depending on whether we’ve called a member function on object A or B.

    Because “this” is just a function parameter, 
    it doesn’t add any memory usage to your class
    (just to the member function call, since that parameter 
    needs to be passed to the function and stored in memory).

    Explicitly referencing “this”

    Most of the time, you never need to explicitly reference the “this” pointer.
    However, there are a few occasions where doing so can be useful:

    First, if you have a constructor (or member function)
    that has a parameter with the same name as a member variable, 
    you can disambiguate them by using “this”

    class Something
    {
    private:
        int data;

    public:
        Something(int data)
        {
            this->data = data;
            // this->data is the member, data is the local parameter
        }
    };

    #Note that our constructor is taking a parameter of the same name
    as a member variable.
    In this case, “data” refers to the parameter, 
    and “this->data” refers to the member variable. 
    Although this is acceptable coding practice, 
    we find using the “m_” prefix on all member variable names 
    provides a better solution by preventing duplicate names altogether!

    Some developers prefer to explicitly add this-> to all class members. 
    We recommend that you avoid doing so, 
    as it tends to make your code less readable for little benefit.
    Using the m_ prefix is a more readable way to differentiate member variables
    from non-member (local) variables.

    Recommendation: Do not add this-> to all uses of your class members.
    Only do so when you have a specific reason to.

    //////////////////////////////////////////////////////////////////////

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

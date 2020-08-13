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


class Employeeodc
{
private:
    int m_id{};
    std::string m_name{};

public:
    Employeeodc(int id = 0, const std::string& name = "") :
        m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a delegating constructor to minimize redundant code
    Employeeodc(const std::string& name) : Employeeodc{ 0, name }
    { }

    /*
    This class has 2 constructors, one of which delegates to 
    Employee(int, const std::string &). 
    In this way, the amount of redundant code is minimized 
    (we only have to write one constructor body instead of two).

    A few additional notes about delegating constructors. 
    First, a constructor that delegates to another constructor 
    is not allowed to do any member initialization itself.
    So your constructors can delegate or initialize, but not both.

    Second, it’s possible for one constructor to delegate to another constructor,
    which delegates back to the first constructor. 
    This forms an infinite loop, and will cause your program to run out of
    stack space and crash. 
    You can avoid this by ensuring all of your constructors resolve 
    to a non-delegating constructor.
    */
};

void class_cpp_oop_86()
{
    /*
    Overlapping and delegating constructors

    Constructors with overlapping functionality

    When you instantiate a new object,
    the object’s constructor is called implicitly. 
    It’s not uncommon to have a class with multiple constructors 
    that have overlapping functionality.

    This class has two constructors: a default constructor, 
    and a constructor that takes an integer. 
    Because the “code to do A” portion of the constructor is required
    by both constructors, the code is duplicated in each constructor.

    As you’ve (hopefully) learned by now, 
    having duplicate code is something to be avoided as much as possible. 
  
    If you try to have one constructor call another constructor,
    it will compile and maybe cause a warning, 
    but it will not work as you expect, 
    and you will likely spend a long time trying to figure out why,
    even with a debugger. 
    What’s happening is that Foo();
    instantiates a new Foo object, 
    which is immediately discarded, 
    because it’s not stored in a variable.

    Delegating constructors

    Constructors are allowed to call other constructors.
    This process is called delegating constructors (or constructor chaining).

    To have one constructor call another,
    simply call the constructor in the member initializer list. 
    This is one case where calling another constructor directly is acceptable.

    class Foo
    {
    private:

    public:
        Foo()
        {
            // code to do A
        }

        Foo(int value): Foo{} // use Foo() default constructor to do A
        {
            // code to do B
        }

    };

    This works exactly as you’d expect. 
    Make sure you’re calling the constructor from the member initializer list,
    not in the body of the constructor.

    Best practice

    If you have multiple constructors that have the same functionality, 
    use delegating constructors to avoid duplicate code.

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

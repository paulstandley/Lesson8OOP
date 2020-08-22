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
#include "Vector3d.h" // for creating Vector3d object
#include "Point3d.h" // for creating Point3d object
#include <chrono> // for std::chrono functions
#include <algorithm> // for std::sort
#include <cmath>


class Point2dq
{
private:
    double m_x{};
    double m_y{};
public:
    Point2dq(double x = 0, double y = 0) : m_x{ 0.0 }, m_y{ 0.0 } { m_x = x; m_y = y; }

    void printq()
    {
        std::cout << "Point2dq(" << m_x << ", " << m_y << ")" << std::endl;
    }
};

class Point2dq1
{
private:
    double m_x{};
    double m_y{};
public:
    Point2dq1(double x = 0, double y = 0) : m_x{ 0.0 }, m_y{ 0.0 } { m_x = x; m_y = y; }

    void printq1()
    {
        std::cout << "Point2dq(" << m_x << ", " << m_y << ")" << std::endl;
    }

    int distanceTo(const Point2dq1 &point) const
    {
        return std::sqrt
        ((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y));
    }
};

class Point2dq2
{
private:
    double m_x{};
    double m_y{};
public:
    Point2dq2(double x = 0, double y = 0) : m_x{ 0.0 }, m_y{ 0.0 } { m_x = x; m_y = y; }

    void printq2()
    {
        std::cout << "Point2dq(" << m_x << ", " << m_y << ")" << std::endl;
    }

    friend double distanceFrom2(const Point2dq2& point, const Point2dq2& point2);
};

double distanceFrom2(const Point2dq2& point, const Point2dq2 &point2)
{
    return std::sqrt
    ((point2.m_x - point.m_x) * (point2.m_x - point.m_x) 
        + (point2.m_y - point.m_y) * (point2.m_y - point.m_y));
}

void chapter_8_comprehensive_quiz()
{
    /*Quick Summary

    Classes allow you to create your own data types that bundle both data and functions
    that work on that data. 
    Data and functions inside the class are called members. 
    Members of the class are selected by using the . operator 
    (or -> if you’re accessing the member through a pointer).

    Access specifiers allow you to specify who can access the members of a class. 
    Public members can be accessed directly by anybody.
    Private members can only be accessed by other members of the class. 
    We’ll cover protected members later, when we get to inheritance.
    By default, all members of a class are private and all members
    of a struct are public.

    Encapsulation is the process of making all of your member data private,
    so it can not be accessed directly.
    This helps protect your class from misuse.

    Constructors are a special type of member function that allow you to
    initialize objects of your class. 
    A constructor that takes no parameters (or has all default parameters)
    is called a default constructor. 
    The default constructor is used if no initialization values are provided
    by the user. 
    You should always provide at least one constructor for your classes.

    Member initializer lists allows you to initialize your member variables 
    from within a constructor (rather than assigning the member variables values).

    In C++11, non-static member initialization allows you to directly 
    specify default values for member variables when they are declared.

    Prior to C++11, constructors should not call other constructors 
    (it will compile, but will not work as you expect).
    In C++11, constructors are allowed to call other constructors 
    (called delegating constructors, or constructor chaining).

    Destructors are another type of special member function that allow your class
    to clean up after itself.
    Any kind of deallocation or shutdown routines should be executed from here.

    All member functions have a hidden *this pointer that points at the class 
    object being modified. 
    Most of the time you will not need to access this pointer directly.
    But you can if you need to.

    It is good programming style to put your class definitions in a 
    header file of the same name as the class, 
    and define your class functions in a .cpp file of the same name as the class.
    This also helps avoid circular dependencies.

    Member functions can (and should) be made const if they do not modify the state of
    the class. Const class objects can only call const member functions.

    Static member variables are shared among all objects of the class. 
    Although they can be accessed from a class object, 
    they can also be accessed directly via the scope resolution operator.

    Similarly, static member functions are member functions that have no 
    *this pointer. They can only access static member variables.

    Friend functions are functions that are treated like member functions of the class
    (and thus can access a class’s private data directly).
    Friend classes are classes where all members of the class are considered 
    friend functions.

    It’s possible to create anonymous class objects for the purpose of evaluation 
    in an expression, or passing or returning a value.

    You can also nest types within a class. 
    This is often used with enums related to the class, 
    but can be done with other types (including other classes) if desired.
    
    a) Write a class named Point2d. 
    Point2d should contain two member variables of type double:
    m_x, and m_y, both defaulted to 0.0. 
    Provide a constructor and a print function.

    */

    Point2dq firstq{};
    Point2dq secondq{ 3.0, 4.0 };
    firstq.printq();
    secondq.printq();

    /*b) Now add a member function named distanceTo that takes
    another Point2d as a parameter, 
    and calculates the distance between them. 
    Given two points (x1, y1) and (x2, y2),
    the distance between them can be calculated as
    std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)).
    The std::sqrt function lives in header cmath.
    
    */

    Point2dq1 firstq1{};
    Point2dq1 secondq1{ 3.0, 4.0 };
    firstq1.printq1();
    secondq1.printq1();
    std::cout << "Distance between two points: " << firstq1.distanceTo(secondq1) << '\n';

    /*c) Change function distanceTo from a member function to a non-member 
    friend function that takes two Points as parameters.
    Also rename it “distanceFrom”.
    
    */

    Point2dq2 firstq2{};
    Point2dq2 secondq2{ 3.0, 4.0 };
    firstq2.printq2();
    secondq2.printq2();
    std::cout << "Distance between two points: " << distanceFrom2(firstq2, secondq2) << '\n';


}

int main()
{
    //timing_your_code();
    chapter_8_comprehensive_quiz();


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

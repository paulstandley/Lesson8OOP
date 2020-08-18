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


class Vector3d1
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Vector3d1(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {

    }

    void print() const
    {
        std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    friend class Point3d1; // Point3d is now a friend of class Vector3d
};

class Point3d1
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d1(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {

    }

    void print() const
    {
        std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    void moveByVector1(const Vector3d1& v)
    {
        // implement this function as a friend of class Vector3d
        m_x += v.m_x;
        m_y += v.m_y;
        m_z += v.m_z;
    }
};

class Vector3d2; // first, we need to tell the compiler that a class named Vector3d exists

class Point3d2
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d2(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {

    }

    void print() const
    {
        std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    void moveByVector2(const Vector3d2& v); // so we can use Vector3d here
       // note: we can't define this function here, because Vector3d hasn't been declared yet (just forward declared)
};

class Vector3d2
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Vector3d2(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {

    }

    void print() const
    {
        std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    friend void Point3d2::moveByVector2(const Vector3d2& v); // Point3d::moveByVector() is now a friend of class Vector3d
};

// Now that Vector3d has been declared, we can define the function Point3d::moveByVector()
void Point3d2::moveByVector2(const Vector3d2& v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

void lesson813quiz()
{
    /*
    1) In geometry, a point is a position in space.
    We can define a point in 3d-space as the set of coordinates x, y, and z.
    For example, the Point(2.0, 1.0, 0.0) would be the point at 
    coordinate space x=2.0, y=1.0, and z=0.0.

    In physics, a vector is a quantity that has a
    magnitude (length) and a direction (but no position).
    We can define a vector in 3d-space as an x, y, and z value 
    representing the direction of the vector along the x, y, and z axis
    (the length can be derived from these). 
    For example, the Vector(2.0, 0.0, 0.0)
    would be a vector representing a direction along the positive x-axis (only), 
    with length 2.0.

    A Vector can be applied to a Point to move the Point to a new position. 
    This is done by adding the vector’s direction to the point’s position
    to yield a new position. 
    For example, Point(2.0, 1.0, 0.0) + Vector(2.0, 0.0, 0.0)
    would yield the point (4.0, 1.0, 0.0).

    Points and Vectors are often used in computer graphics 
    (the point to represent vertices of shape, 
    and vectors represent movement of the shape).

    */

    //1a) Make Point3d a friend class of Vector3d, 
    //and implement function Point3d::moveByVector()

    Point3d1 p1{ 1.0, 2.0, 3.0 };
    Vector3d1 v1{ 2.0, 2.0, -3.0 };

    p1.print();
    p1.moveByVector1(v1);
    p1.print();

    //1b) Instead of making class Point3d a friend of class Vector3d, 
    //make member function Point3d::moveByVector a friend of class Vector3d.

    Point3d2 p2{ 1.0, 2.0, 3.0 };
    Vector3d2 v2{ 2.0, 2.0, -3.0 };

    p2.print();
    p2.moveByVector2(v2);
    p2.print();

    //1c) Reimplement the solution to quiz question 1b using 5 separate files:
    //Point3d.h, Point3d.cpp, Vector3d.h, Vector3d.cpp, and main.cpp.

    //Thanks to reader Shiva for the suggestionand solution.
}

int main()
{
    lesson813quiz();


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

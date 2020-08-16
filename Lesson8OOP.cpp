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


class Accumulator
{
private:
    int m_value;
public:
    Accumulator() { m_value = 0; }
    void add(int value) { m_value += value; }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator& accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}

class Humidity;

class Temperature
{
private:
    int m_temp;
public:
    Temperature(int temp = 0) { m_temp = temp; }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity
{
private:
    int m_humidity;
public:
    Humidity(int humidity = 0) { m_humidity = humidity; }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

void printWeather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
        " and the humidity is " << humidity.m_humidity << '\n';
}


void class_cpp_oop_813()
{//Friend functions and classes
    /*Friend functions

    A friend function is a function that can access the private members
    of a class as though it were a member of that class.
    In all other regards, the friend function is just like a normal function. 
    A friend function may be either a normal function,
    or a member function of another class. 
    To declare a friend function, 
    simply use the friend keyword in front of the prototype of the function
    you wish to be a friend of the class.
    It does not matter whether you declare the friend function
    in the private or public section of the class.
    
    */

    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0

    /*Note that we have to pass an Accumulator object to reset(). 
    This is because reset() is not a member function.
    It does not have a *this pointer, 
    nor does it have an Accumulator object to work with,
    unless given one.
    
    */

    Humidity hum(10);
    Temperature temp(12);
    printWeather(temp, hum);

    /*There are two things worth noting about this example. 
    First, because PrintWeather is a friend of both classes,
    it can access the private data from objects of both classes.
    Second, note the following line at the top of the example
    
    This is a class prototype that tells the compiler that we are going
    to define a class called Humidity in the future. 
    Without this line,
    the compiler would tell us it doesn’t know what a Humidity is
    when parsing the prototype for PrintWeather() inside the Temperature class. 
    
    Class prototypes serve the same role as function prototypes --
    they tell the compiler what something looks like so it can be used
    now and defined later. 
    However, unlike functions, classes have no return types or parameters, 
    so class prototypes are always simply class ClassName, 
    where ClassName is the name of the class.

    /////////////////////////////////////////////////////////////////////////////

    Friend classes

    It is also possible to make an entire class a friend of another class. 
    This gives all of the members of the friend class access to the private members 
    of the other class

    */

}

int main()
{
    class_cpp_oop_813();


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

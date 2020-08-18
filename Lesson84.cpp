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


class Storagecf
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storagecf(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display class a friend of Storage
    friend class Displaycf;
};

class Displaycf
{
private:
    bool m_displayIntFirst;

public:
    Displaycf(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(const Storagecf& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
    }
};

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

class Storagemf; // forward declaration for class Storage

class Displaymf
{
private:
    bool m_displayIntFirst;

public:
    Displaymf(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItemmf(const Storagemf& storage); // forward declaration above needed for this declaration line
};

class Storagemf // full definition of Storage class
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storagemf(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display::displayItem member function a friend of the Storage class (requires seeing the full declaration of class Display, as above)
    friend void Displaymf::displayItemmf(const Storagemf& storage);
};

// Now we can define Display::displayItem, which needs to have seen the full definition of class Storage
void Displaymf::displayItemmf(const Storagemf& storage)
{
    if (m_displayIntFirst)
        std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
    else // display double first
        std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
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

    Storagecf storagecf(5, 6.7);
    Displaycf displaycf(false);
    displaycf.displayItem(storagecf);

    /*Because the Display class is a friend of Storage,
    any of Display’s members that use a Storage class object can access
    the private members of Storage directly.

    A few additional notes on friend classes.
    First, even though Display is a friend of Storage,
    Display has no direct access to the *this pointer of Storage objects.

    Second, just because Display is a friend of Storage,
    that does not mean Storage is also a friend of Display.
    If you want two classes to be friends of each other,
    both must declare the other as a friend.

    Finally, if class A is a friend of B, and B is a friend of C,
    that does not mean A is a friend of C.

    Be careful when using friend functions and classes,
    because it allows the friend function or class to violate encapsulation.
    If the details of the class change,
    the details of the friend will also be forced to change.
    Consequently, limit your use of friend functions and classes to a minimum.

    /////////////////////////////////////////////////////////////////////////

    Friend member functions

    Instead of making an entire class a friend,
    you can make a single member function a friend.
    This is done similarly to making a normal function a friend,
    except using the name of the member function with the
    className:: prefix included (e.g. Display::displayItem).

    However, in actuality, this can be a little trickier than expected.
    Let’s convert the previous example to make Display::displayItem
    a friend member function.

     In order to make a member function a friend,
     the compiler has to have seen the full definition for the class
     of the friend member function (not just a forward declaration).
     Since class Storage hasn’t seen the full definition for class Display yet,
     the compiler will error at the point where we try to make
     the member function a friend.

    */

    Storagemf storagemf(5, 6.7);
    Displaymf displaymf(false);
    displaymf.displayItemmf(storagemf);

    /*Now everything will compile properly:
    the forward declaration of class Storage is enough to satisfy the declaration
    of Display::displayItem() inside the Display class,
    the full definition of Display satisfies declaring Display::displayItem()
    as a friend of Storage,
    and the full definition of class Storage is enough to satisfy
    the definition of member function Display::displayItem().
    If that’s a bit confusing, see the comments in the program above.

    If this seems like a pain -- it is. Fortunately,
    this dance is only necessary because we’re trying to do everything
    in a single file.
    A better solution is to put each class definition in a separate header file,
    with the member function definitions in corresponding .cpp files.
    That way, all of the class definitions would have been visible immediately
    in the .cpp files, and no rearranging of classes or functions is necessary!

    ///////////////////////////////////////////////////////////////////////////

    Summary

    A friend function or class is a function or class that can access the
    private members of another class as though it were a member of that class.
    This allows the friend or class to work intimately with the other class,
    without making the other class expose its private members
    (e.g. via access functions).

    Friending is uncommonly used when two or more classes need to work together
    in an intimate way,
    or much more commonly, when defining overloading operators

    Note that making a specific member function a friend requires the full definition
    for the class of the member function to have been seen first.

    */
}



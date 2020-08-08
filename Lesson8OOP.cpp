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



class DateGetSet
{
private:
    int m_month;
    int m_day;
    int m_year;

public:
    int getMonth() { return m_month; } // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    int getDay() { return m_day; } // getter for day
    void setDay(int day) { m_day = day; } // setter for day

    int getYear() { return m_year; } // getter for year
    void setYear(int year) { m_year = year; } // setter for year
    /*
    The Date class above is essentially an encapsulated data struct
    with a trivial implementation, 
    and a user of the class might reasonably expect to be able to get or set the day,
    month, or year.

    The MyString class above isn’t used just to transport data --
    it has more complex functionality and has an invariant that needs to be maintained.
    No setter was provided for variable m_length because we don’t want the user
    to be able to set the length directly 
    (length should only be set whenever the string is changed). 
    In this class, it does make sense to allow the user to get the
    string length directly, so a getter for the length was provided.

    Getters should provide “read-only” access to data. 
    Therefore, the best practice is that they should 
    return by value or const reference (not by non-const reference).
    A getter that returns a non-const reference would 
    allow the caller to modify the actual object being referenced,
    which violates the read-only nature of the getter (and violates encapsulation).

    Best practice: Getters should return by value or const reference

    Access functions concerns

    There is a fair bit of discussion around in which cases access functions
    should be used or avoided. 
    Although they don’t violate encapsulation, 
    some developers would argue that use of access functions violates
    good OOP class design (a topic that could easily fill an entire book).

    For now, we’ll recommend a pragmatic approach. 
    As you create your classes, consider the following:

    If nobody outside your class needs to access a member,
    don’t provide access functions for that member.

    If someone outside your class needs to access a member, 
    think about whether you can expose a behavior or action instead
    (e.g. rather than a setAlive(bool) setter, implement a kill() function instead).

    If you can’t, consider whether you can provide only a getter.

    Summary

    As you can see, encapsulation provides a lot of benefits
    for just a little bit of extra effort.
    The primary benefit is that encapsulation allows us to use a
    class without having to know how it was implemented.
    This makes it a lot easier to use classes we’re not familiar with.

    */
};

void class_cpp_oop_84()
{
    /*Encapsulation

    In object-oriented programming, Encapsulation (also called information hiding) 
    is the process of keeping the details about how an object is implemented hidden
    away from users of the object. 
    Instead, users of the object access the object through a public interface. 
    In this way, users are able to use the object without having to understand
    how it is implemented.

    Benefit: encapsulated classes are easier to use and reduce the complexity of your programs
    
    All of the classes in the C++ standard library are encapsulated. 
    Imagine how much more complicated C++ would be if you had to understand 
    how std::string, std::vector, or std::cout were implemented in order to use them!

    Benefit: encapsulated classes help protect your data and prevent misuse

    Global variables are dangerous because you don’t have strict control 
    over who has access to the global variable, or how they use it. 
    Classes with public members suffer from the same problem, just on a smaller scale.

    class MyString
    {
        char *m_string; // we'll dynamically allocate our string here
        int m_length; // we need to keep track of the string length
    };

    These two variables have an intrinsic connection:
    m_length should always equal the length of the string held by m_string 
    (this connection is called an invariant).
    If m_length were public, anybody could change the length of the string 
    without changing m_string (or vice-versa). 
    This would put the class into an inconsistent state,
    which could cause all sorts of bizarre problems. 
    By making both m_length and m_string private, 
    users are forced to use whatever public member functions
    are available to work with the class
    (and those member functions can ensure that m_length and m_string are always
    set appropriately).

    We can also help protect the user from mistakes in using our class. 
    Consider a class with a public array member variable:

    If users can access the array directly, 
    they could subscript the array with an invalid index,
    producing unexpected results:

    However, if we make the array private,
    we can force the user to use a function that validates 
    that the index is valid first:

    In this way, we’ve protected the integrity of our program. As a side note, 
    the at() functions of std::array and std::vector do something very similar!

    Benefit: encapsulated classes are easier to change

    Benefit: encapsulated classes are easier to debug

    And finally, encapsulation helps you debug the program when something goes wrong. 
    Often when a program does not work correctly,
    it is because one of our member variables has an incorrect value. 
    If everyone is able to access the variable directly, 
    tracking down which piece of code modified the variable can be difficult
    (it could be any of them, and you’ll need to breakpoint them all to
    figure out which). 
    However, if everybody has to call the same public function to modify a value, 
    then you can simply breakpoint that function and watch as each caller 
    changes the value until you see where it goes wrong.

    Access functions

    Depending on the class, it can be appropriate 
    (in the context of what the class does)
    for us to be able to directly get or set the value of a private member variable.

    An access function is a short public function whose job is to retrieve or
    change the value of a private member variable.

    class MyString
    {
    private:
        char *m_string; // we'll dynamically allocate our string here
        int m_length; // we need to keep track of the string length

    public:
        int getLength() { return m_length; } // access function to get value of m_length
    };

    Access functions typically come in two flavors: getters and setters. 
    Getters (also sometimes called accessors) are functions that return
    the value of a private member variable. 
    Setters (also sometimes called mutators) 
    are functions that set the value of a private member variable.


    */
}

int main()
{
    class_cpp_oop_84();

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

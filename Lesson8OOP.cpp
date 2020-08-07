// Lesson8OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <iostream>


class DateClass1 // members are private by default
{
    int m_month; // private by default, can only be accessed by other members
    int m_day; // private by default, can only be accessed by other members
    int m_year; // private by default, can only be accessed by other members

public:
    void setDate(int month, int day, int year) // public, can be accessed by anyone
    {
        // setDate() can access the private members of the class because it is a member of the class itself
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print() // public, can be accessed by anyone
    {
        std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
    }
};

class DateClass2 // members are private by default
{
    int m_month; // private by default, can only be accessed by other members
    int m_day; // private by default, can only be accessed by other members
    int m_year; // private by default, can only be accessed by other members

public:
    void setDate(int month, int day, int year)
    {
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print()
    {
        std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
    }

    // Note the addition of this function
    void copyFrom(const DateClass2& d)
    {
        // Note that we can access the private members of d directly
        m_month = d.m_month;
        m_day = d.m_day;
        m_year = d.m_year;
    }
};

void lesson82quiz()
{
    /*
    * a) Write a simple class named Point3d. The class should contain:
    * Three private member variables of type int named m_x, m_y, and m_z;
    * A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
    * A public member function named print() 
    that prints the Point in the following format: <m_x, m_y, m_z>
    
    */
}

void class_cpp_oop_83()
{// Public vs private access specifiers

    /*
    struct DateStruct // members are public by default
    {
        int month; // public by default, can be accessed by anyone
        int day; // public by default, can be accessed by anyone
        int year; // public by default, can be accessed by anyone
    };
 
    int main()
    {
        DateStruct date;
        date.month = 10;
        date.day = 14;
        date.year= 2020;
 
        return 0;
    }

    In this program, we declare a DateStruct and then we directly 
    access its members in order to initialize them.
    This works because all members of a struct are public members by default.
    Public members are members of a struct or class that can be accessed
    from outside of the struct or class.
    In this case, function main() is outside of the struct, 
    but it can directly access members month, day, and year, because they are public.

    On the other hand, consider the following almost-identical class

    class DateClass // members are private by default
    {
        int m_month; // private by default, can only be accessed by other members
        int m_day; // private by default, can only be accessed by other members
        int m_year; // private by default, can only be accessed by other members
    };

    int main()
    {
        DateClass date;
        date.m_month = 10; // error
        date.m_day = 14; // error
        date.m_year = 2020; // error

        return 0;
    }

    If you were to compile this program, you would receive errors. 
    This is because by default, all members of a class are private. 
    Private members are members of a class that can only be accessed
    by other members of the class.
    Because main() is not a member of DateClass,
    it does not have access to date’s private members.

    Access specifiers

    Although class members are private by default, 
    we can make them public by using the public keyword:

    class DateClass
    {
    public: // note use of public keyword here, and the colon
        int m_month; // public, can be accessed by anyone
        int m_day; // public, can be accessed by anyone
        int m_year; // public, can be accessed by anyone
    };

    int main()
    {
        DateClass date;
        date.m_month = 10; // okay because m_month is public
        date.m_day = 14;  // okay because m_day is public
        date.m_year = 2020;  // okay because m_year is public

        return 0;
    }

    Because DateClass’s members are now public, 
    they can be accessed directly by main().

    The public keyword, along with the following colon, is called an access specifier.
    Access specifiers determine who has access to the members that follow the specifier. 
    Each of the members “acquires” the access level of the previous access specifier 
    (or, if none is provided, the default access specifier).

    C++ provides 3 different access specifier keywords: public, private, and protected.
    Public and private are used to make the members that follow them 
    public members or private members respectively. 
    The third access specifier, protected, works much like private does. 
    We will discuss the difference between the private and protected 
    access specifier when we cover inheritance.

    Mixing access specifiers

    A class can (and almost always does) 
    use multiple access specifiers to set the access levels of each of its members.
    There is no limit to the number of access specifiers you can use in a class.

    In general, member variables are usually made private,
    and member functions are usually made public.
    We’ll take a closer look at why in the next lesson.

    Rule

    Make member variables private, and member functions public, 
    unless you have a good reason not to.

    Let’s take a look at an example of a class that uses both
    private and public access:

    */

    DateClass1 date1;
    date1.setDate(11, 2, 1972); // okay, because setDate() is public
    date1.print(); // okay, because print() is public

    /*Note that although we can’t access date’s members variables m_month, m_day, 
    and m_year directly from main (because they are private), 
    we are able to access them indirectly through public member functions setDate() 
    and print()!

    The group of public members of a class are often referred to as a public interface.
    Because only public members can be accessed from outside of the class, 
    the public interface defines how programs using the class will interact with the class.
    Note that main() is restricted to setting the date and printing the date. 
    The class protects the member variables from being accessed or edited directly.

    Some programmers prefer to list private members first, 
    because the public members typically use the private ones, 
    so it makes sense to define the private ones first.
    However, a good counterargument is that users of the 
    class don’t care about the private members,
    so the public ones should come first. 
    Either way is fine.
    
    */

    DateClass2 date2;
    date2.setDate(12, 25, 0001); // okay, because setDate() is public

    DateClass2 copy2;
    copy2.copyFrom(date2); // okay, because copyFrom() is public
    copy2.print();

    /*One nuance of C++ that is often missed or misunderstood is that access
    control works on a per-class basis, 
    not a per-object basis. 
    This means that when a function has access to the private members of a class,
    it can access the private members of any object of that class type that it can see.

    In the above example, copyFrom() is a member of DateClass, 
    which gives it access to the private members of DateClass. 
    This means copyFrom() can not only directly access the private members
    of the implicit object it is operating on (copy),
    it also means it has direct access to the private members of DateClass
    parameter d! If parameter d were some other type, this would not be the case.

    This can be particularly useful when we need to copy members from one object
    of a class to another object of the same class.
    We’ll also see this topic show up again when we talk about
    overloading operator << to print members of a class in the next chapter.

    Structs vs classes revisited

    Now that we’ve talked about access specifiers, 
    we can talk about the actual differences between a class and a struct in C++.
    A class defaults its members to private. 
    A struct defaults its members to public.

    That’s it!

    (Okay, to be pedantic, 
    there’s one more minor difference -- 
    structs inherit from other classes publicly and classes inherit privately.
    We’ll cover what this means in a future chapter,
    but this particular point is practically irrelevant since you should never 
    rely on the defaults anyway).
    
    A public member is a member of a class that can be accessed by anyone.

    A private member is a member of a class that can only be accessed by other members of the class.

    An access specifier determines who has access to the members that follow the specifier.

    public, private, and protected

    */
}

int main()
{
    class_cpp_oop_83();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

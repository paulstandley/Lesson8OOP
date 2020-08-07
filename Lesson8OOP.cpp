// Lesson8OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <iostream>
#include <vector>


class DateClass
{
public:
    int m_year{};
    int m_month{};
    int m_day{};

    void print() // defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

class Employee
{
public:
    std::string m_name{};
    int m_id{};
    double m_wage{};

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_name <<
            "  Id: " << m_id <<
            "  Wage: $" << m_wage << '\n';
    }
};

class Calculator
{
public:
    using number_t = int; // this is a nested type alias

    std::vector<number_t> m_resultHistory{};

    number_t add(number_t a, number_t b)
    {
        auto result{ a + b };

        m_resultHistory.push_back(result);

        return result;
    }
};

void class_cpp_oop()
{
    /*Classes

    In the world of object-oriented programming,
    we often want our types to not only hold data, 
    but provide functions that work with the data as well.
    In C++, this is typically done via the class keyword.
    The class keyword defines a new user-defined type called a class.
    
    In C++, classes and structs are essentially the same.
    In fact, the following struct and class are effectively identical

    struct DateStruct
    {
        int year{};
        int month{};
        int day{};
    };
 
    class DateClass
    {
    public:
        int m_year{};
        int m_month{};
        int m_day{};
    }

    Note that the only significant difference is the public: keyword in the class.
    We will discuss the function of this keyword in the next lesson.

    Just like a struct declaration, a class declaration does not allocate any memory.
    It only defines what the class looks like.

    Warning

    Just like with structs,
    one of the easiest mistakes to make in C++ is to forget the semicolon
    at the end of a class declaration.
    This will cause a compiler error on the next line of code.
    Modern compilers like Visual Studio 2010 will give you an indication
    that you may have forgotten a semicolon,
    but older or less sophisticated compilers may not, 
    which can make the actual error hard to find.

    Class (and struct) definitions are like a blueprint 
    -- they describe what the resulting object will look like, 
    but they do not actually create the object. 
    To actually create an object of the class, 
    a variable of that class type must be defined:

    DateClass today { 2020, 10, 14 }; // declare a variable of class DateClass

    Member Functions

    In addition to holding data, classes (and structs) can also contain functions!
    Functions defined inside of a class are called member functions 
    (or sometimes methods). 
    Member functions can be defined inside or outside of the class definition. 
    We’ll define them inside the class for now (for simplicity), 
    and show how to define them outside the class later.

    Here is our Date class with a member function to print the date:

    */

    DateClass today{ 2020, 10, 14 };

    today.m_day = 16; 
    // use member selection operator to select a member variable of the class
    today.print(); 
    // use member selection operator to call a member function of the class

    /*Note how similar this program is to the struct version we wrote above.

    However, there are a few differences. 
    In the DateStruct version of print() from the example above, 
    we needed to pass the struct itself to the print() function as the first parameter.
    Otherwise, print() wouldn’t know what DateStruct we wanted to use.
    We then had to reference this parameter inside the function explicitly.
    
    */

    // Declare two employees
    Employee alex{ "Alex", 1, 25.00 };
    Employee joe{ "Joe", 2, 22.25 };

    // Print out the employee information
    alex.print();
    joe.print();

    /*With normal non-member functions, 
    a function can’t call a function that’s defined “below” it 
    (without a forward declaration):
    
    void x()
    {
    // You can't call y() from here unless the compiler has already seen a forward declaration for y()
    }

    void y()
    {
    }

    With member functions, this limitation doesn’t apply:

    class foo
    {
    public:
        void x() { y(); } // okay to call y() here, even though y() isn't defined until later in this class
        void y() { };
    };

    Member types

    In addition to member variables and member functions, 
    classes can have member types or nested types (including type aliases). 
    In the following example,
    we’re creating a calculator where we can swiftly change the type of number
    it’s using if we ever need to

    */

    Calculator calculator{};

    std::cout << calculator.add(3, 4) << '\n'; // 7
    std::cout << calculator.add(99, 24) << '\n'; // 123

    for (Calculator::number_t result : calculator.m_resultHistory)
    {
        std::cout << result << '\n';
    }

    /*In such a context, the class name effectively acts like a namespace
    for the nested type. From inside the class, we only need reference number_t.
    From outside the class, we can access the type via Calculator::number_t.

    When we decide that an int no longer fulfills our needs and we want to use a double,
    we only need to update the type alias, 
    rather than having to replace every occurrence of int with double.

    Type alias members make code easier to maintain and can reduce typing.
    Template classes, which we’ll cover later, often make use of type alias members.
    You’ve already seen this as std::vector::size_type,
    where size_type is an alias for an unsigned integer.

    Nested types cannot be forward declared. 
    Generally, nested types should only be used when the nested type is used exclusively
    within that class. 
    Note that since classes are types, 
    it’s possible to nest classes inside other classes -- 
    this is uncommon and is typically only done by advanced programmers.
    
    */

}

int main()
{
    class_cpp_oop();

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

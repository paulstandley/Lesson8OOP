// 1
#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <iostream>

class DateClass
{
public:
    int m_year{};
    int m_month{};
    int m_day{};

    void print() // defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
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

class IntPair
{//(h/t to reader Pashka2107 for this quiz idea)
public:
    int m_first{};
    int m_second{};

    void set(int first, int second)
    {
        m_first = first;
        m_second = second;
    }
    void print()
    {
        std::cout << "Pair(" << m_first << ", " << m_second << ")\n";
    }
};

void class_cpp_oop_82()
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

    Rule

    Name your classes starting with a capital letter.

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

    A note about structs in C++

    In C, structs can only hold data, and do not have associated member functions.
    In C++, after designing classes (using the class keyword),
    Bjarne Stroustrup spent some amount of time considering whether structs
    (which were inherited from C) should be granted the ability to have member functions.
    Upon consideration, he determined that they should,
    in part to have a unified ruleset for both.
    So although we wrote the above programs using the class keyword,
    we could have used the struct keyword instead.

    Many developers (including myself) feel this was the incorrect decision to be made,
    as it can lead to dangerous assumptions.
    For example, it’s fair to assume a class will clean up after itself
    (e.g. a class that allocates memory will deallocate it before being destroyed),
    but it’s not safe to assume a struct will.
    Consequently, we recommend using the struct keyword for data-only structures,
    and the class keyword for defining objects that require both data and functions
    to be bundled together.

    Rule: Use the struct keyword for data-only structures.
    Use the class keyword for objects that have both data and functions.

    You have already been using classes without knowing it

    It turns out that the C++ standard library is full of classes
    that have been created for your benefit.
    std::string, std::vector, and std::array are all class types!
    So when you create an object of any of these types,
    you’re instantiating a class object.
    And when you call invoke a function using these objects,
    you’re calling a member function.

    */

    std::string s{ "Hello, world!" }; // instantiate a string class object
    std::array<int, 3> a{ 1, 2, 3 }; // instantiate an array class object
    std::vector<double> v{ 1.1, 2.2, 3.3 }; // instantiate a vector class object
    std::cout << "length: " << s.length() << ' ' << a[1] << ' ' << v[1] << '\n'; // call a member function

    /*Conclusion

    The class keyword lets us create a custom type in C++
    that can contain both member variables and member functions.
    Classes form the basis for Object-oriented programming,
    and we’ll spend the rest of this chapter and many of the future chapters
    exploring all they have to offer!

    Question #1

    a) Create a class called IntPair that holds two integers.
    This class should have two member variables to hold the integers.
    You should also create two member functions: one named “set” that will let
    you assign values to the integers,
    and one named “print” that will print the values of the variables.

    */

    IntPair p1;
    p1.set(1, 1);

    IntPair p2{ 2, 2 };

    p1.print();
    p2.print();
}



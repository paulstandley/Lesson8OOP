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





class Datemfocd
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Datemfocd(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay() { return m_day; }
};

// Date constructor
Datemfocd::Datemfocd(int year, int month, int day)
{
    SetDate(year, month, day);
}

// Date member function
void Datemfocd::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

class Calcmfocd
{
private:
    int m_value = 0;

public:
    Calcmfocd(int value = 0);

    Calcmfocd& add(int value);
    Calcmfocd& sub(int value);
    Calcmfocd& mult(int value);

    int getValue() { return m_value; }
};

Calcmfocd::Calcmfocd(int value) : m_value(value)
{
}

Calcmfocd& Calcmfocd::add(int value)
{
    m_value += value;
    return *this;
}

Calcmfocd& Calcmfocd::sub(int value)
{
    m_value -= value;
    return *this;
}

Calcmfocd& Calcmfocd::mult(int value)
{
    m_value *= value;
    return *this;
}

void class_cpp_oop_89()
{
    /*Defining member functions outside the class definition

    All of the classes that we have written so far have been
    simple enough that we have been able to implement the member
    functions directly inside the class definition itself.

    However, as classes get longer and more complicated,
    having all the member function definitions inside the class
    can make the class harder to manage and work with.

    Using an already-written class only requires understanding
    its public interface (the public member functions),
    not how the class works underneath the hood.
    The member function implementation details just get in the way.

    Fortunately,
    C++ provides a way to separate the “declaration” portion of the class
    from the “implementation” portion.
    This is done by defining the class member functions
    outside of the class definition.

    To do so, simply define the member functions
    of the class as if they were normal functions,
    but prefix the class name to the function using the
    scope resolution operator (::) (same as for a namespace).

    Here is our Date class with the Date constructor and setDate()
    function defined outside of the class definition.
    Note that the prototypes for these functions still exist inside
    the class definition,
    but the actual implementation has been moved outside:

    Putting class definitions in a header file

    In the lesson on header files,
    you learned that you can put function declarations
    inside header files in order to use those functions
    in multiple files or even multiple projects.

    Classes are no different.
    Class definitions can be put in header files in order to facilitate
    reuse in multiple files or multiple projects.
    Traditionally, the class definition is put in a header file
    of the same name as the class,
    and the member functions defined outside of the class
    are put in a .cpp file of the same name as the class.

    //////////////////////////////////////////////////////////////////////////////

    Now any other header or code file that wants to use the Date class
    can simply #include "Date.h".
    Note that Date.cpp also needs to be compiled into any project
    that uses Date.h so the linker knows how Date is implemented.

    Doesn’t defining a class in a header file violate the one-definition rule?

    It shouldn’t. If your header file has proper header guards,
    it shouldn’t be possible to include the class definition more than
    once into the same file.

    Types (which include classes),
    are exempt from the part of the one-definition rule
    that says you can only have one definition per program.
    Therefore, there isn’t an issue #including class definitions into multiple
    code files (if there was, classes wouldn’t be of much use).

    //////////////////////////////////////////////////////////////////////////////

    Doesn’t defining member functions in the header violate the one-definition rule?

    It depends.
    Member functions defined inside the class definition
    are considered implicitly inline.
    Inline functions are exempt from the one definition per program
    part of the one-definition rule.
    This means there is no problem defining trivial member functions
    (such as access functions) inside the class definition itself.

    Member functions defined outside the class definition
    are treated like normal functions,
    and are subject to the one definition per program part of the one-definition rule.
    Therefore,
    those functions should be defined in a code file,
    not inside the header.
    The one exception for this is for template functions,
    which we’ll cover in a future chapter.

    ////////////////////////////////////////////////////////////////////////////////

    So what should I define in the header file vs the cpp file,
    and what inside the class definition vs outside?

    You might be tempted to put all of your member function definitions
    into the header file, inside the class.
    While this will compile, there are a couple of downsides to doing so.
    First, as mentioned above, this clutters up your class definition.
    Second, if you change anything about the code in the header,
    then you’ll need to recompile every file that includes that header.
    This can have a ripple effect,
    where one minor change causes the entire program to need to recompile
    (which can be slow).
    If you change the code in a .cpp file,
    only that .cpp file needs to be recompiled!

    Therefore, we recommend the following:

    For classes used in only one file that aren’t generally reusable,
    define them directly in the single .cpp file they’re used in.

    For classes used in multiple files,
    or intended for general reuse,
    define them in a .h file that has the same name as the class.

    Trivial member functions
    (trivial constructors or destructors, access functions, etc…)
    can be defined inside the class.

    Non-trivial member functions should be defined
    in a .cpp file that has the same name as the class.

    In future lessons, most of our classes will be defined in the .cpp file,
    with all the functions implemented directly in the class definition.
    This is just for convenience and to keep the examples short.
    In real projects,
    it is much more common for classes to be put in their own code and header files,
    and you should get used to doing so.

    Default parameters

    Default parameters for member functions should be declared in the class
    definition (in the header file),
    where they can be seen by whomever #includes the header.

    Libraries

    Separating the class definition and class implementation is very
    common for libraries that you can use to extend your program.
    Throughout your programs,
    you’ve #included headers that belong to the standard library,
    such as iostream, string, vector, array, and other.

    Notice that you haven’t needed to add iostream.cpp,
    string.cpp, vector.cpp, or array.cpp into your projects.
    Your program needs the declarations from the header files
    in order for the compiler to validate you’re writing programs
    that are syntactically correct.

    However, the implementations for the classes that belong
    to the C++ standard library are contained in a precompiled file
    that is linked in at the link stage.
    You never see the code.

    Outside of some open source software
    (where both .h and .cpp files are provided),
    most 3rd party libraries provide only header files,
    along with a precompiled library file.

    There are several reasons for this: 1)
    It’s faster to link a precompiled library than to recompile
    it every time you need it, 2)
    a single copy of a precompiled library can be shared by many applications,
    whereas compiled code gets compiled into every executable that uses it
    (inflating file sizes), and 3)
    intellectual property reasons
    (you don’t want people stealing your code).

    Having your own files separated into declaration
    (header) and implementation (code file) is not only good form,
    it also makes creating your own custom libraries easier.
    Creating your own libraries is beyond the scope of these tutorials,
    but separating your declaration and implementation is a prerequisite to doing so.

    */
}

/*
class DateConst
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    DateConst(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    // setDate() cannot be const, modifies member variables
    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    // The following getters can all be made const
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

// note: We're passing date by const reference here to avoid making a copy of date
void printDateh(const Date& date)
{
    std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

// note: We're passing date by const reference here to avoid making a copy of dateconst
void printDatef(const DateConst& date)
{
    std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

class Somethingocncf
{
private:
    std::string m_value;

public:
    Somethingocncf(const std::string& value = "") : m_value{ value } {}

    const std::string& getValue() const { return m_value; } // getValue() for const objects
    std::string& getValue() { return m_value; } // getValue() for non-const objects
};

*/

void class_cpp_oop_810()
{
    /*Const class objects and member functions

    Const, constexpr, and symbolic constants, you learned that fundamental data types
    (int, double, char, etc…) can be made const via the const keyword,
    and that all const variables must be initialized at time of creation.

    In the case of const fundamental data types,
    initialization can be done through copy, direct,
    or uniform initialization:

    */

    const int value11 = 5; // copy initialization
    const int value21(7); // direct initialization
    const int value31{ 9 }; // uniform initialization (C++11)

    /*Const classes

    Similarly,
    instantiated class objects can also be made const by using the const keyword.
    Initialization is done via class constructors:

    */


    /*
    //const Date date11; 
    // initialize using default constructor
    const Date date21(2020, 10, 16);
    // initialize using parameterized constructor
    const Date date31{ 2020, 10, 16 };
    // initialize using parameterized constructor (C++11)
    */

    /*Once a const class object has been initialized via constructor,
    any attempt to modify the member variables of the object is disallowed,
    as it would violate the const-ness of the object.
    This includes both changing member variables directly (if they are public),
    or calling member functions that set the value of member variables.
    Consider the following class:

    class Something
    {
    public:
        int m_value;

        Something(): m_value{0} { }

        void setValue(int value) { m_value = value; }
        int getValue() { return m_value ; }
    };

    int main()
    {
        const Something something{}; // calls default constructor

        something.m_value = 5; // compiler error: violates const
        something.setValue(5); // compiler error: violates const

        return 0;
    }

    Both of the above lines involving variable something are illegal
    because they violate the constness of something by either attempting
    to change a member variable directly,
    or by calling a member function that attempts to change a member variable.

    Just like with normal variables,
    you’ll generally want to make your class objects const
    when you need to ensure they aren’t modified after creation.

    ////////////////////////////////////////////////////////////////////////////

    Const member functions

    Now, consider the following line of code:

    std::cout << something.getValue();

    Perhaps surprisingly, this will also cause a compile error,
    even though getValue() doesn’t do anything to change a member variable!
    It turns out that const class objects can only explicitly call
    const member functions,
    and getValue() has not been marked as a const member function.

    A const member function is a member function that guarantees
    it will not modify the object or call any non-const member functions
    (as they may modify the object).

    To make getValue() a const member function,
    we simply append the const keyword to the function prototype,
    after the parameter list, but before the function body:

    int getValue() const { return m_value; }
    // note addition of const keyword after parameter list, but before function body

    Now getValue() has been made a const member function,
    which means we can call it on any const objects.

    For member functions defined outside of the class definition,
    the const keyword must be used on both the function prototype
    in the class definition and on the function definition:

    class Something
    {
    public:
        int m_value;
        Something(): m_value{0} { }
        void resetValue() { m_value = 0; }
        void setValue(int value) { m_value = value; }

        int getValue() const; // note addition of const keyword here
    };

    int Something::getValue() const // and here
    {
        return m_value;
    }

    Futhermore,
    any const member function that attempts to change a member variable
    or call a non-const member function will cause a compiler error to occur.
    For example:

    class Something
    {
    public:
        int m_value ;

        void resetValue() const { m_value = 0; } // compile error, const functions can't change member variables.
    };

    In this example, resetValue() has been marked as a const member function,
    but it attempts to change m_value. This will cause a compiler error.

    Note that constructors cannot be marked as const.
    This is because constructors need to be able to initialize their member variables,
    and a const constructor would not be able to do so.
    Consequently, the language disallows const constructors.

    Rule

    Make any member function that does not modify the state of the class object const,
    so that it can be called by const objects.

    //////////////////////////////////////////////////////////////////////////////////

    Const member functions

    Now, consider the following line of code:

    std::cout << something.getValue();

    Perhaps surprisingly,
    this will also cause a compile error, even though getValue()
    doesn’t do anything to change a member variable!
    It turns out that const class objects can only explicitly
    call const member functions,
    and getValue() has not been marked as a const member function.

    A const member function is a member function that guarantees
    it will not modify the object or call any non-const member functions
    (as they may modify the object).

    To make getValue() a const member function,
    we simply append the const keyword to the function prototype,
    after the parameter list, but before the function body:

    class Something
    {
    public:
        int m_value;
        Something(): m_value{0} { }
        void resetValue() { m_value = 0; }
        void setValue(int value) { m_value = value; }
        int getValue() const { return m_value; }
        // note addition of const keyword after parameter list, but before function body
    };

    Now getValue() has been made a const member function,
    which means we can call it on any const objects.

    For member functions defined outside of the class definition,
    the const keyword must be used on both the function
    prototype in the class definition and on the function definition:

    class Something
    {
    public:
        int m_value;

        Something(): m_value{0} { }

        void resetValue() { m_value = 0; }
        void setValue(int value) { m_value = value; }

        int getValue() const; // note addition of const keyword here
    };

    int Something::getValue() const // and here
    {
        return m_value;
    }

    Futhermore,
    any const member function that attempts to change a member variable
    or call a non-const member function will cause a compiler error to occur.
    For example:

    class Something
    {
    public:
        int m_value ;

        void resetValue() const { m_value = 0; } // compile error, const functions can't change member variables.
    };

    In this example, resetValue() has been marked as a const member function,
    but it attempts to change m_value. This will cause a compiler error.

    Note that constructors cannot be marked as const.
    This is because constructors need to be able to initialize their member variables,
    and a const constructor would not be able to do so.
    Consequently, the language disallows const constructors.

    Rule

    Make any member function that does not modify the state of the class object const,
    so that it can be called by const objects.

    /////////////////////////////////////////////////////////////////////////////////////

    Const references

    Although instantiating const class objects is one way to create const objects,
    a more common way is by passing an object to a function by const reference.

    In the lesson on passing arguments by reference,
    we covered the merits of passing class arguments by
    const reference instead of by value.

    To recap, passing a class argument by value causes a copy of the class to be made
    (which is slow) -- most of the time, we don’t need a copy,
    a reference to the original argument works just fine,
    and is more performant because it avoids the needless copy.

    We typically make the reference const in order to ensure the function
    does not inadvertently change the argument,
    and to allow the function to work with R-values (e.g. literals),
    which can be passed as const references, but not non-const references.

    ///////////////////////////////////////////////////////////////////////////////

    Overloading const and non-const function

    Finally, although it is not done very often, it is possible to overload a function
    in such a way to have a const and non-const version of the same function:

    Const references

    Although instantiating const class objects is one way to create const objects,
    a more common way is by passing an object to a function by const reference.

    In the lesson on passing arguments by reference,
    we covered the merits of passing class arguments by const reference
    instead of by value.
    To recap, passing a class argument by value causes a copy of the class
    to be made (which is slow) -- most of the time,
    we don’t need a copy, a reference to the original argument works just fine,
    and is more performant because it avoids the needless copy.

    We typically make the reference const in order to ensure the function
    does not inadvertently change the argument,
    and to allow the function to work with R-values (e.g. literals),
    which can be passed as const references,
    but not non-const references.

    ///////////////////////////////////////////////////////////////////////////////

    Overloading const and non-const function

    Finally, although it is not done very often,
    it is possible to overload a function in such a way to have
    a const and non-const version of the same function:

    The const version of the function will be called on any const objects,
    and the non-const version will be called on any non-const objects:

    */

    /*
    Somethingocncf somethingocncf{};
    somethingocncf.getValue() = "Hi"; // calls non-const getValue();

    const Somethingocncf something2ocncf{};
    something2ocncf.getValue(); // calls const getValue();

    */

    /*Overloading a function with a const and non-const version is typically
    done when the return value needs to differ in constness.
    In the example above, the non-const version of getValue()
    will only work with non-const objects,
    but is more flexible in that we can use it to both read and write m_value
    (which we do by assigning the string “Hi”).

    The const version of getValue()
    will work with either const or non-const objects,
    but returns a const reference,
    to ensure we can’t modify the const object’s data.

    This works because the const-ness of the function is considered
    part of the function’s signature,
    so a const and non-const function which differ only in
    const-ness are considered distinct.

    Summary

    Because passing objects by const reference is common,
    your classes should be const-friendly.
    That means making any member function that does not modify
    the state of the class object const!

    */
}




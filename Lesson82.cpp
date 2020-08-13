#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
#include <cstdint>
#include <iostream>

class Something11
{
private:
    int m_value1;
    double m_value2;
    char m_value3;

public:
    Something11(int value1, double value2, char value3 = 'c')
        : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 } // directly initialize our member variables
    {
        // No need for assignment here
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }

};

void class_cpp_oop_85a()
{
    /*
    In the previous lesson, for simplicity,
    we initialized our class member data in the constructor
    using the assignment operator.

    When the class’s constructor is executed, m_value1, m_value2,
    and m_value3 are created.
    Then the body of the constructor is run,
    where the member data variables are assigned values.
    This is similar to the flow of the following code in non-object-oriented C++

     as you have learned in previous lessons, some types of data
     (e.g. const and reference variables)
     must be initialized on the line they are declared

     Assigning values to const or reference member variables
     in the body of the constructor is clearly not possible in some cases.

     ////////////////////////////////////////////////////////////////////////////

     Member initializer lists

    To solve this problem, C++ provides a method for initializing class
    member variables (rather than assigning values to them after they are created)
    via a member initializer list (often called a “member initialization list”).
    Do not confuse these with the similarly named initializer list
    that we can use to assign values to arrays.

    int value1 = 1; // copy initialization
    double value2(2.2); // direct initialization
    char value3 {'c'}; // uniform initialization

    Using an initialization list is almost identical to doing direct initialization
    or uniform initialization.

    This is something that is best learned by example.
    Revisiting our code that does assignments in the constructor body:

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;

    public:
        Something()
        {
            // These are all assignments, not initializations
            m_value1 = 1;
            m_value2 = 2.2;
            m_value3 = 'c';
        }
    };

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;

    public:
        Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' } // Initialize our member variables
        {
        // No need for assignment here
        }

        void print()
        {
            std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
        }
    };

    int main()
    {
        Something something{};
        something.print();
        return 0;
    }

    The member initializer list is inserted after the constructor parameters.
    It begins with a colon (:), and then lists each variable to initialize
    along with the value for that variable separated by a comma.

    Note that we no longer need to do the assignments in the constructor body,
    since the initializer list replaces that functionality.
    Also note that the initializer list does not end in a semicolon.

    */

    Something11 something11{ 1, 2.2 };
    // value1 = 1, value2=2.2, value3 gets default value 'c'
    something11.print();

    /*
    class Something
    {
    private:
        const int m_value;

    public:
        Something(): m_value{ 5 } // directly initialize our const member variable
        {
        }
    };

    This works because
    we’re allowed to initialize const variables
    (but not assign to them!).

    Rule

    Use member initializer lists to initialize your class member variables
    instead of assignment.

    Initializing array members with member initializer lists

    class Something
    {
    private:
        const int m_array[5];

    public:
        Something(): m_array {} // zero the member array
        {
        }
    };

    However, since C++11,
    you can fully initialize a member array using uniform initialization:

    class Something
    {
    private:
        const int m_array[5];
    public:
        Something(): m_array { 1, 2, 3, 4, 5 } // use uniform initialization to initialize our member array
        {
        }
    };

    /////////////////////////////////////////////////////////////////////////////

    Initializing member variables that are classes

    A member initialization list can also be used to initialize
    members that are classes.

    #include <iostream>

    class A
    {
    public:
        A(int x) { std::cout << "A " << x << '\n'; }
    };

    class B
    {
    private:
        A m_a;
    public:
        B(int y)
             : m_a{ y-1 } // call A(int) constructor to initialize member m_a
        {
            std::cout << "B " << y << '\n';
        }
    };

    int main()
    {
        B b{ 5 };
        return 0;
    }

    When variable b is constructed,
    the B(int) constructor is called with value 5.
    Before the body of the constructor executes,
    m_a is initialized, calling the A(int) constructor with value 4.
    This prints “A 4”.
    Then control returns back to the B constructor,
    and the body of the B constructor executes,
    printing “B 5”.

    /////////////////////////////////////////////////////////////////////

    Formatting your initializer lists

    C++ gives you a lot of flexibility in how to format your initializer lists,
    and it’s really up to you how you’d like to proceed.
    But here are some recommendations:

    If the initializer list fits on the same line as the function name,
    then it’s fine to put everything on one line

    If the initializer list doesn’t fit on the same line as the function name,
    then it should go indented on the next line.

    If all of the initializers don’t fit on a single line
    (or the initializers are non-trivial),
    then you can space them out, one per line:

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;
        float m_value4;

    public:
        Something(int value1, double value2, char value3='c', float value4=34.6f) // this line already has a lot of stuff on it
            : m_value1{ value1 }, // one per line, commas at end of each line
            m_value2{ value2 },
            m_value3{ value3 },
            m_value4{ value4 }
        {
        }
    };

    ////////////////////////////////////////////////////////////////////////////////

    Initializer list order

    Perhaps surprisingly,
    variables in the initializer list are not initialized in the
    order that they are specified in the initializer list.
    Instead, they are initialized in the order in which they are
    declared in the class.

    For best results, the following recommendations should be observed:

    1) Don’t initialize member variables in such a way that they are dependent
    upon other member variables being initialized first
    (in other words, ensure your member variables will properly initialize
    even if the initialization ordering is different).

    2) Initialize variables in the initializer list in the same order in which they
    are declared in your class.
    This isn’t strictly required so long as the prior
    recommendation has been followed,
    but your compiler may give you a warning if you don’t
    do so and you have all warnings turned on.

    Summary

    Member initializer lists allow us to initialize our members rather
    than assign values to them.
    This is the only way to initialize members that require values upon initialization,
    such as const or reference members,
    and it can be more performant than assigning values in the body of the constructor.
    Member initializer lists work both with fundamental types and members that are
    classes themselves.

    */
}

class RGBA
{
public:
    // A type alias saves us some typing and makes the class easier to maintain
    using uif8 = std::uint8_t;
private:
    uif8 m_red;
    uif8 m_green;
    uif8 m_blue;
    uif8 m_alpha;
public:
    RGBA(uif8 red = 1, uif8 green = 1, uif8 blue = 1, uif8 alpha = 255)
        : m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
    {}
    void print()
    {
        std::cout << "Red = " << static_cast<int>(m_red) << " Green = " << static_cast<int>(m_green)
            << " Blue = " << static_cast<int>(m_blue) << " Alpha = " << static_cast<int>(m_alpha) << ".\n";
    };
};

//void class_cpp_oop_85b()
//{
    /*Non-static member initialization

    When writing a class that has multiple constructors (which is most of them),
    having to specify default values for all members in each constructor
    results in redundant code.
    If you update the default value for a member,
    you need to touch each constructor.

    Starting with C++11,
    it’s possible to give normal class member variables
    (those that don’t use the static keyword)
    a default initialization value directly

    Non-static member initialization
    (also called in-class member initializers)
    provides default values for your member variables that your
    constructors will use if the constructors do not provide initialization
    values for the members themselves (via the member initialization list).

    However, note that constructors still determine what
    kind of objects may be created.

    If a default initialization value is provided and the constructor initializes
    the member via the member initializer list,
    the member initializer list will take precedence.

    */

    /*
    Rectanglensmi xxxxx{ 2.0, 3.0 };
    xxxxx.print();

    Rectanglensmi yyyyy{ 4.0 };
    yyyyy.print();

    */

    /*Note that initializing members
    using non-static member initialization requires using either an equals sign,
    or a brace (uniform) initializer -- the direct initialization
    form doesn’t work here.

    Rule

    Favor use of non-static member initialization to give default values
    for your member variables.

    */
//}




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


class Fractionoop
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fractionoop() // default constructor
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Fractionoop1
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fractionoop1() // default constructor
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value
    Fractionoop1(int numerator, int denominator = 1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Fraction2
{
private:
    int m_numerator;
    int m_denominator;

public:
    // Default constructor
    Fraction2(int numerator = 0, int denominator = 1)
    {
        assert(denominator != 0);

        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Date20
{
private:
    // Note: No initializations at member declarations
    int m_year;
    int m_month;
    int m_day;

public:
    // Explicitly defaulted constructor
    Date20() = default;
};

class Date22
{
private:
    // Note: No initializations at member declarations
    int m_year;
    int m_month;
    int m_day;

public:
    // Empty user-provided constructor
    Date22() {};
};

void class_cpp_oop_85()
{
    /*
    When all members of a class (or struct) are public,
    we can use aggregate initialization to initialize the class (or struct)
    directly using an initialization list or uniform initialization:

    class Foo
    {
    public:
        int m_x;
        int m_y;
    };

    int main()
    {
        Foo foo1 = { 4, 5 }; // initialization list
        Foo foo2 { 6, 7 }; // uniform initialization

        return 0;
    }
    
    However, as soon as we make any member variables private,
    we’re no longer able to initialize classes in this way. 
    It does make sense: if you can’t directly access a variable 
    (because it’s private), you shouldn’t be able to directly initialize it.

    So then how do we initialize a class with private member variables? 
    The answer is through constructors.

    ///////////////////////////////////////////////////////////////////////

    Constructors

    A constructor is a special kind of class member function that is automatically 
    called when an object of that class is instantiated. 
    Constructors are typically used to initialize member variables 
    of the class to appropriate default or user-provided values, 
    or to do any setup steps necessary for the class to be used
    (e.g. open a file or database).

    Unlike normal member functions, 
    constructors have specific rules for how they must be named:

    Constructors must have the same name as the class (with the same capitalization)

    Constructors have no return type (not even void)

    */

    Fractionoop fracoop; // Since no arguments, calls Fraction() default constructor
    std::cout << fracoop.getNumerator() << "/" << fracoop.getDenominator() << '\n';

    /*This class was designed to hold a fractional value as an integer numerator
    and denominator. 
    We have defined a default constructor named Fraction
    (the same as the class).

    Because we’re instantiating an object of type Fraction with no arguments,
    the default constructor will be called immediately after memory
    is allocated for the object, and our object will be initialized.
    
    Note that our numerator and denominator were initialized
    with the values we set in our default constructor!
    Without a default constructor,
    the numerator and denominator would have garbage values until 
    we explicitly assigned them reasonable values, 
    or initialize them by other means 
    (remember: fundamental variables aren’t initialized by default).

    While the default constructor is great for ensuring our classes are initialized 
    with reasonable default values,
    often times we want instances of our class to have specific values that we provide.
    Fortunately, constructors can also be declared with parameters.
    Here is an example of a constructor that takes two integer parameters 
    that are used to initialize the numerator and denominator:

    Note that we now have two constructors: 
    a default constructor that will be called in the default case, 
    and a second constructor that takes two parameters.
    These two constructors can coexist peacefully in the same class due to 
    function overloading. 
    In fact, you can define as many constructors as you want,
    so long as each has a unique signature (number and type of parameters).

    So how do we use this constructor with parameters?
    It’s simple! We can use brace or direct initialization:

    */

    Fractionoop1 fiveThirds{ 5, 3 }; // Brace initialization, calls Fraction(int, int)
    Fractionoop1 threeQuarters(3, 4); // Direct initialization, also calls Fraction(int, int)

    /*Since C++11, we prefer brace initialization. 
    There is another special constructor that might make brace initialization
    do something different, 
    in that case we have to use direct initialization.
    We’ll talk about these constructors later.

    Note that we have given the second parameter of the constructor with parameters
    a default value, so the following is also legal:

    Fraction six{ 6 }; // calls Fraction(int, int) constructor, 
    second parameter uses default value

    Default values for constructors work exactly the same way as with any other 
    functions, so in the above case where we call six{ 6 }, 
    the Fraction(int, int) function is called with the second parameter 
    defaulted to value 1.

    Rule

    Favor brace initialization to initialize class objects.

    Copy initialization using equals with classes

    Optional reading

    This section is only relevant if you’re using a standard older than C++11.

    Much like with fundamental variables, 
    it’s also possible to initialize classes using copy initialization:

    Fraction six = Fraction{ 6 };
    // Copy initialize a Fraction, will call Fraction(6, 1)

    Fraction seven = 7;
    // Copy initialize a Fraction.  
    The compiler will try to find a way to convert 7 to a Fraction, 
    which will invoke the Fraction(7, 1) constructor.

    However, we recommend you avoid this form of initialization with classes,
    as it may be less efficient. 
    Although direct initialization, uniform initialization, 
    and copy initialization all work identically with fundamental types, 
    copy-initialization does not work the same with classes 
    (though the end-result is often the same).
    We’ll explore the differences in more detail in a future chapter.

    Reducing your constructors
    
class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
     {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

    */

    Fraction2 zero22; // will call Fraction(0, 1)
    Fraction2 zero2{}; // will call Fraction(0, 1)
    Fraction2 six2{ 6 }; // will call Fraction(6, 1)
    Fraction2 fiveThirds2{ 5, 3 }; // will call Fraction(5, 3)

    /*When implementing your constructors, 
    consider how you might keep the number of constructors
    down through smart defaulting of values.
    
    When implementing your constructors, 
    consider how you might keep the number of constructors down through smart defaulting of values.

    A reminder about default parameters

    The rules around defining and calling functions that have default parameters
    apply to constructors too. 
    To recap, when defining a function with default parameters, 
    all default parameters must follow any non-default parameters, 
    ie. there cannot be a non-defaulted parameters after a defaulted parameter.

    This may produce unexpected results for classes that have multiple default 
    parameters of different types

class Something
{
public:
    // Default constructor
    Something(int n = 0, double d = 1.2) // allows us to construct a Something(int, double), Something(int), or Something()
    {
    }
};

int main()
{
    Something s1 { 1, 2.4 }; // calls Something(int, double)
    Something s2 { 1 }; // calls Something(int, double)
    Something s3 {}; // calls Something(int, double)

    Something s4 { 2.4 }; // will not compile, as there's no constructor to handle Something(double)

    return 0;
}

    With s4, we’ve attempted to construct a Something by providing only a double. 
    This won’t compile, as the rules for how arguments match with default parameters
    won’t allow us to skip a non-rightmost parameter 
    (in this case, the leftmost int parameter).

    If we want to be able to construct a Something with only a double,
    we’ll need to add a second (non-default) constructor:

class Something
{
public:
    // Default constructor
    Something(int n = 0, double d = 1.2) // allows us to construct a Something(int, double), Something(int), or Something()
    {
    }

    Something(double d)
    {
    }
};

int main()
{
    Something s1 { 1, 2.4 }; // calls Something(int, double)
    Something s2 { 1 }; // calls Something(int, double)
    Something s3 {}; // calls Something(int, double)

    Something s4 { 2.4 }; // calls Something(double)

    return 0;
}

    An implicitly generated default constructor

    If your class has no constructors, 
    C++ will automatically generate a public default constructor for you.
    This is sometimes called an implicit constructor 
    (or implicitly generated constructor).

class Date
{
private:
    int m_year;
    int m_month;
    int m_day;

    // No user-provided constructors, the compiler generates a default constructor.
};

    This class has no constructor. 
    Therefore, the compiler will generate a constructor that allows us to create a 
    Date object without arguments.

    This particular implicit constructor allows us to create a Date object
    with no arguments, 
    but doesn’t initialize any of the members unless we create the Date object
    with direct- or list-initialization 
    (because all of the members are fundamental types, 
    and those don’t get initialized upon creation). 
    If Date had members that are class-types themselves, 
    for example std::string,
    the constructors of those members would be called automatically.

    To make sure the member variables get initialized,
    we can initialize them at their declaration

class Date
{
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };
};

    Although you can’t see the implicitly generated constructor, you can prove it exists:

class Date
{
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };

    // No constructor provided, so C++ creates a public default constructor for us
};

int main()
{
    Date date{}; // calls implicit constructor

    return 0;
}

    The above code compiles,
    because the date object will use the implicit constructor 
    (which is public).

    If your class has any other constructors, 
    the implicitly generated constructor will not be provided. 
    For example:
    
class Date
{
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };

public:
    Date(int year, int month, int day) // normal non-default constructor
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    // No implicit constructor provided because we already defined our own constructor
};

int main()
{
    Date date{}; // error: Can't instantiate object because default constructor doesn't exist and the compiler won't generate one
    Date today{ 2020, 1, 19 }; // today is initialized to Jan 19th, 2020

    return 0;
}

    To allow construction of a Date without arguments, 
    either add default arguments to the constructor,
    add an empty default constructor,
    or explicitly add a default constructor:
    
class Date
{
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };

public:
    // Tell the compiler to create a default constructor, even if
    // there are other user-provided constructors.
    Date() = default;

    Date(int year, int month, int day) // normal non-default constructor
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
};

int main()
{
    Date date{}; // date is initialized to Jan 1st, 1900
    Date today{ 2020, 10, 14 }; // today is initialized to Oct 14th, 2020

    return 0;
}

    Using = default is almost the same as adding a default constructor 
    with an empty body. 
    The only difference is that = default allows us to safely initialize
    member variables even if they don’t have an initializer:

class Date
{
private:
    // Note: No initializations at member declarations
    int m_year;
    int m_month;
    int m_day;

public:
    // Explicitly defaulted constructor
    Date() = default;
};

class Date2
{
private:
    // Note: No initializations at member declarations
    int m_year;
    int m_month;
    int m_day;

public:
    // Empty user-provided constructor
    Date2() {};
};

int main()
{
    Date today{}; // today is 0, 0, 0
    Date2 tomorrow{}; // tomorrows's members are uninitialized

    return 0;
}

    */

    Date20 today{}; // today is 0, 0, 0
    Date22 tomorrow{}; // tomorrows's members are uninitialized

    /*Using = default is longer than writing a constructor with an empty body, 
    but expresses better what your intentions are (To create a default constructor),
    and it’s safer. = default also works for other special constructors,
    which we’ll talk about in the future.

    Rule

    If you have constructors in your class and need a default constructor 
    that does nothing, use = default.

    Classes containing classes

    A class may contain other classes as member variables. 
    By default, when the outer class is constructed,
    the member variables will have their default constructors called. 
    This happens before the body of the constructor executes.
    
class A
{
public:
    A() { std::cout << "A\n"; }
};

class B
{
private:
    A m_a; // B contains A as a member variable

public:
    B() { std::cout << "B\n"; }
};

int main()
{
    B b;
    return 0;
}

    When variable b is constructed, the B() constructor is called.
    Before the body of the constructor executes, m_a is initialized, 
    calling the class A default constructor. This prints “A”. 
    Then control returns back to the B constructor,
    and the body of the B constructor executes.

    This makes sense when you think about it, as the B() 
    constructor may want to use variable m_a -- 
    so m_a had better be initialized first!

    The difference to the last example in the previous section is that m_a is a
    class-type.
    class-type members get initialized even if we don’t explicitly initialize them.

    In the next lesson, we’ll talk about how to initialize these class member variables.
    
    Constructor notes

    Many new programmers are confused about whether constructors create the objects or not.
    They do not -- the compiler sets up the memory allocation for the object prior 
    to the constructor call.

    Constructors actually serve two purposes. 
    First, constructors determine who is allowed to create an object. 
    That is, an object of a class can only be created if a matching constructor 
    can be found.

    Second, constructors can be used to initialize objects.
    Whether the constructor actually does an initialization is up to the programmer.
    It’s syntactically valid to have a constructor that does no initialization at all
    (the constructor still serves the purpose of allowing the object to be created, 
    as per the above).

    However, much like it is a best practice to initialize all local variables, 
    it’s also a best practice to initialize all member variables on creation
    of the object. This can be done either via a constructor,
    or via other means we’ll show in future lessons.

    Best practice

    Always initialize all member variables in your objects.

    Finally, constructors are only intended to be used for initialization
    when the object is created. 
    You should not try to call a constructor to re-initialize an existing object.
    While it may compile, the results will not be what you intended 
    (instead, the compiler will create a temporary object and then discard it).


    */

}

int main()
{
    class_cpp_oop_85();

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

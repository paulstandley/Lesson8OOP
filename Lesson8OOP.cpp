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

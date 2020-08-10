// 1
#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
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

    //////////////////////////////////////////////////////////////////////////////

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

    ///////////////////////////////////////////////////////////////////////////

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

    ////////////////////////////////////////////////////////////////////////////////////

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


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



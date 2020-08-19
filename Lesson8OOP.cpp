// Lesson8OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
#include "Vector3d.h" // for creating Vector3d object
#include "Point3d.h" // for creating Point3d object


class Cents1
{
private:
    int m_cents{};

public:
    Cents1(int cents) { m_cents = cents; }

    int getCents1() const { return m_cents; }
};

void print1(const Cents1& cents)
{
    std::cout << cents.getCents1() << " cents\n";
}

class Cents2
{
private:
    int m_cents{};

public:
    Cents2(int cents) { m_cents = cents; }

    int getCents2() const { return m_cents; }
};

void print2(const Cents2& cents)
{
    std::cout << cents.getCents2() << " cents\n";
}

class Cents3
{
private:
    int m_cents{};

public:
    Cents3(int cents) { m_cents = cents; }

    int getCents3() const { return m_cents; }
};

Cents3 add3(const Cents3& c1, const Cents3& c2)
{
    Cents3 sum{ c1.getCents3() + c2.getCents3() };
    return sum;
}

class Cents4
{
private:
    int m_cents{};

public:
    Cents4(int cents) { m_cents = cents; }

    int getCents4() const { return m_cents; }
};

Cents4 add4(const Cents4& c1, const Cents4& c2)
{
    // List initialization looks at the return type of the function
    // and creates the correct object accordingly.
    return { c1.getCents4() + c2.getCents4() }; // return anonymous Cents value
}

class Cents5
{
private:
    int m_cents{};

public:
    Cents5(int cents) { m_cents = cents; }

    int getCents5() const { return m_cents; }
};

Cents5 add5(const Cents5& c1, const Cents5& c2)
{
    return { c1.getCents5() + c2.getCents5() }; // return anonymous Cents value
}

void class_cpp_oop_814()
{//Anonymous objects
    /*In certain cases, we need a variable only temporarily.
    
    #include <iostream>
 
    int add(int x, int y)
    {
        int sum{ x + y };
        return sum;
    }
 
    int main()
    {
        std::cout << add(5, 3) << '\n'; 
        return 0;
    }

    In the add() function, 
    note that the sum variable is really only used as a 
    temporary placeholder variable.
    It doesn’t contribute much -- rather,
    its only function is to transfer the result of the
    expression to the return value.

    There is actually an easier way to write the add()
    function using an anonymous object. 
    An anonymous object is essentially a value that has no name.
    Because they have no name, there’s no way to refer to them 
    beyond the point where they are created. 
    
    Consequently, they have “expression scope”, 
    meaning they are created, evaluated,
    and destroyed all within a single expression.

        return x + y;

    an anonymous object is created to hold and return the result of x + y
    
    When the expression x + y is evaluated, 
    the result is placed in an anonymous object.
    A copy of the anonymous object is then returned to the caller by value,
    and the anonymous object is destroyed.

    This works not only with return values, but also with function parameters.

    void printValue(int value)
    {
        std::cout << value;
    }

    int main()
    {
        printValue(5 + 3);
        return 0;
    }

    In this case, the expression 5 + 3 is evaluated to produce the result 8, 
    which is placed in an anonymous object. 
    A copy of this anonymous object is then passed to the printValue() function,
    (which prints the value 8) and then is destroyed.

    Note how much cleaner this keeps our code -- we don’t have to litter
    the code with temporary variables that are only used once.

    //////////////////////////////////////////////////////////////////////////////

    Anonymous class objects

    Although our prior examples have been with built-in data types, 
    it is possible to construct anonymous objects of our own class types as well. 
    This is done by creating objects like normal,
    but omitting the variable name.

    Cents cents{ 5 }; // normal variable
    Cents{ 7 }; // anonymous object

    In the above code, Cents{ 7 } will create an anonymous Cents object,
    initialize it with the value 7, and then destroy it.
    In this context, that isn’t going to do us much good.
    So let’s take a look at an example where it can be put to good use:

    */

    Cents1 cents1{ 6 };
    print1(cents1);

    //Note that this example is very similar to the prior one using integers.
    //In this case, our main() function is passing a Cents object 
    //(named cents) to function print().

    //We can simplify this program by using anonymous objects

    print2(Cents2{ 12 }); 
    // Note: Now we're passing an anonymous Cents value

    //a slightly more complex example

    Cents3 cents13{ 6 };
    Cents3 cents23{ 8 };
    Cents3 sum3{ add3(cents13, cents23) };
    std::cout << "I have " << sum3.getCents3() << " cents.\n";

    /*In the above example, 
    we’re using quite a few named Cents values. 
    In the add() function, 
    we have a Cents value named sum that we’re using
    as an intermediary value to hold the sum before we return it. 
    And in function main(),
    we have another Cents value named sum also used as an intermediary value.

    We can make our program simpler by using anonymous values
    
    */

    Cents4 cents14{ 6 };
    Cents4 cents24{ 8 };
    std::cout << "I have " << add4(cents14, cents24).getCents4() << " cents.\n"; 
    // print anonymous Cents value

    /*This version of add() functions identically to the one above, 
    except it uses an anonymous Cents value instead of a named variable. 
    Also note that in main(), 
    we no longer use a named “sum” variable as temporary storage.
    Instead, we use the return value of add() anonymously!

    As a result, our program is shorter, cleaner, 
    and generally easier to follow (once you understand the concept).

    In fact, because cents1 and cents2 are only used in one place, 
    we can anonymize this even further:
    
    */

    std::cout << "I have " << add5(Cents5{ 6 }, Cents5{ 8 }).getCents5() << " cents.\n"; 
    // print anonymous Cents value

    /*Summary

    In C++, anonymous objects are primarily used either to pass or return values 
    without having to create lots of temporary variables to do so. 
    Memory allocated dynamically is also done so anonymously
    (which is why its address must be assigned to a pointer,
    otherwise we’d have no way to refer to it).

    However,
    it is worth noting that anonymous objects are treated as rvalues 
    (not lvalues, which have an address) -- therefore,
    all rules about passing and returning rvalues apply.

    It is also worth noting that because anonymous objects have expression scope,
    they can only be used once. 
    If you need to reference a value in multiple expressions, 
    you should use a named variable instead.

    Note: Some compilers, such as Visual Studio, 
    will let you set non-const references to anonymous objects.
    This is non-standard behavior.
    
    */

}

int main()
{
    class_cpp_oop_814();


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

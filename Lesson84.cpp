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
#include <chrono> // for std::chrono functions
#include <algorithm> // for std::sort


class Storagecf
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storagecf(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display class a friend of Storage
    friend class Displaycf;
};

class Displaycf
{
private:
    bool m_displayIntFirst;

public:
    Displaycf(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(const Storagecf& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
    }
};

class Accumulator
{
private:
    int m_value;
public:
    Accumulator() { m_value = 0; }
    void add(int value) { m_value += value; }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator& accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}

class Humidity;

class Temperature
{
private:
    int m_temp;
public:
    Temperature(int temp = 0) { m_temp = temp; }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity
{
private:
    int m_humidity;
public:
    Humidity(int humidity = 0) { m_humidity = humidity; }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

void printWeather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
        " and the humidity is " << humidity.m_humidity << '\n';
}

class Storagemf; // forward declaration for class Storage

class Displaymf
{
private:
    bool m_displayIntFirst;

public:
    Displaymf(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItemmf(const Storagemf& storage); // forward declaration above needed for this declaration line
};

class Storagemf // full definition of Storage class
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storagemf(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display::displayItem member function a friend of the Storage class (requires seeing the full declaration of class Display, as above)
    friend void Displaymf::displayItemmf(const Storagemf& storage);
};

// Now we can define Display::displayItem, which needs to have seen the full definition of class Storage
void Displaymf::displayItemmf(const Storagemf& storage)
{
    if (m_displayIntFirst)
        std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
    else // display double first
        std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
}


void class_cpp_oop_813()
{//Friend functions and classes
    /*Friend functions

    A friend function is a function that can access the private members
    of a class as though it were a member of that class.
    In all other regards, the friend function is just like a normal function.
    A friend function may be either a normal function,
    or a member function of another class.
    To declare a friend function,
    simply use the friend keyword in front of the prototype of the function
    you wish to be a friend of the class.
    It does not matter whether you declare the friend function
    in the private or public section of the class.

    */

    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0

    /*Note that we have to pass an Accumulator object to reset().
    This is because reset() is not a member function.
    It does not have a *this pointer,
    nor does it have an Accumulator object to work with,
    unless given one.

    */

    Humidity hum(10);
    Temperature temp(12);
    printWeather(temp, hum);

    /*There are two things worth noting about this example.
    First, because PrintWeather is a friend of both classes,
    it can access the private data from objects of both classes.
    Second, note the following line at the top of the example

    This is a class prototype that tells the compiler that we are going
    to define a class called Humidity in the future.
    Without this line,
    the compiler would tell us it doesn’t know what a Humidity is
    when parsing the prototype for PrintWeather() inside the Temperature class.

    Class prototypes serve the same role as function prototypes --
    they tell the compiler what something looks like so it can be used
    now and defined later.
    However, unlike functions, classes have no return types or parameters,
    so class prototypes are always simply class ClassName,
    where ClassName is the name of the class.

    /////////////////////////////////////////////////////////////////////////////

    Friend classes

    It is also possible to make an entire class a friend of another class.
    This gives all of the members of the friend class access to the private members
    of the other class

    */

    Storagecf storagecf(5, 6.7);
    Displaycf displaycf(false);
    displaycf.displayItem(storagecf);

    /*Because the Display class is a friend of Storage,
    any of Display’s members that use a Storage class object can access
    the private members of Storage directly.

    A few additional notes on friend classes.
    First, even though Display is a friend of Storage,
    Display has no direct access to the *this pointer of Storage objects.

    Second, just because Display is a friend of Storage,
    that does not mean Storage is also a friend of Display.
    If you want two classes to be friends of each other,
    both must declare the other as a friend.

    Finally, if class A is a friend of B, and B is a friend of C,
    that does not mean A is a friend of C.

    Be careful when using friend functions and classes,
    because it allows the friend function or class to violate encapsulation.
    If the details of the class change,
    the details of the friend will also be forced to change.
    Consequently, limit your use of friend functions and classes to a minimum.

    /////////////////////////////////////////////////////////////////////////

    Friend member functions

    Instead of making an entire class a friend,
    you can make a single member function a friend.
    This is done similarly to making a normal function a friend,
    except using the name of the member function with the
    className:: prefix included (e.g. Display::displayItem).

    However, in actuality, this can be a little trickier than expected.
    Let’s convert the previous example to make Display::displayItem
    a friend member function.

     In order to make a member function a friend,
     the compiler has to have seen the full definition for the class
     of the friend member function (not just a forward declaration).
     Since class Storage hasn’t seen the full definition for class Display yet,
     the compiler will error at the point where we try to make
     the member function a friend.

    */

    Storagemf storagemf(5, 6.7);
    Displaymf displaymf(false);
    displaymf.displayItemmf(storagemf);

    /*Now everything will compile properly:
    the forward declaration of class Storage is enough to satisfy the declaration
    of Display::displayItem() inside the Display class,
    the full definition of Display satisfies declaring Display::displayItem()
    as a friend of Storage,
    and the full definition of class Storage is enough to satisfy
    the definition of member function Display::displayItem().
    If that’s a bit confusing, see the comments in the program above.

    If this seems like a pain -- it is. Fortunately,
    this dance is only necessary because we’re trying to do everything
    in a single file.
    A better solution is to put each class definition in a separate header file,
    with the member function definitions in corresponding .cpp files.
    That way, all of the class definitions would have been visible immediately
    in the .cpp files, and no rearranging of classes or functions is necessary!

    ///////////////////////////////////////////////////////////////////////////

    Summary

    A friend function or class is a function or class that can access the
    private members of another class as though it were a member of that class.
    This allows the friend or class to work intimately with the other class,
    without making the other class expose its private members
    (e.g. via access functions).

    Friending is uncommonly used when two or more classes need to work together
    in an intimate way,
    or much more commonly, when defining overloading operators

    Note that making a specific member function a friend requires the full definition
    for the class of the member function to have been seen first.

    */
}

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

enum FruitType11
{
    APPLE,
    BANANA,
    CHERRY
};

class Fruit11
{
private:
    FruitType11 m_type;
    int m_percentageEaten = 0;

public:

    Fruit11(FruitType11 type) :
        m_type(type) {}

    FruitType11 getType11() { return m_type; }
    int getPercentageEaten() { return m_percentageEaten; }
};

class Fruit12
{
public:
    // Note: we've moved FruitType inside the class, under the public access specifier
    enum FruitType12
    {
        APPLE,
        BANANA,
        CHERRY
    };

private:
    FruitType12 m_type;
    int m_percentageEaten = 0;

public:


    Fruit12(FruitType12 type) :
        m_type(type)
    {
    }

    FruitType12 getType12() { return m_type; }
    int getPercentageEaten() { return m_percentageEaten; }
};

void class_cpp_oop_815()
{
    Fruit11 apple(APPLE);

    if (apple.getType11() == APPLE)
        std::cout << "I am an apple";
    else
        std::cout << "I am not an apple";
    /*There’s nothing wrong with this program.
    But because enum FruitType is meant to be used in conjunction with the Fruit class,
    it’s a little weird to have it exist independently from the class itself.

    Nesting types

    Unlike functions, which can’t be nested inside each other, in C++,
    types can be defined (nested) inside of a class.
    To do this, you simply define the type inside the class,
    under the appropriate access specifier.

    Here’s the same program as above, with FruitType defined inside the class

    */

    // Note: we access the FruitType via Fruit now
    Fruit12 apple12(Fruit12::APPLE);

    if (apple12.getType12() == Fruit12::APPLE)
        std::cout << "I am an apple";
    else
        std::cout << "I am not an apple";

    /*First, note that FruitType is now defined inside the class.
    Second, note that we’ve defined it under the public access specifier,
    so the type definition can be accessed from outside the class.

    Classes essentially act as a namespace for any nested types.
    In the prior example, we were able to access enumerator APPLE directly,
    because the APPLE enumerator was placed into the global scope
    (we could have prevented this by using an enum class instead of an enum,
    in which case we’d have accessed APPLE via FruitType::APPLE instead).

    Now, because FruitType is considered to be part of the class,
    we access the APPLE enumerator by prefixing it with the class name:
    Fruit::APPLE.

    Note that because enum classes also act like namespaces,
    if we’d nested FruitType inside Fruit as an enum class instead of an enum,
    we’d access the APPLE enumerator via Fruit::FruitType::APPLE.

    Other types can be nested too

    Although enumerations are probably the most common type that is nested
    inside a class, C++ will let you define other types within a class,
    such as typedefs, type aliases, and even other classes!

    Like any normal member of a class,
    nested classes have the same access to members of the enclosing class
    that the enclosing class does.
    However, the nested class does not have any special access
    to the “this” pointer of the enclosing class.

    One other limitation of nested types -- they can’t be forward declared.
    This limitation may be lifted in a future version of C++.

    Defining nested classes isn’t very common,
    but the C++ standard library does do so in some cases,
    such as with iterator classes.

    */
}



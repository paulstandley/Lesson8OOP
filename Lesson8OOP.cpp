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


class Somethingsmv
{
private:
    static int s_idGenerator;
    int m_id;

public:
    Somethingsmv() { m_id = s_idGenerator++; } // grab the next value from the id generator

    int getID() const { return m_id; }
};

// Note that we're defining and initializing s_idGenerator 
// even though it is declared as private above.
// This is okay since the definition isn't subject to access controls.
int Somethingsmv::s_idGenerator = 1; // start our ID generator with value 1

void class_cpp_oop_811()
{
    /*Static member variables
    
    static variables keep their values 
    and are not destroyed even after they go out of scope

    The static keyword has another meaning when applied to global variables
    -- it gives them internal linkage
    (which restricts them from being seen/used outside of the file they are defined in).
    Because global variables are typically avoided, 
    the static keyword is not often used in this capacity.

    Static member variables
    
    C++ introduces two more uses for the static keyword when applied to classes:
    static member variables, 
    and static member functions. 
    Fortunately, these uses are fairly straightforward. 
    
    Member variables of a class can be made static by using the static keyword. 
    Unlike normal member variables, 
    static member variables are shared by all objects of the class

    Because s_value is a static member variable, 
    s_value is shared between all objects of the class. 
    Consequently, first.s_value is the same variable as second.s_value. 
    The value we set using first can be accessed using second!

    //////////////////////////////////////////////////////////////////////////////

    Static members are not associated with class objects

    Although you can access static members through objects of the class 
    (as shown with first.s_value and second.s_value in the example above),
    it turns out that static members exist even if no objects 
    of the class have been instantiated! Much like global variables,
    they are created when the program starts, and destroyed when the program ends.

    Consequently, it is better to think of static members as belonging to the 
    class itself, not to the objects of the class.
    Because s_value exists independently of any class objects, 
    it can be accessed directly using the class name and the scope
    resolution operator (in this case, Something::s_value):

    class Something
    {
    public:
        static int s_value; // declares the static member variable
    };

    int Something::s_value{ 1 }; // defines the static member variable (we'll discuss this section below)

    int main()
    {
        // note: we're not instantiating any objects of type Something

        Something::s_value = 2;
        std::cout << Something::s_value << '\n';
        return 0;
    }

    In the above snippet,
    s_value is referenced by class name rather than through an object.
    Note that we have not even instantiated an object of type Something,
    but we are still able to access and use Something::s_value. 
    This is the preferred method for accessing static members.

    /////////////////////////////////////////////////////////////////////////

    Defining and initializing static member variables

    When we declare a static member variable inside a class,
    we’re telling the compiler about the existence of a static member variable, 
    but not actually defining it (much like a forward declaration).
    
    Because static member variables are not part of the individual class objects 
    (they are treated similarly to global variables, 
    and get initialized when the program starts),
    you must explicitly define the static member outside of the class,
    in the global scope.

    int Something::s_value{ 1 }; // defines the static member variable

    This line serves two purposes: 
    it instantiates the static member variable (just like a global variable), 
    and optionally initializes it.
    In this case, we’re providing the initialization value 1.
    If no initializer is provided, C++ initializes the value to 0.

    Note that this static member definition is not subject to access controls:
    you can define and initialize the value even if it’s declared as private
    (or protected) in the class.

    If the class is defined in a .h file, 
    the static member definition is usually placed in the associated code file
    for the class (e.g. Something.cpp).
    
    If the class is defined in a .cpp file,
    the static member definition is usually placed directly underneath the class. 
    Do not put the static member definition in a header file 
    (much like a global variable, if that header file gets included more than once,
    you’ll end up with multiple definitions, which will cause a compile error).

    //////////////////////////////////////////////////////////////////////////////

    Inline initialization of static member variables

    There are a few shortcuts to the above.
    First, when the static member is a const integral type 
    (which includes char and bool) or a const enum,
    the static member can be initialized inside the class definition:

    class Whatever
    {
    public:
        static const int s_value{ 4 };
        // a static const int can be declared and initialized directly
    };

    In the above example, because the static member variable is a const int,
    no explicit definition line is needed.

    Second, static constexpr members can be initialized inside the class definition:

    #include <array>

    class Whatever
    {
    public:
        static constexpr double s_value{ 2.2 }; // ok
        static constexpr std::array<int, 3> s_array{ 1, 2, 3 }; 
        // this even works for classes that support constexpr initialization
    };

    An example of static member variables

    Why use static variables inside classes?

    One great example is to assign a unique ID to every instance of the class.

    */
    
    Somethingsmv firstsmv;
    Somethingsmv secondsmv;
    Somethingsmv thirdsmv;

    std::cout << firstsmv.getID() << '\n';
    std::cout << secondsmv.getID() << '\n';
    std::cout << thirdsmv.getID() << '\n';

    /*Because s_idGenerator is shared by all Something objects,
    when a new Something object is created, 
    the constructor grabs the current value out of s_idGenerator
    and then increments the value for the next object. 
    
    This guarantees that each instantiated Something object
    receives a unique id (incremented in the order of creation). 
    This can really help when debugging multiple items in an array,
    as it provides a way to tell multiple objects of the same class type apart!

    Static member variables can also be useful when the class needs
    to utilize an internal lookup table 
    (e.g. an array used to store a set of pre-calculated values). 
    
    By making the lookup table static, only one copy exists for all objects,
    rather than making a copy for each object instantiated. 
    This can save substantial amounts of memory.
    
    */
}

int main()
{
    class_cpp_oop_811();


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

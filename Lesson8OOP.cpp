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

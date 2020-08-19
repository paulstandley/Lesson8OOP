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

    Although our prior examples have been with built-in data types, it is possible to construct anonymous objects of our own class types as well. This is done by creating objects like normal, but omitting the variable name.

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

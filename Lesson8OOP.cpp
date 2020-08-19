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
		m_type(type){}

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

void timing_your_code()
{
	/*When writing your code, 
	sometimes you’ll run across cases where you’re not sure whether one method 
	or another will be more performant. So how do you tell?

	One easy way is to time your code to see how long it takes to run. 
	C++11 comes with some functionality in the chrono library to do just that.
	
	However, 
	using the chrono library is a bit arcane. 
	The good news is that we can easily encapsulate all the timing functionality 
	we need into a class that we can then use in our own programs.
	
	*/
}


int main()
{
    timing_your_code();


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

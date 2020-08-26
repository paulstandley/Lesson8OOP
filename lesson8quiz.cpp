#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
#include <cstdint>
#include <string>
#include <iostream>
#include "Vector3d.h" // for creating Vector3d object
#include "Point3d.h" // for creating Point3d object
#include <cmath>
#include <string_view>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()


class Point3dlq
{
private:
	int m_x, m_y, m_z;

public:
	void setValues(int x, int y, int z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print()
	{
		std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
	}

	// We can use the fact that access controls work on a per-class basis here
	// to directly access the private members of Point3d parameter p
	bool isEqual(const Point3dlq& p)
	{
		return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
	}

};

class Stack
{
private:
	// We use a std::array to store the elements
	using container_type = std::array<int, 10>;
	// For convenience, add a type alias for the type of the indexes
	using size_type = container_type::size_type;

	container_type m_array; // Here's where we're going to store our stack data
	size_type m_next{ 0 }; // This will hold the index of the next free element on the stack

public:

	void reset()
	{
		m_next = 0;
	}

	bool push(int value)
	{
		// If the stack is already full, return false and bail
		if (m_next == m_array.size())
			return false;

		m_array[m_next++] = value; // set the next free element to the value, then increase m_next
		return true;
	}

	int pop()
	{
		// If there are no elements on the stack, assert out
		assert(m_next > 0 && "Can not pop empty stack");

		// m_next points to the next free element, so the last valid element is m_next -1.
		// what we want to do is something like this:
		// int val = m_array[m_next-1]; // get the last valid element
		// --m_next; // m_next is now one less since we just removed the top element
		// return val; // return the element
		// that can be condensed down into this:
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (size_type i{ 0 }; i < m_next; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
};

/*
void printStack(std::stack<int> stack)
{
	std::cout << "( ";
	while (!stack.empty())
	{
		std::cout << stack.top() << ' ';
		stack.pop();
	}
	std::cout << ")\n";
}
*/

void lesson83quiz()
{
	/*
	* a) Write a simple class named Point3d. The class should contain:
	* Three private member variables of type int named m_x, m_y, and m_z;
	* A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
	* A public member function named print()
	  that prints the Point in the following format: <m_x, m_y, m_z>

	*/

	Point3dlq point1;
	point1.setValues(1, 2, 3);
	point1.print();

	Point3dlq point2;
	point2.setValues(1, 2, 3);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Point3dlq point3;
	point3.setValues(3, 4, 5);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";

	/*
	* b) The class should be named Stack, and should contain:
	* A private fixed array of integers of length 10.
	* A private integer to keep track of the size of the stack.
	* A public member function named reset() that sets the size to 0.
	* A public member function named push() that pushes a value on the stack.
	push() should return false if the array is already full, and true otherwise.
	* A public member function named pop() that pops a value off the stack
	and returns it.
	If there are no values on the stack, the code should exit via an assert.
	* A public member function named print() that prints all the values in the stack.

	*/

	Stack stack;

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.reset();
	stack.print();


	//Rather than writing a custom stack implementation every time you need a stack,
	//use std::stack. Like std::array and std::vector,
	//you can specify the element type when you create it.

	// std::stack only provides access to the topmost element. If we want to
	// print all elements, we need to copy the stack (by passing it by value)
	// and pop elements until the stack is empty.

	// Create a std::stack that holds ints.

	/*
	std::stack<int> stack1{};

	printStack(stack1);

	stack1.push(5);
	stack1.push(3);
	stack1.push(8);
	printStack(stack1);

	stack1.pop();
	printStack(stack1);

	// To clear the stack, assign it an empty stack.
	stack1 = {};
	printStack(stack1);
	*/
}

class Ball1
{
private:
	std::string m_color{};
	double m_radius{};

public:
	// Default constructor with no parameters
	Ball1()
	{
		m_color = "black";
		m_radius = 10.0;
	}

	// Constructor with only color parameter (radius will use default value)
	Ball1(const std::string& color)
	{
		m_color = color;
		m_radius = 10.0;
	}

	// Constructor with only radius parameter (color will use default value)
	Ball1(double radius)
	{
		m_color = "black";
		m_radius = radius;
	}

	// Constructor with both color and radius parameters
	Ball1(const std::string& color, double radius)
	{
		m_color = color;
		m_radius = radius;
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

class Ball2
{
private:
	std::string m_color{};
	double m_radius{};

public:
	// Constructor with only radius parameter (color will use default value)
	Ball2(double radius)
	{
		m_color = "black";
		m_radius = radius;
	}

	// Constructor with both color and radius parameters
	// handles no parameter, color only, and color + radius cases.
	Ball2(const std::string& color = "black", double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

void lesson85quiz()
{
	/*Write a class named Ball.
	Ball should have two private member variables with default values: m_color
	(“black”) and m_radius (10.0). Ball should provide constructors to set
	only m_color, set only m_radius, set both, or set neither value.
	For this quiz question, do not use default parameters for your constructors.
	Also write a function to print out the color and radius of the ball.

	*/

	Ball1 def1{};
	def1.print();

	Ball1 blue1{ "blue" };
	blue1.print();

	Ball1 twenty1{ 20.0 };
	twenty1.print();

	Ball1 blueTwenty1{ "blue", 20.0 };
	blueTwenty1.print();

	//b) Update your answer to the previous 
	//question to use constructors with default parameters. 
	//Use as few constructors as possible.
	std::cout << std::endl;

	Ball2 def2{};
	def2.print();

	Ball2 blue2{ "blue" };
	blue2.print();

	Ball2 twenty2{ 20.0 };
	twenty2.print();

	Ball2 blueTwenty2{ "blue", 20.0 };
	blueTwenty2.print();

	//Question #2 What happens if you don’t declare a default constructor ?

	/*
	If you haven’t defined any other constructors,
	the compiler will create an empty public default constructor for you.
	This means your objects will be instantiable with no parameters.
	If you have defined other constructors (default or otherwise),
	the compiler will not create a default constructor for you.
	Assuming you haven’t provided a default constructor yourself,
	your objects will not be instantiable without arguments.

	*/
}

class Ball85aquiz
{
private:
	std::string m_color{ "black" };
	// The radius always gets initialized by the constructors.
	double m_radius;
public:
	// Constructor with only radius parameter (color will use default value)
	Ball85aquiz(double radius) : m_radius{ radius }
	{}
	// Constructor with both color and radius parameters
	Ball85aquiz(const std::string& color = "black", double radius = 1) : m_color{ color }, m_radius{ radius }
	{}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

void lesson85aquiz()
{
	Ball85aquiz defdd{};
	defdd.print();

	Ball85aquiz blueaaa{ "blue" };
	blueaaa.print();

	Ball85aquiz twentyaaa{ 20.0 };
	twentyaaa.print();

	Ball85aquiz blueTwentyaaa{ "blue", 20.0 };
	blueTwentyaaa.print();

	/*
	Why do we not need to declare a default constructor in the program above,
	even though we’re constructing def without arguments?

	“Ball def{};” uses the second Ball constructor which has a default argument
	for every parameter.

	*/
}

class Vector3d1
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d1(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	void print() const
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	friend class Point3d1; // Point3d is now a friend of class Vector3d
};

class Point3d1
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d1(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector1(const Vector3d1& v)
	{
		// implement this function as a friend of class Vector3d
		m_x += v.m_x;
		m_y += v.m_y;
		m_z += v.m_z;
	}
};

class Vector3d2; // first, we need to tell the compiler that a class named Vector3d exists

class Point3d2
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d2(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector2(const Vector3d2& v); // so we can use Vector3d here
	   // note: we can't define this function here, because Vector3d hasn't been declared yet (just forward declared)
};

class Vector3d2
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d2(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	void print() const
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	friend void Point3d2::moveByVector2(const Vector3d2& v); // Point3d::moveByVector() is now a friend of class Vector3d
};

// Now that Vector3d has been declared, we can define the function Point3d::moveByVector()
void Point3d2::moveByVector2(const Vector3d2& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

void lesson813quiz()
{
	/*
	1) In geometry, a point is a position in space.
	We can define a point in 3d-space as the set of coordinates x, y, and z.
	For example, the Point(2.0, 1.0, 0.0) would be the point at
	coordinate space x=2.0, y=1.0, and z=0.0.

	In physics, a vector is a quantity that has a
	magnitude (length) and a direction (but no position).
	We can define a vector in 3d-space as an x, y, and z value
	representing the direction of the vector along the x, y, and z axis
	(the length can be derived from these).
	For example, the Vector(2.0, 0.0, 0.0)
	would be a vector representing a direction along the positive x-axis (only),
	with length 2.0.

	A Vector can be applied to a Point to move the Point to a new position.
	This is done by adding the vector’s direction to the point’s position
	to yield a new position.
	For example, Point(2.0, 1.0, 0.0) + Vector(2.0, 0.0, 0.0)
	would yield the point (4.0, 1.0, 0.0).

	Points and Vectors are often used in computer graphics
	(the point to represent vertices of shape,
	and vectors represent movement of the shape).

	*/

	//1a) Make Point3d a friend class of Vector3d, 
	//and implement function Point3d::moveByVector()

	Point3d1 p1{ 1.0, 2.0, 3.0 };
	Vector3d1 v1{ 2.0, 2.0, -3.0 };

	p1.print();
	p1.moveByVector1(v1);
	p1.print();

	//1b) Instead of making class Point3d a friend of class Vector3d, 
	//make member function Point3d::moveByVector a friend of class Vector3d.

	Point3d2 p2{ 1.0, 2.0, 3.0 };
	Vector3d2 v2{ 2.0, 2.0, -3.0 };

	p2.print();
	p2.moveByVector2(v2);
	p2.print();

	//1c) Reimplement the solution to quiz question 1b using 5 separate files:
	//Point3d.h, Point3d.cpp, Vector3d.h, Vector3d.cpp, and main.cpp.

	Point3d p{ 1.0, 2.0, 3.0 };
	Vector3d v{ 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	//Thanks to reader Shiva for the suggestionand solution.
}

class Point2dq
{
private:
	double m_x{};
	double m_y{};
public:
	Point2dq(double x = 0, double y = 0) : m_x{ 0.0 }, m_y{ 0.0 } { m_x = x; m_y = y; }

	void printq()
	{
		std::cout << "Point2dq(" << m_x << ", " << m_y << ")" << std::endl;
	}
};

class Point2dq1
{
private:
	double m_x{};
	double m_y{};
public:
	Point2dq1(double x = 0, double y = 0) : m_x{ 0.0 }, m_y{ 0.0 } { m_x = x; m_y = y; }

	void printq1()
	{
		std::cout << "Point2dq(" << m_x << ", " << m_y << ")" << std::endl;
	}

	int distanceTo(const Point2dq1& point) const
	{
		return std::sqrt
		((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y));
	}
};

class Point2dq2
{
private:
	double m_x{};
	double m_y{};
public:
	Point2dq2(double x = 0, double y = 0) : m_x{ 0.0 }, m_y{ 0.0 } { m_x = x; m_y = y; }

	void printq2()
	{
		std::cout << "Point2dq(" << m_x << ", " << m_y << ")" << std::endl;
	}

	friend double distanceFrom2(const Point2dq2& point, const Point2dq2& point2);
};

double distanceFrom2(const Point2dq2& point, const Point2dq2& point2)
{
	return std::sqrt
	((point2.m_x - point.m_x) * (point2.m_x - point.m_x)
		+ (point2.m_y - point.m_y) * (point2.m_y - point.m_y));
}

void chapter_8_comprehensive_quiz()
{
	/*Quick Summary

	Classes allow you to create your own data types that bundle both data and functions
	that work on that data.
	Data and functions inside the class are called members.
	Members of the class are selected by using the . operator
	(or -> if you’re accessing the member through a pointer).

	Access specifiers allow you to specify who can access the members of a class.
	Public members can be accessed directly by anybody.
	Private members can only be accessed by other members of the class.
	We’ll cover protected members later, when we get to inheritance.
	By default, all members of a class are private and all members
	of a struct are public.

	Encapsulation is the process of making all of your member data private,
	so it can not be accessed directly.
	This helps protect your class from misuse.

	Constructors are a special type of member function that allow you to
	initialize objects of your class.
	A constructor that takes no parameters (or has all default parameters)
	is called a default constructor.
	The default constructor is used if no initialization values are provided
	by the user.
	You should always provide at least one constructor for your classes.

	Member initializer lists allows you to initialize your member variables
	from within a constructor (rather than assigning the member variables values).

	In C++11, non-static member initialization allows you to directly
	specify default values for member variables when they are declared.

	Prior to C++11, constructors should not call other constructors
	(it will compile, but will not work as you expect).
	In C++11, constructors are allowed to call other constructors
	(called delegating constructors, or constructor chaining).

	Destructors are another type of special member function that allow your class
	to clean up after itself.
	Any kind of deallocation or shutdown routines should be executed from here.

	All member functions have a hidden *this pointer that points at the class
	object being modified.
	Most of the time you will not need to access this pointer directly.
	But you can if you need to.

	It is good programming style to put your class definitions in a
	header file of the same name as the class,
	and define your class functions in a .cpp file of the same name as the class.
	This also helps avoid circular dependencies.

	Member functions can (and should) be made const if they do not modify the state of
	the class. Const class objects can only call const member functions.

	Static member variables are shared among all objects of the class.
	Although they can be accessed from a class object,
	they can also be accessed directly via the scope resolution operator.

	Similarly, static member functions are member functions that have no
	*this pointer. They can only access static member variables.

	Friend functions are functions that are treated like member functions of the class
	(and thus can access a class’s private data directly).
	Friend classes are classes where all members of the class are considered
	friend functions.

	It’s possible to create anonymous class objects for the purpose of evaluation
	in an expression, or passing or returning a value.

	You can also nest types within a class.
	This is often used with enums related to the class,
	but can be done with other types (including other classes) if desired.

	a) Write a class named Point2d.
	Point2d should contain two member variables of type double:
	m_x, and m_y, both defaulted to 0.0.
	Provide a constructor and a print function.

	*/

	Point2dq firstq{};
	Point2dq secondq{ 3.0, 4.0 };
	firstq.printq();
	secondq.printq();

	/*b) Now add a member function named distanceTo that takes
	another Point2d as a parameter,
	and calculates the distance between them.
	Given two points (x1, y1) and (x2, y2),
	the distance between them can be calculated as
	std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)).
	The std::sqrt function lives in header cmath.

	*/

	Point2dq1 firstq1{};
	Point2dq1 secondq1{ 3.0, 4.0 };
	firstq1.printq1();
	secondq1.printq1();
	std::cout << "Distance between two points: " << firstq1.distanceTo(secondq1) << '\n';

	/*c) Change function distanceTo from a member function to a non-member
	friend function that takes two Points as parameters.
	Also rename it “distanceFrom”.

	*/

	Point2dq2 firstq2{};
	Point2dq2 secondq2{ 3.0, 4.0 };
	firstq2.printq2();
	secondq2.printq2();
	std::cout << "Distance between two points: " << distanceFrom2(firstq2, secondq2) << '\n';

}

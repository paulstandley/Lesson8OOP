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


class Point3d
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
	bool isEqual(const Point3d& p)
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

	Point3d point1;
	point1.setValues(1, 2, 3);
	point1.print();

	Point3d point2;
	point2.setValues(1, 2, 3);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Point3d point3;
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





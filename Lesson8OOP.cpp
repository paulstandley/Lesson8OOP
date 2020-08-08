// Lesson8OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
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
}

int main()
{
    lesson83quiz();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

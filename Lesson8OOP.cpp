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

int main()
{
    lesson85quiz();

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

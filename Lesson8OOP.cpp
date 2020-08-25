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
#include <chrono> // for std::chrono functions
#include <algorithm> // for std::sort
#include <cmath>
#include <string_view>


class HelloWorld
{
private:
	char* m_data{};

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char* init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data << '\n';
	}

};

class Monster
{
public:
	enum class Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_type
	};

private:
	Type m_type;
	std::string m_name;
	std::string m_roar;
	int m_hit_points;

public:
	Monster(Type type, const std::string& name, const std::string& roar, int hitpoints):
		m_type{ type }, m_name{ name }, m_roar{ roar }, m_hit_points{ hitpoints } {}

	// We're returning strings that are known at compile-time. Returning std::string
	// could add a considerable run-time cost.
	std::string_view getTypeString() const
	{
		switch (m_type)
		{
		case Type::dragon: return "dragon";
		case Type::goblin: return "goblin";
		case Type::ogre: return "ogre";
		case Type::orc: return "orc";
		case Type::skeleton: return "skeleton";
		case Type::troll: return "troll";
		case Type::vampire: return "vampire";
		case Type::zombie: return "zombie";
		default: return "???";
		}
	}

	void print()
	{// Bones the skeleton has 4 hit points and says *rattle*
		std::cout << m_name << " the " << getTypeString() << " has " << m_hit_points << " hit points and says " << m_roar << '\n';
	}
};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		return { Monster::Type::skeleton, "Bones", "*rattle*", 4 };
	}
};

void chapter_8_comprehensive_quiz2()
{
	//HelloWorld hello{};
	//hello.print();

	/*Question #3

	Let’s create a random monster generator. This one should be fun.

	a) First, 
	let’s create an enumeration of monster types named MonsterType. 
	Include the following monster types:
	Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie.
	Add an additional max_monster_types enum so we can count how many enumerators
	there are.

	b) Now, let’s create our Monster class. 
	Our Monster will have 4 attributes (member variables): a type (MonsterType),
	a name (std::string), a roar (std::string), and the number of hit points (int).
	Create a Monster class that has these 4 member variables.
	
	c) enum MonsterType is specific to Monster,
	so move the enum inside the class as a public declaration.
	When the enum is inside the class the “Monster” in “MonsterType” is redundant, 
	it can be removed.

	d) Create a constructor that allows you to initialize all of the member variables.

	e) Now we want to be able to print our monster so we can validate it’s correct.
	To do that, we’re going to need to write a function that converts a 
	Monster::Type into a string. 
	Write that function (called getTypeString()), 
	as well as a print() member function.

	f) Now we can create a random monster generator.
	Let’s consider how our MonsterGenerator class will work. 
	Ideally, we’ll ask it to give us a Monster, and it will create a random one for us.
	We don’t need more than one MonsterGenerator.
	This is a good candidate for a static class (one in which all functions are static).
	Create a static MonsterGenerator class. 
	Create a static function named generateMonster(). 
	This should return a Monster.
	For now, make it return anonymous
	Monster(Monster::Type::skeleton, “Bones”, “*rattle*”, 4);

	*/
	Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster monster1{ MonsterGenerator::generateMonster() };
	monster1.print();


}

int main()
{
    //timing_your_code();
    chapter_8_comprehensive_quiz2();
	

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

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


class Timer1
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer1() : m_beg(clock_t::now())
	{
	}

	void reset1()
	{
		m_beg = clock_t::now();
	}

	double elapsed1() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

const int g_arrayElements = 10000;

class Timer2
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer2() : m_beg(clock_t::now())
	{
	}

	void reset2()
	{
		m_beg = clock_t::now();
	}

	double elapsed2() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void sortArray2(std::array<int, g_arrayElements>& array)
{

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex = startIndex;

		// Then look for a smaller element in the rest of the array
		for (int currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

class Timer3
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer3() : m_beg(clock_t::now())
	{
	}

	void reset3()
	{
		m_beg = clock_t::now();
	}

	double elapsed3() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void sortArray3(std::array<int, g_arrayElements>& array)
{

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex = startIndex;

		// Then look for a smaller element in the rest of the array
		for (int currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}
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

	Timer1 t;
	// Code to time goes here
	std::cout << "Time elapsed: " << t.elapsed1() << " seconds\n";

	/*That’s it! To use it,
	we instantiate a Timer object at the top of our main function
	(or wherever we want to start timing),
	and then call the elapsed() 
	member function whenever we want to know how long the program took 
	to run to that point.
	
	*/

	std::array<int, g_arrayElements> array2;
	for (int i = 0; i < g_arrayElements; ++i)
		array2[i] = g_arrayElements - i;

	Timer2 t2;
	sortArray2(array2);
	std::cout << "Time taken: " << t2.elapsed2() << " seconds\n";

	//////////////////////////////////////////////////////////////

	std::array<int, g_arrayElements> array3;
	for (int i = 0; i < g_arrayElements; ++i)
		array3[i] = g_arrayElements - i;

	Timer3 t3;
	std::sort(array3.begin(), array3.end());
	std::cout << "Time taken: " << t3.elapsed3() << " seconds\n";

	/*A few caveats about timing

	Timing is straightforward,
	but your results can be significantly impacted by a number of things, 
	and it’s important to be aware of what those things are.

	First, 
	make sure you’re using a release build target, not a debug build target.
	Debug build targets typically turn optimization off, 
	and that optimization can have a significant impact on the results.
	For example, using a debug build target, 
	running the above std::sort example on the author’s machine took 0.0235 seconds
	-- 33 times as long!

	Second, 
	your timing results will be influenced by other things your system 
	may be doing in the background. 
	For best results, make sure your system isn’t doing anything CPU or memory 
	intensive (e.g. playing a game) or hard drive intensive 
	(e.g. searching for a file or running an antivirus scan).

	Then measure at least 3 times. 
	If the results are all similar, 
	take the average. If one or two results are different, 
	run the program a few more times until you get a better sense 
	of which ones are outliers.
	Note that seemingly innocent things, 
	like web browsers, can temporarily spike your CPU to 100% utilization
	when the site you have sitting in the background rotates
	in a new ad banner and has to parse a bunch of javascript. 
	Running multiple times helps identify whether your initial run may 
	have been impacted by such an event.

	Third, when doing comparisons between two sets of code, 
	be wary of what may change between runs that could impact timing. 
	Your system may have kicked off an antivirus scan in the background, 
	or maybe you’re streaming music now when you weren’t previously. 
	Randomization can also impact timing.
	
	If we’d sorted an array filled with random numbers, 
	the results could have been impacted by the randomization.
	Randomization can still be used, but ensure you use a fixed seed 
	(e.g. don’t use the system clock)
	so the randomization is identical each run. 
	Also, make sure you’re not timing waiting for user input,
	as how long the user takes to input something should not be part of your 
	timing considerations.

	Finally, 
	note that results are only valid for your machine’s architecture,
	OS, compiler, and system specs.
	You may get different results on other systems that have different strengths
	and weaknesses.
	
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

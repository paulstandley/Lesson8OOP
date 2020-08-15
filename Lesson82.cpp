#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
#include <cstdint>
#include <cstddef>
#include <iostream>

class Something11
{
private:
    int m_value1;
    double m_value2;
    char m_value3;

public:
    Something11(int value1, double value2, char value3 = 'c')
        : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 } // directly initialize our member variables
    {
        // No need for assignment here
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }

};

void class_cpp_oop_85a()
{
    /*
    In the previous lesson, for simplicity,
    we initialized our class member data in the constructor
    using the assignment operator.

    When the class’s constructor is executed, m_value1, m_value2,
    and m_value3 are created.
    Then the body of the constructor is run,
    where the member data variables are assigned values.
    This is similar to the flow of the following code in non-object-oriented C++

     as you have learned in previous lessons, some types of data
     (e.g. const and reference variables)
     must be initialized on the line they are declared

     Assigning values to const or reference member variables
     in the body of the constructor is clearly not possible in some cases.

     ////////////////////////////////////////////////////////////////////////////

     Member initializer lists

    To solve this problem, C++ provides a method for initializing class
    member variables (rather than assigning values to them after they are created)
    via a member initializer list (often called a “member initialization list”).
    Do not confuse these with the similarly named initializer list
    that we can use to assign values to arrays.

    int value1 = 1; // copy initialization
    double value2(2.2); // direct initialization
    char value3 {'c'}; // uniform initialization

    Using an initialization list is almost identical to doing direct initialization
    or uniform initialization.

    This is something that is best learned by example.
    Revisiting our code that does assignments in the constructor body:

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;

    public:
        Something()
        {
            // These are all assignments, not initializations
            m_value1 = 1;
            m_value2 = 2.2;
            m_value3 = 'c';
        }
    };

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;

    public:
        Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' } // Initialize our member variables
        {
        // No need for assignment here
        }

        void print()
        {
            std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
        }
    };

    int main()
    {
        Something something{};
        something.print();
        return 0;
    }

    The member initializer list is inserted after the constructor parameters.
    It begins with a colon (:), and then lists each variable to initialize
    along with the value for that variable separated by a comma.

    Note that we no longer need to do the assignments in the constructor body,
    since the initializer list replaces that functionality.
    Also note that the initializer list does not end in a semicolon.

    */

    Something11 something11{ 1, 2.2 };
    // value1 = 1, value2=2.2, value3 gets default value 'c'
    something11.print();

    /*
    class Something
    {
    private:
        const int m_value;

    public:
        Something(): m_value{ 5 } // directly initialize our const member variable
        {
        }
    };

    This works because
    we’re allowed to initialize const variables
    (but not assign to them!).

    Rule

    Use member initializer lists to initialize your class member variables
    instead of assignment.

    Initializing array members with member initializer lists

    class Something
    {
    private:
        const int m_array[5];

    public:
        Something(): m_array {} // zero the member array
        {
        }
    };

    However, since C++11,
    you can fully initialize a member array using uniform initialization:

    class Something
    {
    private:
        const int m_array[5];
    public:
        Something(): m_array { 1, 2, 3, 4, 5 } // use uniform initialization to initialize our member array
        {
        }
    };

    /////////////////////////////////////////////////////////////////////////////

    Initializing member variables that are classes

    A member initialization list can also be used to initialize
    members that are classes.

    #include <iostream>

    class A
    {
    public:
        A(int x) { std::cout << "A " << x << '\n'; }
    };

    class B
    {
    private:
        A m_a;
    public:
        B(int y)
             : m_a{ y-1 } // call A(int) constructor to initialize member m_a
        {
            std::cout << "B " << y << '\n';
        }
    };

    int main()
    {
        B b{ 5 };
        return 0;
    }

    When variable b is constructed,
    the B(int) constructor is called with value 5.
    Before the body of the constructor executes,
    m_a is initialized, calling the A(int) constructor with value 4.
    This prints “A 4”.
    Then control returns back to the B constructor,
    and the body of the B constructor executes,
    printing “B 5”.

    /////////////////////////////////////////////////////////////////////

    Formatting your initializer lists

    C++ gives you a lot of flexibility in how to format your initializer lists,
    and it’s really up to you how you’d like to proceed.
    But here are some recommendations:

    If the initializer list fits on the same line as the function name,
    then it’s fine to put everything on one line

    If the initializer list doesn’t fit on the same line as the function name,
    then it should go indented on the next line.

    If all of the initializers don’t fit on a single line
    (or the initializers are non-trivial),
    then you can space them out, one per line:

    class Something
    {
    private:
        int m_value1;
        double m_value2;
        char m_value3;
        float m_value4;

    public:
        Something(int value1, double value2, char value3='c', float value4=34.6f) // this line already has a lot of stuff on it
            : m_value1{ value1 }, // one per line, commas at end of each line
            m_value2{ value2 },
            m_value3{ value3 },
            m_value4{ value4 }
        {
        }
    };

    ////////////////////////////////////////////////////////////////////////////////

    Initializer list order

    Perhaps surprisingly,
    variables in the initializer list are not initialized in the
    order that they are specified in the initializer list.
    Instead, they are initialized in the order in which they are
    declared in the class.

    For best results, the following recommendations should be observed:

    1) Don’t initialize member variables in such a way that they are dependent
    upon other member variables being initialized first
    (in other words, ensure your member variables will properly initialize
    even if the initialization ordering is different).

    2) Initialize variables in the initializer list in the same order in which they
    are declared in your class.
    This isn’t strictly required so long as the prior
    recommendation has been followed,
    but your compiler may give you a warning if you don’t
    do so and you have all warnings turned on.

    Summary

    Member initializer lists allow us to initialize our members rather
    than assign values to them.
    This is the only way to initialize members that require values upon initialization,
    such as const or reference members,
    and it can be more performant than assigning values in the body of the constructor.
    Member initializer lists work both with fundamental types and members that are
    classes themselves.

    */
}

class RGBA
{
public:
    // A type alias saves us some typing and makes the class easier to maintain
    using uif8 = std::uint8_t;
private:
    uif8 m_red;
    uif8 m_green;
    uif8 m_blue;
    uif8 m_alpha;
public:
    RGBA(uif8 red = 1, uif8 green = 1, uif8 blue = 1, uif8 alpha = 255)
        : m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
    {}
    void print()
    {
        std::cout << "Red = " << static_cast<int>(m_red) << " Green = " << static_cast<int>(m_green)
            << " Blue = " << static_cast<int>(m_blue) << " Alpha = " << static_cast<int>(m_alpha) << ".\n";
    };
};

//void class_cpp_oop_85b()
//{
    /*Non-static member initialization

    When writing a class that has multiple constructors (which is most of them),
    having to specify default values for all members in each constructor
    results in redundant code.
    If you update the default value for a member,
    you need to touch each constructor.

    Starting with C++11,
    it’s possible to give normal class member variables
    (those that don’t use the static keyword)
    a default initialization value directly

    Non-static member initialization
    (also called in-class member initializers)
    provides default values for your member variables that your
    constructors will use if the constructors do not provide initialization
    values for the members themselves (via the member initialization list).

    However, note that constructors still determine what
    kind of objects may be created.

    If a default initialization value is provided and the constructor initializes
    the member via the member initializer list,
    the member initializer list will take precedence.

    */

    /*
    Rectanglensmi xxxxx{ 2.0, 3.0 };
    xxxxx.print();

    Rectanglensmi yyyyy{ 4.0 };
    yyyyy.print();

    */

    /*Note that initializing members
    using non-static member initialization requires using either an equals sign,
    or a brace (uniform) initializer -- the direct initialization
    form doesn’t work here.

    Rule

    Favor use of non-static member initialization to give default values
    for your member variables.

    */
//}

class Employeeodc
{
private:
    int m_id{};
    std::string m_name{};

public:
    Employeeodc(int id = 0, const std::string& name = "") :
        m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a delegating constructor to minimize redundant code
    Employeeodc(const std::string& name) : Employeeodc{ 0, name }
    { }

    void print()
    {
        std::cout << m_id << " is the id of " << m_name << '\n';
    }

    /*
    This class has 2 constructors, one of which delegates to
    Employee(int, const std::string &).
    In this way, the amount of redundant code is minimized
    (we only have to write one constructor body instead of two).

    A few additional notes about delegating constructors.
    First, a constructor that delegates to another constructor
    is not allowed to do any member initialization itself.
    So your constructors can delegate or initialize, but not both.

    Second, it’s possible for one constructor to delegate to another constructor,
    which delegates back to the first constructor.
    This forms an infinite loop, and will cause your program to run out of
    stack space and crash.
    You can avoid this by ensuring all of your constructors resolve
    to a non-delegating constructor.
    */
};

void class_cpp_oop_86()
{
    /*
    Overlapping and delegating constructors

    Constructors with overlapping functionality

    When you instantiate a new object,
    the object’s constructor is called implicitly.
    It’s not uncommon to have a class with multiple constructors
    that have overlapping functionality.

    This class has two constructors: a default constructor,
    and a constructor that takes an integer.
    Because the “code to do A” portion of the constructor is required
    by both constructors, the code is duplicated in each constructor.

    As you’ve (hopefully) learned by now,
    having duplicate code is something to be avoided as much as possible.

    If you try to have one constructor call another constructor,
    it will compile and maybe cause a warning,
    but it will not work as you expect,
    and you will likely spend a long time trying to figure out why,
    even with a debugger.
    What’s happening is that Foo();
    instantiates a new Foo object,
    which is immediately discarded,
    because it’s not stored in a variable.

    Delegating constructors

    Constructors are allowed to call other constructors.
    This process is called delegating constructors (or constructor chaining).

    To have one constructor call another,
    simply call the constructor in the member initializer list.
    This is one case where calling another constructor directly is acceptable.

    class Foo
    {
    private:

    public:
        Foo()
        {
            // code to do A
        }

        Foo(int value): Foo{} // use Foo() default constructor to do A
        {
            // code to do B
        }

    };

    This works exactly as you’d expect.
    Make sure you’re calling the constructor from the member initializer list,
    not in the body of the constructor.

    Best practice

    If you have multiple constructors that have the same functionality,
    use delegating constructors to avoid duplicate code.

    //////////////////////////////////////////////////////////////////////////////

    Make sure you’re calling the constructor from the member initializer list,
    not in the body of the constructor.

    Relatedly,
    you may find yourself in the situation where you want to write
    a member function to re-initialize a class back to default values.
    Because you probably already have a constructor that does this,
    you may be tempted to try to call the constructor from your member function.

    However,
    trying to call a constructor directly will generally result
    in unexpected behavior.
    Many developers simply copy the code from the constructor
    into the initialization function,
    which would work, but lead to duplicate code.

    The best solution in this case is to move the code
    from the constructor to your new function,
    and have the constructor call your function
    to do the work of “initializing” the data:

    class Foo
    {
    public:
        Foo()
        {
            init();
        }

        Foo(int value)
        {
            init();
            // do something with value
        }

        void init()
        {
            // code to "initialize" Foo
        }
    };

    Constructors are allowed to call non-constructor functions in the class.
    Just be careful that any members the non-constructor function
    uses have already been initialized.
    Although you may be tempted to copy code from the first constructor
    into the second constructor,
    having duplicate code makes your class harder to understand
    and more burdensome to maintain.

    We say “initialize”, but it’s not real initialization.
    By the time the constructor calls init(),
    the members already exist and have been default
    initialized or are uninitialized.
    The init function can only assign values to the members.

    There are some types that cannot be instantiated without arguments,
    because they don’t have a default constructor.
    If any of the class members has such a type,
    the init function doesn’t work and the constructors
    have to initialize those members themselves.

    It is fairly common to include an init() function
    that initializes member variables to their default values,
    and then have each constructor call that init() function
    before doing its parameter-specific tasks.
    This minimizes code duplication and allows you to explicitly call init()
    from wherever you like.

    One small caveat: be careful when using init() functions
    and dynamically allocated memory.
    Because init() functions can be called by anyone at any time,
    dynamically allocated memory may or may not have
    already been allocated when init() is called.
    Be careful to handle this situation appropriately --
    it can be slightly confusing,
    since a non-null pointer could be either dynamically allocated memory
    or an uninitialized pointer!

    */
}

class IntArray
{
private:
    int* m_array{};
    int m_length{};

public:
    IntArray(int length) // constructor
    {
        assert(length > 0);

        m_array = new int[static_cast<std::size_t>(length)]{};
        m_length = length;
    }

    ~IntArray() // destructor
    {
        // Dynamically delete the array we allocated earlier
        delete[] m_array;
    }

    void setValue(int index, int value) { m_array[index] = value; }
    int getValue(int index) { return m_array[index]; }

    int getLength() { return m_length; }
};

class Simple
{
private:
    int m_nID{};

public:
    Simple(int nID)
        : m_nID{ nID }
    {
        std::cout << "Constructing Simple " << nID << '\n';
    }

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

void class_cpp_oop_87()
{
    /*
    Destructors

    A destructor is another special kind of class member function
    that is executed when an object of that class is destroyed.
    Whereas constructors are designed to initialize a class,
    destructors are designed to help clean up.

    When an object goes out of scope normally,
    or a dynamically allocated object is explicitly deleted using the delete keyword,
    the class destructor is automatically called (if it exists)
    to do any necessary clean up before the object is removed from memory.
    For simple classes (those that just initialize the values of normal member
    variables), a destructor is not needed because C++ will automatically clean up
    the memory for you.

    However, if your class object is holding any resources
    (e.g. dynamic memory, or a file or database handle),
    or if you need to do any kind of maintenance before the object is destroyed,
    the destructor is the perfect place to do so,
    as it is typically the last thing to happen before the object is destroyed.

    ////////////////////////////////////////////////////////////////////////////////

    Destructor naming

    Like constructors, destructors have specific naming rules:

    1) The destructor must have the same name as the class, preceded by a tilde (~).

    2) The destructor can not take arguments.

    3) The destructor has no return type.

    Note that rule 2 implies that only one destructor may exist per class,
    as there is no way to overload destructors since they can not be differentiated
    from each other based on arguments.

    Generally you should not call a destructor explicitly
    (as it will be called automatically when the object is destroyed),
    since there are rarely cases where you’d want to clean up an object more than once.
    However, destructors may safely call other member functions
    since the object isn’t destroyed until after the destructor executes.

    */

    IntArray ar(10); // allocate 10 integers
    for (int count{ 0 }; count < ar.getLength(); ++count)
        ar.setValue(count, count + 1);

    std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

    /*
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    On the first line, we instantiate a new IntArray class object called ar,
    and pass in a length of 10.
    This calls the constructor,
    which dynamically allocates memory for the array member.
    We must use dynamic allocation here because we do not know at compile time
    what the length of the array is (the caller decides that).

    At the end of main(), ar goes out of scope.
    This causes the ~IntArray() destructor to be called,
    which deletes the array that we allocated in the constructor!

    Constructor and destructor timing

    As mentioned previously, the constructor is called when an object is created,
    and the destructor is called when an object is destroyed.
    In the following example,
    we use cout statements inside the constructor and destructor.

    */

    // Allocate a Simple on the stack
    Simple simple{ 1 };
    std::cout << simple.getID() << '\n';

    // Allocate a Simple dynamically
    Simple* pSimple{ new Simple{ 2 } };

    std::cout << pSimple->getID() << '\n';

    // We allocated pSimple dynamically, so we have to delete it.
    delete pSimple;

    /*Note that “Simple 1” is destroyed after “Simple 2”
    because we deleted pSimple before the end of the function,
    whereas simple was not destroyed until the end of main().

    Global variables are constructed before main() and destroyed after main().

    ////////////////////////////////////////////////////////////////////////////

    RAII

    RAII (Resource Acquisition Is Initialization)
    is a programming technique whereby resource use is tied to the lifetime of objects
    with automatic duration (e.g. non-dynamically allocated objects).
    In C++, RAII is implemented via classes with constructors and destructors.
    A resource (such as memory, a file or database handle, etc…)
    is typically acquired in the object’s constructor
    (though it can be acquired after the object is created if that makes sense).

    That resource can then be used while the object is alive.
    The resource is released in the destructor,
    when the object is destroyed.
    The primary advantage of RAII is that it helps prevent resource leaks
    (e.g. memory not being deallocated)
    as all resource-holding objects are cleaned up automatically.

    The IntArray class at the top of this lesson is an example
    of a class that implements RAII -- allocation in the constructor,
    deallocation in the destructor.
    std::string and std::vector are examples of classes in the standard library
    that follow RAII -- dynamic memory is acquired on initialization,
    and cleaned up automatically on destruction.

    A warning about the exit() function

    Note that if you use the exit() function,
    your program will terminate and no destructors will be called.
    Be wary if you’re relying on your destructors to do necessary cleanup work
    (e.g. write something to a log file or database before exiting).

    Summary

    As you can see, when constructors and destructors are used together,
    your classes can initialize and clean up after themselves without the programmer
    having to do any special work!
    This reduces the probability of making an error,
    and makes classes easier to use.

    */

} // simple goes out of scope here

class CalcFuncCha
{
private:
    int m_value;

public:
    CalcFuncCha() { m_value = 0; }

    CalcFuncCha& add(int value) { m_value += value; return *this; }
    CalcFuncCha& sub(int value) { m_value -= value; return *this; }
    CalcFuncCha& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }
};

void class_cpp_oop_88()
{
    /* The hidden “this” pointer

    One of the questions about classes that new object-oriented programmers
    often ask is, “When a member function is called,
    how does C++ keep track of which object it was called on?”.
    The answer is that C++ utilizes a hidden pointer named “this”!
    Let’s take a look at “this” in more detail.

    The following is a simple class that holds an integer and provides a
    constructor and access functions.
    Note that no destructor is needed because C++ can clean up integer
    member variables for us.

    class Simple
    {
    private:
        int m_id;
    public:
        Simple(int id)
        {
            setID(id);
        }
        void setID(int id) { m_id = id; }
        int getID() { return m_id; }
    };

    int main()
    {
        Simple simple(1);
        simple.setID(2);
        std::cout << simple.getID() << '\n';

        return 0;
    }

    As you would expect, this program produces the result: 2

    Somehow, when we call simple.setID(2);,
    C++ knows that function setID() should operate on object simple,
    and that m_id actually refers to simple.m_id.
    Let’s examine the mechanics behind how this works.

    ////////////////////////////////////////////////////////////

    The hidden *this pointer

    Take a look at the following line of code from the example above:

    simple.setID(2);

    Although the call to function setID() looks like it only has one argument,
    it actually has two! When compiled,
    the compiler converts simple.setID(2);
    into the following:

    setID(&simple, 2);

    note that simple has been changed from an object prefix to a function argument!

    Note that this is now just a standard function call,
    and the object simple (which was formerly an object prefix)
    is now passed by address as an argument to the function.

    But that’s only half of the answer.
    Since the function call now has an added argument,
    the member function definition needs to be modified to accept (and use)
    this argument as a parameter.

    Consequently, the following member function:

    void setID(int id) { m_id = id; }

    is converted by the compiler into:

    void setID(Simple* const this, int id) { this->m_id = id; }

    When the compiler compiles a normal member function,
    it implicitly adds a new parameter to the function named “this”.
    The this pointer is a hidden const pointer that holds the
    address of the object the member function was called on.

    There’s just one more detail to take care of.
    Inside the member function, any class members (functions and variables)
    also need to be updated so they refer to the object the member function
    was called on.
    This is easily done by adding a “this->” prefix to each of them.
    Thus, in the body of function setID(), m_id (which is a class member variable)
    has been converted to this->m_id. Thus,
    when “this” points to the address of simple,
    this->m_id will resolve to simple.m_id.

    Putting it all together:

    1) When we call simple.setID(2), the compiler actually calls setID(&simple, 2).

    2) Inside setID(), the “this” pointer holds the address of object simple.

    3) Any member variables inside setID() are prefixed with “this->”.
    So when we say m_id = id, the compiler is actually executing this->m_id = id,
    which in this case updates simple.m_id to id.

    The good news is that all of this happens automatically,
    and it doesn’t really matter whether you remember how it works or not.
    All you need to remember is that all normal member functions have a “this” pointer
    that refers to the object the function was called on.

    /////////////////////////////////////////////////////////////////////////////////

    “this” always points to the object being operated on

    New programmers are sometimes confused about how many “this” pointers exist.
    Each member function has a “this” pointer parameter that is set to the address
    of the object being operated on.
    Consider:

    Simple A(1); // this = &A inside the Simple constructor
    Simple B(2); // this = &B inside the Simple constructor
    A.setID(3); // this = &A inside member function setID
    B.setID(4); // this = &B inside member function setID

    Note that the “this” pointer alternately holds the address of object A or B
    depending on whether we’ve called a member function on object A or B.

    Because “this” is just a function parameter,
    it doesn’t add any memory usage to your class
    (just to the member function call, since that parameter
    needs to be passed to the function and stored in memory).

    Explicitly referencing “this”

    Most of the time, you never need to explicitly reference the “this” pointer.
    However, there are a few occasions where doing so can be useful:

    First, if you have a constructor (or member function)
    that has a parameter with the same name as a member variable,
    you can disambiguate them by using “this”

    class Something
    {
    private:
        int data;

    public:
        Something(int data)
        {
            this->data = data;
            // this->data is the member, data is the local parameter
        }
    };

    #Note that our constructor is taking a parameter of the same name
    as a member variable.
    In this case, “data” refers to the parameter,
    and “this->data” refers to the member variable.
    Although this is acceptable coding practice,
    we find using the “m_” prefix on all member variable names
    provides a better solution by preventing duplicate names altogether!

    Some developers prefer to explicitly add this-> to all class members.
    We recommend that you avoid doing so,
    as it tends to make your code less readable for little benefit.
    Using the m_ prefix is a more readable way to differentiate member variables
    from non-member (local) variables.

    Recommendation: Do not add this-> to all uses of your class members.
    Only do so when you have a specific reason to.

    //////////////////////////////////////////////////////////////////////

    Chaining member functions

    Second,
    it can sometimes be useful to have a class member function return
    the object it was working with as a return value.
    The primary reason to do this is to allow a series of member functions
    to be “chained” together,
    so several member functions can be called on the same object!
    You’ve actually been doing this for a long time.
    Consider this common example where you’re outputting
    more than one bit of text using std::cout:

    std::cout << "Hello, " << userName;

    In this case, std::cout is an object,
    and operator << is a member function that operates on that object.
    The compiler evaluates the above snippet like this:

    (std::cout << "Hello, ") << userName;

    First,
    operator << uses std::cout and the string literal
    “Hello, ” to print “Hello, ” to the console.
    However, since this is part of an expression,
    operator << also needs to return a value (or void).
    If operator << returned void, you’d end up with this:

    (void) << userName;

    which clearly doesn’t make any sense (and the compiler would throw an error).
    Instead, operator << returns *this, which in this context is the std::cout object.
    That way, after the first operator << has been evaluated, we get:

    (std::cout) << userName;

    In this way,
    we only need to specify the object (in this case, std::cout) once,
    and each function call passes it on to the next function to work with,
    allowing us to chain multiple commands together.

    We can implement this kind of behavior ourselves. Consider the following class:

    class Calc
    {
    private:
        int m_value;
    public:
        Calc() { m_value = 0; }
        void add(int value) { m_value += value; }
        void sub(int value) { m_value -= value; }
        void mult(int value) { m_value *= value; }
        int getValue() { return m_value; }
    };

    If you wanted to add 5, subtract 3, and multiply by 4, you’d have to do this:

    #include <iostream>
    int main()
    {
        Calc calc;
        calc.add(5); // returns void
        calc.sub(3); // returns void
        calc.mult(4); // returns void
        std::cout << calc.getValue() << '\n';
        return 0;
    }

    However, if we make each function return *this,
    we can chain the calls together.
    Here is the new version of Calc with “chainable” functions:

    class Calc
    {
    private:
        int m_value;
    public:
        Calc() { m_value = 0;
        Calc& add(int value) { m_value += value; return *this; }
        Calc& sub(int value) { m_value -= value; return *this; }
        Calc& mult(int value) { m_value *= value; return *this; }
        int getValue() { return m_value; }
    };

    Note that add(), sub() and mult() are now returning *this.
    Consequently, this allows us to do the following:

    #include <iostream>
    int main()
    {
        Calc calc;
        calc.add(5).sub(3).mult(4);
        std::cout << calc.getValue() << '\n';
        return 0;
    }

    */

    CalcFuncCha calcfc;
    calcfc.add(5).sub(3).mult(4);

    std::cout << calcfc.getValue() << '\n';

    /*We have effectively condensed three lines into one expression!
    Let’s take a closer look at how this works.

    First, calc.add(5) is called, which adds 5 to our m_value. add()
    then returns *this, which is just a reference to calc,
    so calc will be the object used in the subsequent evaluation.

    Next calc.sub(3) evaluates, which subtracts 3 from m_value
    and again returns calc.

    Finally, calc.mult(4) multiplies m_value by 4 and returns calc,
    which isn’t used further, and is thus ignored.

    Since each function modified calc as it was executed,
    calc’s m_value now contains the value (((0 + 5) - 3) * 4), which is 8.

    Summary

    The “this” pointer is a hidden parameter implicitly
    added to any non-static member function.
    Most of the time, you will not need to access it directly,
    but you can if needed.

    It’s worth noting that “this” is a const pointer --
    you can change the value of the underlying object it points to,
    but you can not make it point to something else!

    By having functions that would otherwise return
    void return *this instead,
    you can make those functions chainable.

    This is most often used when overloading operators for your classes

    */
}




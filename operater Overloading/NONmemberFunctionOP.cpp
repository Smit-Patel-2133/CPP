// C++ program to show binary
// operator overloading using
// a Friend Function
#include <iostream>
using namespace std;

class Distance
{
public:
    int feet, inch;

    Distance()
    {
        this->feet = 0;
        this->inch = 0;
    }

    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }

    // Declaring friend function
    // using friend keyword
    friend Distance operator+(Distance &,
                              Distance &);
};

// Implementing friend function
// with two parameters
// Call by reference
Distance operator+(Distance &d1,
                   Distance &d2)
{
    // Create an object to return
    Distance d3;

    d3.feet = d1.feet + d2.feet;
    d3.inch = d1.inch + d2.inch;

    // Return the resulting object
    return d3;
}

// Driver Code
int main()
{
    Distance d1(8, 9);
    Distance d2(10, 2);
    Distance d3;

    // Use overloaded operator
    d3 = d1 + d2;

    cout << "\nTotal Feet & Inches: " << d3.feet << "'" << d3.inch;
    return 0;
}

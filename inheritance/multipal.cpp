#include <iostream>
using namespace std;
class Animal
{
public:
    Animal(int a)
    {
        cout << "this is animal class"
             << "\t" << a << endl;
    }
};
class cat
{

public:
    cat() {}
    cat(int b)
    {
        cout << "this is cat Class"
             << "\t" << b << endl;
    }
};
class dog : public Animal, public cat
{
public:
    dog(int a, int b, int c) : Animal(a), cat(b)
    {
        cout << "this is dog Class"
             << "\t" << c << endl;
    }
};
int main(int argc, char const *argv[])
{
    dog d1(10, 20, 30);
    return 0;
}

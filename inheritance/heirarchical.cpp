#include <iostream>
using namespace std;
class Animal
{
public:
    Animal(string a)
    {
        cout << "Who is calling animal"
             << "\t" << a << endl;
    }
};
class cat : public Animal
{

public:
    cat(string a, int b):Animal(a)
    {
        cout << "this is cat Class"
             << "\t" << b << endl;
    }
};
class dog : public Animal
{
public:
    dog(string a, int c) : Animal(a)
    {
        cout << "this is dog Class"
             << "\t" << c << endl;
    }
};
int main(int argc, char const *argv[])
{
    dog d1("dog", 20);
    cat c1("cat", 20);
    return 0;
}

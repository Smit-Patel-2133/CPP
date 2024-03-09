#include <iostream>
using namespace std;
class Animal
{
public:
    Animal()
    {
        cout << "this is animal class" << endl;
    }
};
class cat : public Animal
{
private:
    /* data */
public:
    cat()
    {
        cout << "this is cat Class" << endl;
    }
};
class dog : public cat
{
private:
    /* data */
public:
    dog()
    {
        cout << "this is dog Class" << endl;
    }
};
int main(int argc, char const *argv[])
{
    dog d1;
    return 0;
}

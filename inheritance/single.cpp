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
int main(int argc, char const *argv[])
{
    cat c;
    return 0;
}

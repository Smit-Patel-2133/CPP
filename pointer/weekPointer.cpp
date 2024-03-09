
#include <iostream>
#include <memory>
using namespace std;
class MyClass
{
public:
    MyClass(/*int *x*/)
    {
        // *x = 50;
        // cout << x << endl;
        cout << "constructor is called" << endl;
    }
    ~MyClass()
    {
        cout << "Destructor is called" << endl;
    }
};
int main()
{
    weak_ptr<int> weakptr1;

    {
        shared_ptr<int> shptr2 = make_shared<int>(29);
        weakptr1 = shptr2;
        cout << "Shard pointer:" << *shptr2 << endl;
    }
    // weak pointer will not hold the value 29

    return 0;
}

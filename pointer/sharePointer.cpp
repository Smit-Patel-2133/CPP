
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
    int a = 20;
    cout << "a:" << a << endl;
    shared_ptr<MyClass> shptr1 = make_shared<MyClass>(/*&a*/);
    cout << "Shared count:" << shptr1.use_count() << endl;
    // cout << "a:" << a << endl;
    {
        shared_ptr<MyClass> shptr2 = shptr1;
        cout << "Shared count:" << shptr1.use_count() << endl;
    }
    cout << "Shared count:" << shptr1.use_count() << endl;
    // cout << "shptr1=" << shptr1 << endl;
    // cout << "shptr2=" << shptr2 << endl;
    return 0;
}

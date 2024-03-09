// #include <iostream>
// #include <memory>
// using namespace std;
// int main()
// {
//     int a = 30;
//     unique_ptr<int> ptr1 = make_unique<int>(a);

//     unique_ptr<int> ptr2 = move(ptr1); // move the ownership of the ptr1 to ptr2
//     // cout << *ptr1 << endl;
//     cout << *ptr2 << endl;
//     // cout << ptr1 << endl; //error
//     return 0;
// }

#include <iostream>
#include <memory>
using namespace std;
class MyClass
{
public:
    MyClass()
    {
        cout << "constructor is called" << endl;
    }
    ~MyClass()
    {
        cout << "Destructor is called" << endl;
    }
};
int main()
{
    unique_ptr<MyClass> unptr1 = make_unique<MyClass>();
    // system("pause>nul"); // only the constructor is called  // destructor is called when the program is over or the scope of the unptr1 is over when the program is stop the execution
    return 0; // destructor is also called
}

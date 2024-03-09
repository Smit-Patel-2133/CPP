#include <iostream>
using namespace std;
int main()
{
    int n = 20;
    cout << "n=" << n << endl;
    cout << "address of n=" << &n << endl;
    int *p = &n;
    cout << "address of the variable the pointer hold=" << p << endl;
    cout << "Address pointer=" << &p << endl;
    cout << "Value of the variable that pointer hold =" << *p << endl;
    *p = 10;
    cout << "changing the value of the n using pointer= " << n << endl;

    delete p;

    int a = 20;
    cout << a;
    return 0;
}

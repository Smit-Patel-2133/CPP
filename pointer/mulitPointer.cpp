#include <iostream>
using namespace std;
int main()
{
    int n = 20;
    cout << "n=" << n << endl;
    cout << "address of n=" << &n << endl;
    int *p = &n;
    int *s = &n;
    cout << "address of the variable the pointer p hold=" << p << endl;
    cout << "address of the variable the pointer s hold=" << s << endl;

    *p = 10;
    cout << "value changed by pointer p=" << *p << endl;
    cout << "value of n" << n << endl;

    *s = 40;
    cout << "value changed by pointer s=" << *s << endl;
    cout << "value of n" << n << endl;

    return 0;
}

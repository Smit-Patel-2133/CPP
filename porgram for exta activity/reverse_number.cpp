#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "enter the number :";
    cin >> a;
    cout << endl
         << a;
    int b = 0, lastdigit;

    while (a != 0)
    {
        lastdigit = a % 10;
        b = b * 10 + lastdigit;
        a = a / 10;
    }
    cout << endl
         << "b::" << b;
}
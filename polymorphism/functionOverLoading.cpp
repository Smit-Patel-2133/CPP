#include <iostream>
using namespace std;
class hello
{
public:
    void sayhello(int a)
    {
        cout << "hello from int :\t" << a << endl;
    }
    void sayhello(string b)
    {
        cout << "hello from :\t" << b << endl;
    }
};

int main()
{
    hello a1;
    a1.sayhello(10);
    a1.sayhello("smit");
    return 0;
}

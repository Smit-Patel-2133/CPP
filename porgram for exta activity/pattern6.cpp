#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int count = 1;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        int space = 2 * N - 2 * i;
        for (int j = 0; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = N; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        int space = 2 * N - 2 * i;
        for (int j = 0; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
// *           *
// **         **
// ***       ***
// ****     ****
// *****   *****
// ****** ******
// ****** ******
// *****   *****
// ****     ****
// ***       ***
// **         **
// *           *
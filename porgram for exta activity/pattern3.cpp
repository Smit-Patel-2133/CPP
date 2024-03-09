#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int b;
    cin>>b;
    for (int i = 0; i <=a; i++)
    {
        for (int j = 0; j <=b ; j++)
        {
            if (i==0 ||i==a)
            {
                /* code */cout<<"*";
            }
            else if (j==0||j==b)
            {
                /* code */cout<<"*";
            }
            else{
                cout<<" ";
            }
            
            
        }
        cout << endl;
    }
}
// *****
// *   *
// *   *
// *   *
// *****
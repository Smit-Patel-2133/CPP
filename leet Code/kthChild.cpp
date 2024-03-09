#include <iostream>
#include <string>
using namespace std;
std::string kthChildNthGeneration(int n, long long int k)
{
    if (n == 1)
    {
        return (k == 1) ? "Male" : "Female";
    }

    long long int size = 1LL << (n - 1);
    cout << "size" << size << endl;
    if (k <= size)
    {
        return kthChildNthGeneration(n - 1, k);
    }
    else
    {
        return (kthChildNthGeneration(n - 1, k - size) == "Male") ? "Female" : "Male";
    }
}

int main()
{
    int t;
    // std::cin >> t;
    int n = 5;
    long long int size = 1LL << (n - 1);
    cout << 1LL;
    // while (t--)
    // {
    //     int n;
    //     long long int k;
    //     cout<<"enter the chile and node"<<endl;
    //     std::cin >> n >> k;

    //     std::string result = kthChildNthGeneration(n, k);
    //     std::cout << result << std::endl;
    // }

    return 0;
}

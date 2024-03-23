#include <iostream>
using namespace std;

class Solution
{
public:
    int GCD(int a, int b)
    {
        while (a % b != 0)
        {
            int rem = a % b;
            cout<<rem<<endl;
            a = b;
            b = rem;
        }
        return b;
    }

    string gcdOfStrings(string str1, string str2)
    {
        string x = str1 + str2;
        string y = str2 + str1;
        if (x.compare(y) == 0)
        {
            int a = str1.length();
            int b = str2.length();
            int gcd = GCD(a, b);
            return str1.substr(0, gcd);
        }
        else
        {
            return "";
        }
    }
};

int main()
{
    Solution solution;

    // Test cases
    string str1 = "ABABAB";
    string str2 = "ABAB";

    cout << "GCD of strings: " << solution.gcdOfStrings(str1, str2) << endl;

    return 0;
}

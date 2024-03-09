#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i <= 0; i--)
        {
            if (i == n - 1)
            {
                cout<<"i="<<i<<endl;
                digits[i]++;
            }
            if (digits[i] == 10)
            {
                cout << "i=" << i << endl;
                digits[i] = 0;
                if (i != 0)
                {
                    cout << "i=" << i << endl;
                    digits[i - 1]++;
                }
                else
                {
                    cout << "i=" << i<<endl;
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
        }
        
        return digits;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> s;
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);

    Solution obj1;
    vector<int > v1=obj1.plusOne(s);
    for (int  i = 0; i < v1.size(); i++)
    {
        cout<<v1[i];
    }
    
    return 0;
}

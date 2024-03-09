#include<iostream>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans = "";
        int i = 0;
        while (i < word1.length() || i < word2.length())
        {
            if (i < word1.length())
            {
                ans += word1[i];
            }
            if (i < word2.length())
            {
                ans += word2[i];
            }
            i++;
        }
        return ans;
    }
};

int main(){
    Solution s1;
    string s2=s1.mergeAlternately("smit","patel");
    cout<<s2;
    return 0;
}
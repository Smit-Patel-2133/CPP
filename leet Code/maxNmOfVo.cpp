#include <unordered_set>
#include <algorithm> // For std::max
#include <string>    // For std::string
#include <iostream>

using namespace std; // Adding this line to use std namespace

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        // Set of vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int currentMax = 0;
        int finalMax = 0;

        // Initial calculation for the first window of size k
        for (int i = 0; i < k; ++i)
        {
            if (vowels.count(s[i]))
            {
                currentMax++;
            }
        }

        // Sliding window approach
        for (int i = k; i < s.length(); ++i)
        {
            if (vowels.count(s[i]))
            {
                currentMax++;
            }

            if (vowels.count(s[i - k]))
            {
                currentMax--;
            }

            // Early return if k vowels are found
            if (currentMax == k)
            {
                return k;
            }

            finalMax = max(finalMax, currentMax);
        }

        return finalMax;
    }
};

int main(int argc, char const *argv[])
{
    int ans;
    Solution s1= Solution();
    ans=s1.maxVowels("smitnarendrabhaipatel",20);
    cout << ans;
    return 0;
}

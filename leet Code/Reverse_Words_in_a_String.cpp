#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        istringstream is(s);
        vector<string> words;
        while (is >> s)
        {
            words.push_back(s);
        }
        string out = "";
        for (int i = words.size() - 1; i > 0; --i)
        {
            out += words[i] + " ";
        }
        return out + words[0];
    }
};

int main()
{
    Solution solution;
    string input = "  Hello World   ";
    string result = solution.reverseWords(input);
    cout << result << endl;

    return 0;
}

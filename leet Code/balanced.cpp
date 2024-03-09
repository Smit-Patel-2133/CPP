#include <iostream>
#include <stack>

using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;

    for (auto &ch : s)
    {
        if (ch == ')' || ch == '}' || ch == ']')
        {
            char top = st.top();
            st.pop();
            char opch;

            if (ch == ')')
            {
                opch = '(';
            }
            else if (ch == ']')
            {
                opch = '[';
            }
            else if (ch == '}')
            {
                opch = '{';
            }

            bool balanced = false;
            while (top != opch && !st.empty())
            {
                top = st.top();
                st.pop();
            }

            if (top == opch)
            {
                balanced = true;
            }

            if (!balanced)
            {
                return false; // Parentheses are not balanced
            }
        }
        else
        {
            st.push(ch);
        }
    }

    return st.empty(); // Check if there are any remaining unmatched opening parentheses
}

int main()
{
    string expression1 = "{[()]}";
    string expression2 = "{[(])}";

    cout << isValidParenthesis(expression1) << endl; // Output: 1 (true)
    cout << isValidParenthesis(expression2) << endl; // Output: 0 (false)

    return 0;
}

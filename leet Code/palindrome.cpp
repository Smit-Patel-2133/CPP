#include <iostream>
using namespace std;

bool isPalindrome(int x)
{

    string s = to_string(x);
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        temp = temp + to_string(x % 10);
        x = x / 10;
    }
    if (temp==s){
        return true;
    }
    else{
        return false;
    }

        return 0;
}
int main()
{
    int x = 101;
    isPalindrome(x);
}

#include <iostream>
#include <set>
#include<vector>
int main()
{
    vector<int> v;
    v.push_back(1);
    std::set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');
    for (auto &str : a)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';
    return 0;
}

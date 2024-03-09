#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {3, 7, 2, 5, 7, 3, 8, 1, 2};
    int size = v1.size(), element;
    // cout << "enter size of vector:-";
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << i << ":";
    //     cin >> element;
    //     v1.push_back(element);
    // }
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (v1[i] > v1[j])
            {
                temp = v1[i];
                v1[i] = v1[j];
                v1[j] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (v1[i] == v1[j])
            {
                v1.erase(v1.begin() + j - 1, v1.begin() + j);
                size = v1.size();
                j--;
            }
        }
    }
    size = v1.size();
    for (int i = 0; i < size; i++)
    {

        cout << "element :-" << v1[i];
    }
}
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;
    int size, element;
    cout << "enter size of vector:-";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << i << ":";
        cin >> element;
        v1.push_back(element);
    }
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
        cout << "element" << i + 1 << ":" << v1[i]<<endl;
    }
}
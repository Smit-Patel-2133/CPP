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
    for (int i = 0;i<v1.size();i++){
        cout<<"element"<<i<<":"<<v1[i]<<endl;
    }
    int sum=0;
    for (int i = 0; i < v1.size(); i++)
    {
       sum=sum+v1[i];
    }
    cout<<"sum of the vector element is:"<<sum;
}

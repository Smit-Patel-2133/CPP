// 26 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   vector<int> sortedVector = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    auto last = unique(sortedVector.begin(), sortedVector.end());
    sortedVector.erase(last, sortedVector.end());
    cout << "Vector without duplicates: ";
    for (int num : sortedVector)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

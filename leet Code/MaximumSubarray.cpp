#include <iostream>
using namespace std;
#include <vector>
int main(int argc, char const *argv[])
{

    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    int maxSum = INT8_MIN;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }

        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
cout<<maxSum;
    return 0;
}

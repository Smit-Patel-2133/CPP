#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == target - nums[i])
                {
                    cout << "num1=" << nums[i] << endl
                         << "num=" << nums[j];
                    return {i, j};
                }
            }
        }
        return {};
    }
};
int main()
{
    int target = 9;
    vector<int> num = {2, 3, 4, 1, 5};
    Solution obj1;
     obj1.twoSum(num, target);
    
    return 0;
}


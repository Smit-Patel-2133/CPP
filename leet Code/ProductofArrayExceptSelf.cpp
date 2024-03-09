#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> result(n, 1);

        int leftProduct = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] *= leftProduct;
            leftProduct *= nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            /* code */
            cout << result[i] << endl;
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
            cout << "rightProduct:-" << rightProduct << endl
                 << "result:-" << result[i] << endl;
        }
        for (int i = 0; i < n; i++)
        {
            /* code */
            cout << result[i] << endl;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {-1, 1, 0, -3, 3};

    std::vector<int> result = solution.productExceptSelf(nums);

    std::cout << "Input Array: [";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i];
        if (i < nums.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    std::cout << "Result Array: [";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i];
        if (i < result.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    return 0;
}

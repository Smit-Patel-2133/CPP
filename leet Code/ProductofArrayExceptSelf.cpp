#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftProducts(n, 1);
        vector<int> rightProducts(n, 1);
        vector<int> answer(n, 1);

        int leftProduct = 1;
        for (int i = 1; i < n; ++i)
        {
            leftProduct *= nums[i - 1];
            leftProducts[i] = leftProduct;
        }

        int rightProduct = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            rightProduct *= nums[i + 1];
            rightProducts[i] = rightProduct;
        }

        for (int i = 0; i < n; ++i)
        {
            answer[i] = leftProducts[i] * rightProducts[i];
        }

        return answer;
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

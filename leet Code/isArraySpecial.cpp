#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> prefixMismatch(n, 0);

        // Step 1: Create prefixMismatch array to store parity mismatches
        for (int i = 1; i < n; ++i)
        {
            prefixMismatch[i] = prefixMismatch[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2)
            {
                prefixMismatch[i]++;
            }
        }

        vector<bool> results;
        for (const auto &query : queries)
        {
            int start = query[0];
            int end = query[1];
            if (start == end)
            {
                results.push_back(true);
                continue;
            }
            int mismatches = prefixMismatch[end] - prefixMismatch[start];
            results.push_back(mismatches == 0);
        }
        return results;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> queries = {{0, 1}, {1, 3}, {2, 4}, {0, 4}};
    vector<bool> results = sol.isArraySpecial(nums, queries);

    for (bool result : results)
    {
        // Output results
        if (result)
        {
            printf("Special\n");
        }
        else
        {
            printf("Not Special\n");
        }
    }
    return 0;
}


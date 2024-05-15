#include <iostream>
#include <vector>
#include <algorithm> // for max

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0; // Left pointer of the window
        int zeros = 0; // Number of zeros encountered in the current window
        int ans = 0; // Maximum length of consecutive ones

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                ++zeros;
            }

            // Shrink the window if zeros exceed k
            while (zeros > k) {
                if (nums[left] == 0) {
                    --zeros;
                }
                ++left;
            }

            // Update the answer with the length of the current window
            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    // Example usage
    std::vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    Solution sol;
    std::cout << "Example 1: " << sol.longestOnes(nums1, k1) << std::endl;

    std::vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    std::cout << "Example 2: " << sol.longestOnes(nums2, k2) << std::endl;

    return 0;
}

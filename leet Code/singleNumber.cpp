#include <vector>
#include <iostream>
#include "solution.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single_number = 0;
        for (int num : nums) {
            single_number ^= num;
        }
        return single_number;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {2, 2, 1};
    cout << "Single number in {2, 2, 1} is: " << solution.singleNumber(nums1) << endl;

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Single number in {4, 1, 2, 1, 2} is: " << solution.singleNumber(nums2) << endl;

    vector<int> nums3 = {1};
    cout << "Single number in {1} is: " << solution.singleNumber(nums3) << endl;

    return 0;
}

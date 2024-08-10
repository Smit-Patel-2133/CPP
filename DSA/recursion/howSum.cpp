#include <iostream>
#include <vector>
using namespace std;

vector<int> howSum(int target, vector<int> nums) {
    if (target == 0) return {};
    if (target < 0) return {};

    for (int i : nums) {
        int remainder = target - i;
        vector<int> result = howSum(remainder, nums);
        if (!result.empty() || remainder == 0) {
            result.push_back(i);
            return result;
        }
    }
    return {};
}

int main() {
    vector<int> values = {5, 2, 4, 3};
    int target = 5;

    vector<int> ans = howSum(target, values);

    if (ans.empty()) {
        cout << "No combination found." << endl;
    } else {
        for (int i : ans) {
            cout << i << " ";
        }
    }

    return 0;
}

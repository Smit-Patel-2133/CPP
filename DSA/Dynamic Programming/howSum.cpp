//time : O(n*m^2)
//space : O(m^2)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> howSum(int target, vector<int> nums,unordered_map<int,vector<int>> &memo) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == 0) return {};
    if (target < 0) return {};

    for (int i : nums) {
        int remainder = target - i;
        vector<int> result = howSum(remainder, nums,memo);
        if (!result.empty() || remainder == 0) {
            result.push_back(i);
            memo[target] = result;
            return result;
        }
    }
    memo[target] = {};
    return {};
}

int main() {
    vector<int> values = {7,14};
    int target = 300;
    unordered_map<int,vector<int>> memo;
    vector<int> ans = howSum(target, values,memo);

    if (ans.empty()) {
        cout << "No combination found." << endl;
    } else {
        for (int i : ans) {
            cout << i << " ";
        }
    }

    return 0;
}

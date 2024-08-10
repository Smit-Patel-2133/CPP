#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canSum(int t, vector<int> &vt, unordered_map<int, bool> &memo) {
    if (t == 0) return true;
    if (t < 0) return false;
    if (memo.count(t)) {
        return memo[t];
    }
    for (int i : vt) {
        int remainder = t - i;
        if (canSum(remainder, vt, memo)) {
            memo[t] = true;
            return true;
        }
    }
    memo[t] = false;
    return false;
}

int main() {
    vector<int> vt{3, 4};
    int target = 56;
    unordered_map<int, bool> memo;
    cout << (canSum(target, vt, memo) ? "True" : "False") << endl;
}

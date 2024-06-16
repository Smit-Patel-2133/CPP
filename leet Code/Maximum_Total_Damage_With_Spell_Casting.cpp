#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int& damage, int loc, const std::vector<int>& power, std::vector<bool>& visited, int& maxi) {
        visited[loc] = true;
        damage += power[loc];
        maxi = std::max(maxi, damage);

        for (int i = 0; i < power.size(); i++) {
            if (!visited[i] && (power[loc] + 1 != power[i] && power[loc] + 2 != power[i] && power[loc] - 1 != power[i] && power[loc] - 2 != power[i])) {
                backtrack(damage, i, power, visited, maxi);
            }
        }

        // Backtrack: Undo changes
        visited[loc] = false;
        damage -= power[loc];
    }

    long long maximumTotalDamage(std::vector<int>& power) {
        int maxi = 0;
        for (int i = 0; i < power.size(); i++) {
            int damage = 0;
            std::vector<bool> visited(power.size(), false);
            backtrack(damage, i, power, visited, maxi);
        }

        return maxi;
    }
};

int main() {
    std::vector<int> power = {1, 1, 3, 4};
    Solution solution;
    long long maxDamage = solution.maximumTotalDamage(power);
    std::cout << "Maximum total damage: " << maxDamage << std::endl;

    return 0;
}

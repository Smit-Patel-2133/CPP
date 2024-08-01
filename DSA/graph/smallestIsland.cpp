#include <vector>
#include <iostream>
#include <algorithm> // For std::min

using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col, int& size) {
        // Boundary checks
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1' || visited[row][col]) {
            return;
        }

        // Mark the current cell as visited and increment the island size
        visited[row][col] = true;
        size++;

        // Visit all four neighboring cells
        DFS(grid, visited, row + 1, col, size);
        DFS(grid, visited, row - 1, col, size);
        DFS(grid, visited, row, col + 1, size);
        DFS(grid, visited, row, col - 1, size);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int land = 0;
        int minSize = INT_MAX; // Initialize to a large value

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (!visited[r][c] && grid[r][c] == '1') {
                    land++;
                    int size = 0;
                    DFS(grid, visited, r, c, size);
                    if (size > 0) {
                        minSize = min(minSize, size);
                    }
                }
            }
        }

        return minSize == INT_MAX ? 0 : minSize; // Return 0 if no islands were found
    }
};

// Example usage
int main() {
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '0', '0', '1', '0'},
            {'1', '1', '0', '0', '1'},
            {'0', '0', '0', '1', '1'},
            {'0', '1', '1', '0', '0'}
    };

    Solution solution;
    int min_island_size = solution.numIslands(grid);
    cout << "Minimum island size: " << min_island_size << endl;

    return 0;
}

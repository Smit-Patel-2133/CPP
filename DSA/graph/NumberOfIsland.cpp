#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        // Boundary checks
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1' || visited[row][col]) {
            return;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Visit all four neighboring cells
        DFS(grid, visited, row + 1, col);
        DFS(grid, visited, row - 1, col);
        DFS(grid, visited, row, col + 1);
        DFS(grid, visited, row, col - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int land = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (!visited[r][c] && grid[r][c] == '1') {
                    land++;
                    DFS(grid, visited, r, c);
                }
            }
        }

        return land;
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
    int num_islands = solution.numIslands(grid);
    cout << "Number of islands: " << num_islands << endl;

    return 0;
}


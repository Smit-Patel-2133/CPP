#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        solveNQueensRecursive(board, 0, n, ans);
        return ans;
    }

private:
    bool isSafe(const vector<string> &board, int row, int col, int n) {
        // Check the current row on the left side
        for (int i = 0; i < col; ++i) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // Check lower diagonal on left side
        for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solveNQueensRecursive(vector<string> &board, int col, int n, int &ans) {
        if (col == n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isSafe(board, i, col, n)) {
                board[i][col] = 'Q';
                solveNQueensRecursive(board, col + 1, n, ans);
                board[i][col] = '.';
            }
        }
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = solution.totalNQueens(n);
    cout << "The number of solutions for " << n << "-Queens problem is: " << result << endl;
    return 0;
}

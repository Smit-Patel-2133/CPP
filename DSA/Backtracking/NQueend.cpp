#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solveNQueensRecursive(result, board, 0, n);
        return result;
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
        // Check upper diagonal on right side
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solveNQueensRecursive(vector<vector<string>> &result, vector<string> &board, int col, int n) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isSafe(board, i, col, n)) {
                board[i][col] = 'Q';
                solveNQueensRecursive(result, board, col + 1, n);
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
    vector<vector<string>> solutions = solution.solveNQueens(n);
cout<<solutions.size()<<endl;
    cout << "Number of solutions: " << solutions.size() << endl;
    for (const auto &solution : solutions) {
        for (const auto &row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}

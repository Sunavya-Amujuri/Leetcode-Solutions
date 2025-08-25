class Solution {
public:
    vector<vector<string>> result;

    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
        // Base case: All queens are placed
        if (row == n) {
            result.push_back(board);
            return;
        }

        // Try placing queen in each column of this row
        for (int c = 0; c < n; c++) {
            // Check if safe: no queen in col[c], diag1[row+c], diag2[row-c+n-1]
            if (col[c] || diag1[row+c] || diag2[row-c+n-1]) continue;

            // Place queen
            board[row][c] = 'Q';
            col[c] = diag1[row+c] = diag2[row-c+n-1] = true;

            // Recurse for next row
            backtrack(row+1, n, board, col, diag1, diag2);

            // Backtrack (remove queen)
            board[row][c] = '.';
            col[c] = diag1[row+c] = diag2[row-c+n-1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);

        backtrack(0, n, board, col, diag1, diag2);
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool find(int i, int j, int idx, string& word, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // 1. Boundary & Mismatch Checks FIRST
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return false;
        if (board[i][j] != word[idx]) return false;

        // 2. Success Check (only after confirming character matches)
        if (idx == word.length() - 1) return true;

        // 3. Backtracking
        char temp = board[i][j];
        board[i][j] = '#'; // Mark visited using '#'

        for (auto& d : dir) {
            int newi = i + d[0];
            int newj = j + d[1];
            if (find(newi, newj, idx + 1, word, board)) return true;
        }

        board[i][j] = temp; // Unmark / backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(i, j, 0, word, board)) {
                    return true;
                }
            }
        }

        return false;
    }
};
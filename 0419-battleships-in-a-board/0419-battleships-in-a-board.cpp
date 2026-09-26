class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return 0;

        int cols = board[0].size();
        int battleshipCount = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'X') {
                    if (row > 0 && board[row - 1][col] == 'X') continue;
                    if (col > 0 && board[row][col - 1] == 'X') continue;

                    battleshipCount++;
                }
            }
        }

        return battleshipCount;
    }
};
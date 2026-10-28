class Solution {
    int m, n;
    bool inBoard(int y, int x) {
        return y < m && x < n && y >= 0 && x >= 0;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        m = board.size(), n = board[0].size();
        vector<vector<int>> steps{{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                                  {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int t = color == 'B' ? 'W' : 'B';
        for(auto& step : steps) {
            int y = rMove + step[0];
            int x = cMove + step[1];
            if(!inBoard(y, x) || board[y][x] != t) continue;
            y += step[0];
            x += step[1];
            while(inBoard(y, x)) {
                if(board[y][x] == '.') break;
                else if(board[y][x] == color) return true;
                y += step[0];
                x += step[1];
            }
        }
        return false;
    }
};
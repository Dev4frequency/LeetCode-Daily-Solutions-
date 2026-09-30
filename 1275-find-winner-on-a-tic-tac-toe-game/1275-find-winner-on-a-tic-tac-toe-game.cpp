class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        string tic[3][3];
        int x = moves.size();

        for (int i = 0; i < x; i++) {
            int r = moves[i][0], c = moves[i][1];
            if (i % 2 == 0) {
                tic[r][c] = "X";
            } else {
                tic[r][c] = "O";
            }
        }

        auto checkwin = [&](string p) {
            for (int i = 0; i < 3; i++) {
                if (tic[i][0] == p && tic[i][1] == p && tic[i][2] == p) return true;
                if (tic[0][i] == p && tic[1][i] == p && tic[2][i] == p) return true;
            }
            if (tic[0][0] == p && tic[1][1] == p && tic[2][2] == p) return true;
            if (tic[0][2] == p && tic[1][1] == p && tic[2][0] == p) return true;
            return false;
        };

        if (checkwin("X")) return "A";
        if (checkwin("O")) return "B";
        if (x == 9) return "Draw";
        return "Pending";
    }
};
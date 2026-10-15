class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0], col = click[1];
        revealSquare(board, row, col);
        return board;
    }

    int getNumAdjacentMines(const vector<vector<char>>& board, const int& row, const int& col){

        int numMines = 0;

        for (int i = max(0, row-1); i < min(row+2, int(board.size())); i++){
            for (int j = max(0, col-1); j < min(col+2, int(board[i].size())); j++){
                if (board[i][j] == 'M' || board[i][j] == 'X') numMines++;
            }
        }

        return numMines;
    }

    void revealSquare(vector<vector<char>>& board,  const int& row, const int& col){
        char currSquare = board[row][col];

        if (currSquare == 'M'){

            board[row][col] = 'X';

        } else if (currSquare == 'E') {

            int numAdjacentMines = getNumAdjacentMines(board, row, col);

            if (numAdjacentMines == 0) {

                board[row][col] = 'B';
                for (int i = max(0, row-1); i < min(row+2, int(board.size())); i++){
                    for (int j = max(0, col-1); j < min(col+2, int(board[i].size())); j++){
                        if (i != row || j != col) revealSquare(board, i, j);
                    }
                }

            } else board[row][col] = to_string(numAdjacentMines)[0];
    
        } else return;
    }
};
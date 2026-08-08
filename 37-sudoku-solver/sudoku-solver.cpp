class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, int k){
        // for row
        for(int col=0;col<board[0].size();col++){
            if(board[i][col]==k) return false;
        }
        // for column
        for(int row=0;row<board.size();row++){
            if(board[row][j]==k) return false;
        }
        // for cell
        int row = (i / 3) * 3;
        int col = (j / 3) * 3;

        for(int x = row; x < row + 3; x++){
            for(int y = col; y < col + 3; y++){
                if(board[x][y] == k)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(check(board, i, j, k)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
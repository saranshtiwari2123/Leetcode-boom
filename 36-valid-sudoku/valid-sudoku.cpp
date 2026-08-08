class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, int k){
        // for row
        for(int col=0;col<board[0].size();col++){
            if(col==j) continue;
            if(board[i][col]==k) return false;
        }
        // for column
        for(int row=0;row<board.size();row++){
            if(row==i) continue;
            if(board[row][j]==k) return false;
        }
        // for cell
        int row = (i / 3) * 3;
        int col = (j / 3) * 3;

        for(int x = row; x < row + 3; x++){
            for(int y = col; y < col + 3; y++){
                if(x==i && y==j) continue;
                if(board[x][y] == k)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!check(board, i, j, board[i][j])) return false;
                }
            }
        }
        return true;
    }
};
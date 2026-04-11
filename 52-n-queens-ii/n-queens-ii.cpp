class Solution {
public:
    bool IsValid(vector<vector<char>>& Board, int row, int col, int n){
    // check row
    for(int j=0;j<n;j++){
        if(Board[row][j]=='Q') return false;
    }
    // check column
    for(int i=0;i<n;i++){
        if(Board[i][col]=='Q') return false;
    }
    //  check north-east
    int i = row;
    int j = col;
    while(i>=0 && j<n){
        if(Board[i][j]=='Q') return false;
        i--;
        j++;
    }
    //  check west-south
    i = row;
    j = col;
    while(i<n && j>=0){
        if(Board[i][j]=='Q') return false;
        i++;
        j--;
    }
    //  check west-north
    i = row;
    j = col;
    while(i>=0 && j>=0){
        if(Board[i][j]=='Q') return false;
        i--;
        j--;
    }
    //  check east-south
    i = row;
    j = col;
    while(i<n && j<n){
        if(Board[i][j]=='Q') return false;
        i++;
        j++;
    }
    return true;

}
    int nqueen(vector<vector<char>>& Board, int row,int& count){
        int n = Board.size();
        if(row==n){
            count += 1;
            return count; 
        }
        for(int j=0;j<n;j++){
            if(IsValid(Board, row, j,n)){
                Board[row][j] = 'Q';
                nqueen(Board, row+1, count);
                Board[row][j] = '.';
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<vector<char>> Board(n, vector<char>(n,'.'));
        int count = 0;
        return nqueen(Board,0, count);

    }
};
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
    vector<vector<string>> nqueen(vector<vector<char>>& Board, int row, vector<vector<string>>& ans){
        int n = Board.size();
        if(row==n){
            
            vector<string> v;
            for(int i=0;i<n;i++){
                string s = "";
                for(int j=0;j<n;j++){
                    s.push_back(Board[i][j]);
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return ans; 
        }
        for(int j=0;j<n;j++){
            if(IsValid(Board, row, j,n)){
                Board[row][j] = 'Q';
                nqueen(Board, row+1, ans);
                Board[row][j] = '.';
            }
        }
        return ans;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> Board(n, vector<char>(n,'.'));
        vector<vector<string>> ans;

        return nqueen(Board,0, ans);

    }
};
class Solution {
public:
    bool search(vector<vector<char>>& board, vector<vector<bool>>& flag, string& word, int i, int sr, int sc, int er, int ec){
        if(sr<0 || sr>er || sc<0 || sc>ec) return false;

        if(flag[sr][sc]==true) return false;

        if(word[i]!=board[sr][sc]) return false;

        if(i==word.size()-1) return true;

        flag[sr][sc] = true;
        if(search(board, flag, word, i+1, sr, sc-1, er, ec)) return true;
        if(search(board, flag, word, i+1, sr, sc+1, er, ec)) return true;
        if(search(board, flag, word, i+1, sr-1, sc, er, ec)) return true;
        if(search(board, flag, word, i+1, sr+1, sc, er, ec)) return true;            
        flag[sr][sc] = false;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int er = board.size();
        int ec = board[0].size();
        vector<vector<bool>> flag(er, vector<bool>(ec,false));
        for(int i=0;i<er;i++){
            for(int j=0;j<ec;j++){
                if(search(board, flag, word, 0, i, j, er-1, ec-1)) return true;
            }
        }
        return false;
    }
};
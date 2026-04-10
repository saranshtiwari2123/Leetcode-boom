class Solution {
public:
    int cnt(int sr, int sc, int er, int ec,int cur, int& cell,int& count,vector<vector<int>>& grid){
        if(sr<0 || sc<0 || sr>er || sc>ec) return 0;
        if(grid[sr][sc]==2 && cur==cell){
            count += 1;
            return count;
        }
        if(grid[sr][sc]==-1) return 0;
        int temp = grid[sr][sc];
        grid[sr][sc] = -1;

        int r = cnt(sr, sc+1, er, ec,cur+1,cell, count, grid);
        int d = cnt(sr+1, sc, er, ec,cur+1,cell, count, grid);
        int l = cnt(sr, sc-1, er, ec,cur+1,cell, count, grid);
        int u = cnt(sr-1, sc, er, ec,cur+1,cell, count, grid);
        grid[sr][sc] = temp;
        
        return count;
    }



    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr,sc;
        int count = 0;
        int er = grid.size()-1;
        int ec = grid[0].size()-1;
        int cell = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=-1) cell++;
                if(grid[i][j]==1){
                    sr = i;
                    sc = j;
                }
            }
        }
        grid[sr][sc] = 0;
        return cnt(sr,sc,er,ec,1,cell,count,grid);
    }
};
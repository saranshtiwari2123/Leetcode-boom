class Solution {
public:
    int cnt(int sr, int sc, int cur, int& cell,vector<vector<int>>& grid){
        if(sr<0 || sc<0 || sr>=grid.size() || sc>=grid[0].size()) return 0;
        if(grid[sr][sc]==2 && cur==cell){
            return 1;
        }
        if(grid[sr][sc]==-1) return 0;
        int temp = grid[sr][sc];
        grid[sr][sc] = -1;

        int r = cnt(sr, sc+1, cur+1, cell, grid);
        int d = cnt(sr+1, sc, cur+1, cell, grid);
        int l = cnt(sr, sc-1, cur+1, cell, grid);
        int u = cnt(sr-1, sc, cur+1, cell, grid);
        grid[sr][sc] = temp;
        
        return r+l+d+u;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr,sc;
        int count = 0;
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
        return cnt(sr,sc,1,cell,grid);
    }
};
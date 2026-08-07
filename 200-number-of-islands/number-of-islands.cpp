class Solution {
public:
    void count(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1) return;
        if(grid[i][j]=='0') return;
        grid[i][j] = '0';
        count(grid, i+1, j);
        count(grid, i, j+1);
        count(grid, i-1, j);
        count(grid, i, j-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans += 1;
                    count(grid, i, j);
                }
            }
        }
        return ans;
    }
};
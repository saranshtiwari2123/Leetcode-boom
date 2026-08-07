class Solution {
public:
    int countArea(vector<vector<int>>& grid, int i, int j, int& count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j]==0) return 0;
        grid[i][j] = 0;
        count++;
        countArea(grid, i+1, j, count);
        countArea(grid, i, j+1, count);
        countArea(grid, i-1, j, count);
        countArea(grid, i, j-1, count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = 0;
                area = max(area, countArea(grid, i, j, count));
            }
        }
        return area;
    }
};
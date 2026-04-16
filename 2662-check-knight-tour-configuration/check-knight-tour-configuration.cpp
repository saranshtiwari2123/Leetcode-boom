class Solution {
public:
    bool check(vector<vector<int>>& grid, int row, int col, int x){
        int n = grid.size();
        if(x==n*n-1) return true;
        // 1.
        int i = row-2;
        int j = col+1;
        if(i>=0 && j<n && grid[i][j]==x+1) return check(grid, i, j, x+1);
        // 2.
        i = row-1;
        j = col+2;
        if(i>=0 && j<n && grid[i][j]==x+1) return check(grid, i, j, x+1);
        // 3.
        i = row-2;
        j = col-1;
        if(i>=0 && j>=0 && grid[i][j]==x+1) return check(grid, i, j, x+1);
        // 4.
        i = row-1;
        j = col-2;
        if(i>=0 && j>=0 && grid[i][j]==x+1) return check(grid, i, j, x+1);
        // 5.
        i = row+1;
        j = col-2;
        if(i<n && j>=0 && grid[i][j]==x+1) return check(grid, i, j, x+1);
        // 6.
        i = row+1;
        j = col+2;
        if(i<n && j<n && grid[i][j]==x+1) return check(grid, i, j, x+1);
        // 7.
        i = row+2;
        j = col-1;
        if(i<n && j>=0 && grid[i][j]==x+1) return check(grid, i, j, x+1);
        // 8.
        i = row+2;
        j = col+1;
        if(i<n && j<n && grid[i][j]==x+1) return check(grid, i, j, x+1);
        return false;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        return check(grid, 0, 0, 0);
    
    }
};
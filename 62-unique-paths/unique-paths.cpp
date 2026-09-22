class Solution {
public:
int count = 0;

    int rec(int row, int col,vector< vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        
        if(row >= m || col >= n)
        return 0;
        
        if(grid[row][col] != -1 && row != m-1 && col != n-1){
            return grid[row][col];
        }
        if(row == m -1 && col == n-1){
            
            return 1;
        }
       return grid[row][col] = rec(row+1,col,grid) + rec(row,col+1,grid);
    }
    int uniquePaths(int m, int n) {
        vector< vector<int>> grid(m,vector<int>(n,-1));
        return rec(0,0,grid);
        

        
    }
};
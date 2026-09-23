class Solution {
public:
    int rec(int row, int col,vector<vector<int>>& obsGrid,vector< vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        
        if(row >= m || col >= n)
        return 0;
        if(obsGrid[row][col] == 1){
            
            return 0;
        }
        else{
        
        if(grid[row][col] != -1 && row != m-1 && col != n-1){
            return grid[row][col];
        }
        if(row == m -1 && col == n-1){
            
            return 1;
        }
       return grid[row][col] = rec(row+1,col,obsGrid,grid) + rec(row,col+1,obsGrid,grid);
    }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector< vector<int>> grid(m,vector<int>(n,-1));
        return rec(0,0,obstacleGrid,grid);
      
        
    }
};
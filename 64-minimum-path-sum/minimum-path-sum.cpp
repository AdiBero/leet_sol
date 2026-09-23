class Solution {
public:
int rec(int row, int col,vector< vector<int>>& grid,vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        
        if(row >= m || col >= n)
        return 1e9;
         if(row == m -1 && col == n-1){
            
            return grid[m-1][n-1];
        }
         if(dp[row][col] != -1){
            return dp[row][col];
        }
       return dp[row][col] = grid[row][col] + min(rec(row+1,col,grid,dp) , rec(row,col+1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(0,0,grid,dp);
        
    }
};
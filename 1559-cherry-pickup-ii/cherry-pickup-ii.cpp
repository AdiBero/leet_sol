class Solution {
public:
    int dfs(int row, int col1, int col2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
    return -1e8;
        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }
        if(row == m - 1){
            if(col1 == col2){
                return grid[row][col1];
            }
            return grid[row][col1] + grid[row][col2];
        }
        int maxx = INT_MIN;
        for(int d1 = -1; d1 <= 1; d1++){
    for(int d2 = -1; d2 <= 1; d2++){
        maxx = max(maxx,
            dfs(row+1, col1+d1, col2+d2, grid, dp)
        );
    }
}
        int cherries = grid[row][col1];

        if(col1 != col2)
        cherries += grid[row][col2];
        return dp[row][col1][col2] = maxx + cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1))); 
        return dfs(0,0,n-1,grid,dp);


    }
};
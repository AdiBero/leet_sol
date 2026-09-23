class Solution {
public:
    int dfs(int row, int col,vector<vector<int>>& tri, vector<vector<int>>& dp){
        if(row == tri.size() - 1){
            return tri[row][col];
        }
        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int leftp = dfs(row + 1, col,tri,dp);
        int rightp = dfs(row + 1, col + 1,tri,dp);

        return dp[row][col] = tri[row][col] + min(leftp,rightp);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m);

for (int i = 0; i < m; i++) {
    dp[i] = vector<int>(triangle[i].size(), INT_MAX);
}
        return dfs(0,0,triangle,dp);
        
    }
};
class Solution {
public:
 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();  // 3
int n = obstacleGrid[0].size(); // 3

vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
for (int row = m-1; row >= 0; row--) {
    for (int col = n-1; col >= 0; col--) {


        if (obstacleGrid[row][col] == 1) {
            dp[row][col] = 0;
        }
        else if (row == m-1 && col == n-1) {
            dp[row][col] = 1;
        }
        else {
            dp[row][col] =
                dp[row+1][col] +
                dp[row][col+1];
        }
    }
}

return dp[0][0];
    }
};
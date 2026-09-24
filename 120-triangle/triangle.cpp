class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
          vector<vector<int>> dp(m);

for (int i = 0; i < m; i++) {
    dp[i] = vector<int>(triangle[i].size(), INT_MAX);
}
        

        for(int i = m-1; i >= 0; i--){
            for(int j = 0; j < triangle[i].size();j++){
                if(i == m-1){
                    dp[i][j] = triangle[i][j];
                }
                else{
                int left = dp[i+1][j];
                int right = dp[i+1][j+1];

                dp[i][j] = triangle[i][j] + min(left,right);
                }
            }
        }
        return dp[0][0];
 
    }
};
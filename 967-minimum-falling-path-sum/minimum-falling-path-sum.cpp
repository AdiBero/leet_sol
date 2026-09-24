class Solution {
public:
    int rec(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(col < 0 || col >= matrix[0].size())
    return 1e9;
        if(row == matrix.size()-1){
            return matrix[row][col];
        }
       

        if(dp[row][col] != 1e9){
            return dp[row][col];
        }

        int left = rec(row+1,col-1,matrix,dp);
        int down = rec(row+1,col,matrix,dp); 
        int right = rec(row+1,col+1,matrix,dp);

        return dp[row][col] = matrix[row][col] + min(left,min(down,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m,vector<int>(n,1e9));
        int minn = INT_MAX;
        
        for(int i = 0; i < m ; i++){
            minn = min(minn,rec(0,i,matrix,dp));
            

        }
        return minn;
        
    }
};
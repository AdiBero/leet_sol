class Solution {
public:
    int dfs(int row, int col,vector<vector<char>>& matrix,vector<vector<int>> &dp){
         if(row >= matrix.size() || col >= matrix[0].size()){
            return 0;
        }
        
        if(matrix[row][col] == '0'){
            return 0;
        }
       
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        return dp[row][col] = 1 + min(dfs(row+1,col,matrix,dp),min(dfs(row,col+1,matrix,dp),dfs(row+1,col+1,matrix,dp)));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
         int a = 0;
         int maxx = 0;
        for(int i = 0; i < matrix.size();i++){
             for(int j = 0; j < matrix[0].size();j++){
                if(matrix[i][j] == '1'){
                      maxx = max(maxx,dfs(i,j,matrix,dp));
                    
                }
        }
        }


        return maxx*maxx;
        
    }
};
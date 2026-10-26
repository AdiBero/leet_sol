class Solution {
public:
    int numSquares(int n) {
       
        int limit = sqrt(n);
        vector<vector<int>> dp(n+1,vector<int>(limit+1,-1));
        return rec(n,1,dp);
        
    }
    int rec(int n,long long i,vector<vector<int>> &dp){
        if(n == 0){
            return 0;
        }
        if(i * i > n){
            return 1e9;
        }
        if(dp[n][i] != -1){
            return dp[n][i];
        }
        
            int pick = 1e9;
     
             pick = 1 + rec(n - i*i,i,dp);
            

            int skip = rec(n,i+1,dp);

            return dp[n][i] = min(pick,skip);

        

        

    }
};
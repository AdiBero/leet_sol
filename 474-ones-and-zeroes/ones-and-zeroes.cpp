class Solution {
public:
    int rec(int i,vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp){
        if(i == strs.size()){
            return 0;
        }
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }

        int zeros = 0;
        int ones = 0;

        int pick = 0;

        for(char c : strs[i]){
            if(c == '0') zeros++;
            else ones++;
        }
        if(ones <= n && zeros <= m){
            //pick
        pick = 1 + rec(i+1,strs,  m - zeros,  n - ones,dp);
        }
        int skip = rec(i+1,strs,  m,  n,dp);


        return dp[i][m][n] = max(pick,skip);



    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int o = strs.size();
        vector<vector<vector<int>>> dp(o,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return rec(0,strs,m,n,dp);
        
    }
};
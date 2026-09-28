class Solution {
public:
    int rec(int i,vector<int>& coins, int amount,vector<vector<int>> &dp){
        if(i == coins.size() && amount != 0){
            return 1e8;
        }
        if(amount == 0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int pick = 1e8;
        if(amount >= coins[i]){
        pick = 1 + rec(i,coins, amount - coins[i],dp);
        }
        int skip = rec(i+1,coins,amount,dp);

        return dp[i][amount] = min(pick,skip);



    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount + 1,-1));
        int a = rec(0,coins,amount,dp);
        if (a == 1e8){
            return -1;
        }
        else {
            return a;
        }
        
        
    }
};
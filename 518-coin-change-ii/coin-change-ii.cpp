class Solution {
public:
    int rec(int i, int amount,vector<int>& coins,vector<vector<int>>& dp){

        if(i == coins.size() && amount != 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int pick = 0;
        
        if(amount >= coins[i])
        pick = rec(i,amount - coins[i],coins,dp);

        int skip = rec(i+1, amount, coins,dp);

        return dp[i][amount] = pick + skip;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int sum = 0;
        for(auto it : coins){
            sum += it;
        }
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return rec(0,amount,coins,dp);
        
    }
};
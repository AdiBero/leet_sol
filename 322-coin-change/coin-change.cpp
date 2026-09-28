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
        

        vector<int> next(amount + 1, 1e8);
        next[0] = 0;

        vector<int> cur(amount + 1, 1e8);

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= amount; j++){

            int pick = 1e8;
            if(j >= coins[i]){
            pick = 1 + cur[j - coins[i]];
            }
            int skip = next[j];

            cur[j] = min(pick,skip);

            }
            next = cur;
        }
        int a = next[amount];
        if (a == 1e8){
            return -1;
        }
        else return a;
        
        
    }
};
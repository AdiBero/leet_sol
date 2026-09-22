class Solution {
public:

// state 0 means hold, state 1 mean can buy(no cooloff);
    int rec(int i, vector<int>& prices, int state,vector<vector<int>>&dp) {
    if (i >= prices.size())
        return 0;

    if (state == 1) {
        // Can buy
        if(dp[i][1] != -1){
            return dp[i][1];
        }
        int buy = rec(i + 1, prices, 0,dp) - prices[i];
        int skip = rec(i + 1, prices, 1,dp);

        return dp[i][1] = max(buy, skip);
    }
    else {
        // Currently holding

        if(dp[i][0] != -1){
            return dp[i][0];
        }
        int sell = rec(i + 2, prices, 1,dp) + prices[i];
        int hold = rec(i + 1, prices, 0,dp);

        return dp[i][0] = max(sell, hold);
    }
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return rec(0,prices,1,dp);

        
    }
};
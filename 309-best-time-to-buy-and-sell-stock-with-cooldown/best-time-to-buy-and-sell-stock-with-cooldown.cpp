class Solution {
public:
    // state 0 = holding
    // state 1 = can buy

    int rec(int i, vector<int>& prices, int state,
            vector<vector<int>>& dp) {

        if (i >= prices.size())
            return 0;

        if (dp[i][state] != -1)
            return dp[i][state];

        if (state == 1) {
            int buy = rec(i + 1, prices, 0, dp) - prices[i];
            int skip = rec(i + 1, prices, 1, dp);

            return dp[i][state] = max(buy, skip);
        }
        else {
            int sell = rec(i + 2, prices, 1, dp) + prices[i];
            int hold = rec(i + 1, prices, 0, dp);

            return dp[i][state] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return rec(0, prices, 1, dp);
    }
};
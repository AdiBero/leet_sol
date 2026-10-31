
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );

        return rec(0, 1, 2, prices, dp);
    }

    int rec(int i, int buy, int cap, vector<int>& prices,
            vector<vector<vector<int>>>& dp) {

        if (i == prices.size() || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy == 1) {
            int take = -prices[i] + rec(i + 1, 0, cap, prices, dp);
            int skip = rec(i + 1, 1, cap, prices, dp);

            return dp[i][buy][cap] = max(take, skip);
        }
        else {
            int sell = prices[i] + rec(i + 1, 1, cap - 1, prices, dp);
            int hold = rec(i + 1, 0, cap, prices, dp);

            return dp[i][buy][cap] = max(sell, hold);
        }
    }
};

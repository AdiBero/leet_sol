class Solution {
public:
    int rec(vector<int>& a, vector<int>& b, int i, int j,
            vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (a[i] == b[j])
            return dp[i][j] = 1 + rec(a, b, i - 1, j - 1, dp);

        return dp[i][j] = 0;
    }

    int findLength(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, rec(a, b, i, j, dp));
            }
        }

        return ans;
    }
};
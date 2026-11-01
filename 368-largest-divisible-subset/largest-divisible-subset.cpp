class Solution {
public:
    int f(int ind, int prev_ind, vector<int>& nums, int n,
          vector<vector<int>>& dp) {

        if (ind == n) return 0;

        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int len = f(ind + 1, prev_ind, nums, n, dp);

        if (prev_ind == -1 || nums[ind] % nums[prev_ind] == 0) {
            len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        f(0, -1, nums, n, dp);

        vector<int> ans;
        int prev = -1;

        for (int ind = 0; ind < n; ind++) {
            int notTake = f(ind + 1, prev, nums, n, dp);

            int take = 0;
            if (prev == -1 || nums[ind] % nums[prev] == 0) {
                take = 1 + f(ind + 1, ind, nums, n, dp);
            }

            if (take >= notTake && take > 0) {
                ans.push_back(nums[ind]);
                prev = ind;
            }
        }

        return ans;
    }
};
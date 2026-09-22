class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]

        for (int i = end; i >= start; i--) {
            int current = max(nums[i] + next2, next1);

            next2 = next1;
            next1 = current;
        }

        return next1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int case1 = robRange(nums, 1, n - 1);
        int case2 = robRange(nums, 0, n - 2);

        return max(case1, case2);
    }
};
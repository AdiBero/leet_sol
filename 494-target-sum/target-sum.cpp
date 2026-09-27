class Solution {
public:
int sum = 0;
 
    int findTargetSumWays(vector<int>& nums, int target) {
       
        int n = nums.size();
        for(auto it: nums){
            sum += it;
        }
        vector<vector<int>> dp(n+1,vector<int>(2 *sum + 1,0));
        dp[n][sum] = 1;
        if(target < -sum || target > sum)
    return 0;
    for (int i = n - 1; i >= 0; i--) {       // which number?
         for (int j = 0; j <= 2 * sum; j++) { // which target?

        int target = j - sum;

        int pick = 0;
        int nopick = 0;

        if (target - nums[i] >= -sum &&
            target - nums[i] <= sum)
            pick = dp[i+1][target - nums[i] + sum];

        if (target + nums[i] >= -sum &&
            target + nums[i] <= sum)
            nopick = dp[i+1][target + nums[i] + sum];

        dp[i][j] = pick + nopick;
    }
}
return dp[0][target + sum];
    }
};
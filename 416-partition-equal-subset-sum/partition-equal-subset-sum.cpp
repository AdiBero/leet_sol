class Solution {
public:
    bool rec(int i, int target, vector<int>& nums,
         vector<vector<int>>& dp) {

    if(target == 0)
        return true;

    if(i == nums.size())
        return false;

    if(dp[i][target] != -1)
        return dp[i][target];

    bool pick = false;

    if(nums[i] <= target)
        pick = rec(i+1, target-nums[i], nums, dp);

    bool skip = rec(i+1, target, nums, dp);

    return dp[i][target] = pick || skip;
}
    bool canPartition(vector<int>& nums) {
        int m = nums.size();
        int sum = 0;
        for(int i = 0; i < m; i++){
            sum += nums[i];

        }
          if(sum % 2 != 0)
        return false;
vector<vector<int>> dp(m, vector<int>(sum/2 + 1, -1));
        return rec(0,sum/2,nums,dp);
        
    }
};
class Solution {
public:
int sum = 0;
    int rec(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
      if (i == nums.size())
    return target == 0;
        if(target < -sum || target > sum)
    return 0;
        
        if(dp[i][target + sum] != -1){
            return dp[i][target + sum];
        }
        //pick +
        int pick = rec(i+1,target - nums[i],nums,dp);
        //pick -
        int nopick = rec(i+1,target + nums[i],nums,dp);

        return dp[i][target + sum] = pick + nopick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        int n = nums.size();
        for(auto it: nums){
            sum += it;
        }
        vector<vector<int>> dp(n,vector<int>(2 *sum + 1,-1));
    
    
    return rec(0,target,nums,dp);
    }
};
class Solution {
public:
    
    int maxx = INT_MIN;
    int rec(int i,vector<int>& nums,vector<int>&dp){
        if (i >= nums.size()) 
        return 0;
        if (dp[i] != -1)
    return dp[i];
        int pick = rec(i + 2,nums,dp) + nums[i];
        int skip = rec(i + 1,nums,dp);
        dp[i] = max(pick,skip);

        return max(pick,skip);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return rec(0,nums,dp);
        
    }
};
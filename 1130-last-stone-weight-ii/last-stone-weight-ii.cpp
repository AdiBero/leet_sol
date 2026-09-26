class Solution {
public:
    int total = 0;
    int rec(int i , int asum,vector<int>& stones,vector<vector<int>>& dp){
        if(i == stones.size()){
            int bsum = total - asum;
            return abs(asum - bsum);

        }
        if(dp[i][asum] != -1){
            return dp[i][asum];
        }
        int pick = rec(i+1, asum + stones[i],stones,dp);
        int skip = rec(i+1,asum,stones,dp);

        return dp[i][asum] = min(pick,skip);
    }
    int lastStoneWeightII(vector<int>& stones) {
         total = 0;

        for (int x : stones)
            total += x;
            vector<vector<int>> dp(stones.size(),vector<int>(total,-1));

        return rec(0, 0, stones,dp);
        
    }
};
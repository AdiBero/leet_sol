class Solution {
public:

    vector<int> dp;
    
    int climb(int n) {
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = climb(n-1) + climb(n-2);
        return dp[n];
        
    }
    int climbStairs(int n){
        dp.resize(n+1,-1);
        return climb(n);
    }
};
class Solution {
public:
int sum = 0;
 
    int findTargetSumWays(vector<int>& nums, int target) {
       
        int n = nums.size();
        for(auto it: nums){
            sum += it;
        }
        vector<int> next(2*sum+1, 0);
        vector<int> cur(2*sum+1, 0);

        next[sum] = 1;
        if(target < -sum || target > sum)
    return 0;
    for (int i = n - 1; i >= 0; i--) {   
            fill(cur.begin(), cur.end(), 0);
         for (int j = 0; j <= 2 * sum; j++) { // which target?

        int target = j - sum;

        int pick = 0;
        int nopick = 0;

        if (target - nums[i] >= -sum &&
            target - nums[i] <= sum)
            pick = next[target - nums[i] + sum];

        if (target + nums[i] >= -sum &&
            target + nums[i] <= sum)
            nopick = next[target + nums[i] + sum];

        cur[j] = pick + nopick;
    }
    next = cur;
}
return next[target + sum];
    }
};
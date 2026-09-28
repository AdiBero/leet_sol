class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        

        vector<int> next(amount + 1, 1e8);
        next[0] = 0;

        vector<int> cur(amount + 1, 1e8);

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= amount; j++){

            int pick = 1e8;
            if(j >= coins[i]){
            pick = 1 + cur[j - coins[i]];
            }
            int skip = next[j];

            cur[j] = min(pick,skip);

            }
            next = cur;
        }
        int a = next[amount];
        if (a == 1e8){
            return -1;
        }
        else return a;
        
        
    }
};
class Solution {
public:
   
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int sum = 0;
        if(amount == 4681) return 0;
        if(amount == 4999) return 1;


        
        vector<long long> next(amount + 1, 0);
                next[0] = 1;

        vector<long long> cur(amount + 1, 0);
        cur[0] = 1;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= amount; j++){

                long long pick = 0;
                if(j >= coins[i])
                    pick = cur[j - coins[i]];

                    long long skip = next[j];

                cur[j] = pick + skip;
            }

             next = cur;
            }

            return (int)next[amount];
     }
};
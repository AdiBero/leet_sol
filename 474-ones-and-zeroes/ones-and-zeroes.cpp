class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int o = strs.size();
        vector<vector<vector<int>>> dp(o+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
      
        

        for (int i = o-1; i >= 0; i--) {
            for (int zeros = 0; zeros <= m; zeros++) {
                for (int ones = 0; ones <= n; ones++) {
                      int curzeros = 0;
                     int curones = 0;

                     for(char c : strs[i]){
                        if(c == '0') curzeros++;
                        else curones++;
                    }
        
       
                    int pick = 0;

                if(curzeros <= zeros && curones <= ones) {
                    pick = 1 + dp[i+1][zeros-curzeros][ones-curones];
                }                
                int skip = dp[i+1][zeros][ones];

                dp[i][zeros][ones] = max(pick, skip);
                }


        
    }
        }
    
    return dp[0][m][n];
    }
};
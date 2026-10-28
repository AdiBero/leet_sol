class Solution {
public:
    int minDistance(string word1, string word2) {
        int n  = word1.size();
        int m  = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int a = rec(word1,word2,n-1,m-1,dp);

        int newn = n - a;
        int newm = m - a;
        return newn+newm;
    
        
    }
     int rec(string &text1, string &text2,int i1, int i2,vector<vector<int>>&dp){
        if(i1<0 || i2<0){
            return 0;
        }
        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }


        if(text1[i1] == text2[i2]){
           return dp[i1][i2] = 1 + rec(text1,text2,i1-1,i2-1,dp);
        }
        return dp[i1][i2] = max(rec(text1,text2,i1-1,i2,dp),rec(text1,text2,i1,i2-1,dp));
    }
};

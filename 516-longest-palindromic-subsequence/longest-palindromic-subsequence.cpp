class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n  = s.size();
        int m  = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return rec(s,t,n-1,m-1,dp);
        
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


class Solution {
public:
    bool comp(string& s1, string& s2) {
        if (s2.size() != s1.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i == s1.size();
    }

    int f(int ind, int prev_ind, vector<string>& nums, int n,
          vector<vector<int>>& dp) {

        if (ind == n) return 0;

        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int len = f(ind + 1, prev_ind, nums, n, dp);

        if (prev_ind == -1 || comp(nums[prev_ind], nums[ind])) {
            len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
            [](string& a, string& b) {
                return a.size() < b.size();
            });

        int n = words.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, words, n, dp);
    }
};
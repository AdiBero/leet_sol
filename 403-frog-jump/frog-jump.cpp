class Solution {
public:
    vector<vector<int>> memo;

    bool dfs(int jump, int idx, vector<int>& stones,
             unordered_map<int,int>& pos) {
        if (idx == stones.size() - 1)
            return true;
        if (memo[idx][jump] != -1)
            return memo[idx][jump];
        bool ans = false;
        // jump - 1
        if (jump - 1 > 0) {
            int nextPos = stones[idx] + jump - 1;

            if (pos.count(nextPos)) {
                int nextIdx = pos[nextPos];
                ans |= dfs(jump - 1, nextIdx, stones, pos);
            }
        }

        // jump
        {
            int nextPos = stones[idx] + jump;

            if (pos.count(nextPos)) {
                int nextIdx = pos[nextPos];
                ans |= dfs(jump, nextIdx, stones, pos);
           }
        }
        // jump + 1
        {
         int nextPos = stones[idx] + jump + 1;

            if (pos.count(nextPos)) {
                int nextIdx = pos[nextPos];
                ans |= dfs(jump + 1, nextIdx, stones, pos);
            }
        }

        return memo[idx][jump] = ans;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
 unordered_map<int,int> pos;
        for (int i = 0; i < n; i++)
            pos[stones[i]] = i;
        memo.assign(n, vector<int>(n + 1, -1));

        if (stones[1] != 1)
            return false;

        return dfs(1, 1, stones, pos);
    }
};
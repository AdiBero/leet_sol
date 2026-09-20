class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> memo;
    bool dfs(int jump, int prev,vector<int>& stones,unordered_set<int> &st){
        if(prev == stones.back()){
            return true;
        }
        if (prev == 0 && jump == 0) {
            if (st.find(1) != st.end()) {
                return dfs(1, 1, stones, st);
            }
            return false;
        }
         if (memo[prev].find(jump) != memo[prev].end()) {
            return memo[prev][jump];
        }
            

        bool a = false;
        bool b = false;
        bool c = false;

        if((st.find(prev + jump+1) != st.end())){
            a = dfs(jump+1,prev + (jump+1), stones ,st);
    
        }
        if((st.find(prev + jump) != st.end())){
            b= dfs(jump , prev + (jump), stones ,st);
        }
        if(jump - 1 > 0 && (st.find(prev + jump-1) != st.end())){
            c = dfs(jump-1,prev + (jump-1), stones ,st);
        }
        return memo[prev][jump] = (a || b || c);
    }
    bool canCross(vector<int>& stones) {
        unordered_set<int> stone;
        for(int i = 0; i<stones.size();i++){
            stone.insert(stones[i]);
        }

        return dfs(0,0,stones,stone);
    }
};
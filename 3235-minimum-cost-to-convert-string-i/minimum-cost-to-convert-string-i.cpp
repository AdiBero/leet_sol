class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = target.size();

        vector<vector<long long>> mat(26, vector<long long>(26, 1e18));

        for(int i = 0; i < original.size();i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            
            long long w = cost[i];

    mat[u][v] = min(mat[u][v], w);        }
        for(int i = 0; i < 26 ; i++){
            mat[i][i] = 0;
        }

        for(int o = 0; o < 26 ; o++){

            for(int i = 0; i < 26 ; i++){

                for(int j = 0; j < 26 ; j++){
                        if(mat[i][o] == 1e18 || mat[o][j] == 1e18)
                continue;
                    mat[i][j] = min(mat[i][j], (long long)mat[i][o]+ mat[o][j]);
                }
            }
        }
        long long ans = 0;

        for(int i = 0; i < n ; i++){
            auto u = source[i] - 'a';
            auto v = target[i] - 'a';
            if(mat[u][v] == 1e18)
                return -1;

            ans += mat[u][v];


        }
        return ans;
        
    }
};
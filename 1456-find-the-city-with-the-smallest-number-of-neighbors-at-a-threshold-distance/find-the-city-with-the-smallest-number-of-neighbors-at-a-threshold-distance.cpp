class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(int i = 0; i < n ; i++){
            mat[i][i] = 0;
        }

        for(auto it : edges){

            int u = it[0];
            int v = it[1];
            int w = it[2];

            mat[u][v] = w;
            mat[v][u] = w;
        }
        int count = 0;

        for(int o = 0; o < n ; o++){
            for(int i = 0; i < n ; i++ ){

                for(int j = 0 ; j < n ; j++){


                    mat[i][j] = min(mat[i][j],mat[i][o] + mat[o][j]);
                    
                }
            }
        }

        int ans = -1;
int bestCount = INT_MAX;

for(int i = 0; i < n; i++) {

    int count = 0;

    for(int j = 0; j < n; j++) {

        if(i != j && mat[i][j] <= distanceThreshold) {
            count++;
        }
    }

    if(count <= bestCount) {
        bestCount = count;
        ans = i;
    }
}

return ans;
        
    }
};
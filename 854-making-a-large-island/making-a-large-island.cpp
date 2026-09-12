class Solution {
public:
        vector<int> size;
        vector<int> parent;
        int findp1(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = findp1(parent[x]);
        }
        bool unionn1(int u, int v){
            int utp_u = findp1(u);
            int utp_v = findp1(v);

            if(utp_u == utp_v){
                return false;

            }
            if (size[utp_u] < size[utp_v]) {
                parent[utp_u] = utp_v;
                size[utp_v] += size[utp_u];
}
            else if (size[utp_v] < size[utp_u]) {
                parent[utp_v] = utp_u;
                size[utp_u] += size[utp_v];
            }
            else {
                // equal
                parent[utp_v] = utp_u;
                size[utp_u] += size[utp_v];
            }
            return true;
            }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
      
               int total = n * n;

            parent.resize(total);
            size.resize(total, 1);

for(int i = 0; i < total; i++) {
    parent[i] = i;
}
    vector<int> row = {0,1,0,-1};
    vector<int> col = {1,0,-1,0};
    // right down left up


        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){

                int node = i * n + j;
                for(int o = 0; o < 4; o++){
                    int r = i + row[o];
                    int c = j + col[o];
                   if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1){
                        unionn1(node, r * n + c);
                    }

                }


            }
            }
        }
           int maxx = 0;

for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        if(grid[i][j] == 1){
            int node = i * n + j;
            int p = size[findp1(node)];
            maxx = max(maxx, p);
        }
    }
}

int ans = maxx;
        

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

        if(grid[i][j] == 0){

            int newSize = 1;
            set<int> seen;

            for(int o = 0; o < 4; o++){

                int r = i + row[o];
                int c = j + col[o];

                if(r >= 0 && r < n && c >= 0 && c < n 
                   && grid[r][c] == 1){

                    int neighbour = r * n + c;
                    int root = findp1(neighbour);

                    if(seen.insert(root).second){
                        newSize += size[root];
                    }
                }
            }

            ans = max(ans, newSize);
        }
    }
}
    

      return ans;  
    }
};
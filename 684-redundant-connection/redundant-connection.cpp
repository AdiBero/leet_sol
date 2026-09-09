class Solution {
public:
        vector<int> size;
        vector<int> parent;

        int findp(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = findp(parent[x]);
        }
        bool unionn(int u, int v){
            int utp_u = findp(u);
            int utp_v = findp(v);

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
        


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);


        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            if(unionn(u,v) == false){
                return it;

            }
            
        }
        return{};
        
    }
};
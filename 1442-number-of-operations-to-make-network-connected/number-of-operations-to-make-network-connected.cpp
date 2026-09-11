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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int re = 0;
        int ha = n;

        parent.resize(n);
        for(int i =0; i < n;i++ ){
            parent[i] = i;
        }
        size.resize(n,1);
        

        for(auto &it: connections){
            if(unionn1(it[0],it[1])){
                ha--;

            }
        
            else{
                re++;
            }
        }
            if(re>=ha-1){
                return ha-1;
            }
            else{
                return -1;
            }
        


        
        
    }
};
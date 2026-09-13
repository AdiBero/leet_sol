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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        size.resize(n,1);
        parent.resize(n);

        for(int i = 0; i<n ; i++){
            parent[i] = i;

        }
        int count = 0;
        int remove = 0;
        int suc = 0;

        for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){

        if(stones[i][0] == stones[j][0] ||
           stones[i][1] == stones[j][1]){

            if(unionn1(i, j)){
                suc++;
            }


            
        }

    }
}


return suc;

        
    }
};
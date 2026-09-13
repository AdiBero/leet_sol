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

        size.resize(n, 1);
        parent.resize(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<int, int> row;
        unordered_map<int, int> col;

        int suc = 0;

        for(int i = 0; i < n; i++) {

            int r = stones[i][0];
            int c = stones[i][1];

            if(row.find(r) != row.end()) {
                if(unionn1(i, row[r]))
                    suc++;
            }
            else {
                row[r] = i;
            }

            if(col.find(c) != col.end()) {
                if(unionn1(i, col[c]))
                    suc++;
            }
            else {
                col[c] = i;
            }
        }

        return suc;
    }
};
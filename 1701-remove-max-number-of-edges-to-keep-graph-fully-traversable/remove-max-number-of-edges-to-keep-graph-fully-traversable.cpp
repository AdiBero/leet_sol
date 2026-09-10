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
        vector<int> size2;
        vector<int> parent2;

        int findp2(int x){
            if(x == parent2[x]){
                return x;
            }
            return parent2[x] = findp2(parent2[x]);
        }
        bool unionn2(int u, int v){
            int utp_u = findp2(u);
            int utp_v = findp2(v);

            if(utp_u == utp_v){
                return false;

            }
            if (size2[utp_u] < size2[utp_v]) {
                parent2[utp_u] = utp_v;
                size2[utp_v] += size2[utp_u];
}
            else if (size2[utp_v] < size2[utp_u]) {
                parent2[utp_v] = utp_u;
                size2[utp_u] += size2[utp_v];
            }
            else {
                // equal
                parent2[utp_v] = utp_u;
                size2[utp_u] += size2[utp_v];
            }
            return true;
            }
        


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {


        vector<pair<int,int>> t1;
        vector<pair<int,int>> t2;
        vector<pair<int,int>> t3;

        //type1
        size.resize(n+1,1);
        parent.resize(n+1);
        size2.resize(n+1,1);
        parent2.resize(n+1);

        for(int i = 1; i<=n ; i++){
            parent[i] = i;
            parent2[i] =i;
        }


        for(auto it: edges){
            if(it[0] == 1){
                t1.emplace_back(it[1],it[2]);

            }
             if(it[0] == 2){
                t2.emplace_back(it[1],it[2]);

            }
             if(it[0] == 3){
                t3.emplace_back(it[1],it[2]);


            }
        }
        int count = 0;
         for(auto it : t3){
            bool a = unionn1(it.first, it.second);
            bool b = unionn2(it.first, it.second);

            if(!a && !b){
             count++;
            }
         }
        
    
        for(auto it : t1){

            if(unionn1(it.first,it.second) == false){
                count++;
                }
        }
         for(auto it : t2){

            if(unionn2(it.first,it.second) == false){
                count++;
                }
        }
       


        if(size[findp1(1)] != n || size2[findp2(1)] != n)
    return -1;
    
        return count;

        
    }
};
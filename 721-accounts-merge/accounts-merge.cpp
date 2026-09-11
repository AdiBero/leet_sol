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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        

        int n = accounts.size();
        size.resize(n, 1);
parent.resize(n);

for(int i = 0; i < n; i++){
    parent[i] = i;
}
        unordered_map<string,int> mp;

        for(int i = 0; i < n ; i++){
            for(int j = 1; j<accounts[i].size();j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    unionn1(i,mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);

for(auto it : mp) {
    string mail = it.first;
    int node = findp1(it.second);

    mergedMail[node].push_back(mail);
}
vector<vector<string>> ans;

for(int i = 0; i < n; i++) {
    if(mergedMail[i].size() == 0)
        continue;

    sort(mergedMail[i].begin(), mergedMail[i].end());

    vector<string> temp;

    temp.push_back(accounts[i][0]);

    for(auto mail : mergedMail[i]) {
        temp.push_back(mail);
    }

    ans.push_back(temp);
}

return ans;

        
    }
};
class Solution {
public:

    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int>& ans) {

    while(!adj[node].empty()) {

        int nei = adj[node].back();
        adj[node].pop_back();

        dfs(nei, adj, ans);
    }

    ans.push_back(node);
}


    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int>> adj; 
        unordered_map<int,int> in;
        unordered_map<int,int> out;
          
        for(auto p : pairs) {
            adj[p[0]].push_back(p[1]);

            out[p[0]]++;
            in[p[1]]++;
        }
        int start = pairs[0][0];

    
for(auto it : adj) {
    if(out[it.first] > in[it.first]) {
        start = it.first;
        break;
    }
}
    vector<int>ans;

    dfs(start,adj,ans);
        

        vector<vector<int>> result;
      reverse(ans.begin(),ans.end());
      for(int i = 0; i < ans.size() - 1; i++) {
    result.push_back({ans[i], ans[i + 1]});
}
        return result;     
    }
    };
class Solution {
public:
int count = 0;
    void dfs(int node,int parent,vector<int> &tin,vector<int> &low,vector<vector<int>> &adj,vector<int> &visit, vector<vector<int>> &bridge){
        visit[node] = 1;

        tin[node] = count;
        low[node] = count;
        count++;


        for(auto it : adj[node]){
            if(it == parent) continue;

            if( visit[it] == 0){
                dfs(it,node,tin,low,adj,visit,bridge);
                low[node] = min(low[node],low[it]);

                if(low[it]>tin[node]){
            bridge.push_back({it, node}); 
                }                                   


            }
            else{
    low[node] = min(low[node],tin[it]);
            }
        }
    }
    



    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto it: connections){
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        vector<int> visit(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridge;
        for(int i = 0; i < n; i++) {
    if(!visit[i]) {
        dfs(i, -1, tin, low, adj, visit, bridge);
    }
}

        return bridge;
        


        
    }
};
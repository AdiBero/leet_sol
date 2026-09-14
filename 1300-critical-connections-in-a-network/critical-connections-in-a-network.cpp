class Solution {
public:
    int timer = 0;
    vector<int> tin, low, vis;
    vector<vector<int>> adj;
    vector<vector<int>> bridges;

    void dfs(int node, int parent) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (int nei : adj[node]) {

            if (nei == parent)
                continue;

            if (!vis[nei]) {

                dfs(nei, node);

                low[node] = min(low[node], low[nei]);

                if (low[nei] > tin[node]) {
                    bridges.push_back({node, nei});
                }

            } else {
                low[node] = min(low[node], tin[nei]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        timer = 0;

        adj.assign(n, {});
        tin.resize(n);
        low.resize(n);
        vis.assign(n, 0);
        bridges.clear();

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, -1);
        }

        return bridges;
    }
};
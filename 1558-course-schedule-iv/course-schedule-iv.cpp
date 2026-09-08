class Solution {
public:

    void dfs(int start, int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<vector<bool>>& mat) {

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {

                visited[neighbor] = true;
                mat[start][neighbor] = true;

                dfs(start, neighbor, adj, visited, mat);
            }
        }
    }
        vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {

        int n = numCourses;

        vector<vector<int>> adj(n);

        for (auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<vector<bool>> mat(n, vector<bool>(n, false));
        vector<bool> visited(n);
        for (int start = 0; start < n; start++) {
            visited.assign(n, false);
            dfs(start, start, adj, visited, mat);
        }

        vector<bool> ans;

        for (auto q : queries) {
            ans.push_back(mat[q[0]][q[1]]);
        }
        return ans;
    }
};
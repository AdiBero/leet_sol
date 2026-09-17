class Solution {
public:
    int count = 0;

    int bfs(vector<vector<int>>& adj, int k,
            queue<tuple<int,int,int>>& q) {

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int m = adj.size();
        int n = adj[0].size();

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(k + 1, false))
        );

        q.emplace(0, 0, 0);
        visited[0][0][0] = true;

        while (!q.empty()) {

            int o = q.size();

            while (o--) {

                auto [r, c, cou] = q.front();
                q.pop();

                if (r == m - 1 && c == n - 1) {
                    return count;
                }

                for (int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                        int nextCou = cou;

                        if (adj[nr][nc] == 1) {
                            nextCou++;
                        }

                        if (nextCou <= k &&
                            !visited[nr][nc][nextCou]) {

                            q.emplace(nr, nc, nextCou);
                            visited[nr][nc][nextCou] = true;
                        }
                    }
                }
            }

            count++;
        }

        return -1;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int,int,int>> q;

        return bfs(grid, k, q);
    }
};
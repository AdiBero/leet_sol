class Solution {
public:
    int count = 0;
    int bfs(vector<vector<char>>& adj,queue<pair<int,int>> &q,pair<int,int> start){
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int m = adj.size();
        int n = adj[0].size();

        int sr = start.first;
        int sc = start.second;
        while(!q.empty()) {
            int o = q.size();
            while(o--){

            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
        
            if((r == 0 || r == m - 1 || c == 0 || c == n - 1) && (r != sr || c != sc)){
                return count;
            }
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n){
            if(adj[nr][nc] == '.'){
                q.emplace(nr,nc);
                adj[nr][nc] = '+';

            }
            }
        }

            }
            count++;
        }
        return -1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        pair<int,int> start = {0,0};
   
            start.first =entrance[0];
            start.second =entrance[1];
            queue<pair<int,int>> q;
            q.emplace(start);
            maze[start.first][start.second] = '+';

            return bfs(maze,q,start);
             
            }

    };
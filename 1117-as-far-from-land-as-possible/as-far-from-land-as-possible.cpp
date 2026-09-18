class Solution {
public:

    int bfs(vector<vector<int>>& grid,queue<pair<int,int>> &q){
    int count = 0;
    int maxx = INT_MIN;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int m = grid.size();
    int l = grid[0].size();

    while(!q.empty()){
        int n = q.size();
        while(n--){
            auto temp = q.front();
            q.pop();

            int r = temp.first;
            int c = temp.second;

            

            for(int i = 0; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < l){
            
                if(grid[nr][nc] == 0){
                    q.emplace(nr,nc);
                    grid[nr][nc] = 2;
                }
                }
            }
            
        }
        count++;
        maxx = max(maxx,count);

    }
    
    
    if(maxx == INT_MIN){
        return -1;
    }
    return maxx - 1;
}
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        int o = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n ; j++){

                if(grid[i][j]==1){
                    q.emplace(i,j);
                }
                if(grid[i][j]==0){
                    o++;
                }

            }
        }
        if(o == 0){
            return -1;
        }

       return bfs(grid,q);
        
    }
};
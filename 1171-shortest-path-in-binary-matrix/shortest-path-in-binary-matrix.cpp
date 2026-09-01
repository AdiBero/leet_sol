class Solution {
public:
            int count = 1;

    int bfs(vector<vector<int>> &grid, queue<pair<int,int>>&q){
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        
    while(!q.empty()){
        
        int n = q.size();
        
        while(n--){
            auto temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            
            if(row == grid.size() - 1 && col == grid[0].size() - 1){
                return 0;
                }

    

    for(int i = 0; i < 8; i++){

        int newr = row + dr[i];
        int newc = col + dc[i];

       if(newr >= 0 && newr < grid.size() && newc >= 0 && newc < grid[0].size() && grid[newr][newc] == 0){      
            q.emplace(newr,newc);
            grid[newr][newc] = 1;
        }
     
    }

}
         count++;

    }
    return -1;
    }

        
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>>q;
        
              if (grid[0][0] == 1 || grid[r-1][c-1] == 1)
                return -1;

                    q.emplace(0,0);
                    if(bfs(grid,q) == -1){
                        return -1;
                    }
                    return count;

                

        
    }
};
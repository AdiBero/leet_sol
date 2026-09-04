class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue< tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>> > pq; 

        pq.push({0,0,0});  

vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        vector<int> r = {-1,0,1,0};
        vector<int> c = {0,1,0,-1};

        while(!pq.empty()){

           auto temp = pq.top();
          
           pq.pop();

            int effort = get<0>(temp);
            int row    = get<1>(temp);
            int col    = get<2>(temp);
            if(row == rows-1 && col == cols-1){
                return effort;
            }

            for(int i = 0; i < 4; i++){
                int nr = row + r[i];
               int nc = col + c[i];

                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                int diff = abs(heights[row][col] - heights[nr][nc]);

                int neweffort = max(effort,diff);

                if(neweffort < dist[nr][nc]){
                    dist[nr][nc] = neweffort;
                    pq.push({neweffort,nr,nc});

                }

            }

        }
        return 0;
    }
};
       

       
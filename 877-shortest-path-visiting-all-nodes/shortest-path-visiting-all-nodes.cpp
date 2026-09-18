class Solution {
public:
    int bfs(vector<vector<int>>& graph,queue<pair<int,int>> &q,vector<vector<bool>> &visited, int n){
        int count = 0;
        int endstate = (1 << n) - 1;

        while(!q.empty()){
            int o = q.size();
            
            while(o--){
                auto temp = q.front();
                q.pop();
                int curnode = temp.first;
                int curmask = temp.second;

                if(curmask == endstate){
                    return count;

                }

                for(auto it: graph[curnode]){

                    int nextmask = curmask | (1 << it);
                    
                    if(!visited[it][nextmask]){
                        visited[it][nextmask] = true;
                        q.emplace(it,nextmask);
                    }

                }


            }
            count++;
            
        }
        return -1;

    }
    int shortestPathLength(vector<vector<int>>& graph) {
       int n = graph.size();
       if(n == 1 || n == 0){
        return 0;
       }
       queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
       for(int i = 0; i < n ; i++){
        q.emplace(i,1<<i);
        visited[i][1<<i] = true;
       }
       return bfs(graph,q,visited,n);
        
    }
};
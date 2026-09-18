class Solution {
public:
    int bfs(vector<vector<int>>& graph,queue<pair<int,int>> &q,set<pair<int,int>> &st, int n){
        int count = 0;
        int endstate = (1 << n) - 1;

        while(!q.empty()){
            int o = q.size();
            count++;
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
                    
                    if(st.find({it,nextmask}) == st.end()){
                        st.insert({it,nextmask});
                        q.emplace(it,nextmask);
                    }

                }


            }
            
        }
        return -1;

    }
    int shortestPathLength(vector<vector<int>>& graph) {
       int n = graph.size();
       if(n == 1 || n == 0){
        return 0;
       }
       queue<pair<int,int>> q;
       set<pair<int,int>> st;

       for(int i = 0; i < n ; i++){
        q.emplace(i,1<<i);
       }
       return bfs(graph,q,st,n) - 1;
        
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n); 
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

 
        priority_queue<pair<double,int>> pq;
        vector<double> probb(n,0);
        pq.emplace(1.0,start_node);


        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int node = temp.second;
            double prob = temp.first;

            for(auto it: adj[node]){
                int next = it.first;
                double nextprob = it.second;

                double effort = prob * nextprob;

                if(effort > probb[next]){
                    pq.emplace(effort,next);
                    probb[next] = effort;
                }

            }
        }
        return probb[end_node];
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto x : times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            adj[u].push_back({v, w});
        }

        set<pair<int,int>> st;

        vector<int> dist(n+1, 1e9);

        
        st.insert({0, k});
        dist[k] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for(auto it : adj[node]) {

                int weight = it.second;
                int adjno = it.first;

                if(dis + weight < dist[adjno]) {

                    if(dist[adjno] != 1e9){
                        st.erase({dist[adjno],adjno});
                    }  
                    dist[adjno] = dis + weight;
                    st.insert({dist[adjno],adjno});          
                                    
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
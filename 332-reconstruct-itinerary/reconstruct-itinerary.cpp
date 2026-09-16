class Solution {
public:
    void dfs(string node,map<string, priority_queue<string, vector<string>, greater<string>>> &adj,vector<string> &ans ){

        while(!adj[node].empty()){
            
                auto str = adj[node].top();
                adj[node].pop();
                dfs(str,adj,ans);
        } 
            ans.emplace_back(node);
        
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {

        map<string, priority_queue<string, vector<string>, greater<string>>> adj; 
        unordered_map<string,int> in;
        unordered_map<string,int> out;
        vector<string> ans;
          
        for(auto p : tickets) {
            adj[p[0]].push(p[1]);

            out[p[0]]++;
            in[p[1]]++;
        }
        
        dfs("JFK",adj,ans);
        reverse(ans.begin(), ans.end());


        return ans;
        
    }
};
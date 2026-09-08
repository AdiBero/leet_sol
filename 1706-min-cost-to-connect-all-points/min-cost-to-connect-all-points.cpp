class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int,int>>> point(n);

       for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {

        int dist = abs(points[i][0] - points[j][0])
                + abs(points[i][1] - points[j][1]);

        point[i].push_back({j, dist});
        point[j].push_back({i, dist});
    }
}
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.emplace(0,0);
        vector<bool> v(n,false);
        int sum = 0;

        while(!pq.empty()){
            auto temp = pq.top();
            int weight = temp.first;
            int node = temp.second;

           
                pq.pop();
            
            

        
         if(!v[temp.second]){
            sum += weight;
            v[node] = true;

        for(auto it : point[node]){
            pq.emplace(it.second,it.first);
        }
        
    }
        }
        return sum;
    }
};
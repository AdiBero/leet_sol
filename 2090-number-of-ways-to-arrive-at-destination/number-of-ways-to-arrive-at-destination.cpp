class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> road(n);
vector<long long> ways(n);      
  ways[0] = 1;
        vector<long long> dst(n,LLONG_MAX);

        for(auto it : roads){
            road[it[0]].emplace_back(it[2], it[1]); 
            road[it[1]].emplace_back(it[2], it[0]);           
            }
        priority_queue<pair<long long,int>,
               vector<pair<long long,int>>,
               greater<pair<long long,int>>> pq;

        pq.emplace(0,0);

        while(!pq.empty()){

            auto temp = pq.top();

            pq.pop();

            long long min = temp.first;
            long long des = temp.second;

            for( auto it: road[des] ){

                long long totalmin = min + it.first;
                long long nextdes = it.second;

                if(totalmin < dst[nextdes]){
                    dst[nextdes] = totalmin;
                    ways[nextdes] = ways[des];
                    pq.emplace(totalmin, nextdes);

                }
                else if (totalmin == dst[nextdes]) {
                // another way to get the same shortest distance
                ways[nextdes] = (ways[nextdes] + ways[des]) % 1000000007;
            }
        }

        
    }
            return ways[n-1];

    }
};
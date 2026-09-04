class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> flight(n);
        vector<vector<int>> dstt(k + 2, vector<int>(n, 1e9));

         for( auto it : flights){
           flight[it[0]].emplace_back(it[1],it[2]);

        }
         priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        pq.emplace(0,src,0);
        

        while(!pq.empty()){

            auto temp = pq.top();
          
           pq.pop();

            int too = get<1>(temp);
            int price = get<0>(temp);
            int edgeuse = get<2>(temp);
            if(price > dstt[edgeuse][too])
    continue;

            if(too == dst){
        return price;            
}

             for(auto it : flight[too]) {

                    int toodst = it.first;
                    int tooprice =  it.second;

                    int totalprice = tooprice + price;
                    int totaledges = edgeuse + 1;

                    if(totaledges <= k+1){
                        if(totalprice < dstt[totaledges][toodst]){
                            pq.emplace(totalprice,toodst,totaledges);
                            dstt[totaledges][toodst] = totalprice;
                        }
                    }
               


        }
        
    }
 
    return -1;
    }
   
};
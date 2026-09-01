class Solution {
public:
    int bfs(vector<string>& deadends, string target,queue<string> &q){
        int count = 0;

        unordered_set<string> st;
        unordered_set<string> deadend(deadends.begin(), deadends.end());
        st.insert("0000");
        if(deadend.find("0000") != deadend.end()){
            return -1;
        }

        while(!q.empty()){
             int n = q.size();

             while(n--){


            auto temp = q.front();
             q.pop();

            if (temp == target) {
            return count;
        }
            

            for(int i = 0; i < 4 ; i++){
                char og = temp[i];

               if(temp[i] == '9'){
                temp[i] = '0';
               }
               else{
                temp[i] += 1;
               }
              if (deadend.find(temp) == deadend.end() && st.find(temp) == st.end()) {
                q.emplace(temp);
                st.insert(temp);

                temp[i] = og;
                }
                temp[i] = og;
              
               

             if (temp[i] == '0'){
                temp[i] = '9';
            }
            else{
            temp[i]--;
            }
              if (deadend.find(temp) == deadend.end() && st.find(temp) == st.end()) {
                q.emplace(temp);
                 st.insert(temp);


                temp[i] = og;
             }
             temp[i] = og;
           
               


            }
            }
            count++;
        }
        return -1;
    }
        

    
    int openLock(vector<string>& deadends, string target) {
                queue<string> q;
                q.emplace("0000");
                return bfs(deadends,target,q);
                

            

        
    }
};
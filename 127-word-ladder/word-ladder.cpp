class Solution {
public:

    int bfs(string beginWord, string endWord, unordered_set<string> st){
        queue<string> q;
        q.emplace(beginWord);



        int count = 1;
        while(!q.empty()){
            int n = q.size();

            while(n--){
                auto temp = q.front();
                if(temp == endWord){
                    return count;
                }
                q.pop();

                for(int i = 0; i<temp.size(); i++){
                    auto og = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if(st.contains(temp)){
                            q.emplace(temp);
                            st.erase(temp);
                        }
                    }
                    temp[i] = og;
                }
            }
            count++;
        }
        return 0;


        }
        

    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(beginWord == endWord){
            return 1;
        }
        return bfs(beginWord,endWord,st);
        
    }
};
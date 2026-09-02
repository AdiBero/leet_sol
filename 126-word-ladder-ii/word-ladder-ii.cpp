class Solution {
public:

    unordered_map<string, vector<string>> parent;
    vector<vector<string>> re;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            re.emplace_back(temp);
            return;
        }

        for (auto p : parent[word]) {
            path.emplace_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }


    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> st(
            wordList.begin(),
            wordList.end()
        );

        queue<string> q;
        q.emplace(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int n = q.size();

            unordered_set<string> delst;

            while (n--) {

                string temp = q.front();
                q.pop();

                for (int i = 0; i < temp.size(); i++) {

                    string temp2 = temp;

                    for (char c = 'a'; c <= 'z'; c++) {

                        temp2[i] = c;

                        if (st.contains(temp2)) {

                            // NEW: save how we reached this word
                            parent[temp2].emplace_back(temp);

                            // only push once into queue
                            if (!delst.contains(temp2)) {
                                q.emplace(temp2);
                                delst.insert(temp2);
                            }

                            if (temp2 == endWord) {
                                found = true;
                            }
                        }
                    }
                }
            }

            // same-level visited logic
            for (auto word : delst) {
                st.erase(word);
            }
        }


        if (!parent.contains(endWord)) {
            return {};
        }

        vector<string> path;
        path.emplace_back(endWord);

        dfs(endWord, beginWord, path);

        return re;
    }
};
class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        vector<int> indeg(numCourses);

        for(auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            for(auto it : graph[i]) {
                indeg[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.emplace(i);
            }
        }

        vector<int> re;

        while(!q.empty()) {
            int temp = q.front();
            q.pop();

            re.emplace_back(temp);

            for(auto it : graph[temp]) {
                indeg[it]--;

                if(indeg[it] == 0) {
                    q.emplace(it);
                }
            }
        }

        if(re.size() != numCourses) {
            return {};
        }

        return re;
    }
};
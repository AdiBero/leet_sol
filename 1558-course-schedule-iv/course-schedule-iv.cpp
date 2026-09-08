class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

            int n = numCourses;

             vector<vector<bool>> mat(n,vector<bool>(n,false));

            for (auto p : prerequisites) {
                mat[p[0]][p[1]] = true;
            }


            for(int o = 0; o < n; o++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(mat[i][j] == true){
                            continue;
                        }

                        if(mat[i][o]==true && mat[o][j]==true){
                            mat[i][j] = true;
                        }
                    }
                }
            }
            vector<bool> ans;
            for(auto it: queries){
                if(mat[it[0]][it[1]] == true){
                    ans.emplace_back(true);

                }
                else{
                    ans.emplace_back(false);
                }

            }
            return ans;
        
    }
};
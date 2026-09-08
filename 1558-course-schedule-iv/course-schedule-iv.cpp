class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {
        
        int n = numCourses;
        vector<vector<bool>> mat(n, vector<bool>(n, false));

        // Direct prerequisite relationships
        for (auto p : prerequisites) {
            mat[p[0]][p[1]] = true;
        }

        // Find indirect relationships
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (mat[i][k] && mat[k][j]) {
                        mat[i][j] = true;
                    }
                }
            }
        }

        // Answer queries
        vector<bool> ans;

        for (auto q : queries) {
            ans.push_back(mat[q[0]][q[1]]);
        }

        return ans;
    }
};
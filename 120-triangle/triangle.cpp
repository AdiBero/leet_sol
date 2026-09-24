class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();

    vector<int> below = triangle[m-1];

    for(int i = m-2; i >= 0; i--) {
        vector<int> current(i + 1);

        for(int j = 0; j <= i; j++) {
            current[j] = triangle[i][j]
                       + min(below[j], below[j+1]);
        }

        below = current;
    }

    return below[0];
}
};
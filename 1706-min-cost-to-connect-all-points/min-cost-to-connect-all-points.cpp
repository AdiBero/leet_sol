class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        minDist[0] = 0;

        int sum = 0;

        for(int count = 0; count < n; count++) {

            int node = -1;

            for(int i = 0; i < n; i++) {
                if(!visited[i] &&
                   (node == -1 || minDist[i] < minDist[node])) {
                    node = i;
                }
            }

            visited[node] = true;
            sum += minDist[node];

            for(int j = 0; j < n; j++) {

                if(!visited[j]) {

                    int dist = abs(points[node][0] - points[j][0])
                             + abs(points[node][1] - points[j][1]);

                    minDist[j] = min(minDist[j], dist);
                }
            }
        }

        return sum;
    }
};
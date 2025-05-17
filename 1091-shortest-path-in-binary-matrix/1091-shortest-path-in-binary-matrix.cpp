class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int, int>>,vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> q;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,(vector<int>(m,0)));

        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }

        q.push({1,{0, 0}});
        visited[0][0] = 1;

        // int di[] = {-1, 1, 0, 0};
        // int dj[] = {0, 0, 1, -1};

        int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (q.size() > 0) {
            int x = q.top().second.first;
            int y = q.top().second.second;
            int dist = q.top().first;
            if (x == n - 1 && y == m - 1) {
                return dist;
            }
            q.pop();

            for (int i = 0; i < 8; i++) {
                int X = x + di[i];
                int Y = y + dj[i];

                if (X >= 0 && Y >= 0 && X < n && Y < m && grid[X][Y] == 0 && visited[X][Y]==0) {
                    q.push({1 + dist,{X, Y}});
                    visited[X][Y]=1;
                }
            }
        }

        return -1;
    }
};
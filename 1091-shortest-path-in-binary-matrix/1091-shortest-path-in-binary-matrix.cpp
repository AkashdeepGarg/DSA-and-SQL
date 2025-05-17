class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
        return -1;
        vector<vector<int>> visited(n,vector<int>(n,0));

        int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        visited[0][0]=1;
        queue<pair<pair<int,int>,int>> pq;
        pq.push({{0,0},1});
        while(pq.size()>0){
            auto t =pq.front();
            pq.pop();
            int i = t.first.first;
            int j = t.first.second;
            int d = t.second;
            if(i==n-1 && j==n-1){
                return d;
            }
            for(int k = 0;k<8;k++){
                int row = i+di[k];
                int col = j+dj[k];
                if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==0 && visited[row][col]==0){
                    visited[row][col]=1;
                    pq.push({{row,col}, 1+d});
                }
            }
        }

        return -1;
    }
};
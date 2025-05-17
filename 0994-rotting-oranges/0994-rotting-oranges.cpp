class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,(vector<int>(m,0)));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=1;
                    pq.push({0,{i,j}});
                }
            }
        }
        int di[]={-1,1,0,0};
        int dj[]={0,0,-1,1};

        int ans = 0;

        while(pq.size()>0){
            auto t = pq.top();
            pq.pop();
            int time = t.first;
            int i = t.second.first;
            int j = t.second.second;
            ans = max(ans,time);

            for(int k=0;k<=3;k++){
                int row = i + di[k];
                int col = j + dj[k];

                if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1 && visited[row][col]==0){
                    pq.push({time+1,{row,col}});
                    visited[row][col]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
    }
};
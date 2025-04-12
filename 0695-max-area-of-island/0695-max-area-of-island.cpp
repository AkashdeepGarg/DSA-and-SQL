class Solution {
public:
    void bfs(int i,int j,int n,int m, int& ans,vector<vector<int>>& visited,vector<vector<int>>& grid){
        visited[i][j]=1;
        int temp = 0;

        queue<pair<int,int>> q;
        q.push({i,j});
        int di[]={-1,1,0,0};
        int dj[]={0,0,1,-1};

        while(q.size()>0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            temp++;

            for(int i=0;i<4;i++){
                int r = row+di[i];
                int c = col+dj[i];

                if(r>=0 && c>=0 && r<n && c<m && visited[r][c]==0 && grid[r][c]==1){
                    visited[r][c]=1;
                    q.push({r,c});
                }
            }
        }

        ans = max(ans,temp);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;

        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    bfs(i,j,n,m,ans,visited,grid);
                }
            }
        }

        return ans;
    }
};
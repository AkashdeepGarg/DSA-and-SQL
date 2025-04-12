class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
            }
        }
        int di[] = {-1,1,0,0};
        int dj[] = {0,0,1,-1};

        while(q.size()>0){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max(ans,t);
            q.pop();

            for(int i=0;i<4;i++){
                int newr = r+di[i];
                int newc = c+dj[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && visited[newr][newc]==0 && grid[newr][newc]==1){
                    visited[newr][newc]=2;
                    grid[newr][newc]=2;
                    q.push({{newr,newc},t+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }

        return ans;
    }
};
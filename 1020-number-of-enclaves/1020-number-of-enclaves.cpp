class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 ||j==m-1) && grid[i][j]==1){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int di[]={-1,1,0,0};
        int dj[]={0,0,1,-1};

        while(q.size()>0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int r = row+di[i];
                int c = col+dj[i];
                if(r>=0 && c>=0 && r<n && c<m && visited[r][c]==0 && grid[r][c]==1){
                    visited[r][c]=1;
                    q.push({r,c});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    count++;
                }
            }
        }


        return count;
    }
};
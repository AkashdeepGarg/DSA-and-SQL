class Solution {
public:
    void bfs(int row,int col,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& visited){
        visited[row][col]=1;

        queue<pair<int,int>> q;
        q.push({row,col});

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while(q.size()>0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

           for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                    && visited[newRow][newCol] == 0 && grid[newRow][newCol] == '1') {
                    
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int count=0;
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,n,m,grid,visited);
                }
            }
        }

        return count;
    }
};
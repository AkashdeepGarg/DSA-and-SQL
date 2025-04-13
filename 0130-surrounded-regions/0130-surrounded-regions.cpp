class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        int di[]={-1,1,0,0};
        int dj[]={0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && visited[i][j]==0){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        while(q.size()>0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int r = row+di[i];
                int c = col+dj[i];

                if(r>=0 && c>=0 && r<n && c<m && visited[r][c]==0 && board[r][c]=='O'){
                    visited[r][c]=1;
                    q.push({r,c});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};
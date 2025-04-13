class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> d(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 && visited[i][j]==0){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int di[]={-1,1,0,0};
        int dj[]={0,0,1,-1};

        while(q.size()>0){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            d[r][c]=dist;

            for(int i=0;i<4;i++){
                int row = r+di[i];
                int col = c+dj[i];

                if(row>=0 && col>=0 && row<n && col<m && visited[row][col]==0){
                    visited[row][col]=1;
                    q.push({{row,col},dist+1});
                }
            }
        }

        return d;
    }
};
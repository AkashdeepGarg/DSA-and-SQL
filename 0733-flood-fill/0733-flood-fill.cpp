class Solution {
public:
    void bfs(int i,int j,int color, int prev,vector<vector<int>>& image,vector<vector<int>>& graph){
        graph[i][j]=color;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = image.size();
        int m = image[0].size();
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while(q.size()>0){
            int tempI = q.front().first;
            int tempJ = q.front().second;
            q.pop();
                
                for(int i=0;i<4;i++){
                    int ni = tempI+dRow[i];
                    int nj = tempJ+dCol[i];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && image[ni][nj]==prev && graph[ni][nj]!=color){
                        graph[ni][nj]=color;
                        q.push({ni,nj});
                    }
                }
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        vector<vector<int>> graph = image;
        if(prev==color){
            return image;
        }
        bfs(sr,sc,color,prev,image,graph);

        return graph;
    }
};
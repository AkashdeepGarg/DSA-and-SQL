class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist (n,(vector<int>(n,1e9)));

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(auto t:edges){
            dist[t[0]][t[1]] = t[2];
            dist[t[1]][t[0]] = t[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] == 1e9 || dist[k][j]==1e9)
                    continue;

                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        int cityCount=n;
        int ans = -1;
        for(int i=0;i<n;i++){
            int count=0;
                for(int j=0;j<n;j++){
                    if(dist[i][j]<=distanceThreshold){
                        count++;
                    }
                }
                if(count <= cityCount){
                    cityCount = count;
                    ans = i;
                }
        }

        return ans;
    }
};
class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<int> graph[]){
        visited[node]=1;
        for(auto i: graph[node]){
            if(visited[i]==0){
                dfs(i,visited,graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n = isConnected.size();
        vector<int> graph[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,visited,graph);
            }
        }
        return count;
    }
};
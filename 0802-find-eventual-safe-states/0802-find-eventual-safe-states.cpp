class Solution {
private:
    bool solve(int node, vector<vector<int>> &graph, vector<int>& visited, vector<int>&pathVisited,vector<int>&ans){
        visited[node]=1;
        pathVisited[node]=1;

        for(int i: graph[node]){
            if(visited[i]==0){
                if(solve(i,graph,visited,pathVisited,ans)){
                    ans[node] = 0;
                    return true;
                }
            }
            else if(pathVisited[i]==1){
                ans[node]=0;
                return true;
            }
        }

        ans[node]=1;
        pathVisited[node]=0;
        return false;

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                solve(i,graph,visited,pathvisited, ans);
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(ans[i]==1){
                result.push_back(i);
            }
        }

        return result;
    }
};
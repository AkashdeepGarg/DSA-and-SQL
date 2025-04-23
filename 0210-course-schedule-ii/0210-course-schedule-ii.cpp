class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;

        while(q.size()>0){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i:adj[node]){
                indegree[i]--;

                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        vector<int> temp;

        return ans.size()==n ? ans : temp;
    }
};
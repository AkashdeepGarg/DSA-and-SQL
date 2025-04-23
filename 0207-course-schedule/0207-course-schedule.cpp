class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for(auto i: prerequisites){
            adj[i[0]].push_back(i[1]);
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
        int count=0;

        while(q.size()>0){
            int node = q.front();
            q.pop();
            count++;

            for(int i:adj[node]){
                indegree[i]--;

                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        if(count==n){
            return true;
        }

        return false;
    }
};
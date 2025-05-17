class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,1e9);
        vector<int> visited(n+1,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto t: times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        int ans=0;
        time[k]=0;
        pq.push({0,k});

        while(pq.size()>0){
            auto t= pq.top();
            pq.pop();
            int T = t.first;
            int node = t.second;

            if(visited[node]==1) continue;
            visited[node] = 1;
            ans = max(ans,T);

            for(auto temp: adj[node]){
                if(T + temp.second < time[temp.first]){
                    time[temp.first] = T + temp.second;
                    pq.push({time[temp.first],temp.first});
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(time[i] == 1e9) return -1;
        }
        return ans;
    }
};
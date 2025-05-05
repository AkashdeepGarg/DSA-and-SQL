class DisjointSet{
    public:
    vector<int> parent,size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int v){
        if(parent[v]==v){
            return v;
        }

        return parent[v] = findParent(parent[v]);
    }

    void unionParent(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu==pv){
            return;
        }

        if(size[pu]>size[pv]){
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};


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
        //DFS
        // int count=0;
        // int n = isConnected.size();
        // vector<int> graph[n];

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1 && i!=j){
        //             graph[i].push_back(j);
        //             graph[j].push_back(i);
        //         }
        //     }
        // }

        // vector<int> visited(n,0);
        // for(int i=0;i<n;i++){
        //     if(visited[i]==0){
        //         count++;
        //         dfs(i,visited,graph);
        //     }
        // }
        // return count;


        //Kruskal's Algo
        int n = isConnected.size();
        DisjointSet d(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    d.unionParent(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(d.parent[i]==i){
                count++;
            }
        }

        return count;
    }
};
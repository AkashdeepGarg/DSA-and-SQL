class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(parent[node]==node) return node;

        return parent[node] = find(parent[node]);
    }

    void unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return;
        }
        if (size[pv] > size[pu]) {
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU d(n*n);
        int di[]={-1,1,0,0};
        int dj[]={0,0,1,-1};
        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                for(int k=0;k<=3;k++){
                    int row = i+di[k];
                    int col = j+dj[k];

                    if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==1){
                        d.unionSets(((i*n)+j),((row*n)+col));
                    }
                }
            }
        }
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> st;
                for(int k=0;k<=3;k++){
                    int row = i+di[k];
                    int col = j+dj[k];
                    if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==1){
                        st.insert(d.find((row*n)+col));
                    }
                }
                int total = 0;
                for(auto t: st){
                    total += d.size[t];
                }

                ans = max(ans,total + 1);
            }
        }

        //if whole grid is filled with 1
        for(int i=0;i<n*n;i++){
            ans = max(ans,d.size[d.find(i)]);
        }

        return ans;
    }
};
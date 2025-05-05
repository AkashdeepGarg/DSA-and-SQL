class Disjoint{
    public:

    vector<int> parent,size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int n){
        if(parent[n]==n){
            return n;
        }

        return parent[n] = findParent(parent[n]);
    }

    void unionSize(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu==pv){
            return;
        }

        if(size[pu]>size[pv]){
            parent[pv]=pu;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        Disjoint d(n);
        int extras=0;
        for(auto t: connections){
            if(d.findParent(t[0])==d.findParent(t[1])){
                extras++;
            }
            else{
                d.unionSize(t[0],t[1]);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(d.parent[i]==i){
                ans++;
            }
        }

        if(extras >= ans-1){
            return ans-1;
        }

        return -1;
    }
};
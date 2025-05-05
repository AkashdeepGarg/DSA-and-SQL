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
        if(pu==pv) return;
        if(size[pu]>=size[pv]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint d(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    d.unionSize(i,mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }
        vector<vector<string>> ans(n);
       for(auto it: mp){
        string temp = it.first;
        int node = d.findParent(it.second);
        ans[node].push_back(temp);
       }

       vector<vector<string>> result;
       for(int i=0;i<n;i++){
        if(ans[i].size()==0) continue;

        sort(ans[i].begin(),ans[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);

        for(auto t: ans[i]){
            temp.push_back(t);
        }

        result.push_back(temp);
       }

       return result;
    }
};
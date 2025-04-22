class Solution {
private: 
    bool check(int ind, vector<vector<int>>& graph, vector<int> &color) {
        int n = graph.size();
        queue<int> q;
        q.push(ind);
        color[ind]=0;

        while(q.size()>0){
            int node = q.front();
            q.pop();

            for(int i:graph[node]){
                if(color[i]==-1){
                    color[i] = !color[node];
                     q.push(i);
                }
                else if(color[i]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,graph,color)==false){
                    return false;
                }
            }
        }

        return true;
    }
};
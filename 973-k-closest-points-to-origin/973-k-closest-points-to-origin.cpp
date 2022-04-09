#include<bits/stdc++.h>
class Solution {
public:
    int distance(int i, int j){
        return (pow(i,2)+pow(j,2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>> maxh;
        for(auto x:points){
            int dist= distance(x[0],x[1]);
            maxh.push({dist,x});
            if(maxh.size()>k)
                maxh.pop();
        }
        while(maxh.size()>0){
            vector<int> res = maxh.top().second;
            ans.push_back(res);
            maxh.pop();
        }
        
        return ans;
    }
};